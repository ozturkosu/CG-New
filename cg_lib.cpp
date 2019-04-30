# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>
using namespace std;

# include "cg_lib.hpp"
# include "bitflip.h"


//****************************************************************************80

int i4_min ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MIN returns the minimum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MIN, the smaller of I1 and I2.
//
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80


double *orth_random ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    ORTH_RANDOM returns the ORTH_RANDOM matrix.
//
//  Discussion:
//
//    The matrix is a random orthogonal matrix.
//
//  Properties:
//
//    The inverse of A is equal to A'.
//    A is orthogonal: A * A' = A' * A = I.
//    Because A is orthogonal, it is normal: A' * A = A * A'.
//    Columns and rows of A have unit Euclidean norm.
//    Distinct pairs of columns of A are orthogonal.
//    Distinct pairs of rows of A are orthogonal.
//    The L2 vector norm of A*x = the L2 vector norm of x for any vector x.
//    The L2 matrix norm of A*B = the L2 matrix norm of B for any matrix B.
//    det ( A ) = +1 or -1.
//    A is unimodular.
//    All the eigenvalues of A have modulus 1.
//    All singular values of A are 1.
//    All entries of A are between -1 and 1.
//
//  Discussion:
//
//    Thanks to Eugene Petrov, B I Stepanov Institute of Physics,
//    National Academy of Sciences of Belarus, for convincingly
//    pointing out the severe deficiencies of an earlier version of
//    this routine.
//
//    Essentially, the computation involves saving the Q factor of the
//    QR factorization of a matrix whose entries are normally distributed.
//    However, it is only necessary to generate this matrix a column at
//    a time, since it can be shown that when it comes time to annihilate
//    the subdiagonal elements of column K, these (transformed) elements of
//    column K are still normally distributed random values.  Hence, there
//    is no need to generate them at the beginning of the process and
//    transform them K-1 times.
//
//    For computational efficiency, the individual Householder transformations
//    could be saved, as recommended in the reference, instead of being
//    accumulated into an explicit matrix format.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Pete Stewart,
//    Efficient Generation of Random Orthogonal Matrices With an Application
//    to Condition Estimators,
//    SIAM Journal on Numerical Analysis,
//    Volume 17, Number 3, June 1980, pages 403-409.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input/output, int &SEED, a seed for the random number
//    generator.
//
//    Output, double ORTH_RANDOM[N*N] the matrix.
//
{
  double *a;
  int i;
  int j;
  double *v;
  double *x;
//
//  Start with A = the identity matrix.
//
  a = r8mat_zero_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = 1.0;
  }
//
//  Now behave as though we were computing the QR factorization of
//  some other random matrix.  Generate the N elements of the first column,
//  compute the Householder matrix H1 that annihilates the subdiagonal elements,
//  and set A := A * H1' = A * H.
//
//  On the second step, generate the lower N-1 elements of the second column,
//  compute the Householder matrix H2 that annihilates them,
//  and set A := A * H2' = A * H2 = H1 * H2.
//
//  On the N-1 step, generate the lower 2 elements of column N-1,
//  compute the Householder matrix HN-1 that annihilates them, and
//  and set A := A * H(N-1)' = A * H(N-1) = H1 * H2 * ... * H(N-1).
//  This is our random orthogonal matrix.
//
  x = new double[n];

  for ( j = 0; j < n - 1; j++ )
  {
//
//  Set the vector that represents the J-th column to be annihilated.
//
    for ( i = 0; i < j; i++ )
    {
      x[i] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      x[i] = r8_normal_01 ( seed );
    }
//
//  Compute the vector V that defines a Householder transformation matrix
//  H(V) that annihilates the subdiagonal elements of X.
//
//  The COLUMN argument here is 1-based.
//
    v = r8vec_house_column ( n, x, j+1 );
//
//  Postmultiply the matrix A by H'(V) = H(V).
//
    r8mat_house_axh ( n, a, v );

    delete [] v;
  }
  delete [] x;

  return a;
}
//****************************************************************************80

double *pds_random ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    PDS_RANDOM returns the PDS_RANDOM matrix.
//
//  Discussion:
//
//    The matrix is a "random" positive definite symmetric matrix.
//
//    The matrix returned will have eigenvalues in the range [0,1].
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    A is positive definite: 0 < x'*A*x for nonzero x.
//
//    The eigenvalues of A will be real.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input/output, int &SEED, a seed for the random 
//    number generator.
//
//    Output, double PDS_RANDOM[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  double *lambda;
  double *q;

  a = new double[n*n];
//
//  Get a random set of eigenvalues.
//
  lambda = r8vec_uniform_01_new ( n, seed );
//
//  Get a random orthogonal matrix Q.
//
  q = orth_random ( n, seed );
//
//  Set A = Q * Lambda * Q'.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        a[i+j*n] = a[i+j*n] + q[i+k*n] * lambda[k] * q[j+k*n];
      }
    }
  }
  delete [] lambda;
  delete [] q;

  return a;
}
//****************************************************************************80

double  r8_normal_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NORMAL_01 samples the standard normal probability distribution.
//
//  Discussion:
//
//    The standard normal probability distribution function (PDF) has
//    mean 0 and standard deviation 1.
//
//    The Box-Muller method is used.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input/output, int SEED, a seed for the random number generator.
//
//    Output, double R8_NORMAL_01, a normally distributed random value.
//
{
  double r1;
  double r2;
  const double r8_pi = 3.141592653589793;
  double x;

  r1 = r8_uniform_01 ( seed );
  r2 = r8_uniform_01 ( seed );
  x = sqrt ( -2.0 * log ( r1 ) ) * cos ( 2.0 * r8_pi * r2 );

  return x;
}
//****************************************************************************80

double r8_sign ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_SIGN returns the sign of an R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the number whose sign is desired.
//
//    Output, double R8_SIGN, the sign of X.
//
{
  double value;

  if ( x < 0.0 )
  {
    value = -1.0;
  }
  else
  {
    value = 1.0;
  }
  return value;
}
//****************************************************************************80

double r8_uniform_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_01 returns a unit pseudorandom R8.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//    If the initial seed is 12345, then the first three computations are
//
//      Input     Output      R8_UNIFORM_01
//      SEED      SEED
//
//         12345   207482415  0.096616
//     207482415  1790989824  0.833995
//    1790989824  2035175616  0.947702
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input/output, int &SEED, the "seed" value.  Normally, this
//    value should not be 0.  On output, SEED has been updated.
//
//    Output, double R8_UNIFORM_01, a new pseudorandom variate, 
//    strictly between 0 and 1.
//
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + i4_huge;
  }
  r = ( double ) ( seed ) * 4.656612875E-10;

  return r;
}
//****************************************************************************80

void r83_cg ( int n, double a[], double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83_CG uses the conjugate gradient method on an R83 system.
//
//  Discussion:
//
//    The R83 storage format is used for a tridiagonal matrix.
//    The superdiagonal is stored in entries (1,2:N), the diagonal in
//    entries (2,1:N), and the subdiagonal in (3,1:N-1).  Thus, the
//    original matrix is "collapsed" vertically into the array.
//
//    The matrix A must be a positive definite symmetric band matrix.
//
//    The method is designed to reach the solution after N computational
//    steps.  However, roundoff may introduce unacceptably large errors for
//    some problems.  In such a case, calling the routine again, using
//    the computed solution as the new starting estimate, should improve
//    the results.
//
//  Example:
//
//    Here is how an R83 matrix of order 5 would be stored:
//
//       *  A12 A23 A34 A45
//      A11 A22 A33 A44 A55
//      A21 A32 A43 A54  *
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, double A[3*N], the matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution, which may be 0.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r83_mv ( n, n, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//
  for ( it = 1; it <= n; it++ )
  {
//
//  Compute the matrix*vector product AP=A*P.
//
    delete [] ap;
    ap = r83_mv ( n, n, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = r8vec_dot_product ( n, p, ap );
    pr = r8vec_dot_product ( n, p, r );

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = r8vec_dot_product ( n, r, ap );

    beta = - rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }
  }
//
//  Free memory.
//
  delete [] p;
  delete [] r;

  return;
}
//****************************************************************************80

double *r83_dif2 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R83_DIF2 returns the DIF2 matrix in R83 format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double A[3*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int mn;

  a = new double[3*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      a[i+j*3] = 0.0;
    }
  }

  mn = i4_min ( m, n );

  for ( j = 1; j < mn; j++ )
  {
    a[0+j*3] = -1.0;
  }

  for ( j = 0; j < mn; j++ )
  {
    a[1+j*3] = 2.0;
  }

  for ( j = 0; j < mn -1; j++ )
  {
    a[2+j*3] = -1.0;
  }

  if ( n < m )
  {
    a[2+(mn-1)*3] = -1.0;
  }
   
  return a;
}
//****************************************************************************80

double *r83_mv ( int m, int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83_MV multiplies a R83 matrix times a vector.
//
//  Discussion:
//
//    The R83 storage format is used for a tridiagonal matrix.
//    The superdiagonal is stored in entries (1,2:N), the diagonal in
//    entries (2,1:N), and the subdiagonal in (3,1:N-1).  Thus, the
//    original matrix is "collapsed" vertically into the array.
//
//  Example:
//
//    Here is how a R83 matrix of order 5 would be stored:
//
//       *  A12 A23 A34 A45
//      A11 A22 A33 A44 A55
//      A21 A32 A43 A54  *
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A[3*N], the R83 matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R83_MV[M], the product A * x.
//
{
  double *b;
  int i;
  int mn;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }

  mn = i4_min ( m, n );

  for ( i = 0; i < mn; i++ )
  {
    b[i] = b[i] + a[1+i*3] * x[i];
  }
  for ( i = 0; i < mn - 1; i++ )
  {
    b[i] = b[i] + a[0+(i+1)*3] * x[i+1];
  }
  for ( i = 1; i < mn; i++ )
  {
    b[i] = b[i] + a[2+(i-1)*3] * x[i-1];
  }

  if ( n < m )
  {
    b[n] = b[n] + a[2+(n-1)*3] * x[n-1];
  }
  else if ( m < n )
  {
    b[m-1] = b[m-1] + a[0+m*3] * x[m];
  }

  return b;
}
//****************************************************************************80

double *r83_res ( int m, int n, double a[], double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83_RES computes the residual R = B-A*X for R83 matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[3*N], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R83_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r83_mv ( m, n, a, x );

  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r83s_cg ( int n, double a[], double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83S_CG uses the conjugate gradient method on an R83S system.
//
//  Discussion:
//
//    The R83S storage format is used for a tridiagonal scalar matrix.
//    The vector A(3) contains the subdiagonal, diagonal, and superdiagonal
//    values that occur on every row.
//
//    The matrix A must be a positive definite symmetric band matrix.
//
//    The method is designed to reach the solution after N computational
//    steps.  However, roundoff may introduce unacceptably large errors for
//    some problems.  In such a case, calling the routine again, using
//    the computed solution as the new starting estimate, should improve
//    the results.
//
//  Example:
//
//    Here is how an R83S matrix of order 5, stored as (A1,A2,A3), would
//    be interpreted:
//
//      A2  A3   0   0   0
//      A1  A2  A3   0   0
//       0  A1  A2  A3   0 
//       0   0  A1  A2  A3
//       0   0   0  A1  A2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, double A[3], the matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution, which may be 0.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r83s_mv ( n, n, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//
  for ( it = 1; it <= n; it++ )
  {
//
//  Compute the matrix*vector product AP=A*P.
//
    delete [] ap;
    ap = r83s_mv ( n, n, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = r8vec_dot_product ( n, p, ap );
    pr = r8vec_dot_product ( n, p, r );

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = r8vec_dot_product ( n, r, ap );

    beta = - rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }
  }
//
//  Free memory.
//
  delete [] p;
  delete [] r;

  return;
}
//****************************************************************************80

double *r83s_dif2 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R83S_DIF2 returns the DIF2 matrix in R83S format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//    A is tridiagonal.
//    Because A is tridiagonal, it has property A (bipartite).
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//    A is Toeplitz: constant along diagonals.
//    A is symmetric: A' = A.
//    Because A is symmetric, it is normal.
//    Because A is normal, it is diagonalizable.
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//    A is positive definite.
//    A is an M matrix.
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//    A has an LU factorization A = L * U, without pivoting.
//      The matrix L is lower bidiagonal with subdiagonal elements:
//        L(I+1,I) = -I/(I+1)
//      The matrix U is upper bidiagonal, with diagonal elements
//        U(I,I) = (I+1)/I
//      and superdiagonal elements which are all -1.
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//    The eigenvalues are
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//    The corresponding eigenvector X(I) has entries
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//    Simple linear systems:
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//    det ( A ) = N + 1.
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double A[3], the matrix.
//
{
  double *a;

  a = new double[3];

  a[0] = -1.0;
  a[1] =  2.0;
  a[2] = -1.0;
   
  return a;
}
//****************************************************************************80

double *r83s_mv ( int m, int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83S_MV multiplies a R83S matrix times a vector.
//
//  Discussion:
//
//    The R83S storage format is used for a tridiagonal scalar matrix.
//    The vector A(3) contains the subdiagonal, diagonal, and superdiagonal
//    values that occur on every row.
//
//  Example:
//
//    Here is how an R83S matrix of order 5, stored as (A1,A2,A3), would
//    be interpreted:
//
//      A2  A3   0   0   0
//      A1  A2  A3   0   0
//       0  A1  A2  A3   0 
//       0   0  A1  A2  A3
//       0   0   0  A1  A2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A[3], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R83S_MV[M], the product A * x.
//
{
  double *b;
  int i;
  int ihi;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }

  ihi = i4_min ( m, n + 1 );

  for ( i = 1; i < ihi; i++ )
  {
    b[i] = b[i] + a[0] * x[i-1];
  }

  ihi = i4_min ( m, n );
  for ( i = 0; i < ihi; i++ )
  {
    b[i] = b[i] + a[1] * x[i];
  }

  ihi = i4_min ( m, n - 1 );
  for ( i = 0; i < ihi; i++ )
  {
    b[i] = b[i] + a[2] * x[i+1];
  }

  return b;
}
//****************************************************************************80

double *r83s_res ( int m, int n, double a[], double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83S_RES computes the residual R = B-A*X for R83S matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[3], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R83S_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r83s_mv ( m, n, a, x );
  
  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r83t_cg ( int n, double a[], double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83T_CG uses the conjugate gradient method on an R83T system.
//
//  Discussion:
//
//    The R83T storage format is used for a tridiagonal matrix.
//    The superdiagonal is stored in entries (1:N-1,3), the diagonal in
//    entries (1:N,2), and the subdiagonal in (2:N,1).  Thus, the
//    original matrix is "collapsed" horizontally into the array.
//
//    The matrix A must be a positive definite symmetric band matrix.
//
//    The method is designed to reach the solution after N computational
//    steps.  However, roundoff may introduce unacceptably large errors for
//    some problems.  In such a case, calling the routine again, using
//    the computed solution as the new starting estimate, should improve
//    the results.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, double A[N*3], the matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution, which may be 0.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r83t_mv ( n, n, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//
  for ( it = 1; it <= n; it++ )
  {
//
//  Compute the matrix*vector product AP=A*P.
//
    delete [] ap;
    ap = r83t_mv ( n, n, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = r8vec_dot_product ( n, p, ap );
    pr = r8vec_dot_product ( n, p, r );

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = r8vec_dot_product ( n, r, ap );

    beta = - rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }
  }
//
//  Free memory.
//
  delete [] p;
  delete [] r;

  return;
}
//****************************************************************************80

double *r83t_dif2 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R83T_DIF2 returns the DIF2 matrix in R83T format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double A[M*3], the matrix.
//
{
  double *a;
  int i;
  int j;
  int mn;

  a = new double[m*3];

  for ( j = 0; j < 3; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }

  mn = i4_min ( m, n );

  j = 0;
  for ( i = 1; i < mn; i++ )
  {
    a[i+j*m] = -1.0;
  }

  j = 1;
  for ( i = 0; i < mn; i++ )
  {
    a[i+j*m] = 2.0;
  }

  j = 2;
  for ( i = 0; i < mn -1; i++ )
  {
    a[i+j*m] = -1.0;
  }

  if ( m < n )
  {
    i = mn - 1;
    j = 2;
    a[i+j*m] = -1.0;
  }
  else if ( n < m )
  {
    i = mn;
    j = 0;
    a[i+j*m] = -1.0;
  }
   
  return a;
}
//****************************************************************************80

double *r83t_mv ( int m, int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83T_MV multiplies a R83T matrix times a vector.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A[M*3], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R83T_MV[M], the product A * x.
//
{
  double *b;
  int i;
  int j;
  int mn;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }

  if ( n == 1 )
  {
    i = 0;
    j = 1;
    b[0] = a[i+j*m] * x[0];
    if ( 1 < m )
    {
      i = 1;
      j = 0;
      b[1] = a[i+j*m] * x[0];
    }
    return b;
  }

  mn = i4_min ( m, n );

  b[0] = a[0+1*m] * x[0]
       + a[0+2*m] * x[1];

  for ( i = 1; i < mn - 1; i++ )
  {
    b[i] = a[i+0*m] * x[i-1]
         + a[i+1*m] * x[i]
         + a[i+2*m] * x[i+1];
  }
  b[mn-1] = a[mn-1+0*m] * x[mn-2]
          + a[mn-1+1*m] * x[mn-1];

  if ( n < m )
  {
    b[mn] = b[mn] + a[mn+0*m] * x[mn-1];
  }
  else if ( m < n )
  {
    b[mn-1] = b[mn-1] + a[mn-1+2*m] * x[mn];
  }

  return b;
}
//****************************************************************************80

double *r83t_res ( int m, int n, double a[], double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R83T_RES computes the residual R = B-A*X for R83T matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[M*3], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R83T_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r83t_mv ( m, n, a, x );

  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r8ge_cg ( int n, double a[], double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8GE_CG uses the conjugate gradient method on an R8GE system.
//
//  Discussion:
//
//    The R8GE storage format is used for a general M by N matrix.  A storage 
//    space is made for each entry.  The two dimensional logical
//    array can be thought of as a vector of M*N entries, starting with
//    the M entries in the column 1, then the M entries in column 2
//    and so on.  Considered as a vector, the entry A(I,J) is then stored
//    in vector location I+(J-1)*M.
//
//    The matrix A must be a positive definite symmetric band matrix.
//
//    The method is designed to reach the solution after N computational
//    steps.  However, roundoff may introduce unacceptably large errors for
//    some problems.  In such a case, calling the routine again, using
//    the computed solution as the new starting estimate, should improve
//    the results.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, double A[N*N], the matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution, which may be 0.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r8ge_mv ( n, n, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//
  for ( it = 1; it <= n; it++ )
  {
  // inject bit flip - replace with custom bit injecter
    if (it == Global::pos) {
        injectBitflip (n, a, x, b);
    }
//
//  Compute the matrix*vector product AP=A*P.
//
    delete [] ap;
    ap = r8ge_mv ( n, n, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = r8vec_dot_product ( n, p, ap );
    pr = r8vec_dot_product ( n, p, r );

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = r8vec_dot_product ( n, r, ap );

    beta = - rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }

    //Error Detection Method

    double curRes = getResidual ( n, n, a, x, b );
    if ( isFlipped(curRes )) {

      // bit error occurred, start recovery procedure (if any)
      // by default, exit.

      cerr << "Bit error detected, terminating application" << endl;
      exit(-1);

    } else {
      recordResidual(curRes);
    }
    cout << "res at i = " << i << getResidual( n, n, a, x, b ) << endl;
  }

  delete [] p;
  delete [] r;

  return;
}

//**************************************************
//  Emin Codes Block

void r8ge_cg_emin ( int n, double a[], double b[], double x[] , int range1 , int range2 , int k)//, double r[])
{

  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;


  cout << " Emin new cg method is started " << endl ;

  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
  //
  //  Do the N steps of the conjugate gradient method.
  //
  for ( it = 1; it <= n; it++ )
  {
  // inject bit flip - replace with custom bit injecter
    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

        injectBitFlipNotRandom(n , r, p , x ,range1, range2, k) ;

    }

  //
  //  Compute the matrix*vector product AP=A*P.
  //
      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );
  //
  //  Compute the dot products
  //    PAP = P*AP,
  //    PR  = P*R
  //  Set
  //    ALPHA = PR / PAP.
  //

       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];
      }
      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];
      }

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
        rap = r8vec_dot_product ( n, r, ap );

        beta = - rap / pap;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];
      }

      //Error Detection

      //Jiaqi's method calculate residual unnecessaryly 


      //double curRes = getResidual ( n, n, a, x, b );
      double curRes= r8vec_norm(n , r ) ;

      if ( isFlipped(curRes )) {

      //if( isDetected())

      // bit error occurred, start recovery procedure (if any)
      // by default, exit.

      cerr << "Bit error detected, terminating application" << endl;
      exit(-1);

      } else {
        recordResidual(curRes);
      }

      cout << "res at i = " << it << endl;
      cout << " curRes = " <<curRes <<endl ;
  }

  delete [] p;
  delete [] r;

  return;

}

//End of Emin Code Block 
//*********************************************************************
double getCurIndicatorValue(double x[] , double r[] , double b[] , int n)
{
    double *sum ;
    sum = new double[n] ;

    double result=0;

    for (int i = 0; i < n; ++i)
    {
      /* code */

      sum[i] = (-1)*( r[i] + b[i]) ;


    }


    /*
    for (int i = 0; i < n; ++i)
    {
      
      result = result + x[i]*sum[i] ;
    }

    result = result*(-1) ;

    */

    result=r8vec_dot_product(n , x , sum) ;

    //result= result*(-1);

    delete [] sum;
    return result ; 

}

double getFunctionIndicatorCunverge ( int n , double x[] , double b[] ) 
{
    //return -x^T*b

    double sum;

    for (int i = 0; i < n; ++i)
    {
      /* code */
      sum= sum + x[i]*b[i] ;
    }

    return -sum;

}

void r8ge_cg_newAlphaImprovement_emin(int n , double a[] ,double b[] , double x[] , int range1 ,int  range2 ,int k) 
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 

  double *arrayForAlpha;
  double *arrayForBeta ;

  arrayForAlpha = new double[n] ;
  arrayForBeta = new double[n] ;

  cout << " Detection by New Indicator Method fn=-x^T*(-rn-b) to detect soft error with considering Improvement " <<endl ;
  cout << "" <<endl ;


  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  //queue<double>& detector = Global::eminDetector;

  for ( it = 1; it <= n; it++ )
  {
    // inject bit flip - replace with custom bit injecter

    cout<<" Number of iteration = "<<it<<endl ;

    if ( it > Global::pos)
    {
      /* code */

      cout<< " After error injection "<<endl ;
      cout<<""<<endl;

    }

    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

          cout << " Fault Injecting is occurred here" <<endl ;
          injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

    }

    //
    //  Compute the matrix*vector product AP=A*P.
    //
      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );

    //
    //  Compute the dot products
    //    PAP = P*AP,
    //    PR  = P*R
    //  Set
    //    ALPHA = PR / PAP.


       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      arrayForAlpha[it-1] = alpha ;

      //cout<<""<<endl;
      cout<<" Alpha = "<<alpha<<endl ;
      //cout<<""<<endl;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];

        //cout<<" x[ "<<i<<" ] = "<<x[i]<<endl ; 
      }

      cout<<""<<endl;

      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];

        //cout<<" r[ "<<i<<" ] = "<<r[i]<<endl ;
      }

      cout<<""<<endl;

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
      rap = r8vec_dot_product ( n, r, ap );

      beta = - rap / pap;

      arrayForBeta[it-1] = beta ;

      //cout<<""<<endl;
      cout<<" Beta = "<<beta<<endl ;
      //cout<<""<<endl;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];

          //cout<<" p[ "<<i<<" ] = "<<p[i]<<endl ;
      }

      cout<<""<<endl;

      //Error Detection

      curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

      if ( it == 1)
      {
        /* code */
        Global::previousValueOfIndicator = curIndicatorValue ;
      }

      cout << "IndicatorFunction Value at i = " << it << endl;
      cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;


      
      if ( improveMethodWithAlpha(curIndicatorValue,  alpha) )
      {
        /* code */
        cerr << " Bit error detected, terminating application for improveMethod" << endl;
        cout << " Bit error detected, terminating application for improveMethod" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;

        cout<<"*******************"<<endl ;
        cout<<" The Value of Alpha"<<endl ;


        for (int i = 0; i < it; ++i)
        {
          /* code */
          cout<<"For iteration = "<<i+1<<" Alpha = "<<arrayForAlpha[i]<<endl;


        }

        cout<<"*******************"<<endl ;
        cout<<" The Value of Beta"<<endl ;

        for (int i = 0; i < it; ++i)
        {
          /* code */
          cout<<"For iteration = "<<i+1<<" Beta = "<<arrayForBeta[i]<<endl;


        }





        delete [] arrayForAlpha;
        delete [] arrayForBeta ;


        return ;

      } 

      


  }

  
  //cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

  cout<<"*******************"<<endl ;
  cout<<" The Value of Alpha"<<endl ;


  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout<<"For iteration = "<<i+1<<" Alpha = "<<arrayForAlpha[i]<<endl;


  }

  cout<<"*******************"<<endl ;
  cout<<" The Value of Beta"<<endl ;

  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout<<"For iteration = "<<i+1<<" Beta = "<<arrayForBeta[i]<<endl;


  }



  delete [] p;
  delete [] r;

  delete [] arrayForAlpha;
  delete [] arrayForBeta ;

  return;


}

bool r8ge_cg_newAlphaImprovement_eminForRelativeError(int n , double a[] ,double b[] , double x[] , int range1 ,int  range2 ,int k) 
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 

  bool detected = false;

  double *arrayForAlpha;
  double *arrayForBeta ;

  arrayForAlpha = new double[n] ;
  arrayForBeta = new double[n] ;

  cout << " Detection by New Indicator Method fn=-x^T*(-rn-b) to detect soft error with considering Improvement " <<endl ;
  cout << "" <<endl ;


  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  //queue<double>& detector = Global::eminDetector;

  for ( it = 1; it <= n; it++ )
  {
    // inject bit flip - replace with custom bit injecter

    cout<<" Number of iteration = "<<it<<endl ;

    if ( it > Global::pos)
    {
      /* code */

      cout<< " After error injection "<<endl ;
      cout<<""<<endl;

    }

    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

          cout << " Fault Injecting is occurred here" <<endl ;
          injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

    }

    //
    //  Compute the matrix*vector product AP=A*P.
    //
      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );

    //
    //  Compute the dot products
    //    PAP = P*AP,
    //    PR  = P*R
    //  Set
    //    ALPHA = PR / PAP.


       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      arrayForAlpha[it-1] = alpha ;

      //cout<<""<<endl;
      cout<<" Alpha = "<<alpha<<endl ;
      //cout<<""<<endl;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];

        //cout<<" x[ "<<i<<" ] = "<<x[i]<<endl ; 
      }

      cout<<""<<endl;

      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];

        //cout<<" r[ "<<i<<" ] = "<<r[i]<<endl ;
      }

      cout<<""<<endl;

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
      rap = r8vec_dot_product ( n, r, ap );

      beta = - rap / pap;

      arrayForBeta[it-1] = beta ;

      //cout<<""<<endl;
      cout<<" Beta = "<<beta<<endl ;
      //cout<<""<<endl;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];

          //cout<<" p[ "<<i<<" ] = "<<p[i]<<endl ;
      }

      cout<<""<<endl;

      //Error Detection

      curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

      if ( it == 1)
      {
        /* code */
        Global::previousValueOfIndicator = curIndicatorValue ;
      }

      cout << "IndicatorFunction Value at i = " << it << endl;
      cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;


      
      if ( improveMethodWithAlpha(curIndicatorValue,  alpha) )
      {
        /* code */
        cerr << " Bit error detected, terminating application for improveMethod" << endl;
        cout << " Bit error detected, terminating application for improveMethod" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;
        detected = true ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;

        cout<<"*******************"<<endl ;
        cout<<" The Value of Alpha"<<endl ;


        for (int i = 0; i < it; ++i)
        {
          /* code */
          cout<<"For iteration = "<<i+1<<" Alpha = "<<arrayForAlpha[i]<<endl;


        }

        cout<<"*******************"<<endl ;
        cout<<" The Value of Beta"<<endl ;

        for (int i = 0; i < it; ++i)
        {
          /* code */
          cout<<"For iteration = "<<i+1<<" Beta = "<<arrayForBeta[i]<<endl;


        }





        delete [] arrayForAlpha;
        delete [] arrayForBeta ;


        return detected;

      } 

      


  }

  
  //cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

  cout<<"*******************"<<endl ;
  cout<<" The Value of Alpha"<<endl ;


  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout<<"For iteration = "<<i+1<<" Alpha = "<<arrayForAlpha[i]<<endl;


  }

  cout<<"*******************"<<endl ;
  cout<<" The Value of Beta"<<endl ;

  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout<<"For iteration = "<<i+1<<" Beta = "<<arrayForBeta[i]<<endl;


  }



  delete [] p;
  delete [] r;

  delete [] arrayForAlpha;
  delete [] arrayForBeta ;

  Global::undetectedNumber++;

  return detected ;


}





void r8ge_cg_newImprovement_emin(int n , double a[] , double b[] , double x[] , int range1, int range2, int k ) 
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 

  double *arrayForAlpha;
  double *arrayForBeta ;

  arrayForAlpha = new double[n] ;
  arrayForBeta = new double[n] ;




  cout << " Detection by New Indicator Method fn=alpha* r^t * r to detect soft error " <<endl ;
  cout << "" <<endl ;


  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  //queue<double>& detector = Global::eminDetector;

  for ( it = 1; it <= n; it++ )
  {
    // inject bit flip - replace with custom bit injecter

    cout<<" Number of iteration = "<<it<<endl ;

    if ( it > Global::pos)
    {
      /* code */

      cout<< " After error injection "<<endl ;
      cout<<""<<endl;

    }

    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

          cout << " Fault Injecting is occurred here" <<endl ;
          injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

    }

    //
    //  Compute the matrix*vector product AP=A*P.
    //
      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );

    //
    //  Compute the dot products
    //    PAP = P*AP,
    //    PR  = P*R
    //  Set
    //    ALPHA = PR / PAP.


       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      arrayForAlpha[it-1] = alpha ;

      cout<<""<<endl;
      cout<<" Alpha = "<<alpha<<endl ;
      cout<<""<<endl;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];

        cout<<" x[ "<<i<<" ] = "<<x[i]<<endl ; 
      }

      cout<<""<<endl;

      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];

        cout<<" r[ "<<i<<" ] = "<<r[i]<<endl ;
      }

      cout<<""<<endl;

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
      rap = r8vec_dot_product ( n, r, ap );

      beta = - rap / pap;

      arrayForBeta[it-1] = beta ;

      cout<<""<<endl;
      cout<<" Beta = "<<beta<<endl ;
      cout<<""<<endl;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];

          cout<<" p[ "<<i<<" ] = "<<p[i]<<endl ;
      }

      cout<<""<<endl;

      //Error Detection

      curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

      if ( it == 1)
      {
        /* code */
        Global::previousValueOfIndicator = curIndicatorValue ;
      }

      cout << "IndicatorFunction Value at i = " << it << endl;
      cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;


      //if ( isFlippedIndicator(curIndicatorValue)) {

      /*

      if( isDetected (curIndicatorValue ))//, detector))
      {


      // bit error occurred, start recovery procedure (if any)
      // by default, exit.

        cerr << " Bit error detected, terminating application" << endl;
        cout << " Bit error detected, terminating application" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;
        return ;

      } 

      */
      if ( improveMethod( curIndicatorValue) )
      {
        /* code */
        cerr << " Bit error detected, terminating application for improveMethod" << endl;
        cout << " Bit error detected, terminating application for improveMethod" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;

        cout<<"*******************"<<endl ;
        cout<<" The Value of Alpha"<<endl ;


        for (int i = 0; i < it; ++i)
        {
          /* code */
          cout<<"For iteration = "<<i+1<<" Alpha = "<<arrayForAlpha[i]<<endl;


        }

        cout<<"*******************"<<endl ;
        cout<<" The Value of Beta"<<endl ;

        for (int i = 0; i < it; ++i)
        {
          /* code */
          cout<<"For iteration = "<<i+1<<" Beta = "<<arrayForBeta[i]<<endl;


        }





        delete [] arrayForAlpha;
        delete [] arrayForBeta ;


        return ;

      }

      /*
      else 
      {
        //recordIndicator(curIndicatorValue);

        getIndicator( curIndicatorValue ) ;// ,detector) ;
      }

      */


  }

  
  //cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

  cout<<"*******************"<<endl ;
  cout<<" The Value of Alpha"<<endl ;


  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout<<"For iteration = "<<i+1<<" Alpha = "<<arrayForAlpha[i]<<endl;


  }

  cout<<"*******************"<<endl ;
  cout<<" The Value of Beta"<<endl ;

  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout<<"For iteration = "<<i+1<<" Beta = "<<arrayForBeta[i]<<endl;


  }



  delete [] p;
  delete [] r;

  delete [] arrayForAlpha;
  delete [] arrayForBeta ;

  return;


}

void   r8ge_cg_checkSum_emin2( int n , double  a[] , double b[] , double x[] , int range1, int  range2, int k )
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 


  cout << " Detection by New Indicator Method fn=-x^T*(-rn-b) to detect soft error with considering CheckSum" <<endl ;
  cout << "" <<endl ;

  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  //queue<double>& detector = Global::eminDetector;

  initialCheckSum(n , r , p , x) ;

  for ( it = 1; it <= n; it++ )
  {
    // inject bit flip - replace with custom bit injecter
    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

          initialCheckSum(n , r , p , x) ;
          cout << " Fault Injecting is occurred here" <<endl ;
          injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

    }

    //
    //  Compute the matrix*vector product AP=A*P.
    //
      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );

    //
    //  Compute the dot products
    //    PAP = P*AP,
    //    PR  = P*R
    //  Set
    //    ALPHA = PR / PAP.


       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];
      }
      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];
      }

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
      rap = r8vec_dot_product ( n, r, ap );

      beta = - rap / pap;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];
      }

      //Error Detection

      curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

      if ( it == 1)
      {
        /* code */
        Global::previousValueOfIndicator = curIndicatorValue ;
      }

      cout << "IndicatorFunction Value at i = " << it << endl;
      cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;



      if ( checkSumMethod( n , r , p , x))
      {
        /* code */
        cerr << " Bit error detected, terminating application by chechsum" << endl;
        cout << " Bit error detected, terminating application by checksum" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;
        return ;

      }

  }

  delete [] p;
  delete [] r;

  return;



} 
void r8ge_cg_checkSum_emin(int n , double a[] , double b[] , double x[] , int range1, int range2, int k ) 
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 




  cout << " Detection by New Indicator Method fn=-x^T*(-rn-b) to detect soft error with considering Improvement " <<endl ;
  cout << "" <<endl ;


  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  //queue<double>& detector = Global::eminDetector;

  for ( it = 1; it <= n; it++ )
  {
    // inject bit flip - replace with custom bit injecter
    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

          cout << " Fault Injecting is occurred here" <<endl ;
          injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

    }

    //
    //  Compute the matrix*vector product AP=A*P.
    //
      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );

    //
    //  Compute the dot products
    //    PAP = P*AP,
    //    PR  = P*R
    //  Set
    //    ALPHA = PR / PAP.


       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];
      }
      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];
      }

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
      rap = r8vec_dot_product ( n, r, ap );

      beta = - rap / pap;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];
      }

      //Error Detection

      curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

      if ( it == 1)
      {
        /* code */
        Global::previousValueOfIndicator = curIndicatorValue ;
      }

      cout << "IndicatorFunction Value at i = " << it << endl;
      cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;


      //if ( isFlippedIndicator(curIndicatorValue)) {

      /*

      if( isDetected (curIndicatorValue ))//, detector))
      {


      // bit error occurred, start recovery procedure (if any)
      // by default, exit.

        cerr << " Bit error detected, terminating application" << endl;
        cout << " Bit error detected, terminating application" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;
        return ;

      } 

      */
      if ( improveMethodFOrCheckSUm(  n,  a ,   x ,  b , curIndicatorValue) )
      {
        /* code */
        cerr << " Bit error detected, terminating application by chechsum" << endl;
        cout << " Bit error detected, terminating application by checksum" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        delete [] p;
        delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;
        return ;

      }

      /*
      else 
      {
        //recordIndicator(curIndicatorValue);

        getIndicator( curIndicatorValue ) ;// ,detector) ;
      }

      */


  }

  
  //cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;


  delete [] p;
  delete [] r;

  return;





}

void r8ge_cg_newIndicatior_emin(int n , double a[] , double b[] , double x[] , int range1, int range2, int k ) //, double r[]) ;
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 

  cout << " Detection by New Indicator Method fn=-x^T*(-rn-b) to detect soft error " <<endl ;
  cout << "" <<endl ;

  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv ( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  //queue<double>& detector = Global::eminDetector;

  for ( it = 1; it <= n; it++ )
  {
    // inject bit flip - replace with custom bit injecter
    if (it == Global::pos) {
        //injectBitflip (n, a, x, b);

          cout << " Fault Injecting is occurred here" <<endl ;
          injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

    }

    //
    //  Compute the matrix*vector product AP=A*P.
    //
        delete [] ap;
        ap = r8ge_mv ( n, n, a, p );

    //
    //  Compute the dot products
    //    PAP = P*AP,
    //    PR  = P*R
    //  Set
    //    ALPHA = PR / PAP.


       pap = r8vec_dot_product ( n, p, ap );
       pr = r8vec_dot_product ( n, p, r );

      if ( pap == 0.0 )
      {
        delete [] ap;
        break;
      }

      alpha = pr / pap;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];
      }
      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];
      }

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
        rap = r8vec_dot_product ( n, r, ap );

        beta = - rap / pap;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];
      }

      //Error Detection

      curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

      cout << "IndicatorFunction Value at i = " << it << endl;
      cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;


      //if ( isFlippedIndicator(curIndicatorValue)) {



      if( isDetected (curIndicatorValue ))//, detector))
      {


      // bit error occurred, start recovery procedure (if any)
      // by default, exit.

        cerr << " Bit error detected, terminating application" << endl;
        cout << " Bit error detected, terminating application" <<endl ;
        cout << "*******************************************" << endl;

        cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        //delete [] p;
        //delete [] r;
        //detector.pop();
        //detector.pop();
        //delete detector;
        //return ;

      } 
      else 
      {
        //recordIndicator(curIndicatorValue);

        getIndicator( curIndicatorValue ) ;// ,detector) ;
      }

      


  }

  
  //cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;


  delete [] p;
  delete [] r;

  return;
}

void r8ge_gcr_Residual(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k)
{
  
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double rTr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ;

  double *ar ; 
  double rar ;
  double updated_rar;
  double apap;

  double newIndicator;

  cout << " Detection by  Indicator_version2 Method fn_new = alpha * r^T * r to detect soft error  " <<endl ;
  cout << "" <<endl ;

  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }


  double preResidual=0;
  double curRes = 0;

  double curProposedIndicator =0;
  double prevProposedIndicator = 0;

  for( it=1 ; it <= n ; it ++)
  {

      // inject bit flip - replace with custom bit injecter
      if (it == Global::pos) {
          //injectBitflip (n, a, x, b);

            cout << " Fault Injecting is occurred here" <<endl ;
            injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

      }


      //
      //  Compute the matrix*vector product AP=A*P.
      //

      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );
      ar = r8ge_mv ( n, n, a, r );

      rar = r8vec_dot_product(n , r, ar) ;
      apap = r8vec_dot_product(n , ap, ap) ;

      if ( apap == 0.0 )
      {
         delete [] ap;
         break;
      }


      alpha = rar / apap ;

      double previousRes= r8vec_norm(n , r ) ;


      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];
      }
      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];
      }

      //
      //  Compute the vector dot product
      //    RAP = R*AR
      //  Set
      //    Beta = updated_rar/rar
      //

      ar = r8ge_mv ( n, n, a, r );

      updated_rar=r8vec_dot_product(n, r, ar) ;

      beta =  updated_rar / rar ;

       //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];
      }


      for( i = 0 ; i < n ; i++ )
      {
          ap[i] = ar[i] + beta*ap[i] ; 
      }


      //Error Detection

      preResidual = curRes ;
      prevProposedIndicator= curProposedIndicator ;

      curRes= r8vec_norm(n , r ) ;
      cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;

      double curProposedIndicator = getCurIndicatorValue( x, r , b, n) ;
      cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curProposedIndicator << endl;
      
      

       if (curRes > preResidual && it != 1 ) 
       {

          cerr << "Bit error detected by Residual, terminating application" << endl;
          cout << "Bit error detected by Residual, terminating application" << endl;

          cout << "Norm of residual at current  ="<< it <<" ||Ax-b||_n = " <<  curRes << endl;
          cout << "Norm of residual at previous ="<< it <<" ||Ax-b||_{n-1} = " <<  preResidual << endl;

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

           delete [] p;
           delete [] r;

           return ;

       } 
       else if(isnan(curRes))
       {

        cerr << "Bit error detected residual is nan, terminating application" << endl;
        cout << "Bit error detected residual is nan, terminating application" << endl;

        cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;
        cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curProposedIndicator << endl;


        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
               //successful ++ ;
                  Global::successfulRate ++ ;
        }

        delete [] p;
        delete [] r;

        return ;


       }
       else if(abs(curProposedIndicator) - abs(prevProposedIndicator) < 0 && it !=1)
       {
          cerr << "Bit error detected by proposed indicator, terminating application" << endl;
          cout << "Bit error detected by proposed indicator, terminating application" << endl;

          
          

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

          delete [] p;
          delete [] r;

          return ;

       }
       else if(isinf(abs(curProposedIndicator)))
       {
          cerr << "Bit error detected by proposed indicator is inf, terminating application" << endl;
          cout << "Bit error detected by proposed indicator is inf, terminating application" << endl;

          cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;
          cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curProposedIndicator << endl;

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

           delete [] p;
           delete [] r;

           return ;

       }
       else if(isnan(curProposedIndicator))
       {
        
        cerr << "Bit error detected proposed indicator is nan, terminating application" << endl;
        cout << "Bit error detected proposed indicator is nan, terminating application" << endl;

        cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;
        cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curProposedIndicator << endl;


        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
               //successful ++ ;
                  Global::successfulRate ++ ;
        }

        delete [] p;
        delete [] r;

        return ;

       }
     
      



  }

  delete [] p;
  delete [] r;

  return;


}




void r8ge_cg_Indicator_version2(int n , double a[] , double b[] , double x[] , int range1 , int range2 , int k)  
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double rTr;
  double *r; //It takes it as parameter
  double rap;
  double curIndicatorValue ; 

  double newIndicator;

  cout << " Detection by  Indicator_version2 Method fn_new = alpha * r^T * r to detect soft error  " <<endl ;
  cout << "" <<endl ;

  //
  //  Initialize
  //    AP = A * x,
  //    R  = b - A * x,
  //    P  = b - A * x.
  //
  ap = r8ge_mv( n, n, a, x );
  r = new double[n];


  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }

  //
  //  Do the N steps of the conjugate gradient method.
  //

  for( it = 1; it <= n; it++ )
  {
      // inject bit flip - replace with custom bit injecter
      if (it == Global::pos) {
          //injectBitflip (n, a, x, b);

            cout << " Fault Injecting is occurred here" <<endl ;
            injectBitFlipNotRandom(n , r, p , x , range1 ,  range2 ,  k) ;

      }


      //
      //  Compute the matrix*vector product AP=A*P.
      //

      delete [] ap;
      ap = r8ge_mv ( n, n, a, p );
      
         //
      //  Compute the dot products
      //    PAP = P*AP,
      //    PR  = P*R
      //  Set
      //    ALPHA = PR / PAP.

     pap = r8vec_dot_product ( n, p, ap );
     pr = r8vec_dot_product ( n, p, r );

     rTr = r8vec_dot_product( n , r , r) ;

     if ( pap == 0.0 )
     {
        delete [] ap;
        break;
     }

     alpha = pr / pap;

     newIndicator = alpha * rTr ;

      //pr = (rk)^T(rk)
      //pap = (pk)^T A (pk)  A is Symetric positive definite (SPD)

      //
      //  Set
      //    X = X + ALPHA * P
      //    R = R - ALPHA * AP.
      //

      for ( i = 0; i < n; i++ )
      {
        x[i] = x[i] + alpha * p[i];
      }
      for ( i = 0; i < n; i++ )
      {
        r[i] = r[i] - alpha * ap[i];
      }

      //
      //  Compute the vector dot product
      //    RAP = R*AP
      //  Set
      //    BETA = - RAP / PAP.
      //
      rap = r8vec_dot_product ( n, r, ap );

      beta = - rap / pap;
      //
      //  Update the perturbation vector
      //    P = R + BETA * P.
      //
      for ( i = 0; i < n; i++ )
      {
          p[i] = r[i] + beta * p[i];
      }

      //Error Detection part

      
      cout << " new indicator at i "<< it << " NewIndicator= " << newIndicator <<endl; 

      //getIndicator( newIndicator ) ;

      //Global::previousValueOfIndicator = newIndicator ;

      if( isDetected(newIndicator) && it != 1)//, detector))
      {
     
        cerr << " Bit error detected, terminating application" << endl;
        cout << " Bit error detected, terminating application" <<endl ;
        cout << "*******************************************" << endl;

        //cout << " New Indicator Convergent Value -x^T*b = " << getFunctionIndicatorCunverge ( n , x ,b ) << endl ;

        //int& successful = Global::successfulRate ;

        if( it - Global::pos <=10 && it - Global::pos >= 0)
        {
          //successful ++ ;
          Global::successfulRate ++ ;
        }

        //exit(-1);

        //delete [] p;
        //delete [] r;
       
        //return ;

      } 
      else 
      {
        //recordIndicator(curIndicatorValue);
        getIndicator(newIndicator) ;// ,detector) ;
      }

  }

   delete [] p;
   delete [] r;

   return;



}


void r8ge_bcg_emin(int n, double a[], double b[], double x[] , int range1 , int range2 , int k )
{
    double alpha;
    double *ap;

    double *s ;
    double *s_prime ;


    double beta ;
    int i;
    int it;

    double *p;
    double *p_prime;


    double pap;
    double pr;


    double *r; //It takes it as parameter
    double *r_prime;


    double rap;
    double rr;

    double curIndicatorValue =0;
    double prevIndicatorValue =0;

    double prevRes =0 ;
    double curRes=0;

    cout << " Emin new bi-cg method is started " << endl ;

    //  Initialize
    //    AP = A * x,
    //    R  = b - A * x,
    //    P  = b - A * x.
    //
    ap = r8ge_mv ( n, n, a, x );
    r = new double[n];

    //r_0 = b- Ax0

    for ( i = 0; i < n; i++ )
    {
      r[i] = b[i] - ap[i];
    }


    //Choose ro_prime = r_0
    r_prime = new double[n];
    for ( i = 0; i < n; i++ )
    {
      r_prime[i] = b[i] - ap[i];
    }


    //SET p_prime_0 = p_0 = 0 and beta = 0 ;

    p = new double[n];
    for ( i = 0; i < n; i++ )
    {
      p[i] = 0 ;
    }


    p_prime = new double[n];
    for ( i = 0; i < n; i++ )
    {
      p_prime[i] = 0 ;
    }

    beta = 0;

    s = r8ge_mv(n , n , a, x) ;
    s_prime = r8ge_mv_TransposeA( n, n , a , p_prime) ;


    for ( it = 0; it <=n ; it++)
    {
     
        if (it == Global::pos) 
        {
          injectBitFlipNotRandom(n , r, p , x ,range1, range2, k) ;
          cout << " Bit Flip injection is done " << endl ;
        }

        for ( i = 0; i < n; i++ )
        {
          p[i] = r[i] + beta * p[i];
        }

        for ( i = 0; i < n; i++ )
        {
          p_prime[i] = r_prime[i] + beta * p_prime[i] ;
        }

        delete [] ap;
        ap = r8ge_mv ( n, n, a, p );


        delete [] s;
        s = r8ge_mv(n , n , a, p) ;

        delete [] s_prime ;
        s_prime = r8ge_mv_TransposeA( n, n , a , p_prime) ;


        //Alpha = (rn_prime^t * rn) / ( p_prime^t * sn )

        alpha = r8vec_dot_product(n, r_prime , r) / r8vec_dot_product(n, p_prime, s) ;


        // x = x + alpha* p

        for ( i = 0; i < n; i++ )
        {
          x[i] = x[i] + alpha * p[i];
        }

        rr = r8vec_dot_product(n, r_prime , r) ;

        for ( i = 0; i < n; i++ )
        {
           r[i] = r[i] - alpha * s[i];
        }


        for ( i = 0; i < n; i++ )
        {
           r_prime[i] = r_prime[i] - alpha * s_prime[i];
        }


        beta =  r8vec_dot_product(n, r_prime , r) / rr ;


        //Error Detection

        prevIndicatorValue = curIndicatorValue;
        prevRes= curRes ;

        curRes= r8vec_norm(n , r ) ;
        cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;



        curIndicatorValue = getCurIndicatorValue( x, r , b, n) ;

        cout << "IndicatorFunction Value at i = " << it << endl;
        cout << "CurIndicatorValue = " << curIndicatorValue  <<endl ;





        if( isnan (curIndicatorValue ) && it != 0)//, detector))
        {

          cerr << "Bit error detected curIndicator is nan, terminating application" << endl;
          cout << "Bit error detected curIndicator is nan, terminating application" << endl;

        
          cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curIndicatorValue << endl;

         
          //int& successful = Global::successfulRate ;

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
            //successful ++ ;
            Global::successfulRate ++ ;
          }


          
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
          
          
        } 
         else if(isinf(abs(curIndicatorValue)))
         {
          cerr << "Bit error detected by proposed indicator is inf, terminating application" << endl;
          cout << "Bit error detected by proposed indicator is inf, terminating application" << endl;

         
          cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curProposedIndicator << endl;

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

            
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
          

        }
        else if(isinf(abs(curRes)))
         {
          cerr << "Bit error detected by residual is inf, terminating application" << endl;
          cout << "Bit error detected by residual is inf, terminating application" << endl;

          cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;
         

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

            
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
          

        }
        else if( isnan(curRes) && it !=0 )
        {
              cerr << "Bit error detected residual is nan, terminating application" << endl;
              cout << "Bit error detected residual is nan, terminating application" << endl;

              cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;
          

              if( it - Global::pos <=10 && it - Global::pos >= 0)
              {
               //successful ++ ;
                  Global::successfulRate ++ ;
              }

          
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
          

        }
        else if( (abs(curIndicatorValue) - abs(prevIndicatorValue)) > abs(prevIndicatorValue)*1e+10  && it !=0)
        {
          cerr << "Bit error detected by proposed indicator, terminating application" << endl;
          cout << "Bit error detected by proposed indicator, terminating application" << endl;

          cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curIndicatorValue << endl;

          

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

          
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
          

        }
        else if(  (abs(curRes) - abs(prevRes)) > abs(prevRes)*1e+10  && it !=0)
        {


          cerr << "Bit error detected by residual , terminating application" << endl;
          cout << "Bit error detected by residual , terminating application" << endl;

          cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;



          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

          
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
       
          
        }






    }






delete [] p;
delete [] p_prime;

delete [] r;
delete [] r_prime;

delete [] s;
delete [] s_prime;

return;





}



void r8ge_bcr_emin(int n, double a[], double b[], double x[] , int range1 , int range2 , int k )
{
    double alpha;
    double *ap;

    double *s ;
    double *s_prime ;

    double *t ;

    double beta ;
    int i;
    int it;

    double *p;
    double *p_prime;


    double pap;
    double pr;


    double *r; //It takes it as parameter
    double *r_prime;


    double rap;
    double rr;

    double curIndicatorValue ;

    double preResidual=0;
    double curRes = 0;

    double curProposedIndicator =0;
    double prevProposedIndicator = 0;

    cout << " Emin new bi-cg method is started " << endl ;

    //  Initialize
    //    AP = A * x,
    //    R  = b - A * x,
    //    P  = b - A * x.
    //
    ap = r8ge_mv ( n, n, a, x );
    r = new double[n];

    //r_0 = b- Ax0

    for ( i = 0; i < n; i++ )
    {
      r[i] = b[i] - ap[i];
    }


    //Choose ro_prime = r_0
    r_prime = new double[n];
    for ( i = 0; i < n; i++ )
    {
      r_prime[i] = b[i] - ap[i];
    }


    t = new double[n] ;
    for ( i = 0; i < n; ++i)
    {
        t[i] = 0;
    }

    //SET p_prime_0 = p_0 = 0 and beta = 0 ;

    p = new double[n];
    for ( i = 0; i < n; i++ )
    {
      p[i] = 0 ;
    }


    p_prime = new double[n];
    for ( i = 0; i < n; i++ )
    {
      p_prime[i] = 0 ;
    }

    beta = 0;

    s = r8ge_mv(n , n , a, x) ;
    s_prime = r8ge_mv_TransposeA( n, n , a , p_prime) ;


    for ( it = 0; it <=n ; it++)
    {
     
        if (it == Global::pos) 
        {
          injectBitFlipNotRandom(n , r, p , x ,range1, range2, k) ;
          cout << " Bit Flip injection is done " << endl ;
        }

        for ( i = 0; i < n; i++ )
        {
          p[i] = r[i] + beta * p[i];
        }

        for ( i = 0; i < n; i++ )
        {
          p_prime[i] = r_prime[i] + beta * p_prime[i] ;
        }

        delete [] ap;
        ap = r8ge_mv ( n, n, a, p );


        delete [] s;
        s = r8ge_mv(n , n , a, p) ;

        delete [] s_prime ;
        s_prime = r8ge_mv_TransposeA( n, n , a , p_prime) ;


        delete [] t ;
        t = r8ge_mv(n , n , a, r) ;



        //Alpha = (rn_prime^t * rn) / ( p_prime^t * sn )

        alpha = r8vec_dot_product(n, r_prime , t) / r8vec_dot_product(n, s_prime, s) ;


        // x = x + alpha* p

        for ( i = 0; i < n; i++ )
        {
          x[i] = x[i] + alpha * p[i];
        }

        rr = r8vec_dot_product(n, r_prime , r) ;

        for ( i = 0; i < n; i++ )
        {
           r[i] = r[i] - alpha * s[i];
        }


        for ( i = 0; i < n; i++ )
        {
           r_prime[i] = r_prime[i] - alpha * s_prime[i];
        }


        t = r8ge_mv(n , n , a, r) ;

        beta =  r8vec_dot_product(n, r_prime , t) / rr ;


          //Error Detection

        preResidual = curRes ;
        prevProposedIndicator= curProposedIndicator ;

        curRes= r8vec_norm(n , r ) ;
        cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;

        double curProposedIndicator = getCurIndicatorValue( x, r , b, n) ;
        cout << "IndicatorFunction Value at i = " << it <<" CurIndicatir = "<< curProposedIndicator << endl;
            



        if( curRes - preResidual > 1 && it != 0)//, detector))
        {

          cerr << "Bit error detected by Residual, terminating application" << endl;
          cout << "Bit error detected by Residual, terminating application" << endl;

          cout << "Norm of residual at current  ="<< it <<" ||Ax-b||_n = " <<  curRes << endl;
          cout << "Norm of residual at previous ="<< it <<" ||Ax-b||_{n-1} = " <<  preResidual << endl;

          if( it - Global::pos <=10 && it - Global::pos >= 0)
          {
               //successful ++ ;
                  Global::successfulRate ++ ;
          }

          /*
          
            delete [] p;
            delete [] p_prime;

            delete [] r;
            delete [] r_prime;

            delete [] s;
            delete [] s_prime;

            return ;
          */
          
        } 
        else if(isnan(curRes))
        {

            cerr << "Bit error detected residual is nan, terminating application" << endl;
            cout << "Bit error detected residual is nan, terminating application" << endl;

            cout << "Norm of residual at it "<< it <<" ||Ax-b|| = " <<  curRes << endl;
           

            if( it - Global::pos <=10 && it - Global::pos >= 0)
            {
                   //successful ++ ;
                      Global::successfulRate ++ ;
            }

             /*
              delete [] p;
              delete [] p_prime;

              delete [] r;
              delete [] r_prime;

              delete [] s;
              delete [] s_prime;

              return ;

            */

         

        }

    }




delete [] p;
delete [] p_prime;

delete [] r;
delete [] r_prime;

delete [] s;
delete [] s_prime;

return;



}








//****************************************************************************80

double *r8ge_dif2 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8GE_DIF2 returns the DIF2 matrix in R8GE format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2000
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double R8GE_DIF2[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( j == i - 1 )
      {
        a[i+j*m] = -1.0;
      }
      else if ( j == i )
      {
        a[i*j*m] = 2.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*m] = -1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double *r8ge_mv ( int m, int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8GE_MV multiplies an R8GE matrix by an R8VEC.
//
//  Discussion:
//
//    The R8GE storage format is used for a general M by N matrix.  A storage 
//    space is made for each entry.  The two dimensional logical
//    array can be thought of as a vector of M*N entries, starting with
//    the M entries in the column 1, then the M entries in column 2
//    and so on.  Considered as a vector, the entry A(I,J) is then stored
//    in vector location I+(J-1)*M.
//
//    R8GE storage is used by LINPACK and LAPACK.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R8GE_MV[M], the product A * x.
//
{
  int i;
  int j;
  double *b;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
    for ( j = 0; j < n; j++ )
    {
      b[i] = b[i] + a[i+j*m] * x[j];
    }
  }

  return b;
}



double *r8ge_mv_TransposeA ( int m, int n, double a[], double x[] )
{

  int i;
  int j;
  double *b;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
    for ( j = 0; j < n; j++ )
    {
      b[i] = b[i] + a[j+i*m] * x[j];
    }
  }

  return b;

}








//****************************************************************************80

double *r8ge_res ( int m, int n, double a[], double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8GE_RES computes the residual R = B-A*X for R8GE matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R8GE_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r8ge_mv ( m, n, a, x );
  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r8mat_copy ( int m, int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_COPY copies one R8MAT to another.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A1[M*N], the matrix to be copied.
//
//    Output, double A2[M*N], the copy of A1.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }
  return;
}
//****************************************************************************80

void r8mat_house_axh ( int n, double a[], double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_HOUSE_AXH computes A*H where H is a compact Householder matrix.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The Householder matrix H(V) is defined by
//
//      H(V) = I - 2 * v * v' / ( v' * v )
//
//    This routine is not particularly efficient.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    07 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of A.
//
//    Input/output, double A[N*N], on input, the matrix to be postmultiplied.
//    On output, A has been replaced by A*H.
//
//    Input, double V[N], a vector defining a Householder matrix.
//
{
  double *ah;
  int i;
  int j;
  int k;
  double v_normsq;

  v_normsq = 0.0;
  for ( i = 0; i < n; i++ )
  {
    v_normsq = v_normsq + v[i] * v[i];
  }
//
//  Compute A*H' = A*H
//
  ah = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      ah[i+j*n] = a[i+j*n];
      for ( k = 0; k < n; k++ )
      {
        ah[i+j*n] = ah[i+j*n] - 2.0 * a[i+k*n] * v[k] * v[j] / v_normsq;
      }
    }
  }
//
//  Copy A = AH;
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = ah[i+j*n];
    }
  }
  delete [] ah;

  return;
}
//****************************************************************************80

double *r8mat_identity_new ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IDENTITY_NEW returns an identity matrix.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of A.
//
//    Output, double R8MAT_IDENTITY_NEW[N*N], the N by N identity matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[n*n];

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[k] = 1.0;
      }
      else
      {
        a[k] = 0.0;
      }
      k = k + 1;
    }
  }

  return a;
}
//****************************************************************************80

void r8mat_print ( int m, int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT prints an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    Entry A(I,J) is stored as A[I+J*M]
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in A.
//
//    Input, int N, the number of columns in A.
//
//    Input, double A[M*N], the M by N matrix.
//
//    Input, string TITLE, a title.
//
{
  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
//****************************************************************************80

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_SOME prints some of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, designate the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title.
//
{
# define INCX 5

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  cout << "\n";
  cout << title << "\n";

  if ( m <= 0 || n <= 0 )
  {
    cout << "\n";
    cout << "  (None)\n";
    return;
  }
//
//  Print the columns of the matrix, in strips of 5.
//
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    if ( n < j2hi )
    {
      j2hi = n;
    }
    if ( jhi < j2hi )
    {
      j2hi = jhi;
    }
    cout << "\n";
//
//  For each column J in the current range...
//
//  Write the header.
//
    cout << "  Col:    ";
    for ( j = j2lo; j <= j2hi; j++ )
    {
      cout << setw(7) << j - 1 << "       ";
    }
    cout << "\n";
    cout << "  Row\n";
    cout << "\n";
//
//  Determine the range of the rows in this strip.
//
    if ( 1 < ilo )
    {
      i2lo = ilo;
    }
    else
    {
      i2lo = 1;
    }
    if ( ihi < m )
    {
      i2hi = ihi;
    }
    else
    {
      i2hi = m;
    }

    for ( i = i2lo; i <= i2hi; i++ )
    {
//
//  Print out (up to) 5 entries in row I, that lie in the current strip.
//
      cout << setw(5) << i - 1 << ": ";
      for ( j = j2lo; j <= j2hi; j++ )
      {
        cout << setw(12) << a[i-1+(j-1)*m] << "  ";
      }
      cout << "\n";
    }
  }

  return;
# undef INCX
}
//****************************************************************************80

double *r8mat_zero_new ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_ZERO_NEW returns a new zeroed R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Output, double R8MAT_ZERO_NEW[M*N], the new zeroed matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }
  return a;
}
//****************************************************************************80

void r8pbu_cg ( int n, int mu, double a[], double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8PBU_CG uses the conjugate gradient method on a R8PBU system.
//
//  Discussion:
//
//    The R8PBU storage format is used for a symmetric positive definite band matrix.
//
//    To save storage, only the diagonal and upper triangle of A is stored,
//    in a compact diagonal format that preserves columns.
//
//    The diagonal is stored in row MU+1 of the array.
//    The first superdiagonal in row MU, columns 2 through N.
//    The second superdiagonal in row MU-1, columns 3 through N.
//    The MU-th superdiagonal in row 1, columns MU+1 through N.
//
//    The matrix A must be a positive definite symmetric band matrix.
//
//    The method is designed to reach the solution after N computational
//    steps.  However, roundoff may introduce unacceptably large errors for
//    some problems.  In such a case, calling the routine again, using
//    the computed solution as the new starting estimate, should improve
//    the results.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 February 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, int MU, the number of superdiagonals.
//    MU must be at least 0, and no more than N-1.
//
//    Input, double A[(MU+1)*N], the R8PBU matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r8pbu_mv ( n, n, mu, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//
  for ( it = 1; it <= n; it++ )
  {
//
//  Compute the matrix*vector product AP=A*P.
//
    delete [] ap;
    ap = r8pbu_mv ( n, n, mu, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = 0.0;
    for ( i = 0; i < n; i++ )
    {
      pap = pap + p[i] * ap[i];
    }

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    pr = 0.0;
    for ( i = 0; i < n; i++ )
    {
      pr = pr + p[i] * r[i];
    }
    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }

    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = 0.0;
    for ( i = 0; i < n; i++ )
    {
      rap = rap + r[i] * ap[i];
    }
    beta = - rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }

  }

  delete [] p;
  delete [] r;

  return;
}
//****************************************************************************80

double *r8pbu_dif2 ( int m, int n, int mu )

//****************************************************************************80
//
//  Purpose:
//
//    R8PBU_DIF2 returns the DIF2 matrix in R8PBU format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I.
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int MU, the number of superdiagonals.
//    MU must be at least 0, and no more than N-1.
//
//    Output, double R8PBU_DIF2[(MU+1)*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[(mu+1)*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < mu + 1; i++ )
    {
      a[i+j*(mu+1)] = 0.0;
    }
  }
  for ( j = 1; j < n; j++ )
  {
    i = mu - 1;
    a[i+j*(mu+1)] = -1.0;
  }
  for ( j = 0; j < n; j++ )
  {
    i = mu;
    a[i+j*(mu+1)] = 2.0;
  }
 
  return a;
}
//****************************************************************************80

double *r8pbu_mv ( int m, int n, int mu, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8PBU_MV multiplies a R8PBU matrix times a vector.
//
//  Discussion:
//
//    The R8PBU storage format is used for a symmetric positive definite band matrix.
//
//    To save storage, only the diagonal and upper triangle of A is stored,
//    in a compact diagonal format that preserves columns.
//
//    The diagonal is stored in row MU+1 of the array.
//    The first superdiagonal in row MU, columns 2 through N.
//    The second superdiagonal in row MU-1, columns 3 through N.
//    The MU-th superdiagonal in row 1, columns MU+1 through N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 February 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int MU, the number of superdiagonals in the matrix.
//    MU must be at least 0 and no more than N-1.
//
//    Input, double A[(MU+1)*N], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R8PBU_MV[M], the result vector A * x.
//
{
  double *b;
  int i;
  int ieqn;
  int j;

  b = new double[m];
//
//  Multiply X by the diagonal of the matrix.
//
  for ( j = 0; j < n; j++ )
  {
    b[j] = a[mu+j*(mu+1)] * x[j];
  }
//
//  Multiply X by the superdiagonals of the matrix.
//
  for ( i = mu; 1 <= i; i-- )
  {
    for ( j = mu+2-i; j <= n; j++ )
    {
      ieqn = i + j - mu - 1;
      b[ieqn-1] = b[ieqn-1] + a[i-1+(j-1)*(mu+1)] * x[j-1];
      b[j-1] = b[j-1] + a[i-1+(j-1)*(mu+1)] * x[ieqn-1];
    }
  }

  return b;
}
//****************************************************************************80

double *r8pbu_res ( int m, int n, int mu, double a[], double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8PBU_RES computes the residual R = B-A*X for R8PBU matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, int MU, the number of superdiagonals in the matrix.
//    MU must be at least 0 and no more than N-1.
//
//    Input, double A[(MU+1)*N], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R8PBU_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r8pbu_mv ( m, n, mu, a, x );
  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r8sd_cg ( int n, int ndiag, int offset[], double a[], double b[], 
  double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SD_CG uses the conjugate gradient method on a R8SD linear system.
//
//  Discussion:
//
//    The R8SD storage format is used for symmetric matrices whose only nonzero entries
//    occur along a few diagonals, but for which these diagonals are not all
//    close enough to the main diagonal for band storage to be efficient.
//
//    In that case, we assign the main diagonal the offset value 0, and 
//    each successive superdiagonal gets an offset value 1 higher, until
//    the highest superdiagonal (the A(1,N) entry) is assigned the offset N-1.
//
//    Assuming there are NDIAG nonzero diagonals (ignoring subdiagonals!),
//    we then create an array B that has N rows and NDIAG columns, and simply
//    "collapse" the matrix A to the left:
//
//    For the conjugate gradient method to be applicable, the matrix A must 
//    be a positive definite symmetric matrix.
//
//    The method is designed to reach the solution to the linear system
//      A * x = b
//    after N computational steps.  However, roundoff may introduce
//    unacceptably large errors for some problems.  In such a case,
//    calling the routine a second time, using the current solution estimate
//    as the new starting guess, should result in improved results.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 February 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, int NDIAG, the number of diagonals that are stored.
//    NDIAG must be at least 1 and no more than N.
//
//    Input, int OFFSET[NDIAG], the offsets for the diagonal storage.
//
//    Input, double A[N*NDIAG], the matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution, which may be 0.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r8sd_mv ( n, n, ndiag, offset, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//

  for ( it = 1; it < n; it++ )
  {
//
//  Compute the matrix*vector product AP = A*P.
//
    delete [] ap;
    ap = r8sd_mv ( n, n, ndiag, offset, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = r8vec_dot_product ( n, p, ap );

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    pr = r8vec_dot_product ( n, p, r );

    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = r8vec_dot_product ( n, r, ap );

    beta = -rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }
  }

  delete [] p;
  delete [] r;

  return;
}
//****************************************************************************80

double *r8sd_dif2 ( int m, int n, int ndiag, int offset[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SD_DIF2 returns the DIF2 matrix in R8SD format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I.
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int NDIAG, the number of diagonals available for storage.
//
//    Input, int OFFSET[NDIAG], the indices of the diagonals.  It is
//    presumed that OFFSET[0] = 0 and OFFSET[1] = 1.
//
//    Output, double R8SD_DIF2[N*NDIAG], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*ndiag];

  for ( j = 0; j < ndiag; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    j = 0;
    a[i+j*ndiag] = 2.0;
  }
  for ( i = 0; i < n - 1; i++ )
  {
    j = 1;
    a[i+j*ndiag] = -1.0;
  }
 
  return a;
}
//****************************************************************************80

double *r8sd_mv ( int m, int n, int ndiag, int offset[], double a[], 
  double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SD_MV multiplies a R8SD matrix times a vector.
//
//  Discussion:
//
//    The R8SD storage format is used for symmetric matrices whose only nonzero entries
//    occur along a few diagonals, but for which these diagonals are not all
//    close enough to the main diagonal for band storage to be efficient.
//
//    In that case, we assign the main diagonal the offset value 0, and 
//    each successive superdiagonal gets an offset value 1 higher, until
//    the highest superdiagonal (the A(1,N) entry) is assigned the offset N-1.
//
//    Assuming there are NDIAG nonzero diagonals (ignoring subdiagonals!),
//    we then create an array B that has N rows and NDIAG columns, and simply
//    "collapse" the matrix A to the left.
//
//  Example:
//
//    The "offset" value is printed above each column.
//
//    Original matrix               New Matrix
//
//       0   1   2   3   4   5       0   1   3   5
//
//      11  12   0  14   0  16      11  12  14  16
//      21  22  23   0  25   0      22  23  25  --
//       0  32  33  34   0  36      33  34  36  --
//      41   0  43  44  45   0      44  45  --  --
//       0  52   0  54  55  56      55  56  --  --
//      61   0  63   0  65  66      66  --  --  --
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 February 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int NDIAG, the number of diagonals that are stored.
//    NDIAG must be at least 1 and no more than N.
//
//    Input, int OFFSET[NDIAG], the offsets for the diagonal storage.
//
//    Input, double A[N*NDIAG], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R8SD_MV[N], the product A * x.
//
{
  double *b;
  int i;
  int j;
  int jdiag;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }

  for ( i = 0; i < n; i++ )
  {
    for ( jdiag = 0; jdiag < ndiag; jdiag++ )
    {
      j = i + offset[jdiag];
      if ( 0 <= j && j < n )
      {
        b[i] = b[i] + a[i+jdiag*n] * x[j];
        if ( offset[jdiag] != 0 )
        {
          b[j] = b[j] + a[i+jdiag*n] * x[i];
        }
      }
    }
  }

  return b;
}
//****************************************************************************80

double *r8sd_res ( int m, int n, int ndiag, int offset[], double a[], 
  double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SD_RES computes the residual R = B-A*X for R8SD matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, int NDIAG, the number of diagonals that are stored.
//    NDIAG must be at least 1 and no more than N.
//
//    Input, int OFFSET[NDIAG], the offsets for the diagonal storage.
//
//    Input, double A[N*NDIAG], the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R8SD_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r8sd_mv ( m, n, ndiag, offset, a, x );

  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r8sp_cg ( int n, int nz_num, int row[], int col[], double a[], 
  double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SP_CG uses the conjugate gradient method on a R8SP linear system.
//
//  Discussion:
//
//    The R8SP storage format stores the row, column and value of each nonzero
//
//    It is possible that a pair of indices (I,J) may occur more than
//    once.  Presumably, in this case, the intent is that the actual value
//    of A(I,J) is the sum of all such entries.  This is not a good thing
//    to do, but I seem to have come across this in MATLAB.
//
//    The R8SP format is used by CSPARSE ("sparse triplet"), DLAP/SLAP
//    (nonsymmetric case), by MATLAB, and by SPARSEKIT ("COO" format).
//
//    For the conjugate gradient method to be applicable, the matrix A must 
//    be a positive definite symmetric matrix.
//
//    The method is designed to reach the solution to the linear system
//      A * x = b
//    after N computational steps.  However, roundoff may introduce
//    unacceptably large errors for some problems.  In such a case,
//    calling the routine a second time, using the current solution estimate
//    as the new starting guess, should result in improved results.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Frank Beckman,
//    The Solution of Linear Equations by the Conjugate Gradient Method,
//    in Mathematical Methods for Digital Computers,
//    edited by John Ralston, Herbert Wilf,
//    Wiley, 1967,
//    ISBN: 0471706892,
//    LC: QA76.5.R3.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, int NZ_NUM, the number of nonzero elements in the matrix.
//
//    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
//    of the nonzero elements.
//
//    Input, double A[NZ_NUM], the nonzero elements of the matrix.
//
//    Input, double B[N], the right hand side vector.
//
//    Input/output, double X[N].
//    On input, an estimate for the solution, which may be 0.
//    On output, the approximate solution vector.
//
{
  double alpha;
  double *ap;
  double beta;
  int i;
  int it;
  double *p;
  double pap;
  double pr;
  double *r;
  double rap;
//
//  Initialize
//    AP = A * x,
//    R  = b - A * x,
//    P  = b - A * x.
//
  ap = r8sp_mv ( n, n, nz_num, row, col, a, x );

  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    r[i] = b[i] - ap[i];
  }

  p = new double[n];
  for ( i = 0; i < n; i++ )
  {
    p[i] = b[i] - ap[i];
  }
//
//  Do the N steps of the conjugate gradient method.
//
  for ( it = 1; it <= n; it++ )
  {
//
//  Compute the matrix*vector product AP = A*P.
//
    delete [] ap;
    ap = r8sp_mv ( n, n, nz_num, row, col, a, p );
//
//  Compute the dot products
//    PAP = P*AP,
//    PR  = P*R
//  Set
//    ALPHA = PR / PAP.
//
    pap = r8vec_dot_product ( n, p, ap );

    if ( pap == 0.0 )
    {
      delete [] ap;
      break;
    }

    pr = r8vec_dot_product ( n, p, r );

    alpha = pr / pap;
//
//  Set
//    X = X + ALPHA * P
//    R = R - ALPHA * AP.
//
    for ( i = 0; i < n; i++ )
    {
      x[i] = x[i] + alpha * p[i];
    }
    for ( i = 0; i < n; i++ )
    {
      r[i] = r[i] - alpha * ap[i];
    }
//
//  Compute the vector dot product
//    RAP = R*AP
//  Set
//    BETA = - RAP / PAP.
//
    rap = r8vec_dot_product ( n, r, ap );

    beta = -rap / pap;
//
//  Update the perturbation vector
//    P = R + BETA * P.
//
    for ( i = 0; i < n; i++ )
    {
      p[i] = r[i] + beta * p[i];
    }
  }

  delete [] p;
  delete [] r;

  return;
}
//****************************************************************************80

double *r8sp_dif2 ( int m, int n, int nz_num, int row[], int col[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SP_DIF2 returns the DIF2 matrix in R8SP format.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I.
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int NZ_NUM, the number of nonzeros.
//
//    Input, int ROW[NZ_NUM], COL[NZ_NUM], space in which the rows and columns
//    of nonzero entries will be stored.
//
//    Output, double R8SP_DIF2[NZ_NUM], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  int mn;

  a = new double[nz_num];

  for ( k = 0; k < nz_num; k++ )
  {
    row[k] = 0;
    col[k] = 0;
    a[k] = 0.0;
  }

  mn = i4_min ( m, n );

  k = 0;
  for ( i = 0; i < mn; i++ )
  {
    if ( 0 < i )
    {
      row[k] = i;
      col[k] = i - 1;
      a[k] = -1.0;
      k = k + 1;
    }

    row[k] = i;
    col[k] = i;
    a[k] = 2.0;
    k = k + 1;

    if ( i < n - 1 )
    {
      row[k] = i;
      col[k] = i + 1;
      a[k] = -1.0;
      k = k + 1;
    }
  }

  return a;
}
//****************************************************************************80

double *r8sp_mv ( int m, int n, int nz_num, int row[], int col[], 
  double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SP_MV multiplies a R8SP matrix times a vector.
//
//  Discussion:
//
//    The R8SP storage format stores the row, column and value of each nonzero
//
//    It is possible that a pair of indices (I,J) may occur more than
//    once.  Presumably, in this case, the intent is that the actual value
//    of A(I,J) is the sum of all such entries.  This is not a good thing
//    to do, but I seem to have come across this in MATLAB.
//
//    The R8SP format is used by CSPARSE ("sparse triplet"), DLAP/SLAP
//    (nonsymmetric case), by MATLAB, and by SPARSEKIT ("COO" format).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    17 February 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns of the matrix.
//
//    Input, int NZ_NUM, the number of nonzero elements in the matrix.
//
//    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices
//    of the nonzero elements.
//
//    Input, double A[NZ_NUM], the nonzero elements of the matrix.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double R8SP_MV[M], the product vector A*X.
//
{
  double *b;
  int i;
  int j;
  int k;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }

  for ( k = 0; k < nz_num; k++ )
  {
    i = row[k];
    j = col[k];
    b[i] = b[i] + a[k] * x[j];
  }

  return b;
}
//****************************************************************************80

double *r8sp_res ( int m, int n, int nz_num, int row[], int col[], double a[], 
  double x[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8SP_RES computes the residual R = B-A*X for R8SP matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, int NZ_NUM, the number of nonzeros.
//
//    Input, int ROW[NZ_NUM], COL[NZ_NUM], the row and column indices.
//
//    Input, double A[NZ_NUM], the values.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Input, double B[M], the desired result A * x.
//
//    Output, double R8SP_RES[M], the residual R = B - A * X.
//
{
  int i;
  double *r;

  r = r8sp_mv ( m, n, nz_num, row, col, a, x );

  for ( i = 0; i < m; i++ )
  {
    r[i] = b[i] - r[i];
  }

  return r;
}
//****************************************************************************80

void r8vec_copy ( int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_COPY copies an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 July 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, double A1[N], the vector to be copied.
//
//    Output, double A2[N], the copy of A1.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return;
}
//****************************************************************************80

double r8vec_dot_product ( int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_DOT_PRODUCT computes the dot product of a pair of R8VEC's.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 July 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, double A1[N], A2[N], the two vectors to be considered.
//
//    Output, double R8VEC_DOT_PRODUCT, the dot product of the vectors.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a1[i] * a2[i];
  }
  return value;
}
//****************************************************************************80

double *r8vec_house_column ( int n, double a[], int k )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_HOUSE_COLUMN defines a Householder premultiplier that "packs" a column.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    The routine returns a vector V that defines a Householder
//    premultiplier matrix H(V) that zeros out the subdiagonal entries of
//    column K of the matrix A.
//
//       H(V) = I - 2 * v * v'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix A.
//
//    Input, double A[N], column K of the matrix A.
//
//    Input, int K, the column of the matrix to be modified.
//
//    Output, double R8VEC_HOUSE_COLUMN[N], a vector of unit L2 norm which
//    defines an orthogonal Householder premultiplier matrix H with the property
//    that the K-th column of H*A is zero below the diagonal.
//
{
  int i;
  double s;
  double *v;

  v = r8vec_zero_new ( n );

  if ( k < 1 || n <= k )
  {
    return v;
  }

  s = r8vec_norm ( n+1-k, a+k-1 );

  if ( s == 0.0 )
  {
    return v;
  }

  v[k-1] = a[k-1] + fabs ( s ) * r8_sign ( a[k-1] );

  r8vec_copy ( n-k, a+k, v+k );

  s = r8vec_norm ( n-k+1, v+k-1 );

  for ( i = k-1; i < n; i++ )
  {
    v[i] = v[i] / s;
  }

  return v;
}
//****************************************************************************80

double r8vec_norm ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_NORM returns the L2 norm of an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    The vector L2 norm is defined as:
//
//      R8VEC_NORM = sqrt ( sum ( 1 <= I <= N ) A(I)^2 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 March 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in A.
//
//    Input, double A[N], the vector whose L2 norm is desired.
//
//    Output, double R8VEC_NORM, the L2 norm of A.
//
{
  int i;
  double v;

  v = 0.0;

  for ( i = 0; i < n; i++ )
  {
    v = v + a[i] * a[i];
  }
  v = sqrt ( v );

  return v;
}
//****************************************************************************80

double r8vec_norm_affine ( int n, double v0[], double v1[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_NORM_AFFINE returns the affine L2 norm of an R8VEC.
//
//  Discussion:
//
//    The affine vector L2 norm is defined as:
//
//      R8VEC_NORM_AFFINE(V0,V1)
//        = sqrt ( sum ( 1 <= I <= N ) ( V1(I) - V0(I) )^2 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 October 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the dimension of the vectors.
//
//    Input, double V0[N], the base vector.
//
//    Input, double V1[N], the vector.
//
//    Output, double R8VEC_NORM_AFFINE, the affine L2 norm.
//
{
  int i;
  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )
  {
    value = value + ( v1[i] - v0[i] ) * ( v1[i] - v0[i] );
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

void r8vec_print ( int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT prints an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(8)  << i
         << ": " << setw(14) << a[i]  << "\n";
  }

  return;
}
//****************************************************************************80

double *r8vec_uniform_01_new ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW returns a new unit pseudorandom R8VEC.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
//    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
//
{
  int i;
  const int i4_huge = 2147483647;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_01_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[n];

  for ( i = 0; i < n; i++ )
  {
    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + i4_huge;
    }

    r[i] = ( double ) ( seed ) * 4.656612875E-10;
  }

  return r;
}
//****************************************************************************80

double *r8vec_zero_new ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_ZERO_NEW creates and zeroes an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Output, double R8VEC_ZERO_NEW[N], a vector of zeroes.
//
{
  double *a;
  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return a;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  size_t len;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}



///Implemented by Jiaqi  



double getResidual ( int m, int n, double a[], double x[], double b[] ) 

{
  double* res = r8ge_res ( n, n, a, x, b );
  double res_norm = r8vec_norm ( n, res );
  delete [] res;
  return res_norm;

}

void injectBitflip ( int n, double a[], double x[], double b[] )
{

  //Written by Jiaqi

  double ** badpointer = new double* [3];

  badpointer[0] = a;
  badpointer[1] = b;
  badpointer[2] = x;
  srand (time(NULL));
  int dim1 = rand() % 3;
  int dim2 = rand() % n;

  cout << "flipping: " << dim1 << "/" << dim2 << endl;

  BitFlip::randomFlip(&badpointer[dim1][dim2]);
  delete [] badpointer;
}

// Note = In this method injection is decided randomly
//
// n in this method refer to number of iteration of CG Algorithm
//
//

// Implemented by Emin

void injectBitFlipNotRandom( int n , double r[] , double p[] , double x[] ,  int range1, int range2 , int k)
{

  //Written By Emin

  double ** badpointer = new double* [3] ;

  badpointer[0] = r ;
  badpointer[1] = p ;
  badpointer[2] = x ;

  srand (time(NULL)) ;

  int dim1 = k ;

  // Emin Question = n  
  

  int dim2 = rand() % n ;

  if(k == 0)
    cout << " flipping in r "<<dim2<< endl ;
  else if (k==1)
  {
    /* code */
    cout<< " flipping in p "<<dim2<<endl ;
  }
  else if (k==2)
  {
    /* code */
    cout<< " flipping in x"<<dim2<<endl ;
  }

  BitFlip::randomFlip(&badpointer[dim1][dim2],  range1 ,  range2) ;

  delete [] badpointer;

}

bool checkSumImpMethod( int n , double a[] ,double x[] , double b[])
{
  double* checkSumOfA ;

  checkSumOfA = new double[n] ;

  double checkSumOfB ;

  for (int i = 0; i < n; ++i)
  {
    /* code */
    checkSumOfB = checkSumOfB + b[i] ;

  }


  for (int i = 0; i < n; ++i)
  {
    /* code */
    for (int j = 0; i < n; ++i)
    {
      /* code */

      checkSumOfA[i] = checkSumOfA[i] + a[i + j*n] ;


    }
  }

  double sumCheck = 0 ;

  for (int i = 0; i < n; ++i)
  {
    /* code */

    sumCheck = sumCheck +  checkSumOfA[i]*x[i] ;

  }

  if ( sumCheck != checkSumOfB )
  {
    /* code */

    delete checkSumOfA ;

    cout<< " Checksum detected an error " <<endl ;

    return true;
  }

  delete checkSumOfA ;
  return false ;
}

void initialCheckSum(int n , double r[] , double p[] , double x[])
{
  double& generalChecksumForR = Global::checkSumForR ;
  double& generalChecksumForP = Global::checkSumForP ;
  double& generalChecksumForX = Global::checkSumForX ;

  for (int i = 0; i < n; ++i)
  {
    /* code */

    generalChecksumForX =  generalChecksumForX + x[i] ;
    generalChecksumForP =  generalChecksumForP + p[i] ;
    generalChecksumForR =  generalChecksumForR + r[i] ;

  }

 return ;

}


bool checkSumMethod(int n , double r[] , double p[] , double x[])
{

  double checksumForR ;
  double checksumForP ;
  double checksumForX ;

  double& generalChecksumForR = Global::checkSumForR ;
  double& generalChecksumForP = Global::checkSumForP ;
  double& generalChecksumForX = Global::checkSumForX ;

  for (int i = 0; i < n; ++i)
  {
    /* code */

    checksumForX =  checksumForX + x[i] ;
    checksumForP =  checksumForP + p[i] ;
    checksumForR =  checksumForR + r[i] ;

  }

  //return true;

  if ( checksumForR != generalChecksumForR)
  {
    /* code */
    cout << " Checksum for R is not same " <<endl ;
    return true ;

  }
  else if ( checksumForP != generalChecksumForP)
  {
    /* code */
    cout << " Checksum for P is not same " <<endl ;
    return true ;
  }
  else if ( checksumForX != generalChecksumForX)
  {
    /* code */
    cout << " Checksum for X is not same " <<endl ;
    return true;
  }

  return false ;


}

bool improveMethodFOrCheckSUm ( int n, double a[] ,  double x[] , double b[] , double curFunct)
{
    double& previous=Global::previousValueOfIndicator ;

    double difference = previous - curFunct ;

    int& becauseImprove = Global::ImproveRate ;
    int& becauseCheckSum = Global::CheckSumImproveRate ;

    //double& gTdifference = Global::globalTotalDifference ;

    //int size = Global::windowSize ;

    //queue<double>& diffs = Global::diffsImprove;


    double diffIndicatorValue = curFunct - previous ;

    cout<<" Difference OF f function from previous f = "<<diffIndicatorValue<<endl; 

    if ( diffIndicatorValue > 0 && diffIndicatorValue >= previous*1e-13*-1 )
    {
      /* code */
      cout<<" Error detected by fn increase"<<endl ;
      return true ;

    }

    previous = curFunct ;

    if( isnan(curFunct))
    {
      cout<<" Error detected by fn = nan"<<endl ;
      return true;

    }
    
   
    if ( checkSumImpMethod( n , a , x ,  b))
    {
        cout<<" Error detected by checksum"<<endl ;
        becauseCheckSum ++ ;
        cout<<" Checksum = "<<becauseCheckSum <<endl ;
        return true ;
    }


    return false ;


}
bool improveMethodWithAlpha(double curFunct, double alpha)
{

  //double& previous = Global::previousValueOfIndicator ;

    double& previous=Global::previousValueOfIndicator ;

    double difference = previous - curFunct ;

    int& becauseImprove = Global::ImproveRate ;

    double& gTdifference = Global::globalTotalDifference ;

    int size = Global::windowSize ;

    queue<double>& diffs = Global::diffsImprove;


    double diffIndicatorValue = curFunct - previous ;

    cout<<" Difference OF f function from previous f = "<<diffIndicatorValue<<endl; 

    if ( diffIndicatorValue > 0 && diffIndicatorValue >= previous*1e-13*-1 )
    {
      /* code */
      cout<<" Error detected by fn increase"<<endl ;
      return true ;

    }
    if( isnan(curFunct))
    {
      cout<<" Error detected by fn = nan"<<endl ;
      return true;

    }

    //This part is just for P

    if ( alpha == 0)
    {
      /* code */
      cout<<" Error detected by Alpha == 0 "<<endl ;
      return true;

    }
    
    previous = curFunct ;

    if ( diffs.size() == 0)
    {
      /* code */
      diffs.push(difference) ;
      gTdifference = gTdifference + difference ;
      cout << " gTdifference = "<<gTdifference<<endl ;
      return false;
    }
    else if ( diffs.size() < size)
    {
      /* code */
      diffs.push(difference) ;
      gTdifference = gTdifference + difference ;
      cout << " gTdifference = "<<gTdifference<<endl ;
      return false ;
    }
    else if( diffs.size() == size)
    {
      double k= gTdifference / size ;
      cout << " k = " <<k<<endl ;

      if ( difference > k )
      {
        /* code */
        cout << " difference   = "<<difference<<endl ;
        cout << " gTdifference = "<<gTdifference<<endl ;
        cout << " Error detected by improve"<<endl ;
        becauseImprove ++ ;
        return true;
      }
      else
      {
        gTdifference = gTdifference - diffs.front() + difference ;
        cout << " gTdifference = "<<gTdifference<<endl ;
        diffs.pop() ;
        return false;

      }


    }

    //delete 
    return false;


}

bool improveMethod(double curFunct)
{



    //double& previous = Global::previousValueOfIndicator ;

    double& previous=Global::previousValueOfIndicator ;

    double difference = previous - curFunct ;

    int& becauseImprove = Global::ImproveRate ;

    double& gTdifference = Global::globalTotalDifference ;

    int size = Global::windowSize ;

    queue<double>& diffs = Global::diffsImprove;


    double diffIndicatorValue = curFunct - previous ;

    cout<<" Difference OF f function from previous f = "<<diffIndicatorValue<<endl; 

    if ( diffIndicatorValue > 0 && diffIndicatorValue >= previous*1e-13*-1 )
    {
      /* code */
      cout<<" Error detected by fn increase"<<endl ;
      return true ;

    }
    if( isnan(curFunct))
    {
      cout<<" Error detected by fn = nan"<<endl ;
      return true;

    }
    
    previous = curFunct ;

    if ( diffs.size() == 0)
    {
      /* code */
      diffs.push(difference) ;
      gTdifference = gTdifference + difference ;
      cout << " gTdifference = "<<gTdifference<<endl ;
      return false;
    }
    else if ( diffs.size() < size)
    {
      /* code */
      diffs.push(difference) ;
      gTdifference = gTdifference + difference ;
      cout << " gTdifference = "<<gTdifference<<endl ;
      return false ;
    }
    else if( diffs.size() == size)
    {
      double k= gTdifference / size ;
      cout << " k = " <<k<<endl ;

      if ( difference > k )
      {
        /* code */
        cout << " difference   = "<<difference<<endl ;
        cout << " gTdifference = "<<gTdifference<<endl ;
        cout << " Error detected by improve"<<endl ;
        becauseImprove ++ ;
        return true;
      }
      else
      {
        gTdifference = gTdifference - diffs.front() + difference ;
        cout << " gTdifference = "<<gTdifference<<endl ;
        diffs.pop() ;
        return false;

      }


    }

    //delete 
    return false;

}



void init ( int iter, int winSize, double thres, int flipPosition) {
  Global::MAX_ITER = iter;
  Global::windowSize = winSize;
  Global::threshold = thres;
  Global::pos = flipPosition;
}

bool isFlipped (double curRes) {

  int size = Global::windowSize;

  double& gTrend = Global::gTrend;

  queue<double>& res = Global::window;
  queue<double>& diffs = Global::diffs;
  queue<double>& trend = Global::trend;

  double thres = Global::threshold;

  
  if (res.size() == 0) {
    return false;
  } else if (res.size() < size) {
    return false;
  } else {
    if (gTrend < 0) {
      // residual is increasing
      return true;
    }
    double prevRes = res.back(); // In queue back() give latest item
    double curDiff = prevRes - curRes;
    double curTrend = curDiff / prevRes;
    
    return curTrend < 0 && -curTrend > gTrend + thres;
  }
  
  return false;
}

void recordResidual (double curRes) {

  int size = Global::windowSize;

  double& gTrend = Global::gTrend;

  queue<double>& res = Global::window;
  queue<double>& diffs = Global::diffs;
  queue<double>& trend = Global::trend;

  if (res.size() == 0) {
    res.push(curRes);

  } else if (res.size() < size) {

    double prevRes = res.back();
    res.push(curRes);

    double curDiff = prevRes - curRes;
    double curTrend = curDiff / prevRes;

    trend.push(curTrend);
    gTrend = (gTrend * (trend.size() - 1) + curTrend) / trend.size();
    diffs.push(curDiff);

  } else {


    res.pop();
    diffs.pop();
    trend.pop();
    double prevRes = res.back();
    res.push(curRes);
    double curDiff = prevRes - curRes;
    double dumpTrend = trend.front();
    
    double curTrend = curDiff / prevRes;
    
    trend.push(curTrend);
    gTrend = (gTrend * trend.size() - dumpTrend + curTrend) / trend.size();
    
    diffs.push(curDiff);
  }
}


//Implemented By Emin

bool isDetected( double curFunction )// , queue<double> & detector)
{

  double& previous = Global::previousValueOfIndicator ;
  double diffIndicatorValue = curFunction - previous ;

  cout<<" Difference OF f function from previous f = "<<diffIndicatorValue<<endl; 

  if ( diffIndicatorValue > 0 && abs(diffIndicatorValue) >= abs(previous*1e-9))
  {
    return true ;
  }
  else if( isnan(curFunction))
  {
    return true;
  }
  else 
  {
    return false ;
  }

}


void getIndicator( double curFunction  )//, queue<double> & detector)
{
    
    double& previous = Global::previousValueOfIndicator ;

    if ( previous == 0 )
    {
      previous = curFunction ;
    }
    else
    {
      previous = curFunction ;
    }
}

bool isFlippedIndicator (double curFunction)
{
    int size = Global::windowSize;

    double& gTrend = Global::funGTrend;

    queue<double>& indicator = Global::windowForIndicator;
    queue<double>& diffs = Global::funcIndicatorDiffs;
    queue<double>& trend = Global::funcIndicatorTrend;

    double thres = Global::threshold;

  
    if (indicator.size() == 0) {
      return false;
    } else if (indicator.size() < size) {
      return false;
    }
    else 
    {
      if (gTrend < 0) {
        // indicator is increasing
        return true;
      }
      double prevFunc = indicator.back(); // In queue back() give latest item
      double curDiff = prevFunc - curFunction;

      cout<< "curDiff = "<< curDiff << endl ;
      double curTrend = curDiff / prevFunc;
      
      return curTrend < 0 && -curTrend > gTrend + thres;
    }
    
    return false;




}
void recordIndicator(double curFunction)
{

    int size = Global::windowSize;

    double& gTrend = Global::funGTrend;

    queue<double>& indicator = Global::windowForIndicator;
    queue<double>& diffs = Global::funcIndicatorDiffs;
    queue<double>& trend = Global::funcIndicatorTrend;

    if (indicator.size() == 0) {
      indicator.push(curFunction);

    } else if (indicator.size() < size) {

      double prevIndicator = indicator.back();
      indicator.push(curFunction);

      double curDiff = prevIndicator - curFunction;
      double dumpTrend= trend.front() ;


      double curTrend = curDiff / prevIndicator;

      trend.push(curTrend);
      gTrend = (gTrend * trend.size() - dumpTrend + curTrend) / trend.size();

      diffs.push(curDiff);

    } else {


      indicator.pop();
      diffs.pop();
      trend.pop();

      double prevIndicator = indicator.back();
      indicator.push(curFunction);

      double curDiff = prevIndicator - curFunction;

      double dumpTrend = trend.front();
      
      double curTrend = curDiff / prevIndicator;
      
      trend.push(curTrend);
      gTrend = (gTrend * trend.size() - dumpTrend + curTrend) / trend.size();
      
      diffs.push(curDiff);

    }

}
void finish () {
  cout << " "<< endl ;
  cout << "windowSize: " << Global::windowSize << endl;
  cout << "maxIter: " << Global::MAX_ITER << endl;
  cout << "threshold: " << Global::threshold << endl;
  //cout << "queue size: " << Global::window.size() << endl;

  //cout << "gTrend: " << Global::gTrend << endl;

  cout << "New Indicator converge value -x^T*b =" <<
  cout << " Emin modifed the codes " <<endl ;
}
