//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: relativeerror.hpp

#include "relativeerror.h"

using namespace std;

template <class T>
RelativeError<T>::RelativeError(const vector<T>& v1, const vector<T>& v2)
{
  try
  {
    if(v1.size()!=v2.size())
    {
      throw ErrorSizeException();
    }
    for(unsigned int i=0;i<v1.size();i++)
    {
      if(v2[i]==0)
      {
        m_error.push_back(100*abs((v2[i]-v1[i])/v2[i]+SMALL_VAL));
      }
      else
      {
        m_error.push_back(100*abs((v2[i]-v1[i])/v2[i]));
      }
    }
  }
  catch(ErrorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
}