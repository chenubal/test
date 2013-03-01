/* 
 * File:   AbstractEBC.h
 * Author: jheers
 *
 * Created on 26. Februar 2013, 08:04
 */

#ifndef ABSTRACTEBC_H
#define	ABSTRACTEBC_H
#include "EBC_Types.h"

class AbstractEBC
{
public:
    virtual size_t NumIn() const = 0;
    virtual size_t NumOut() const = 0;
    virtual action_type In(size_t inPort) = 0;
    virtual void Out(size_t outPort, action_type other) = 0;

    virtual ~AbstractEBC()
    {
    };
};
#endif	/* ABSTRACTEBC_H */

