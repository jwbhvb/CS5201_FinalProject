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
  int matrix_size = (m_numDivisions-1) * (m_numDivisions-1);
  SymmetricMatrix<double> m_matrix(matrix_size);
  
  double h = 1.0/m_numDivisions;

  double x_vals = 0;
  double y_vals = 0;

  bool r, t;


  for (int i=0; i<matrix_size; i++)
  {
    x_vals += h;

    if (i%(m_numDivisions-1) == 0)
    {
      y_vals += h;
      x_vals = h;
    }
    
    r = (m_numDivisions-2 != i%(m_numDivisions-1));
    t = (i != matrix_size - 1);

    for (int j=r; j<matrix_size; j++)
    {
      if (j == (i+(m_numDivisions-1)) && t)
        m_matrix(i,j) = -h;
      else if (j == (i+1) && r)
        m_matrix(i,j) = -h;
      else if (i == j)
        m_matrix(i,j) = 1;
      else
        m_matrix(i,j) = 0;
    }

  }
  //cout << "made it to end of createMatrix();" << endl;
  cout << m_matrix << endl;

  return;
}

template <class T_returnType, class T_functionPtr>
void DirichletSolver<T_returnType,T_functionPtr>::createVector()
{
  m_vector.setSize((m_numDivisions-1) * (m_numDivisions-1));
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
