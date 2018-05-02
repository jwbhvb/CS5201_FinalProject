//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: solutionundefinedexception.h

/*! \file
 *
 * A solution undefined exception library.
 */

#ifndef SOLUTIONUNDEFINEDEXCEPTION_H
#define SOLUTIONUNDEFINEDEXCEPTION_H 

#include <iostream>

using namespace std;

class SolutionUndefinedException
{
  private:
    string m_msg = "Solution Undefined.";
  public:

    /*! Insertion operator.
     * \pre None.
     * \post Formats the SolutionUndefinedException object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const SolutionUndefinedException& e)
    {
      return out<<e.m_msg;
    }
};

#endif