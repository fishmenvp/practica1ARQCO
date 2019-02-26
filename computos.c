#include <stdio.h>
#include <stdlib.h>
#include <pmmintrin.h>
#include "rutina_clock.h"

double randfrom();
void datosOrdenados(double *ciclos);

#define N 40

void main(int argc, char *argv[]){
	
	int L = atoi(argv[1]);
	int D = atoi(argv[2]);
	
	int R = (64*L)/(8*D);

	int *e = (int*)malloc(R*sizeof(int));
	double suma = 0, S[N], *A, ciclos[N];
        	
	A = (double*)_mm_malloc(D*R*sizeof(double), 64);
	
	//Se inicializan los vectores A, e y ciclos
	for(int i=0; i < R*D; i++)
		A[i]= randfrom();
	for(int i = 0; i < R; i++)
		e[i] = i*D;
	for(int i = 0; i < N; i++)
		ciclos[i] = 0;

	//Se realiza N veces la suma
	
	for(int i =0; i < N;i++){
		start_counter();
		for(int j = 0; j < R; j++){
			suma += A[e[j]];
		}
		ciclos[i] = get_counter()/R;	
		S[i] = suma;
		suma = 0;
	}

	
	//Se imprimen los resultados
	for(int i = 0; i < N; i++)
		printf("%f ", S[i]);
	
	datosOrdenados(ciclos);

	printf("%d %f %d\n", L, ciclos[N/2], D);
	_mm_free(A);


	exit(1);
}

void datosOrdenados(double *ciclos){
	int aux =0;
	for (int i=0; i<N-1; i++){
  		 for (int j=i+1; j<N; j++){
    			if(ciclos[i]>ciclos[j]){
     				aux = ciclos[i];
    				ciclos[i] = ciclos[j];
     				ciclos[j] = aux;
    			}
  		}
	}
	return;
}


double randfrom()
{
    double range = 1000;
    double div = RAND_MAX / range;
    return rand() / div;
}
