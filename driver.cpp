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
#include "GaussSeidel.h"
#include "SteepestDescent.h"
#include "DirichletSolver.h"

//todo document
double func1(double x, double y);
typedef double(*funcPtr)(double,double);

using namespace std;

int main(int argc, char *argv[])
{
  try
  {
    if(argc!=2)
    {
      cerr<<"Please use the following command: '"<<argv[0]<<" int'"<<endl;
      exit(1);
    }
    int numDivisions=stoi(argv[1]);
    if(numDivisions<1)
    {
      cerr<<"Enter a number of divisions greater than 0."<<endl;
      exit(1);
    }
    MyFunction<double,funcPtr> boundaryFunc(&func1);
    DirichletSolver<double,funcPtr> solver(numDivisions,boundaryFunc);
    MyVector<double> solutionGaussSeidel = solver.computeGaussSeidel();

    for(int i=0;i<numDivisions-1;i++)
    {
      for(int j=0;j<numDivisions-1;j++)
      {
        cout<<fixed<<setprecision(DIGITS_OF_PRECISION)<<solutionGaussSeidel[numDivisions-1*i+j]<<" ";
      }
      cout<<"\n";
    }

    //MyVector<double> solutionSteepestDescent = solver.computeSteepestDescent();
  }
  catch(ErrorSizeException e)
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

double func1(double x, double y)
{
  return(y?0:1-4*(pow(x-.5,2)));
}