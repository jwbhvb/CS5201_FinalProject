//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: myvectorsizeexception.h

/*! \file
 *
 * A MyVector size exception library.
 */

#ifndef MYVECTORSIZEEXCEPTION_H
#define MYVECTORSIZEEXCEPTION_H 

#include <iostream>

using namespace std;

class MyVectorSizeException
{
  private:
    string m_msg = "Size Error when creating/resizing a MyVector object.";
  public:

    /*! Insertion operator.
     * \pre None.
     * \post Formats the MyVectorSizeException object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const MyVectorSizeException& e)
    {
      return out<<e.m_msg;
    }
};

#endif