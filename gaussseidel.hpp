//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
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
      T sum = 0;
      for(int j=0;j<m.getSize();j++)
      {
        if(j<i)
        {
          sum += -m(i,j)*x[j];
        }
        else if (j > i)
        {
          sum += -m(i,j)*oldX[j];
        }
        x[i] = (sum+v[i])/m(i,i);
      }
    }
  }while((oldX-x).dotProduct(oldX-x)>pow(.1,DIGITS_OF_ERROR_TOLERANCE)&&m_iterations<10000);
  return x;
}