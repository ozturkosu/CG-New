# include <cmath>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>
# include <time.h>
# include "omp.h"

using namespace std;

# include "cg_lib.hpp"

int main (int argc, char** argv);
void r8ge_cg_start (int windowSize, int psize, double threshold, int fPos ,int range1, int range2 , int k);
void r8ge_cg_start_withResidual (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k);
void r8ge_cg_start_withImprovement (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k);
void r8ge_cg_start_withCheckSum (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;
void r8ge_cg_start_withAlphaDetection (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;
double r8ge_cg_start_withAlphaDetectionAndRelativeErrors(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;


int main (int argc, char** argv)
{
  if (argc != 7) {
    cout << "usage: ./main [windowSize] [problemSize] [flipPosition] [range1] [range2] [Bit Injecting Type]" << endl;
    return 0;
  }

  int windowSize = atoi(argv[1]); // size of window to monitor
  int psize = atoi(argv[2]);  // problem size
  int fPos = atoi(argv[3]);   // iteration to flip bits
  int range1=atoi(argv[4]);   //   Bit flip range start
  int range2=atoi(argv[5]) ;  // Bit flip range finish
  int k=atoi(argv[6]) ;  // K for injecting type
  // threshold by default set to 0.1, please modify as needed. 
  double threshold = 1e-1;
  
  //int& succesfulrate= Global::successfulRate ;

  // iteration to flip bits
  
  timestamp ( );
  cout << "\n";
  cout << "CG_PRB\n";
  cout << "  C++ version\n";
  cout << "  Test the CG library.\n";


  //queue<double>& detector = Global::eminDetector;

  //This part of only fn 

  /*

  for (int i = 0; i < 100; ++i)
  {
   
    Global::previousValueOfIndicator =0 ;

    cout << " Number of Iteration = " << i << endl ;

    r8ge_cg_start (windowSize, psize, threshold, fPos , range1 , range2 , k );

    cout << "  successfulRate = " << Global::successfulRate << " % " <<endl ;

    //detector.pop() ;
    //detector.pop() ;
  }

  */

  int succesfulrateForIndicator = Global::successfulRate ;
  Global::successfulRate = 0 ;

  /*
  for (int i = 0; i < 100; ++i)
  {
   
    Global::previousValueOfIndicator =0 ;

    cout << " Number of Iteration = " << i << endl ;

    r8ge_cg_start_withResidual (windowSize, psize, threshold, fPos , range1 , range2 , k );

    cout << "  successfulRate = " << Global::successfulRate << " % " <<endl ;

    //detector.pop() ;
    //detector.pop() ;
  }

  int succesfulrateForResidual = Global::successfulRate ;
  
  */


  // Fn with improvement method 

  


  cout << " \n";
  cout << "******************************** \n";
  cout << "******************************** \n";
  cout << "******For improvement ********** \n";

  queue<double>& diffsImp = Global::diffsImprove;


  double& totalDifference =  Global::globalTotalDifference;
  double& prevValueOfIndicator = Global::previousValueOfIndicator;
  //int& ImpRate= Global::ImproveRate ;

  double averageRelativeError = 0 ;

  double res =0;

  for (int i = 0; i < 100; ++i)
  {
    
    prevValueOfIndicator=0 ;
    totalDifference=0 ;
    //ImpRate=0;
   

    cout << "Number of Experience = " << i << endl ;

    //r8ge_cg_start_withImprovement(windowSize, psize, threshold, fPos , range1 , range2 , k );
    //r8ge_cg_start_withAlphaDetection(windowSize, psize, threshold, fPos , range1 , range2 , k );

    //res = r8ge_cg_start_withAlphaDetectionAndRelativeErrors(windowSize, psize, threshold, fPos , range1 , range2 , k ) ;

    //cout<<" Res = "<<res<<endl ;
    //averageRelativeError = averageRelativeError + res ;




    //cout << "SuccessfulRate = " << Global::successfulRate << " % " <<endl ;
    //cout << "SuccessfulRate for improve = " << Global::ImproveRate << " % " <<endl ;

    r8ge_cg_Indicator_version2(windowSize, psize, threshold, fPos , range1 , range2 , k ) ;

    
    /*    

    while (!diffsImp.empty())
    {
     //sum += myqueue.front();
        diffsImp.pop();
    }

    */

  }

  //int succesfulrateForImprovement = Global::successfulRate ;
  //double unsuccesful = Global::undetectedNumber ;

  //averageRelativeError = averageRelativeError / unsuccesful ;


    
//
//  Terminate.
//
  cout << " \n";
  cout << "CG_PRB\n";
  cout << "  Normal end of execution.\n";
  //cout << "  successfulRate for fn indicator"<<succesfulrateForIndicator<<  endl;
  cout << "  SuccessfulRate for fn with improvement "<< succesfulrateForImprovement <<endl ;
  cout << "  Averae Relative Error "<<averageRelativeError<<endl ;
  cout << " \n";


  
  timestamp ( );

  return 0;




}



//****************************************************************************80

void r8ge_cg_start (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k)


{
  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  double *r;
  double r_norm;
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";

  //cout << " Number of "



  n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();
  a = pds_random ( n, seed );
//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( n, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( n, n, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x2[i] = 1.0;
  }
  init (n, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );

  //r8ge_cg_emin( n ,a , b , x2) ; 
  r8ge_cg_newIndicatior_emin(n , a , b , x2 , range1 , range2 , k) ;


//
//  Compute the residual.  //Emin Note = calculation residual again is non necessary because cg calculate residual as well 
//
  //r = r8ge_res ( n, n, a, x2, b );
  //r_norm = r8vec_norm ( n, r );
//
//  Compute the error.
//
  //e_norm = r8vec_norm_affine ( n, x1, x2 );
//
//  Report.
//
  cout << "\n";
  //cout << "  Number of variables N = " << n << "\n";
  //cout << "  Norm of residual ||Ax-b|| = " << r_norm << "\n";
  //cout << "  Norm of error ||x1-x2|| = " << e_norm << "\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
  delete [] r;
  delete [] x1;
  delete [] x2;

  
  finish();
  return;
}
//****************************************************************************80

void r8ge_cg_start_withResidual (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k)


{
  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  double *r;
  double r_norm;
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";

  //cout << " Number of "



  n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();
  a = pds_random ( n, seed );
//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( n, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( n, n, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x2[i] = 1.0;
  }
  init (n, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );

  r8ge_cg_emin( n ,a , b , x2 , range1 , range2 , k) ; 
  //r8ge_cg_newIndicatior_emin(n , a , b , x2 , range1 , range2 , k) ;


//
//  Compute the residual.  //Emin Note = calculation residual again is non necessary because cg calculate residual as well 
//
  //r = r8ge_res ( n, n, a, x2, b );
  //r_norm = r8vec_norm ( n, r );
//
//  Compute the error.
//
  //e_norm = r8vec_norm_affine ( n, x1, x2 );
//
//  Report.
//
  cout << "\n";
  //cout << "  Number of variables N = " << n << "\n";
  //cout << "  Norm of residual ||Ax-b|| = " << r_norm << "\n";
  //cout << "  Norm of error ||x1-x2|| = " << e_norm << "\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
  delete [] r;
  delete [] x1;
  delete [] x2;

  
  finish();
  return;
}
//****************************************************************************80

void r8ge_cg_start_withImprovement (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k)
{

  double *a;
  double *b;

  double e_norm;
  int i;
  int n;
  double *r;

  double r_norm;
  int seed;

  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";

  //cout << " Number of "



  n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();
  a = pds_random ( n, seed );
//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( n, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( n, n, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x2[i] = 1.0;
  }
  init (n, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );

  //r8ge_cg_emin( n ,a , b , x2 , range1 , range2 , k) ; 
  //r8ge_cg_newIndicatior_emin(n , a , b , x2 , range1 , range2 , k) ;
  r8ge_cg_newImprovement_emin(n , a , b , x2 , range1 , range2 , k) ;

//
//  Compute the residual.  //Emin Note = calculation residual again is non necessary because cg calculate residual as well 
//
  //r = r8ge_res ( n, n, a, x2, b );
  //r_norm = r8vec_norm ( n, r );
//
//  Compute the error.
//
  //e_norm = r8vec_norm_affine ( n, x1, x2 );
//
//  Report.
//
  cout << "\n";
  //cout << "  Number of variables N = " << n << "\n";
  //cout << "  Norm of residual ||Ax-b|| = " << r_norm << "\n";
  //cout << "  Norm of error ||x1-x2|| = " << e_norm << "\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
  delete [] r;
  delete [] x1;
  delete [] x2;

  
  finish();
  return;


}


void r8ge_cg_start_withCheckSum (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k)
{

  double *a;
  double *b;

  double e_norm;
  int i;
  int n;
  double *r;

  double r_norm;
  int seed;

  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";

  //cout << " Number of "



  n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();
  a = pds_random ( n, seed );
//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( n, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( n, n, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x2[i] = 1.0;
  }
  init (n, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );

  //r8ge_cg_emin( n ,a , b , x2 , range1 , range2 , k) ; 
  //r8ge_cg_newIndicatior_emin(n , a , b , x2 , range1 , range2 , k) ;
  //r8ge_cg_newImprovement_emin(n , a , b , x2 , range1 , range2 , k) ;

  //r8ge_cg_checkSum_emin( n ,  a ,  b ,  x2 ,  range1,  range2, k ) ;
  r8ge_cg_checkSum_emin2( n ,  a ,  b ,  x2 ,  range1,  range2, k ) ;


//
//  Compute the residual.  //Emin Note = calculation residual again is non necessary because cg calculate residual as well 
//
  //r = r8ge_res ( n, n, a, x2, b );
  //r_norm = r8vec_norm ( n, r );
//
//  Compute the error.
//
  //e_norm = r8vec_norm_affine ( n, x1, x2 );
//
//  Report.
//
  cout << "\n";
  //cout << "  Number of variables N = " << n << "\n";
  //cout << "  Norm of residual ||Ax-b|| = " << r_norm << "\n";
  //cout << "  Norm of error ||x1-x2|| = " << e_norm << "\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
  delete [] r;
  delete [] x1;
  delete [] x2;

  
  finish();
  return;




}

void r8ge_cg_start_withAlphaDetection (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) 
{

  double *a;
  double *b;

  double e_norm;
  int i;
  int n;
  double *r;

  double r_norm;
  int seed;

  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";

  //cout << " Number of "



  n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();
  a = pds_random ( n, seed );
//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( n, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( n, n, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x2[i] = 1.0;
  }
  init (n, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );

  //r8ge_cg_emin( n ,a , b , x2 , range1 , range2 , k) ; 
  //r8ge_cg_newIndicatior_emin(n , a , b , x2 , range1 , range2 , k) ;
  r8ge_cg_newAlphaImprovement_emin(n , a , b , x2 , range1 , range2 , k) ;

//
//  Compute the residual.  //Emin Note = calculation residual again is non necessary because cg calculate residual as well 
//
  //r = r8ge_res ( n, n, a, x2, b );
  //r_norm = r8vec_norm ( n, r );
//
//  Compute the error.
//
  //e_norm = r8vec_norm_affine ( n, x1, x2 );
//
//  Report.
//
  cout << "\n";
  //cout << "  Number of variables N = " << n << "\n";
  //cout << "  Norm of residual ||Ax-b|| = " << r_norm << "\n";
  //cout << "  Norm of error ||x1-x2|| = " << e_norm << "\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
  delete [] r;
  delete [] x1;
  delete [] x2;

  
  finish();
  return;


}

double r8ge_cg_start_withAlphaDetectionAndRelativeErrors(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) 
{

  double *a;
  double *b;

  double e_norm;
  int i;
  int n;
  //double *r;

 // double r_norm;
  int seed;

  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";

  //cout << " Number of "



  n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();
  a = pds_random ( n, seed );
//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( n, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( n, n, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x2[i] = 1.0;
  }
  init (n, winSize, thres, flipPosition);

  //r8ge_cg ( n, a, b, x2 );

  //r8ge_cg_emin( n ,a , b , x2 , range1 , range2 , k) ; 
  //r8ge_cg_newIndicatior_emin(n , a , b , x2 , range1 , range2 , k) ;

  bool isDetected;
  isDetected=r8ge_cg_newAlphaImprovement_eminForRelativeError( n ,  a , b ,  x2 ,  range1 ,  range2 ,k) ;

  //r8ge_cg_newAlphaImprovement_emin(n , a , b , x2 , range1 , range2 , k) ;


  double XesNorm2 ;
  XesNorm2= r8vec_norm(n , x2) ;

  e_norm = r8vec_norm_affine ( n, x1, x2 );

  double result;
  result = e_norm / XesNorm2 ;

  double finalResult;

  finalResult = log10(result) ;

  cout<<" Relative Error is "<<finalResult << endl ;





//
//  Compute the error.
//
  //e_norm = r8vec_norm_affine ( n, x1, x2 );
//
//  Report.
//
  cout << "\n";
  //cout << "  Number of variables N = " << n << "\n";
  //cout << "  Norm of residual ||Ax-b|| = " << r_norm << "\n";
  //cout << "  Norm of error ||x1-x2|| = " << e_norm << "\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
  //delete [] r;
  delete [] x1;
  delete [] x2;

  
  finish();

  if(!isDetected )
    return finalResult;
  else
    return 0 ;

}


