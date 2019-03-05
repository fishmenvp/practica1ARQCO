#include <stdio.h>
#include <stdlib.h>
#include <pmmintrin.h>
#include "rutina_clock.h"

double randfrom();
void datosOrdenados(double *ciclos);

int N=0;

void main(int argc, char *argv[]){
	
	int L = atoi(argv[1]);
	int D = atoi(argv[2]);
	N = atoi(argv[3]);
	
	//Cálculo del R
	int R; 
	if(D < 8) 
		R=1 + ((8*L - 1) / D );
	else if (D >= 8)
	       	R = L;	
	int *e = (int*)malloc(R*sizeof(int));
	double suma = 0, S[N], *A, ciclos=0;
        	
	A = (double*)_mm_malloc(D*R*sizeof(double), 64);
	
	//Se inicializan los vectores A, e y ciclos
	for(int i=0; i < R*D; i++)
		A[i]= randfrom();
	for(int i = 0; i < R; i++)
		e[i] = i*D;

	//Se realiza N veces la suma
	start_counter();
	for(int i =0; i < N;i++){
		for(int j = 0; j < R; j++){
			suma += A[e[j]];
		}
		S[i] = suma;
		suma = 0;
	}
	ciclos = get_counter();	

	
	//Se imprimen los resultados
	FILE *f = fopen("auxiliar.txt", "w");
	for(int i = 0; i < N; i++){
		fprintf(f, "%f ", S[i]);
	}
	
	printf("%d %f %d\n", L, ciclos/(R*N), D);
	_mm_free(A);


	exit(1);
}


double randfrom()
{
    double range = 1000;
    double div = RAND_MAX / range;
    return rand() / div;
}
