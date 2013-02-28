/* 
 * File:   ebc_types.h
 * Author: jheers
 *
 * Created on 27. Februar 2013, 08:14
 */

#ifndef EBC_TYPES_H
#define	EBC_TYPES_H

#include <string>
#include <boost/function.hpp>
#include <boost/variant.hpp>

typedef boost::function < void( int ) >  IntAction;
typedef boost::function < void( double ) >  DoubleAction;
typedef boost::function < void( std::string const& ) >  StringAction;

typedef boost::variant<IntAction, DoubleAction, StringAction> action_type;

void apply_action(action_type a, std::string const& x)
{
   boost::get<StringAction>(a)(x);
}

void apply_action(action_type a, int x)
{
   boost::get<IntAction>(a)(x);
}

void apply_action(action_type a, double x)
{
   boost::get<DoubleAction>(a)(x);
}

#endif	/* EBC_TYPES_H */

