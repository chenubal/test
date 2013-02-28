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
#include <iostream>

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

struct connector : 
  public boost::static_visitor<> 
{ 
  action_type ref;
  connector (action_type ref_) : ref(ref_) {}
  
  void operator()(IntAction &a) const { } 

  void operator()(DoubleAction &a) const { } 

  void operator()(StringAction &a) const { 
     if (ref.which()==2)
     {
        a =  boost::get<StringAction>(ref);
     }
  } 
}; 

bool connect_actions(action_type out, action_type in)
{
   bool ok = out.which() == in.which();
   if (ok)
      boost::apply_visitor(connector(in), out);
   return ok;
}


#endif	/* EBC_TYPES_H */

