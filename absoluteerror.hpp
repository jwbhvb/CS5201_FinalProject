//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: absoluteerror.hpp

#include "absoluteerror.h"

using namespace std;

template <class T>
AbsoluteError<T>::AbsoluteError(const vector<T>& v1, const vector<T>& v2)
{
  try
  {
    if(v1.size()!=v2.size())
    {
      throw ErrorSizeException();
    }
    for(unsigned int i=0;i<v1.size();i++)
    {
      m_error.push_back(abs(v1[i]-v2[i]));
    }
  }
  catch(ErrorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
}