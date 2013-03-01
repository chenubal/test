/* 
 * File:   ebc_types.h
 * Author: jheers
 *
 * Created on 27. Februar 2013, 08:14
 */

#ifndef EBC_TYPES_H
#define	EBC_TYPES_H

#include <string>
#include <functional>
#include <boost/variant.hpp>

typedef std::function < void( int) > IntAction;
typedef std::function < void( double) > DoubleAction;
typedef std::function < void( std::string const&) > StringAction;

typedef boost::variant<IntAction, DoubleAction, StringAction> action_type;

#endif	/* EBC_TYPES_H */

