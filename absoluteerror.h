//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: absoluteerror.h

/*! \file
 *
 * An absolute error library.
 */

#ifndef ABSOLUTEERROR_H
#define ABSOLUTEERROR_H

#include <cmath>
#include <iostream>
#include <vector>
#include "errorsizeexception.h"

using namespace std;

template <class T>
class AbsoluteError
{
  private:
    vector<T> m_error;

  public:
    /*! Constructor.
     * \pre v1 and v2 must have the same size.
     * \post m_error is filled with absolute error values.
     * \return None.
     */
    AbsoluteError(const vector<T>& v1, const vector<T>& v2);

    /*! Insertion operator.
     * \pre None.
     * \post Formats the AbsoluteError object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const AbsoluteError& a)
    {
      for(unsigned int i=0;i<a.m_error.size();i++)
      {
        out<<"Absolute Error: "<<a.m_error[i]<<endl;
      }
      return out;
    }
};

#include "absoluteerror.hpp"
#endif