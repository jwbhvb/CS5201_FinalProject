//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: relativeerror.h

/*! \file
 *
 * A relative error library.
 */

#ifndef RELATIVEERROR_H
#define RELATIVEERROR_H

#include <cmath>
#include <iostream>
#include <vector>
#include "errorsizeexception.h"

using namespace std;

const double SMALL_VAL = .00000000000001;

template <class T>
class RelativeError
{
  private:
    vector<T> m_error;

  public:
    /*! Creates a RelativeError object with m_error filling up with the relative error between v1 and v2.
     * \pre v1 and v2 must be the same size, v2 must not have any element = 0, otherwise some calculation error will occur.
     * \post m_error is filled up.
     * \return None.
     */
    RelativeError(const vector<T>& v1, const vector<T>& v2);

    /*! Insertion operator.
     * \pre None.
     * \post Formats the RelativeError object when displayed in the output stream.
     * \return ostream object.
     */
    friend ostream& operator<<(ostream &out, const RelativeError& r)
    {
      for(unsigned int i=0;i<r.m_error.size();i++)
      {
        out<<"Relative Error Percent: "<<r.m_error[i]<<endl;
      }
      return out;
    }
};

#include "relativeerror.hpp"
#endif