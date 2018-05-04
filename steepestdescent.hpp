//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: steepestdescent.hpp

/*! \file
 *
 * Implementation for the Steepest Descent Library.
 */

#include "steepestdescent.h"

using namespace std;

template <class T>
SteepestDescent<T>::SteepestDescent()
{

}

template <class T>
MyVector<T> SteepestDescent<T>::operator()(const MatrixBase<T>& m, const MyVector<T>& v)
{
  if(m.getSize()!=v.getSize())
    throw SolutionUndefinedException();
  if(!m.isSymmetric()||!m.isDiagonallyDominant())
    throw "Matrix must be symmetric and diagonally dominant.";
  if(m.isIdentity())
    return v;
  MyVector<T> currentGuess(v.getSize());
  for(int i=0;i<v.getSize();i++)
  {
    currentGuess[i]=i;
  }
  MyVector<T> previousGuess(v.getSize());
  MyVector<T> r;
  do
  {
    previousGuess=currentGuess;
    r=v-(m*currentGuess);
    auto alpha=(r.dotProduct(r))/((m*r).dotProduct(r));
    currentGuess+=r*alpha;
  } while(r.dotProduct(r)>pow(0.1,25));
  return currentGuess;
}
