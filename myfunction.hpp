//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: myfunction.hpp

/*! \file
 *
 * Implementation for the MyFunction Library.
 */

#include "myfunction.h"

using namespace std;

template <class T_returnType, class T_functionPtr>
MyFunction<T_returnType,T_functionPtr>::MyFunction(T_functionPtr f)
{
  m_func=f;
}

template <class T_returnType, class T_functionPtr>
T_returnType MyFunction<T_returnType,T_functionPtr>::operator()(const T_returnType& x, const T_returnType& y)
{
  return m_func(x,y);
}