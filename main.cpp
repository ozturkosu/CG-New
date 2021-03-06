# include <cmath>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <cmath>
# include <time.h>
# include <algorithm>
# include <cstring>


using namespace std;

# include "cg_lib.hpp"

int main (int argc, char** argv);
void r8ge_cg_start (int windowSize, int psize, double threshold, int fPos ,int range1, int range2 , int k);
void r8ge_cg_start_withResidual (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k);
void r8ge_cg_start_withImprovement (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k);
void r8ge_cg_start_withCheckSum (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;
void r8ge_cg_start_withAlphaDetection (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;
double r8ge_cg_start_withAlphaDetectionAndRelativeErrors(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;

void  r8ge_cg_start_withNewIndicator(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k , std::string matrixname) ;

double r8ge_cg_start_withNewIndicatorRelativeErrors(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k , std::string matrixname) ;

void r8ge_cr_start_withResidual(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) ;
double r8ge_cr_start_withEnergyNormRelativeErrors(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k ) ;


void r8ge_gcr_start_withResidual (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k, std::string matrixname);

double r8ge_gcr_start_withNewIndicatorRelativeErrors(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k , std::string matrixname) ;

void r8ge_gbcg_start_withResidual(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k, std::string matrixname);
void r8ge_bcg_start_withIndicator(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k , std::string matrixname);
void r8ge_bcr_start_withIndicator(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k , std::string matrixname);

int main (int argc, char** argv)
{
  if (argc != 8) {
    cout << "usage: ./main [windowSize] [problemSize] [flipPosition] [range1] [range2] [Bit Injecting Type]" << endl;
    return 0;
  }

  int windowSize = atoi(argv[1]); // size of window to monitor
  int psize = atoi(argv[2]);  // problem size
  int fPos = atoi(argv[3]);   // iteration to flip bits
  int range1=atoi(argv[4]);   //   Bit flip range start
  int range2=atoi(argv[5]) ;  // Bit flip range finish
  int k=atoi(argv[6]) ;  // K for injecting type 0 - 1- 2
  std::string matrixname=argv[7] ;
  // threshold by default set to 0.1, please modify as needed. 
  double threshold = 1e-1;
  
  //int& succesfulrate= Global::successfulRate ;

  // iteration to flip bits
  
  timestamp ( );
  cout << "\n";
  cout << "CG_PRB\n";
  cout << "  C++ version\n";
  cout << "  Test the CG library.\n";

  int succesfulrateForIndicator = Global::successfulRate ;
  Global::successfulRate = 0 ;


  cout << " \n";
  cout << "******************************** \n";
  cout << "******************************** \n";

  double sum=0;
  double averageRelativeError=0;
 
  for (int i = 0; i < 100; ++i)
  {
    
    cout << "Number of Experience = " << i << endl ;
    cout << "SuccessfulRate = " << Global::successfulRate << " % " <<endl ;
   

  
    r8ge_cg_start_withNewIndicator(windowSize, psize, threshold, fPos , range1 , range2 , k , matrixname) ;

    //sum = sum + r8ge_cg_start_withNewIndicatorRelativeErrors(windowSize, psize, threshold, fPos , range1 , range2 , k , matrixname) ;


    //sum = sum + r8ge_gcr_start_withNewIndicatorRelativeErrors(windowSize, psize, threshold, fPos , range1 , range2 , k , matrixname) ;


    //r8ge_gcr_start_withResidual ( windowSize, psize, threshold, fPos , range1 , range2 , k , matrixname);
    //r8ge_bcg_start_withIndicator( windowSize, psize, threshold, fPos , range1 , range2 , k , matrixname);
    //r8ge_bcr_start_withIndicator( windowSize, psize, threshold, fPos , range1 , range2 , k , matrixname);
  }

  //int succesfulrateForImprovement = Global::successfulRate ;
  //double unsuccesful = Global::undetectedNumber ;

  //averageRelativeError = sum / (100 - Global::successfulRate) ;
     
//
//  Terminate.
//
  cout << " \n";
  cout << "CG_PRB\n";
  cout << "  Normal end of execution.\n";
  //cout << "  successfulRate for fn indicator"<<succesfulrateForIndicator<<  endl;
  //cout << "  SuccessfulRate for fn with improvement "<< succesfulrateForImprovement <<endl ;
  //cout << "  Averae Relative Error "<<averageRelativeError<<endl ;

  cout << " Successful Rate = " << Global::successfulRate << " % " <<endl ; 
  cout << " False Positive Rate = "<<Global::falsePositive <<" % " <<endl ;
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


void r8ge_cr_start_withResidual(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k) 
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



double r8ge_cr_start_withEnergyNormRelativeErrors(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k ) 
{





}

void r8ge_cg_start_withNewIndicator (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k , std::string matrixname)
{

  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix Default Matirx.\n";


   n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();


  //a = pds_random ( n, seed ); // pds is returning random positive definite symmetric matrix


  //Read Matrix from file // Added Emin at March 6
  

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;

  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;



  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
  
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  }
  
  matrixfile.close() ;


  cout << " Matrix A is filled from file"<<endl ;
  


//
//  Choose a random solution.
//

  

  x1 = r8vec_uniform_01_new ( m, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( m, ni, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    x2[i] = 1.0;
  }
  init (m, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );


  r8ge_cg_Indicator_version2( m ,a , b , x2 , range1 , range2 , k) ; 

  cout << "\n";

  delete [] a;
  delete [] b;
  
  delete [] x1;
  delete [] x2;

  
  finish();
  return;

}


double  r8ge_cg_start_withNewIndicatorRelativeErrors(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k , std::string matrixname) 
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
  //a = pds_random ( n, seed );

  /*
   //Read Matrix from file // Added Emin at March 6
  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;

  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return 0;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;



  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
  
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  } 
  matrixfile.close() ;
  cout << " Matrix A is filled from file"<<endl ;
  */

  double **amat;
  amat = new double *[n];

  a = new double[n*n];

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;

  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
          cout<<"Error: file not found"<<endl;
                return 0;
  }
  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
              matrixfile >> amat[i][j];
                        //cout<<"a[i][j] = "<<a[i][j]<<endl ;
      }
  }

  matrixfile.close();

  cout << " Array A is ready "<<endl ;


  for (int i = 0; i < n; ++i)
  {
                  for (int j = 0; j < n; ++j)
                  {
                           a[i*n + j] =amat[i][j] ;
                  }
  }


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

  //r8ge_cg_Indicator_version2( m ,a , b , x2 , range1 , range2 , k) ; 

  bool isDetected=false;
  isDetected= r8ge_cg_Indicator_version2_RelativeError( n ,a , b , x2 , range1 , range2 , k) ;
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

  delete [] amat;


  finish();

  if(!isDetected )
    return finalResult;
  else
    return 0 ;

}




void r8ge_gcr_start_withResidual (int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k , std::string matrixname)
{

  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";


   n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();

  //a = pds_random ( n, seed ); // pds is returning random positive definite symmetric matrix


  //Read Matrix from file // Added Emin at March 6
  

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;




  //ifstream matrixfile("1138_bus.mtx");
  //ifstream matrixfile("bcsstk06.mtx");
  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;


  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
    /* code */
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  }
  
  matrixfile.close() ;


  cout << " Matrix A is filled from file"<<endl ;



//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( m, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( m, ni, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    x2[i] = 1.0;
  }
  init (m, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );


  //r8ge_cg_Indicator_version2( m ,a , b , x2 , range1 , range2 , k) ; 


  time_t currenttime1;
  time_t currenttime2;

  currenttime1 = time(NULL);

  r8ge_gcr_Residual( m ,a , b , x2 , range1 , range2 , k) ; 

  currenttime2 = time(NULL);

  cout << currenttime2 - currenttime1 << " seconds has passed" ;

  cout << "\n";

  delete [] a;
  delete [] b;
  
  delete [] x1;
  delete [] x2;

  
  finish();
  return;

}


void r8ge_bcg_start_withIndicator(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k , std::string matrixname)
{

  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";


   n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();

  //a = pds_random ( n, seed ); // pds is returning random positive definite symmetric matrix


  //Read Matrix from file // Added Emin at March 6
  

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;




  //ifstream matrixfile("1138_bus.mtx");
  //ifstream matrixfile("bcsstk06.mtx");
  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;


  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
    /* code */
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  }
  
  matrixfile.close() ;


  cout << " Matrix A is filled from file"<<endl ;



//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( m, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( m, ni, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    x2[i] = 1.0;
  }
  init (m, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );


  
  r8ge_bcg_emin( m ,a , b , x2 , range1 , range2 , k) ; 

  cout << "\n";

  delete [] a;
  delete [] b;
  
  delete [] x1;
  delete [] x2;

  
  finish();
  return;

}




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
  //delete [] r;
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

void r8ge_gbcg_start_withResidual(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k, std::string matrixname)
{

  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";


   n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();

  //a = pds_random ( n, seed ); // pds is returning random positive definite symmetric matrix


  //Read Matrix from file // Added Emin at March 6
  

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;




  //ifstream matrixfile("1138_bus.mtx");
  //ifstream matrixfile("bcsstk06.mtx");
  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;


  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
    /* code */
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  }
  
  matrixfile.close() ;


  cout << " Matrix A is filled from file"<<endl ;



//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( m, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( m, ni, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    x2[i] = 1.0;
  }
  init (m, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );


  r8ge_gcr_Residual( m ,a , b , x2 , range1 , range2 , k) ; 


  cout << "\n";

  delete [] a;
  delete [] b;
  
  delete [] x1;
  delete [] x2;

  
  finish();
  return;





}

void r8ge_bcr_start_withIndicator(int windowSize, int psize, double threshold, int fPos , int range1 , int range2 , int k , std::string matrixname)
{
  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";


   n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();

  //a = pds_random ( n, seed ); // pds is returning random positive definite symmetric matrix


  //Read Matrix from file // Added Emin at March 6
  

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;




  //ifstream matrixfile("1138_bus.mtx");
  //ifstream matrixfile("bcsstk06.mtx");
  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;


  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
    /* code */
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  }
  
  matrixfile.close() ;


  cout << " Matrix A is filled from file"<<endl ;



//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( m, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( m, ni, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    x2[i] = 1.0;
  }
  init (m, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );


  r8ge_bcr_emin( m ,a , b , x2 , range1 , range2 , k) ; 

  cout << "\n";

  delete [] a;
  delete [] b;
  
  delete [] x1;
  delete [] x2;

  
  finish();
  return;



}

double r8ge_gcr_start_withNewIndicatorRelativeErrors(int windowSize, int psize, double threshold,int fPos , int range1 , int range2 , int k , std::string matrixname) 
{

  double *a;
  double *b;
  double e_norm;
  int i;
  int n;
  
  int seed;
  double *x1;
  double *x2;

  int winSize = windowSize;
  double thres = threshold;
  int flipPosition = fPos;
  
  cout << "\n";
  cout << "R8GE_CG_TEST\n";
  cout << "  R8GE_CG applies CG to a full storage matrix.\n";


   n = psize;
//
//  Let A be the -1 2 -1 matrix.
//
  srand (time(NULL));
  seed = rand();

  //a = pds_random ( n, seed ); // pds is returning random positive definite symmetric matrix


  //Read Matrix from file // Added Emin at March 6
  

  char nameOfMatrix[matrixname.size() +1] ;
  strcpy(nameOfMatrix , matrixname.c_str()) ;




  //ifstream matrixfile("1138_bus.mtx");
  //ifstream matrixfile("bcsstk06.mtx");
  ifstream matrixfile(nameOfMatrix);
  if(!(matrixfile.is_open())){
      cout << "Error : file not found " <<endl;
      return 0;
  }
  int m,ni,l;
  while(matrixfile.peek()=='%') matrixfile.ignore(2048, '\n');
  matrixfile>>m>>ni>>l ;


  cout << " m = "<<m<<endl ;
  cout << " n = "<<ni<<endl ;
  cout << " l = "<<l<<endl ;

  a = new double[m*ni] ;
  std::fill(a , a + m * ni , 0.) ;

  double *I, *J;
  double *val ;

  I = new double[l] ;
  J = new double[l] ;
  val = new double[l] ;

  int xi , yi ;

  for (int i = 0; i < l; ++i)
  {
    /* code */
    matrixfile >> I[i] >> J[i] >> val[i] ;
    xi = I[i] -1 ;
    yi = J[i] -1 ;

    a[xi * m + yi] = val[i] ;

    //cout << " i = " << i << endl ;
    //cout << "a[x][y] "<< a[xi * m + yi] <<endl ;
    //cout << " I[i] = " <<I[i] <<" J[i] = " << J[i] << endl ;


  }
  
  matrixfile.close() ;


  cout << " Matrix A is filled from file"<<endl ;



//
//  Choose a random solution.
//
  x1 = r8vec_uniform_01_new ( m, seed );
//
//  Compute the corresponding right hand side.
//
  b = r8ge_mv ( m, ni, a, x1 );
//
//  Call the CG routine.
//
  x2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    x2[i] = 1.0;
  }
  init (m, winSize, thres, flipPosition);
  //r8ge_cg ( n, a, b, x2 );


  //r8ge_cg_Indicator_version2( m ,a , b , x2 , range1 , range2 , k) ; 
  //r8ge_gcr_Residual( m ,a , b , x2 , range1 , range2 , k) ; 


  bool isDetected=false;
  isDetected= r8ge_gcr_Residual_RelativeError( m ,a , b , x2 , range1 , range2 , k) ;
  //r8ge_cg_newAlphaImprovement_emin(n , a , b , x2 , range1 , range2 , k) ;



  double XesNorm2 ;
  XesNorm2= r8vec_norm(m , x2) ;

  e_norm = r8vec_norm_affine ( m, x1, x2 );

  double result;
  result = e_norm / XesNorm2 ;

  double finalResult;

  finalResult = log10(result) ;

  cout<<" Relative Error is "<<finalResult << endl ;


  cout << "\n";

  delete [] a;
  delete [] b;
  
  delete [] x1;
  delete [] x2;

  
  finish();

   if(!isDetected )
    return finalResult;
  else
    return 0 ;



  
}


