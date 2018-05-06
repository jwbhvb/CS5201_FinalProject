//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
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
  m_numDivisions=n;
  m_func=f;
  createMatrix();
  createVector();
}

template <class T_returnType, class T_functionPtr>
MyVector<T_returnType> DirichletSolver<T_returnType,T_functionPtr>::computeGaussSeidel()
{
  m_solverGaussSeidel=new GaussSeidel<T_returnType>();
  return m_solverGaussSeidel->operator()(*m_matrix,m_vector);
}

template <class T_returnType, class T_functionPtr>
MyVector<T_returnType> DirichletSolver<T_returnType,T_functionPtr>::computeSteepestDescent()
{
  m_solverSteepestDescent=new SteepestDescent<T_returnType>();
  return m_solverSteepestDescent->operator()(*m_matrix,m_vector);
}


template <class T_returnType, class T_functionPtr>
void DirichletSolver<T_returnType,T_functionPtr>::createMatrix()
{
  int size = (m_numDivisions-1) * (m_numDivisions-1);
  m_matrix=new SymmetricMatrix<T_returnType>(size);
  
  for (int i=0; i < size; i++)
  {
    m_matrix->operator()(i,i) = 1;
    if (i < size-1 && (i+1)%(m_numDivisions-1) != 0)
    {
      m_matrix->operator()(i+1,i) = -0.25;
      m_matrix->operator()(i,i+1) = -0.25;
    }
    if (i < size-(m_numDivisions-1))
    {
      m_matrix->operator()(i+(m_numDivisions-1),i) = -0.25;
      m_matrix->operator()(i,i+(m_numDivisions-1)) = -0.25;
    }
  }
  return;
}

template <class T_returnType, class T_functionPtr>
void DirichletSolver<T_returnType,T_functionPtr>::createVector()
{
  m_vector.setSize((m_numDivisions-1)*(m_numDivisions-1));
  double h=1.0/m_numDivisions;
  double x=0;
  double y=0;
  bool l,b,r,t;

  for(int i=0;i<m_vector.getSize();i++)
  {
    x+=h;
    if(!(i%(m_numDivisions-1)))
    {
      x=h;
      y+=h;
    }
    l=(x==h);
    b=(y==h);
    r=(x==1-h);
    t=(y==1-h);
    m_vector[i]=0;
    if(l)
      m_vector[i]+=m_func(x-h,y);
    if(b)
      m_vector[i]+=m_func(x,y-h);
    if(r)
      m_vector[i]+=m_func(x+h,y);
    if(t)
      m_vector[i]+=m_func(x,y+h);
  }
  m_vector = m_vector * 0.25;
  return;
}
