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
  m_numDivisions=n;
  m_func=f;
  createMatrix();
  createVector();
}

template <class T_returnType, class T_functionPtr>
MyVector<T_returnType> DirichletSolver<T_returnType,T_functionPtr>::computeGaussSeidel()
{
  return GaussSeidel<T_returnType>()(*m_matrix,m_vector);
}

template <class T_returnType, class T_functionPtr>
MyVector<T_returnType> DirichletSolver<T_returnType,T_functionPtr>::computeSteepestDescent()
{
  return SteepestDescent<T_returnType>()(*m_matrix,m_vector);
}


template <class T_returnType, class T_functionPtr>
void DirichletSolver<T_returnType,T_functionPtr>::createMatrix()
{
  m_matrix=new SymmetricMatrix<T_returnType>((m_numDivisions-1)*(m_numDivisions-1));
  double h = 1.0/m_numDivisions;
  double x = 0;
  double y = 0;
  bool r, t;

  for (int i=0; i<m_matrix->getSize(); i++)
  {
    x += h;

    if (!(i%(m_numDivisions-1)))
    {
      y += h;
      x = h;
    }
    
    r = (m_numDivisions-2 != i%(m_numDivisions-1));
    t = (i != m_matrix->getSize() - 1);

    for (int j=i; j<m_matrix->getSize(); j++)
    {
      if (j == (i+(m_numDivisions-1)) && t)
        m_matrix->operator()(i,j)=-h;
      else if (j == (i+1) && r)
        m_matrix->operator()(i,j) = -h;
      else if (i == j)
        m_matrix->operator()(i,j) = 1;
      else
        m_matrix->operator()(i,j) = 0;
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
      m_vector[i]+=h*m_func(x-h,y);
    if(b)
      m_vector[i]+=h*m_func(x,y-h);
    if(r)
      m_vector[i]+=h*m_func(x+h,y);
    if(t)
      m_vector[i]+=h*m_func(x,y+h);
  }
  cout<<"\n\nYou already know:\n\n"<<m_vector<<endl;
  return;
}
