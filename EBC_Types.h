/* 
 * File:   ebc_types.h
 * Author: jheers
 *
 * Created on 27. Februar 2013, 08:14
 */

#ifndef EBC_TYPES_H
#define	EBC_TYPES_H

#include <functional>
#include <boost/variant.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>

typedef std::function < void( int) > IntAction;
typedef std::function < void( double) > DoubleAction;
typedef std::function < void( std::string const&) > StringAction;
typedef std::function < void( cv::Mat const&) > ImageAction;

typedef boost::variant<IntAction, DoubleAction, StringAction, ImageAction> action_type;

#endif	/* EBC_TYPES_H */

