# include <queue>
#include <string>
using namespace std;

int i4_min ( int i1, int i2 );
double *orth_random ( int n, int &seed );
double *pds_random ( int n, int &seed );
double r8_normal_01 ( int &seed );
double r8_sign ( double x );
double r8_uniform_01 ( int &seed );

void r83_cg ( int n, double a[], double b[], double x[] );
double *r83_dif2 ( int m, int n );
double *r83_mv ( int m, int n, double a[], double x[] );
double *r83_res ( int m, int n, double a[], double x[], double b[] );

void r83s_cg ( int n, double a[], double b[], double x[] );
double *r83s_dif2 ( int m, int n );
double *r83s_mv ( int m, int n, double a[], double x[] );
double *r83s_res ( int m, int n, double a[], double x[], double b[] );

void r83t_cg ( int n, double a[], double b[], double x[] );
double *r83t_dif2 ( int m, int n );
double *r83t_mv ( int m, int n, double a[], double x[] );
double *r83t_res ( int m, int n, double a[], double x[], double b[] );

void r8ge_cg ( int n, double a[], double b[], double x[] );
double *r8ge_dif2 ( int m, int n );
double *r8ge_mv ( int m, int n, double a[], double x[] );
double *r8ge_mv_TransposeA ( int m, int n, double a[], double x[] ) ;
double *r8ge_res ( int m, int n, double a[], double x[], double b[] );

void r8mat_copy ( int m, int n, double a1[], double a2[] );
void r8mat_house_axh ( int n, double a[], double v[] );
double *r8mat_identity_new ( int n );
void r8mat_print ( int m, int n, double a[], string title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title );
double *r8mat_zero_new ( int m, int n );

void r8pbu_cg ( int n, int mu, double a[], double b[], double x[] );
double *r8pbu_dif2 ( int m, int n, int mu );
double *r8pbu_mv ( int m, int n, int mu, double a[], double x[] );
double *r8pbu_res ( int m, int n, int mu, double a[], double x[], double b[] );

void r8sd_cg ( int n, int ndiag, int offset[], double a[], double b[], 
  double x[] );
double *r8sd_dif2 ( int m, int n, int ndiag, int offset[] );
double *r8sd_mv ( int m, int n, int ndiag, int offset[], double a[], double x[] );
double *r8sd_res ( int m, int n, int ndiag, int offset[], double a[], 
  double x[], double b[] );

void r8sp_cg ( int n, int nz_num, int row[], int col[], double a[], 
  double b[], double x[] );
double *r8sp_dif2 ( int m, int n, int nz_num, int row[], int col[] );
double *r8sp_mv ( int m, int n, int nz_num, int row[], int col[], 
  double a[], double x[] );
double *r8sp_res ( int m, int n, int nz_num, int row[], int col[], double a[], 
  double x[], double b[] );

void r8vec_copy ( int n, double a1[], double a2[] );
double r8vec_dot_product ( int n, double a1[], double a2[] );
double *r8vec_house_column ( int n, double a[], int k );
double r8vec_norm ( int n, double a[] );
double r8vec_norm_affine ( int n, double a[], double b[] );
void r8vec_print ( int n, double a[], string title );
double *r8vec_uniform_01_new ( int n, int &seed );
double *r8vec_zero_new ( int n );

void timestamp ( );

///////

bool improveMethodFOrCheckSUm ( int n, double a[] ,  double x[] , double b[] , double curFunction);
//New Function which was added by Emin
void r8ge_cg_emin ( int n, double a[], double b[], double x[] , int range1 , int range2 , int k) ;//, double r[]);
void r8ge_cg_newIndicatior_emin(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k) ; //, double r[]) ;
void r8ge_cg_newImprovement_emin(int n , double a[] , double b[] , double x[] ,int range1, int range2 , int k ) ;
void r8ge_cg_checkSum_emin(int n , double a[] , double b[] , double x[] , int range1, int range2, int k )  ;
void r8ge_cg_newAlphaImprovement_emin(int n , double a[] ,double b[] , double x2[] , int range1 ,int  range2 ,int k) ;
bool r8ge_cg_newAlphaImprovement_eminForRelativeError(int n , double a[] ,double b[] , double x[] , int range1 ,int  range2 ,int k) ;
bool r8ge_cg_Indicator_version2_RelativeError(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k)  ;
void r8ge_cg_checkSum_emin2(int n ,  double a[] , double  b[] , double  x2[] , int  range1, int  range2, int k ) ;
void r8ge_cg_Indicator_version2(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k)  ;
void r8ge_bcg_emin(int n, double a[], double b[], double x[] , int range1 , int range2 , int k ) ;
void r8ge_bcr_emin(int n, double a[], double b[], double x[] , int range1 , int range2 , int k ) ;
void r8ge_gcr_Residual(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k);
bool r8ge_gcr_Residual_RelativeError(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k);

void getCurIndicatorValue( double x[], double r[] , double b[]) ;
void initialCheckSum(int n , double r[] , double p[] , double x[]);
bool checkSumMethod(int n , double r[] , double p[] , double x[]) ;
bool checkSumImpMethod( int n , double a[] ,double x[] , double b[]) ;

//*********************



double getResidual ( int m, int n, double a[], double x[], double b[] );
double getFunctionIndicatorCunverge ( int n, double x[] , double b[] ) ;
void injectBitflip ( int n, double a[], double x[], double b[] );
void injectBitFlipNotRandom(int n , double r[] , double p[] , double x[] , int range1 , int range2 , int k ) ;
void injectBitFlipNotRandom2( int n , double r[] , double p[] , double x[] , double r_prime[] , double p_prime[] , double t[], int range1 , int range2 , int k );
void init ( int iter, int winSize, double thres, int flipPosition);
void finish ();
bool isFlipped ( double curRes );
bool isFlippedIndicator (double curRes) ;
bool isDetected( double curFunction ) ;//, queue<double> & detector) ;
void recordResidual ( double curRes );
void recordIndicator(double curFunction) ;
void getIndicator( double curFunction ) ;//, queue<double> & detector) ;
bool improveMethodWithAlpha(double curFunct, double alpha);
bool improveMethod(double curFunct) ;


#ifndef GLOBAL
#define GLOBAL
class Global {
 public:
  static int MAX_ITER;
  static int windowSize;
  static queue<double> window;
  static queue<double> windowForIndicator;
  static double threshold;
  static int pos;
  static int successfulRate;
  static int undetectedNumber;
  static int falsePositive;
  static int ImproveRate ;
  static int CheckSumImproveRate ;
  static double gTrend;
  static double funGTrend;
  static double convergeValue;
  static double previousValueOfIndicator ;
  static double globalTotalDifference ;
  static double checkSumForX;
  static double checkSumForP;
  static double checkSumForR;

  static queue<double> diffs;
  static queue<double> diffsImprove ;
  static queue<double> trend;
  static queue<double> funcIndicatorTrend;
  static queue<double> funcIndicatorDiffs;
  static queue<double> eminDetector;
};



/* 
// in case of the compiler error - undefined references, please uncomment this
int Global::MAX_ITER = 0;
int Global::windowSize = 0;
int Global::successfulRate=0;
int Global::undetectedNumber=0;
int Global::falsePositive=0;
int Global::ImproveRate = 0;
int Global::CheckSumImproveRate = 0;
queue<double> Global::window;
queue<double> Global::windowForIndicator;
double Global::threshold = 0;
int Global::pos = 0;
double Global::gTrend = 0;
double Global::funGTrend=0;
double Global::convergeValue=0;
double Global::previousValueOfIndicator = 0;
double Global::globalTotalDifference =0 ;
double Global::checkSumForX = 0 ;
double Global::checkSumForP = 0 ;
double Global::checkSumForR = 0 ;

queue<double> Global::diffs;
queue<double> Global::diffsImprove;
queue<double> Global::trend;
queue<double> Global::funcIndicatorTrend;
queue<double> Global::funcIndicatorDiffs;
queue<double> Global::eminDetector;





/*
int Global::MAX_ITER = 0;
int Global::windowSize = 0;
queue<double> Global::window;
double Global::threshold = 0;
int Global::pos = 0;
double Global::gTrend = 0;
queue<double> Global::diffs;
queue<double> Global::trend;
*/
#endif

