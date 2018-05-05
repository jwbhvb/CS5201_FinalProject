//Programmer: John Bagsby, Ryan Leas
//Date: 5/5/18
//File: driver.cpp

/*! \file
 *
 * The purpose of this file is to solve a system of equations created by the DirichletSolver.
 */

#include "MyFunction.h"
#include "DenseMatrix.h"
#include "SymmetricMatrix.h"
#include "DirichletSolver.h"
#include <time.h>

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
    clock_t my_clock;
    clock_t my_clock2;
    MyFunction<double,funcPtr> boundaryFunc(&func1);
    DirichletSolver<double,funcPtr> solver(numDivisions,boundaryFunc);



    /*------------------------------Gauss Seidel------------------------------*/
    my_clock=clock();
    MyVector<double> solutionGaussSeidel = solver.computeGaussSeidel();
    my_clock=clock()-my_clock;
    cout<<"\nGauss-Seidel Solution:\n";
    for(int i=numDivisions-1;i>0;i--)
    {
      for(int j=0;j<numDivisions-1;j++)
      {
        cout<<fixed<<setprecision(DIGITS_OF_PRECISION)<<solutionGaussSeidel[(i-1)*(numDivisions-1)+j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\nNumber of Iterations: "<<solver.getGaussSeidelSolver().getCount();
    cout<<"\nTime took: "<<(1000*my_clock)/CLOCKS_PER_SEC<<" ms."<<endl;
    /*----------------------------End Gauss Seidel----------------------------*/



    /*----------------------------Steepest Descent----------------------------*/
    cout<<"\nSteepest Descent Solution:\n";
    my_clock2=clock();
    MyVector<double> solutionSteepestDescent = solver.computeSteepestDescent();
    my_clock2=clock()-my_clock2;
    for(int i=numDivisions-1;i>0;i--)
    {
      for(int j=0;j<numDivisions-1;j++)
      {
        cout<<fixed<<setprecision(DIGITS_OF_PRECISION)<<solutionSteepestDescent[(i-1)*(numDivisions-1)+j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\nNumber of Iterations: "<<solver.getSteepestDescentSolver().getCount();
    cout<<"\nTime took: "<<(1000*my_clock2)/CLOCKS_PER_SEC<<" ms."<<endl;
    /*--------------------------End Steepest Descent--------------------------*/



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