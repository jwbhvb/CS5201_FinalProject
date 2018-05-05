//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: truncatedfileexception.h

/*! \file
 *
 * A truncated file exception library.
 */

#ifndef TRUNCATEDFILEEXCEPTION_H
#define TRUNCATEDFILEEXCEPTION_H 

#include <iostream>

using namespace std;

class TruncatedFileException
{
  private:
    string m_msg = "File is truncated or formatted incorrectly.";
  public:

    /*! Insertion operator.
     * \pre None.
     * \post Formats the TruncatedFileException object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const TruncatedFileException& e)
    {
      return out<<e.m_msg;
    }
};

#endif