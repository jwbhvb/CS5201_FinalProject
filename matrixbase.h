//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: matrixbase.h

/*! \file
 *
 * Base class for a square Matrix Library.
 */

#ifndef MATRIXBASE_H
#define MATRIXBASE_H 

#include "myvector.h"

using namespace std;

template <class T>
class MatrixBase
{
  protected:
    int m_size;
  public:
    /*! Size getter.
     * \pre None.
     * \post Returns the size of the matrix.
     * \return Int.
     */
    virtual int getSize() const {return m_size;}
    /*! Accesses the element at the location i,j.
     * \pre i and j must be between 0 and m_size-1.
     * \post Returns the element of the matrix at that location.
     * \return T.
     */
    virtual T& operator()(const int &i, const int &j) = 0;

    /*! Accesses the element at the location i,j.
     * \pre i and j must be between 0 and m_size-1.
     * \post Returns the element of the matrix at that location.
     * \return T.
     */
    virtual const T& operator()(const int& i, const int& j) const = 0;

    /*! Checks if the matrix is diagonally dominant.
     * \pre None.
     * \post Returns true if the matrix is digonally dominant.
     * \return Bool.
     */
    virtual bool isDiagonallyDominant() const = 0;

    /*! Computes the transpose of a matrix.
     * \pre None.
     * \post Returns the transpose of the matrix.
     * \return MatrixBase<T>.
     */
    virtual const MatrixBase<T>& transpose() const = 0;

    /*! Row getter.
     * \pre 'row' must be between 0 and m_size-1.
     * \post Returns the row of the matrix at that location.
     * \return MyVector<T>.
     */
    virtual MyVector<T>& operator[](const int& row) = 0;

    /*! Row getter.
     * \pre 'row' must be between 0 and m_size-1.
     * \post Returns the row of the matrix at that location.
     * \return MyVector<T>.
     */
    virtual const MyVector<T>& operator[](const int& row) const = 0;

    /*! * operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix multiplied by other.
     * \return MyVector<T>.
     */
    virtual MyVector<T>& operator*(const MyVector<T>& other) const
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
          tmp+=operator()(i,j)*other[j];
        }
        ret->operator[](i)=tmp;
      }
      return *ret;
    }

    /*! * operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix multiplied by other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator*(const MatrixBase<T>& other) const = 0;

    /*! * operator.
     * \pre None.
     * \post Multiplies every matrix element by val.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator*(const T& val) const = 0;

    /*! *= operator.
     * \pre None.
     * \post Multiplies every matrix element by val and changes the calling object.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator*=(const T& val)
    {
      *this=*this*val;
      return *this;
    }

    /*! *= operator.
     * \pre m_size must be the same as other's size.
     * \post Multiplies the matrix with other and modifies the calling object.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator*=(const MatrixBase<T>& other)
    {
      *this=*this*other;
      return *this;
    }

    /*! += operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix added with other and modifies the calling object.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator+=(const MatrixBase<T>& other)
    {
      *this=*this+other;
      return *this;
    }

    /*! -= operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix subtracted by other and modifies the calling object.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator-=(const MatrixBase<T>& other)
    {
      *this=*this-other;
      return *this;
    }

    /*! + operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix added with other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator+(const MatrixBase<T>& other) const = 0;

    /*! - operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix subtracted by other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator-(const MatrixBase<T>& other) const = 0;

    /*! Assignment operator.
     * \pre None.
     * \post Sets the calling object to the other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator=(const MatrixBase<T>& other) = 0;

    /*! Equality operator.
     * \pre None.
     * \post Returns true if 'other' is equivalent to the calling object.
     * \return Bool.
     */
    virtual bool operator==(const MatrixBase<T>& other) const
    {
      if(m_size!=other.m_size)
      {
        throw MyVectorSizeException();
      }
      for(int i=0;i<m_size;i++)
      {
        for(int j=0;j<m_size;j++)
        {
          if(other(i,j)!=operator()(i,j))
          {
            return false;
          }
        }
      }
      return true;
    }

    /*! Inequality operator.
     * \pre None.
     * \post Returns true if 'other' is not equivalent to the calling object.
     * \return Bool.
     */
    virtual bool operator!=(const MatrixBase<T>& other) const
    {
      return !(*this==other);
    }

    /*! Symmetry Checker.
     * \pre None.
     * \post Returns true if 'other' is the calling object is symmetrical.
     * \return Bool.
     */
    virtual bool isSymmetric() const = 0;

    /*! Identity Checker.
     * \pre None.
     * \post Returns true if the calling object is the identity.
     * \return Bool.
     */
    virtual bool isIdentity() const
    {
      for(int i=0;i<m_size;i++)
      {
        for(int j=0;j<m_size;j++)
        {
          if(i==j&&operator()(i,j)!=1)
            return false;
          if(i!=j&&operator()(i,j))
            return false;
        }
      }
      return true;
    }

    /*! Extraction operator.
     * \pre None.
     * \post Gets input from the stream and inserts it into a matrix.
     * \return istream object.
     */
    friend istream& operator>>(istream& in, MatrixBase<T>& matrix)
    {
      for(int i=0;i<matrix.getSize();i++)
      {
        for(int j=0;j<matrix.getSize();j++)
        {
          in>>matrix(i,j);
        }
      }
      return in;
    }

    /*! Insertion operator.
     * \pre None.
     * \post Prints out the matrix to the stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream& out, const MatrixBase<T>& matrix)
    {
      for(int i=0;i<matrix.getSize();i++)
      {
        for(int j=0;j<matrix.getSize();j++)
        {
          out<<fixed<<setprecision(DIGITS_OF_PRECISION)<<matrix(i,j)<<" ";
        }
        out<<"\n";
      }
      return out;
    }
};

#endif