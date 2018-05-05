//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: steepestdescent.h

/*! \file
 *
 * A class for solving a system of equations using steepest descent.
 */

#ifndef STEEPESTDESCENT_H
#define STEEPESTDESCENT_H 

#include "matrixbase.h"
#include "solutionundefinedexception.h"

using namespace std;

template <class T>
class SteepestDescent
{
  private:
    int m_iterations;
  public:
    /*! Constructor.
     * \pre None.
     * \post Creates a Steepest Descent object.
     * \return None.
     */
    SteepestDescent();

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
    const int& getCount(){return m_iterations;}
};

#include "steepestdescent.hpp"
#endif