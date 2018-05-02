//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: errorsizeexception.h

/*! \file
 *
 * A Error Size Exception library.
 */

#ifndef ERRORSIZEEXCEPTION_H
#define ERRORSIZEEXCEPTION_H 

#include <iostream>

using namespace std;

class ErrorSizeException
{
  private:
    string m_msg = "Vectors must be the same size to calculate the error between them.";
  public:

    /*! Insertion operator.
     * \pre None.
     * \post Formats the ErrorSizeException object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const ErrorSizeException& e)
    {
      return out<<e.m_msg;
    }
};

#endif