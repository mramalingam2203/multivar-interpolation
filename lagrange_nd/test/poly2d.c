#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void read_csv(char[], double [], int);

int main()
{   
    int n = 12;
    double xi[n];
    char file_name[] = "input.csv";
    read_csv(file_name, xi, n);
}


void read_csv(char file_name[],double x[], int n)
{
   FILE* fp;
   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

    
    float temp;
    for(int j=0;j<n;j++){
        fscanf(fp,"%f",&temp);
            x[j] = temp;
            std::cout << x[j] << std::endl;
        }
    
    
}