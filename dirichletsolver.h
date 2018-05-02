//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: dirichletsolver.h

/*! \file
 *
 * A class for implementing a Dirichlet Solver.
 */


#ifndef DIRICHLETSOLVER_H
#define DIRICHLETSOLVER_H 

#include "GaussSeidel.h"
#include "SteepestDescent.h"

using namespace std;

template <class T_returnType, class T_functionPtr>
class DirichletSolver
{
  private:
    DenseMatrix<T_returnType> m_matrix;
    MyVector<T_returnType> m_vector;
  public:
    /*! Constructor.
     * \pre None.
     * \post Creates a Dirichlet Solver object.
     * \return None.
     */
    DirichletSolver(const int& n, const MyFunction<T_returnType,T_functionPtr>& f);

    /*! Solves the system of equations using the Gauss Seidel method.
     * \pre None.
     * \post Computes the solution to the system of equations.
     * \return MyVector<T_returnType>.
     */
    MyVector<T_returnType> computeGaussSeidel();

    /*! Solves the system of equations using the Steepest Descent method.
     * \pre None.
     * \post Computes the solution to the system of equations.
     * \return MyVector<T_returnType>.
     */
    MyVector<T_returnType> computeSteepestDescent();
};

#include "dirichletsolver.hpp"
#endif