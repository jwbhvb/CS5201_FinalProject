//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: myfunction.h

/*! \file
 *
 * A class for holding a function.
 */

#ifndef MYFUNCTION_H
#define MYFUNCTION_H 

using namespace std;

template <class T_returnType, class T_functionPtr>
class MyFunction
{
  private:
    T_functionPtr m_func;
  public:
    /*! Constructor.
     * \pre None.
     * \post Creates a MyFunction object.
     * \return None.
     */
    MyFunction() {}

    /*! Constructor.
     * \pre None.
     * \post Creates a MyFunction object with m_func pointing to the function that 'f' is pointing to.
     * \return None.
     */
    MyFunction(T_functionPtr f);

    /*! () operator, which evaluates the function at x and y.
     * \pre The function needs to be defined for x and y else it will throw an error.
     * \post Evaluates the function at x and y and returns the result.
     * \return T_returnType.
     * \throws SolutionUndefinedException
     */
    T_returnType operator()(const T_returnType& x, const T_returnType& y);
};

#include "myfunction.hpp"
#endif