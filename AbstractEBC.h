/* 
 * File:   AbstractEBC.h
 * Author: jheers
 *
 * Created on 26. Februar 2013, 08:04
 */

#ifndef ABSTRACTEBC_H
#define	ABSTRACTEBC_H
#include <vector>
#include "EBC_Types.h"
#include <boost/bind.hpp> 

class AbstractEBC 
{
public:
    virtual size_t NumIn() const = 0;
    virtual size_t NumOut() const = 0;
    virtual action_type In(size_t inPort) = 0;
    virtual void Out(size_t outPort, action_type other) = 0;
    virtual ~AbstractEBC() {};
};


/// A generic terminal EBC, with a single T input and no output
template<class T>
class Terminal :public AbstractEBC
{
public:
    virtual size_t NumIn() const {return 1;};
    virtual size_t NumOut() const {return 0;};
    virtual action_type In(size_t inPort) {return in;};
    virtual void Out(size_t outPort, action_type other) {throw "empty";};

    typedef boost::function < void ( T const& ) > action_t;

    action_t in;

	/// Constructor
	/// @author silverback
	Terminal()
	{
		in = boost::bind( &Terminal<T>::process, this, _1 ) ;
	}
	/// Main processing ( to be overwritten)
	/// @param	x give the input value
	/// @author silverback
	virtual void process( T const& x ) {}
};

class ConsoleWriter : public Terminal<std::string>
{
   std::string prefix;
public:
   ConsoleWriter(std::string s = ""): prefix(s) {}
	/// Prints a message
	/// @param	message gives the message
	/// @author silverback
	virtual void process( std::string const& message ) {	std::cout << prefix << message << std::endl; }
};

template<class T>
class Multiplier
{
   typedef boost::function < void ( T const& ) > action_t;
	action_t in;
	std::vector<action_t> outs;

public:
	Multiplier( size_t numOuts )
	{
		in = boost::bind( &Multiplier<T>::process, this, _1 ) ;
		outs.resize( numOuts );
	}

   virtual size_t NumIn() const {return 1;};
   virtual size_t NumOut() const {return outs.size();};
   virtual action_type In(size_t inPort)  {  return in;};
   virtual void Out(size_t outPort, action_type other) 
   { 
      outs[outPort] = boost::get<action_t>(other); 
   };
	void process( T const& x )	
   {
      for(size_t i=0; i< outs.size(); i++ ) {
         if (outs[i]) outs[i](x);
      }
   }

};

#endif	/* ABSTRACTEBC_H */

