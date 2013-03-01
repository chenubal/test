/* 
 * File:   BasicEBC.h
 * Author: jheers
 *
 * Created on 1. März 2013, 09:53
 */

#ifndef BASICEBC_H
#define	BASICEBC_H

#include <vector>
#include <stdexcept>
#include "AbstractEBC.h"

/// A generic terminal EBC, with a single T input and no output

template<class T>
class Terminal : public AbstractEBC
{
public:

    Terminal()
    {
        in = std::bind(&Terminal<T>::process, this, std::placeholders::_1);
    }

    virtual size_t NumIn() const
    {
        return 1;
    };

    virtual size_t NumOut() const
    {
        return 0;
    };

    virtual action_type In(size_t inPort)
    {
        return in;
    };

    virtual void Out(size_t outPort, action_type other)
    {
        throw std::logic_error("no Out port available");
    };

    typedef std::function < void ( T const&) > action_t;

    action_t in;

    /// Main processing ( to be overwritten)
    virtual void process(T const& x)
    {
    }
};

class ConsoleWriter : public Terminal<std::string>
{
    std::string prefix;
public:

    ConsoleWriter(std::string s = "") : prefix(s)
    {
    }

    /// Prints a message
    virtual void process(std::string const& message)
    {
        std::cout << prefix << message << std::endl;
    }
};

template<class T>
class Multiplier
{
    typedef std::function < void ( T const&) > action_t;
    action_t in;
    std::vector<action_t> outs;

public:

    Multiplier(size_t numOuts) : outs(numOuts)
    {
        in = std::bind(&Multiplier<T>::process, this, std::placeholders::_1);
    }

    virtual size_t NumIn() const
    {
        return 1;
    };

    virtual size_t NumOut() const
    {
        return outs.size();
    };

    virtual action_type In(size_t inPort)
    {
        return in;
    };

    virtual void Out(size_t outPort, action_type other)
    {
        outs[outPort] = boost::get<action_t>(other);
    };

    void process(T const& x)
    {
        for (auto out : outs) 
            if (out) out(x);
    }

};

#endif	/* BASICEBC_H */

