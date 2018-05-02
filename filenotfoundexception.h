//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: filenotfoundexception.h

/*! \file
 *
 * A file not found exception library.
 */

#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H 

#include <iostream>

using namespace std;

class FileNotFoundException
{
  private:
    string m_msg = "File not found.";
  public:

    /*! Insertion operator.
     * \pre None.
     * \post Formats the FileNotFoundException object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const FileNotFoundException& e)
    {
      return out<<e.m_msg;
    }
};

#endif