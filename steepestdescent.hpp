//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
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
  MyVector<T> currentGuess(v);
  MyVector<T> previousGuess(v);
  MyVector<T> r;
  m_iterations=0;
  do
  {
    m_iterations++;
    previousGuess=currentGuess;
    r=v-(m*currentGuess);
    T alpha=(r.dotProduct(r))/((m*r).dotProduct(r));
    currentGuess+=r*alpha;
  } while((previousGuess-currentGuess).dotProduct((previousGuess-currentGuess))>pow(0.1,DIGITS_OF_ERROR_TOLERANCE)&&m_iterations<10000);
  return currentGuess;
}
