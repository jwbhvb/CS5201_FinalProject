//Programmer: John Bagsby, Ryan Leas
//Date: 4/29/18
//File: driver.cpp

/*! \file
 *
 * todo.
 */

#include "MyFunction.h"
#include "DenseMatrix.h"
#include "SymmetricMatrix.h"
#include "AbsoluteError.h"
#include "RelativeError.h"
#include "FileNotFoundException.h"
#include "GaussSeidel.h"
#include "SteepestDescent.h"
#include "DirichletSolver.h"


//todo document
double func1(const double& x, const double& y);

using namespace std;

int main(int argc, char *argv[])
{
  try
  {
    if(argc!=2)
    {
      cerr<<"Please use the following command: '"<<argv[0]<<" filename'"<<endl;
      exit(1);  
    }
    ifstream inFile(argv[1]);
    if(!inFile.is_open())
    {
      throw FileNotFoundException();
    }
    //todo
    double (*funcPtr)(double) = func1;
    //cout<<DirichletSolver<double,>()(A,b);
  }
  catch(ErrorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  catch(FileNotFoundException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  catch(MyVectorIndexException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  catch(MyVectorSizeException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  catch(TruncatedFileException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  catch(SolutionUndefinedException e)
  {
    cerr<<e<<endl;
    exit(1);
  }
  catch(...)
  {
    cerr<<"Default Exception"<<endl;
    exit(1);
  }
  return 0;
}

double func1(const double& x, const double& y)
{
  return(y?0:1-4*(pow(x-.5,2)));
}