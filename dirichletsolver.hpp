//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: dirichletsolver.hpp

/*! \file
 *
 * Implementation for the DirichletSolver Library.
 */

#include "dirichletsolver.h"

using namespace std;

template <class T_returnType, class T_functionPtr>
DirichletSolver<T_returnType,T_functionPtr>::DirichletSolver(const int& n, const MyFunction<T_returnType,T_functionPtr>& f)
{
  createMatrix();
  createVector();
}

template <class T_returnType, class T_functionPtr>
MyVector<T_returnType> DirichletSolver<T_returnType,T_functionPtr>::computeGaussSeidel()
{
  return GaussSeidel<T_returnType>()(m_matrix,m_vector);
}

template <class T_returnType, class T_functionPtr>
MyVector<T_returnType> DirichletSolver<T_returnType,T_functionPtr>::computeSteepestDescent()
{
  return SteepestDescent<T_returnType>()(m_matrix,m_vector);
}

template <class T_returnType, class T_functionPtr>
void DirichletSolver<T_returnType,T_functionPtr>::createMatrix()
{
  m_matrix.setSize(pow(m_numDivisions-1,2));
  //todo
  return;
}

template <class T_returnType, class T_functionPtr>
void DirichletSolver<T_returnType,T_functionPtr>::createVector()
{
  m_vector.setSize(pow(m_numDivisions-1,2));
  //todo
  return;
}
