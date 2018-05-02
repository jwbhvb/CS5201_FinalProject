//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: densematrix.h

/*! \file
 *
 * A Dense Matrix Library.
 */

#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H 

#include "matrixbase.h"

using namespace std;

template <class T>
class DenseMatrix: public MatrixBase<T>
{
  private:
    MyVector<MyVector<T>> m_data;
  public:
     /*! Size getter.
     * \pre None.
     * \post Returns the size of the matrix.
     * \return Int.
     */
    virtual int getSize() const {return this->m_size;}

    /*! + operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix added with other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator+(const MatrixBase<T>& other) const;

    /*! - operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix subtracted by other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator-(const MatrixBase<T>& other) const;

    /*! Assignment operator.
     * \pre None.
     * \post Sets the calling object to the other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator=(const MatrixBase<T>& other);

    /*! Accesses the element at the location i,j.
     * \pre i and j must be between 0 and m_size-1.
     * \post Returns the element of the matrix at that location.
     * \return T.
     */
    virtual T& operator()(const int &i, const int &j);

    /*! Accesses the element at the location i,j.
     * \pre i and j must be between 0 and m_size-1.
     * \post Returns the element of the matrix at that location.
     * \return T.
     */
    virtual const T& operator()(const int& i, const int& j) const;

    /*! Row getter.
     * \pre 'row' must be between 0 and m_size-1.
     * \post Returns the row of the matrix at that location.
     * \return MyVector<T>.
     */
    virtual MyVector<T>& operator[](const int& row);

    /*! Row getter.
     * \pre 'row' must be between 0 and m_size-1.
     * \post Returns the row of the matrix at that location.
     * \return MyVector<T>.
     */
    virtual const MyVector<T>& operator[](const int& row) const;

    /*! * operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix multiplied by other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator*(const MatrixBase<T>& other) const;

    /*! * operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix multiplied by other.
     * \return MatrixBase<T>.
     */
    virtual MatrixBase<T>& operator*(const T& val) const;

    /*! Computes the transpose of a matrix.
     * \pre None.
     * \post Returns the transpose of the matrix.
     * \return MatrixBase<T>.
     */
    virtual const MatrixBase<T>& transpose() const;

    /*! Checks if the matrix is diagonally dominant.
     * \pre None.
     * \post Returns true if the matrix is digonally dominant.
     * \return Bool.
     */
    virtual bool isDiagonallyDominant() const;

    /*! * operator.
     * \pre m_size must be the same as other's size.
     * \post Returns the output of the matrix multiplied by other.
     * \return MyVector<T>.
     */
    virtual MyVector<T>& operator*(const MyVector<T>& other) const;

    /*! Symmetry Checker.
     * \pre None.
     * \post Returns true if 'other' is the calling object is symmetrical.
     * \return Bool.
     */
    virtual bool isSymmetric() const;

    /*! Constructor.
     * \pre None.
     * \post Creates a DenseMatrix object with a size of 0.
     * \return None.
     */
    DenseMatrix();

    /*! Constructor.
     * \pre None.
     * \post Creates a DenseMatrix object with a size of 'size'.
     * \return None.
     */
    DenseMatrix(const int& size);

    /*! Copy Constructor.
     * \pre None.
     * \post Creates a copy of other.
     * \return None.
     */
    DenseMatrix(const DenseMatrix<T>& other);
};

#include "densematrix.hpp"
#endif