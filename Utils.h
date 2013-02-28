/* 
 * File:   Utils.h
 * Author: jheers
 *
 * Created on 26. Februar 2013, 10:35
 */

#ifndef UTILS_H
#define	UTILS_H

struct FalseType { enum { value = false }; };
struct TrueType { enum { value = true }; };


template <typename T1, typename T2>
struct IsSame
{
   typedef FalseType Result;
};


template <typename T>
struct IsSame<T,T>
{
   typedef TrueType Result;
};

#endif	/* UTILS_H */

