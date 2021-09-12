# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <stdio.h>

using namespace std;

# include "../lagrange_nd.hpp"

int main ( );

void test3d ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
{
  int option;

  timestamp ( );
  cout << "\n";
  cout << "LAGRANGE_ND_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the LAGRANGE_ND library.\n";

  test3d ( );
  
  cout << "\n";
  cout << "LAGRANGE_ND_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************


//****************************************************************************80

void test3d( )

//****************************************************************************80
{
  double *c;
  int d;
  int *e;
  double error;
  int i;
  int j;
  char label[80];
  int n;
  int nd;
  int o;
  double *pc;
  int *pe;
  int *po;
  int r;
  double *v;
  double *value;
  double xd[3*10] = {
    0.0,  0.0,  0.0, 
    1.0,  0.0,  0.0, 
    2.0,  0.0,  0.0, 
    0.0,  1.0,  0.0, 
    1.0,  1.0,  0.0, 
    0.0,  2.0,  0.0, 
    0.0,  0.0,  1.0, 
    1.0,  0.0,  1.0, 
    0.0,  1.0,  1.0, 
    0.0,  0.0,  2.0 };

  cout << "\n";
  cout << "TEST07\n";
  cout << "  LAGRANGE_COMPLETE determines\n";
  cout << "  the Lagrange interpolating polynomials L(x)\n";
  cout << "  for ND points in D dimensions, assuming that\n";
  cout << "  the number of points exactly coincides with\n";
  cout << "  R = Pi(D,N), the number of monomials of degree N or less\n";
  cout << "\n";
  cout << "  The data points are the grid nodes of a tetrahedron.\n";

  nd = 10;

  d = 3;
  n = 2;
  r = mono_upto_enum ( d, n );

  pc = new double[nd*r];
  pe = new int[nd*r];
  po = new int[nd];

  c = new double[r];
  e = new int[r];

  cout << "\n";
  cout << "  Spatial dimension D = " << d << "\n";
  cout << "  Maximum degree N = " << n << "\n";
  cout << "  Number of monomials R = " << r << "\n";
  cout << "  Number of data points ND = " << nd << "\n";

  r8mat_transpose_print ( d, nd, xd, "  Data points XD:" );

  lagrange_complete ( d, n, r, nd, xd, po, pc, pe );
//
//  Print the polynomials.
//
  cout << "\n";
  cout << "  Lagrange polynomials for XD data points:\n";
  cout << "\n";

  for ( i = 0; i < nd; i++ )
  {
    o = po[i];
    for ( j = 0; j < o; j++ )
    {
      c[j] = pc[i+j*nd];
      e[j] = pe[i+j*nd];
    }
    sprintf ( label, "  P(%d)(x) =", i );
//    polynomial_print ( d, o, c, e, label );
  }
//
//  Evaluate the polynomials at XD.
//
  value = new double[nd*nd];

  for ( i = 0; i < nd; i++ )
  {
    o = po[i];
    for ( j = 0; j < o; j++ )
    {
      c[j] = pc[i+j*nd];
      e[j] = pe[i+j*nd];
    }
    v = polynomial_value ( d, o, c, e, nd, xd );

    for ( j = 0; j < nd; j++ )
    {
      value[i+j*nd] = v[j];
    }
    delete [] v;
  }

  error = r8mat_is_identity ( nd, value );
  cout << "\n";
  cout << "  Frobenius norm of Lagrange matrix error = " << error << "\n";
	
double xi[3*10] = {
    0.1,  1.0,  0.8,
    1.0,  0.3,  1.0,
    2.0,  0.5,  0.9,
    0.10,  1.0,  1.9,
    1.2,  1.12,  0.66,
    0.4,  2.43,  0.54,
    0.45,  0.33,  1.0,
    1.3,  0.12,  1.23,
    0.43,  1.14,  1.67,
    0.12,  0.54,  1.45 };
  
double pd[10] = {0.011, -2.123, 3.12, 4.54, 0.981, 0.764, 0.343,  1.012, 3.12, 0.98};
int pn = nd;

  double *zi;

zi = interpolant_value ( d, r,  pn, po, pc, pe, pd,30, xi );

/*
error = 0.0;
  for ( k = 0; k < ni; k++ )
  {
    f = sin ( xyi[0+k*2] ) * cos ( xyi[1+k*2] );
    if ( error < fabs ( zi[k] - f ) )
    {
      error = fabs ( zi[k] - f );
    }
  }
  cout << "\n";
  cout << "  Maximum absolute interpolant error on 11x11 grid = " << error << "\n";
*/

  for (int i=1; i< 10; i++)
      cout << zi[i]<< endl;
  
  
//
//  Free memory.
//
  delete [] c;
  delete [] e;
  delete [] pc;
  delete [] pe;
  delete [] po;
  delete [] value;

  return;
}
//****************************************************************************80

