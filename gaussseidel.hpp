//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: gaussseidel.hpp

/*! \file
 *
 * Implementation for the Gauss Seidel Library.
 */

#include "gaussseidel.h"

using namespace std;

template <class T>
GaussSeidel<T>::GaussSeidel()
{

}

template <class T>
MyVector<T> GaussSeidel<T>::operator()(const MatrixBase<T>& m, const MyVector<T>& v)
{
  if(m.getSize()!=v.getSize())
    throw SolutionUndefinedException();
  if(m.isIdentity())
    return v;
  MyVector<T> x(v);
  MyVector<T> y(v);
  MyVector<T> oldX(x);
  m_iterations=0;
  do
  {
    m_iterations++;
    oldX=x;
    for(int i=0;i<m.getSize();i++)
    {
      y[i]=v[i]/(m[i][i]);
      for(int j=0;j<m.getSize();j++)
      {
        if(j==i)
          continue;
        y[i]-=((m[i][j]/m[i][i])*x[j]);
        x[i]=y[i];
      }
    }
  }while((oldX-x).dotProduct(oldX-x)>pow(.1,20)&&m_iterations<10000);
  return x;
}