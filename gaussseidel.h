//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: gaussseidel.h

/*! \file
 *
 * A class for solving a system of equations using the Gauss Seidel method.
 */

#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H 

#include "matrixbase.h"
#include "solutionundefinedexception.h"

using namespace std;

template <class T>
class GaussSeidel
{
  private:
    int m_iterations;
  public:
    /*! Constructor.
     * \pre None.
     * \post Creates a GaussSeidel object.
     * \return None.
     */
    GaussSeidel();

    /*! () operator, which computes the solution ONLY for square matrices.
     * \pre The size of m must be the size of v. If the system is undefined, it will throw an error.
     * \post Calculates the solution vector of the system and returns it to the calling object.
     * \return MyVector<T> object.
     * \throws SolutionUndefinedException
     */
    MyVector<T> operator()(const MatrixBase<T>& m, const MyVector<T>& v);

    /*! Count getter.
     * \pre The function evaluator needs to be called before grabbing this value.
     * \post Returns the m_iterations.
     * \return Int.
     */
    const int& getCount() const {return m_iterations;}
};

#include "gaussseidel.hpp"
#endif