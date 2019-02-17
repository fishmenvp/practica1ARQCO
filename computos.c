#include <stdio.h>
#include <stdlib.h>
#include <pmmintrin.h>
#include "rutina_clock.h"

double randfrom();

void main(int argc, char *argv[]){
	
	int R = atoi(argv[1]);
	int D = atoi(argv[2]);

	int e[R];
	double suma = 0, S[10], *A, ciclos;
	
	A = (double*)_mm_malloc(D*R*sizeof(double), 64);
	
	//Se inicializan los vectores A y e
	for(int i=0; i < R*D; i++)
		A[i]= randfrom();
	for(int i = 0; i < R; i++)
		e[i] = i*D;
	

	//Se realiza 10 veces la suma
	start_counter();
	for(int i =0; i < 10;i++){
		for(int j = 0; j < R; j++){
			suma += A[e[j]];
		}
		S[i] = suma;
		suma = 0;
	}
	ciclos = get_counter();	
	
	//Se imprimen los resultados
	for(int i = 0; i < 10; i++)
		printf("%f ", S[i]);
	
	printf("%d %f %d\n", R, ciclos/10, D);
	_mm_free(A);


	exit(1);
}

double randfrom()
{
    double range = 1000;
    double div = RAND_MAX / range;
    return rand() / div;
}
