//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: symmetricmatrix.hpp

/*! \file
 *
 * Implementation for the Symmetric Matrix Library.
 */

#include "symmetricmatrix.h"

using namespace std;

template <class T>
MatrixBase<T>& SymmetricMatrix<T>::operator+(const MatrixBase<T>& other) const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator[](i)+other[i];
  } 
  return *ret;
}

template <class T>
MatrixBase<T>& SymmetricMatrix<T>::operator-(const MatrixBase<T>& other) const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator[](i)-other[i];
  } 
  return *ret;
}

template <class T>
MatrixBase<T>& SymmetricMatrix<T>::operator=(const MatrixBase<T>& other)
{
  this->m_size=other.getSize();
  for(int i=0;i<getSize();i++)
  {
    for(int j=0;j<getSize();j++)
    {
      if(other(i,j)!=other(j,i))
      {
        throw "Can't set a non-symmetric matrix to a symmetric matrix.";
      }
      else
      {
        operator()(i,j)=other(i,j);
      }
    }  
  }
  return *this;
}

template <class T>
T& SymmetricMatrix<T>::operator()(const int &i, const int &j)
{
  if(i>j)
    return m_data[i][j];
  return m_data[j][i];
}

template <class T>
const T& SymmetricMatrix<T>::operator()(const int& i, const int& j) const
{
  if(i>j)
    return m_data[i][j];
  return m_data[j][i];
}

template <class T>
MyVector<T>& SymmetricMatrix<T>::operator[](const int& row)
{
  MyVector<T>* ret = new MyVector<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator()(row,i);
  }
  return *ret;
}

template <class T>
const MyVector<T>& SymmetricMatrix<T>::operator[](const int& row) const
{
  MyVector<T>* ret = new MyVector<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator()(row,i);
  }
  return *ret;
}

template <class T>
MatrixBase<T>& SymmetricMatrix<T>::operator*(const MatrixBase<T>& other) const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  if(getSize()!=other.getSize())
  {
    throw MyVectorSizeException();
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
MatrixBase<T>& SymmetricMatrix<T>::operator*(const T& val) const
{
  MatrixBase<T>* ret = new DenseMatrix<T>(getSize());
  for(int i=0;i<getSize();i++)
  {
    ret->operator[](i)=operator[](i)*val;
  }
  return *ret;
}

template <class T>
const MatrixBase<T>& SymmetricMatrix<T>::transpose() const
{
  return *this;
}

template <class T>
bool SymmetricMatrix<T>::isDiagonallyDominant() const
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
MyVector<T>& SymmetricMatrix<T>::operator*(const MyVector<T>& other) const
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
      tmp+=operator()(i,j)*other[i];
    }
    ret->operator[](i)=tmp;
  }
  return *ret;
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix()
{
  this->m_size=0;
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix(const int& size)
{
  this->m_size=size;
  m_data.setSize(size);
  for(int i=0;i<size;i++)
  {
    m_data[i].setSize(i+1);
  }
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix(const SymmetricMatrix<T>& other)
{
  this->m_size=other.m_size;
  m_data=other.m_data;
}