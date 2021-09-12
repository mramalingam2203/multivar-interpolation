# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <stdio.h>
#include<string.h>


using namespace std;

#include "../lagrange_nd.hpp"

void read_csv(int , int , char *, double **);
//void readfile(int row, char *filename, double *dat);

void arr2D_to_1D(int,int,double**, double*, double*);

void read_csv(int row, int col, char *filename, double **data){
	FILE *file;
	file = fopen(filename, "r");

	int i = 0;
    char line[4098];
	while (fgets(line, 4098, file) && (i < row))
    {
    	// double row[ssParams->nreal + 1];
        char* tmp = strdup(line);

	    int j = 0;
	    const char* tok;
	    for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, "\t\n"))
	    {
	        data[i][j] = atof(tok);
	        //printf("%f\t", data[i][j]);
	    }
	    printf("\n");

        free(tmp);
        i++;
    }
}

/*
void readfile(int row, char *filename, double *dat){
    
FILE *file = fopen("input.txt", "r");
    int i = 0;
    if (file != NULL) {
        while (!feof(file) && i < MAX) {
            if (fscanf(file, "%lf", &dat[i++]) != -1) {
                printf("%lf ", dat[i-1]);
            }
        }
        fclose(file);
    } else {
        printf("%s", "Unable to open file");
    }
}

*/
void arr2D_to_1D(int row ,int col,double **arr2D, double* arr1D_1, double* arr1D_2){
    // allocating memeory to 1D dynamically
	// size of 1D array will be n*m
	//arr1D = (double*)malloc(row * col * sizeof(int));
    int i,j,k;
    
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
            if (j%3 != 0){
                k = j
                arr1D_1[i * col + k] = arr2D[i][j];}
            else if(j == 0 ){
                arr1D_2[i] = arr2D[i][j];
            }
        
		}
	}
}
    

int main(int argc, char const *argv[])
{
	/* code */
	if (argc < 3){
		printf("Please specify the CSV file as an input.\n");
		exit(0);
	}

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
      double value[10];

	int row_xy     = atoi(argv[1]);
	int col_xy     = atoi(argv[2]);
	char fname_xy[256];	
    strcpy(fname_xy, argv[3]);
    
    for (i=0; i < 10; i++)
        value[i] = i*2;
    
	double **data;
	data = (double **)malloc(row_xy * sizeof(double *));
	for (int i = 0; i < row_xy; ++i){
		data[i] = (double *)malloc(col_xy * sizeof(double));
	}

	read_csv(row_xy, col_xy, fname_xy, data);
    
    double *data_1D;
	data_1D = (double *)malloc(row_xy * col_xy* sizeof(double *));
    
    
    arr2D_to_1D(row_xy ,col_xy, data,data_1D,value);
    
    for (int i=0; i < row_xy*col_xy; i++)
        printf("%lf\n", data_1D[i]);
    /*
    nd = 10;

   d = 2;
   n = 4;
  
   r = mono_upto_enum ( d, n );

   pc = new double[nd*r];
   pe = new int[nd*r];
   po = new int[nd];

   c = new double[r];
   e = new int[r];

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
    printf ("  P(%d)(x) =", i );
    polynomial_print ( d, o, c, e, label );
  }

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
    
    */
    
}

