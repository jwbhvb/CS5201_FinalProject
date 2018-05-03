//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: myvector.h

/*! \file
 *
 * A Custom Vector Library.
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H 

#include <iomanip>
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include "myvectorsizeexception.h"
#include "myvectorindexexception.h"
#include "truncatedfileexception.h"

using namespace std;

const int DIGITS_OF_PRECISION = 4;

template <class T>
class MyVector
{
  private:
    int m_size;
    T* m_data;
    /*! Copy function.
     * \pre The other object must have the same size of the calling object.
     * \post Copies all the values from other into the calling object's data.
     * \return Void.
     */
    void copy(const MyVector<T>& other);

  public:
    /*! Default constructor.
     * \pre None.
     * \post Initializes a MyVector object.
     * \return None.
     */
    MyVector();

    /*! Creates a MyVector object with m_size = size.
     * \pre Size must be positive.
     * \post Initializes a MyVector object.
     * \return None.
     * \throws MyVectorSizeException
     */
    MyVector(int size);

    /*! Copy constructor.
     * \pre None.
     * \post Copies the values from other into a new MyVector object.
     * \return None.
     */
    MyVector(const MyVector<T>& other);

    /*! Move constructor.
     * \pre None.
     * \post Copies the values from other into a new MyVector object and sets other to null.
     * \return None.
     */
    MyVector(MyVector<T>&& other);

    /*! Destructor.
     * \pre None.
     * \post Frees up memory.
     * \return None.
     */
    ~MyVector();

    /*! Size getter.
     * \pre None.
     * \post Returns the m_size.
     * \return Int.
     */
    int getSize() const;

    /*! Swaps the elements at index i and j.
     * \pre 'i' and 'j' must be between 0 and m_size-1.
     * \post Elements at spot i and j and swapped.
     * \return Void.
     * \throws MyVectorIndexException
     */
    void swap(const int i, const int j);

    /*! Size setter.
     * \pre Size must be positive.
     * \post Sets the m_size to size.
     * \return Void.
     * \throws MyVectorSizeException
     */
    void setSize(const int size);

    /*! Subscript operator.
     * \pre 'i' must be between 0 and m_size-1.
     * \post Returns the element at that index.
     * \return T object.
     * \throws MyVectorIndexException
     */
    T& operator[](const int i);

    /*! Subscript operator.
     * \pre 'i' must be between 0 and m_size-1.
     * \post Returns the element at that index.
     * \return T object.
     * \throws MyVectorIndexException
     */
    const T& operator[](const int i) const;

    /*! Calculates the dot product between 2 vectors.
     * \pre Size of rhs and calling object size must be the same. T must have the += operator defined.
     * \post Returns the dot product of the calling object and rhs.
     * \return T object.
     * \throws MyVectorSizeException
     */
    const T dotProduct(const MyVector<T>& rhs) const;

    /*! + operator.
     * \pre Size of rhs and calling object size must be the same.
     * \post Elements from rhs are added to the calling object and stored in a new MyVector<T> object.
     * \return MyVector object.
     * \throws MyVectorSizeException
     */
    MyVector<T> operator+(const MyVector<T>& rhs) const;
    
    /*! - operator.
     * \pre Size of rhs and calling object size must be the same.
     * \post Elements from rhs are subtracted from the calling object and stored in a new MyVector<T> object.
     * \return MyVector object.
     * \throws MyVectorSizeException
     */
    MyVector<T> operator-(const MyVector<T>& rhs) const;
    
    /*! += operator.
     * \pre Size of rhs and calling object size must be the same.
     * \post Elements from rhs are added to the calling object.
     * \return MyVector object.
     * \throws MyVectorSizeException
     */
    MyVector<T>& operator+=(const MyVector<T>& rhs);
    
    /*! -= operator.
     * \pre Size of rhs and calling object size must be the same.
     * \post Elements from rhs are subtracted from the calling object.
     * \return MyVector object.
     * \throws MyVectorSizeException
     */
    MyVector<T>& operator-=(const MyVector<T>& rhs);

    /*! Assignment operator.
     * \pre None.
     * \post Assigns the values from rhs into a new MyVector object.
     * \return MyVector object.
     */
    MyVector<T>& operator=(const MyVector<T>& rhs);

    /*! Move assignment operator.
     * \pre None.
     * \post Assigns the values from rhs into a new MyVector object and sets rhs to null.
     * \return MyVector object.
     */
    MyVector<T>& operator=(MyVector<T>&& rhs);

    /*! Assignment operator.
     * \pre None.
     * \post Assigns val to every spot in the MyVector object.
     * \return MyVector object.
     */
    MyVector<T>& operator=(const T val);

    /*! Equality operator.
     * \pre None.
     * \post Returns true if the calling object and rhs are the same, else false.
     * \return Bool.
     */
    bool operator==(const MyVector<T>& rhs) const;

    /*! Inequality operator.
     * \pre None.
     * \post Returns true if the calling object and rhs are not the same, else false.
     * \return Bool.
     */
    bool operator!=(const MyVector<T>& rhs) const;

    /*! * operator.
     * \pre None.
     * \post Elements from v are multiplied by val and stored in a new MyVector<T> object.
     * \return MyVector object.
     */
    friend MyVector<T> operator*(const T& val, const MyVector<T>& v)
    {
      MyVector<T> ret(v);
      for(int i=0;i<v.m_size;i++)
      {
        ret.m_data[i]*=val;
      }
      return ret;
    }

    /*! * operator.
     * \pre None.
     * \post Elements from v are multiplied by val and stored in a new MyVector<T> object.
     * \return MyVector object.
     */
    friend MyVector<T> operator*(const MyVector<T>& v, const T& val)
    {
      MyVector<T> ret(v);
      for(int i=0;i<v.m_size;i++)
      {
        ret.m_data[i]*=val;
      }
      return ret;
    }

    /*! *= operator.
     * \pre None.
     * \post Elements from v are multiplied by val.
     * \return MyVector object.
     */
    friend MyVector<T>& operator*=(MyVector<T>& v, const T& val)
    {
      for(int i=0;i<v.m_size;i++)
      {
        v.m_data[i]*=val;
      }
      return v;
    }

    /*! Extraction operator.
     * \pre None.
     * \post Elements are read in from the stream and stored in m_data.
     * \return istream object.
     * \throws TruncatedFileException
     */
    friend istream& operator>>(istream& in, MyVector<T>& vector)
    {
      for(int i=0;i<vector.getSize();i++)
      {
        if(!(in>>vector[i]))
          throw TruncatedFileException(); 
      }
      return in;
    }

    /*! Insertion operator.
     * \pre None.
     * \post Elements from m_data are inserted into the stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream& out, const MyVector<T>& vector)
    {
      for(int i=0;i<vector.getSize();i++)
      {
        if(i+1<vector.getSize())
        {
          out<<fixed<<setprecision(DIGITS_OF_PRECISION)<<vector[i]<<"\n";
        }
        else
        {
          out<<fixed<<setprecision(DIGITS_OF_PRECISION)<<vector[i];  
        }
      }
      return out;
    }
};

#include "myvector.hpp"
#endif