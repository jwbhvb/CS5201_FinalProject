//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: densematrix.hpp

/*! \file
 *
 * Implementation for the Dense Matrix Library.
 */

#include "densematrix.h"

using namespace std;

template <class T>
MatrixBase<T>& DenseMatrix<T>::operator+(const MatrixBase<T>& other) const
{
  if(getSize()!=other.getSize())
  {
    throw "Matrix addition size error.";
  }
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator[](i)+other[i];
  } 
  return *ret;
}

template <class T>
MatrixBase<T>& DenseMatrix<T>::operator-(const MatrixBase<T>& other) const
{
  if(getSize()!=other.getSize())
  {
    throw "Matrix subtration size error.";
  }
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator[](i)-other[i];
  } 
  return *ret;
}

template <class T>
MatrixBase<T>& DenseMatrix<T>::operator=(const MatrixBase<T>& other)
{
  this->m_size=other.getSize();
  for(int i=0;i<getSize();i++)
  {
    for(int j=0;j<getSize();j++)
    {
      operator()(i,j)=other(i,j);
    }  
  }
  return *this;
}

template <class T>
T& DenseMatrix<T>::operator()(const int &i, const int &j)
{
  return m_data[i][j];
}

template <class T>
const T& DenseMatrix<T>::operator()(const int& i, const int& j) const
{
  return m_data[i][j];
}

template <class T>
MyVector<T>& DenseMatrix<T>::operator[](const int& row)
{
  return m_data[row];
}

template <class T>
const MyVector<T>& DenseMatrix<T>::operator[](const int& row) const
{
  return m_data[row];
}

template <class T>
MatrixBase<T>& DenseMatrix<T>::operator*(const MatrixBase<T>& other) const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  if(getSize()!=other.getSize())
  {
    throw "Matrix multiplication size error.";
  }
  for(int i=0;i<getSize();i++)
  {
    for(int j=0;j<getSize();j++)
    {
      ret->operator()(i,j)=operator[](i).dotProduct(other.transpose()[j]);
    }
  } 
  return *ret;
}

template <class T>
MatrixBase<T>& DenseMatrix<T>::operator*(const T& val) const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator[](i)*val;
  } 
  return *ret;
}

template <class T>
const MatrixBase<T>& DenseMatrix<T>::transpose() const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    for(int j=0;j<getSize();j++)
    {
      ret->operator()(i,j)=operator()(j,i);
    }
  }
  return *ret;
}

template <class T>
bool DenseMatrix<T>::isDiagonallyDominant() const
{
  for(int i=0;i<getSize();i++)
  {
    T diagonalValue=abs(operator()(i,i));
    for(int j=0;j<getSize();j++)
    {
      if(i==j)
        continue;
      diagonalValue-=abs(operator()(i,j));
    }
    if(diagonalValue<0)
    {
      return false;
    }
  }
  return true;
}

template <class T>
MyVector<T>& DenseMatrix<T>::operator*(const MyVector<T>& other) const
{
  MyVector<T>* ret = new MyVector<T>(getSize());
  if(getSize()!=other.getSize())
  {
    throw MyVectorSizeException();
  }
  for(int i=0;i<getSize();i++)
  {
    T tmp=0;
    for(int j=0;j<getSize();j++)
    {
      tmp+=m_data[i][j]*other[j];
    }
    ret->operator[](i)=tmp;
  }
  return *ret;
}

template <class T>
bool DenseMatrix<T>::isSymmetric() const
{
  for(int i=0;i<getSize();i++)
  {
    for(int j=0;j<getSize();j++)
    {
      if(i!=j&&(operator()(i,j)!=operator()(j,i)))
        return false;
    }
  }
  return true;
}

template <class T>
DenseMatrix<T>::DenseMatrix()
{
  this->m_size=0;
}

template <class T>
DenseMatrix<T>::DenseMatrix(const int& size)
{
  this->m_size=size;
  m_data.setSize(size);
  for(int i=0;i<size;i++)
  {
    m_data[i].setSize(size);
  }
}

template <class T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& other)
{
  if(this!=&other)
  {
    this->m_size=other.getSize();
    m_data=other.m_data;
  }
}