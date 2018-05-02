//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: myvector.hpp

/*! \file
 *
 * Implementation for the MyVector Library.
 */

#include "myvector.h"

using namespace std;

template <class T>
MyVector<T>::MyVector()
{
  m_size=0;
  m_data=NULL;
}

template <class T>
MyVector<T>::MyVector(int size)
{
  try
  {
    if(size<0)
    {
      throw MyVectorSizeException();
    }
    else
    {
      m_size=size;
      m_data=new T[m_size];
    }
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
  m_size=other.m_size;
  m_data=new T[m_size];
  copy(other);
}

template <class T>
MyVector<T>::MyVector(MyVector<T>&& other)
{
  if(this!=&other)
  {
    m_size=other.m_size;
    m_data=other.m_data;
    other.m_data=NULL;
    other.m_size=0;
  }
}

template <class T>
MyVector<T>::~MyVector()
{
  delete[] m_data;
}

template <class T>
int MyVector<T>::getSize() const
{
  return m_size;
}

template <class T>
void MyVector<T>::swap(const int i, const int j)
{
  if(i==j)
  {
    return;
  }
  try
  {
    if(i<0||j<0||i>=m_size||j>=m_size)
    {
      throw MyVectorIndexException();
    }
    T tmp=m_data[i];
    m_data[i]=m_data[j];
    m_data[j]=tmp;
  }
  catch(MyVectorIndexException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
}

template <class T>
void MyVector<T>::setSize(const int size)
{
  if(size<0)
  {
    delete[] m_data;
    m_size=size;
    throw MyVectorSizeException();
  }
  if(size!=m_size)
  {
    delete[] m_data;
    m_size=size;
    m_data=new T[m_size];
  }
}

template <class T>
T& MyVector<T>::operator[](const int i)
{
  if(i<0||i>=m_size)
  {
    throw MyVectorIndexException();
  }
  return m_data[i];
}

template <class T>
const T& MyVector<T>::operator[](const int i) const
{
  try
  {
    if(i<0||i>=m_size)
    {
      throw MyVectorIndexException();
    }
    return m_data[i];
  }
  catch(MyVectorIndexException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  return m_data[i];
}

template <class T>
const T MyVector<T>::dotProduct(const MyVector<T>& rhs) const
{
  T ret=0;
  try
  {
    if(m_size!=rhs.m_size)
    {
      throw MyVectorSizeException();
    }
    for(int i=0;i<m_size;i++)
    {
      ret+=m_data[i]*rhs.m_data[i];
    }
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  return ret;
}

template <class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& rhs) const
{
  MyVector<T> ret(*this);
  try
  {
    if(m_size!=rhs.m_size)
    {
      throw MyVectorSizeException();
    }
    for(int i=0;i<m_size;i++)
    {
      ret.m_data[i]+=rhs.m_data[i];
    }
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  return ret;
}

template <class T>
MyVector<T> MyVector<T>::operator-(const MyVector<T>& rhs) const
{
  MyVector<T> ret(*this);
  try
  {
    if(m_size!=rhs.m_size)
    {
      throw MyVectorSizeException();
    }
    for(int i=0;i<m_size;i++)
    {
      ret.m_data[i]-=rhs.m_data[i];
    }
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  return ret;
}

template <class T>
MyVector<T>& MyVector<T>::operator+=(const MyVector<T>& rhs)
{
  try
  {
    if(m_size!=rhs.m_size)
    {      
      throw MyVectorSizeException();
    }
    for(int i=0;i<m_size;i++)
    {
      m_data[i]+=rhs.m_data[i];
    }
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::operator-=(const MyVector<T>& rhs)
{
  try
  {
    if(m_size!=rhs.m_size)
    {
      throw MyVectorSizeException();
    }
    for(int i=0;i<m_size;i++)
    {
      m_data[i]-=rhs.m_data[i];
    }
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs)
{
  if(m_data!=rhs.m_data)
  {
    setSize(rhs.m_size);
    copy(rhs);
  }
  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const T val)
{
  T* p = m_data+m_size;
  while(p>m_data)*--p=val;
  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& rhs)
{
  if(this!=&rhs)
  {
    m_size=rhs.m_size;
    delete[] m_data;
    m_data=rhs.m_data;
    rhs.m_data=NULL;
    rhs.m_size=0;
  }
  return *this;
}

template <class T>
bool MyVector<T>::operator==(const MyVector<T>& rhs) const
{
  if(m_size!=rhs.m_size)
  {
    return false;
  }
  for(int i=0;i<m_size;i++)
  {
    if(m_data[i]!=rhs.m_data[i])
    {
      return false;
    }
  }
  return true;
}

template <class T>
bool MyVector<T>::operator!=(const MyVector<T>& rhs) const
{
  return !(*this==rhs);
}

template <class T>
void MyVector<T>::copy(const MyVector<T>& other)
{
  T* p = m_data+m_size;
  T* q = other.m_data+other.m_size;
  while(p>m_data)*--p=*--q;
  return;
}
