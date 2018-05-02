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
  int n=100; //number of iterations
  MyVector<T> x(v);
  MyVector<T> y(v);
  while(n>0) //convert this to error checking later
  {
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
    n--;
  }
  return x;


  //https://www.sanfoundry.com/cpp-program-implement-gauss-seidel-method/
}