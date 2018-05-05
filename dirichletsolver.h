//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
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
    MatrixBase<T_returnType>* m_matrix;
    MyVector<T_returnType> m_vector;
    int m_numDivisions;
    MyFunction<T_returnType,T_functionPtr> m_func; 
    GaussSeidel<T_returnType>* m_solverGaussSeidel;
    SteepestDescent<T_returnType>* m_solverSteepestDescent;

    /*! Creates the matrix from the bondary function and the number of divisions.
     * \pre None.
     * \post The m_matrix is updated.
     * \return Void.
     */
    void createMatrix();

    /*! Creates the vector from the bondary function and the number of divisions.
     * \pre None.
     * \post The m_vector is updated.
     * \return Void.
     */
    void createVector();

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

    /*! Solver getter.
     * \pre None.
     * \post Gets m_solverGaussSeidel.
     * \return GaussSeidel<T_returnType>.
     */
    const GaussSeidel<T_returnType>& getGaussSeidelSolver() const {return *m_solverGaussSeidel;}

    /*! Solver getter.
     * \pre None.
     * \post Gets m_solverSteepestDescent.
     * \return SteepestDescent<T_returnType>.
     */
    const SteepestDescent<T_returnType>& getSteepestDescentSolver() const {return *m_solverSteepestDescent;}
};

#include "dirichletsolver.hpp"
#endif