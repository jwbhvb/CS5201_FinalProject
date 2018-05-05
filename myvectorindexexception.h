//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: myvectorindexexception.h

/*! \file
 *
 * A MyVector index exception library.
 */

#ifndef MYVECTORINDEXEXCEPTION_H
#define MYVECTORINDEXEXCEPTION_H 

#include <iostream>

using namespace std;

class MyVectorIndexException
{
  private:
    string m_msg = "Index Error when indexing a MyVector object.";
  public:

    /*! Insertion operator.
     * \pre None.
     * \post Formats the MyVectorIndexException object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const MyVectorIndexException& e)
    {
      return out<<e.m_msg;
    }
};

#endif