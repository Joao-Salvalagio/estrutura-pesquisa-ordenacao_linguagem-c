// Turma A e B ADS 5 - 2026 - Implementando terça 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

void imprimir(int A[], int n, int tempo);
void delay(int tempo_segundos);
int* criarArranjo(int n); //Random
int* criarArranjoCrescente(int n); //Crescente
int* criarArranjoDecrescente(int n); //Decrescente
void trocar(int *x, int *y);
void ordenacao_por_insersao(int A[],int n); //Inserction-Sort
void ordenacao_por_selecao(int A[], int n); //Selection-Sort
void ordenacao_bubble(int A[], int n); //Bubble-Sort

int main(){
	clock_t t;
	int n = 10000;
	 printf("Inteiro: %zu bytes\n", sizeof(int));
	 printf("Inteiro em bits: %zu\n", sizeof(int) * CHAR_BIT);
	int* A = criarArranjo(n);
	int* B = criarArranjoCrescente(n);
	int* C = B;

	t = clock();
	int temp = B[0];
	B[0] = B[n-1];
	B[n-1] = temp;
    ordenacao_bubble(C,n);
    t = clock() - t;
    printf("\n\nTempo de execucao de ordenacao por bubble (crescente): %lf\n\n", ((double)t)/(CLOCKS_PER_SEC/1000));
    
    system("pause");
	return 0;
}

void ordenacao_bubble(int A[], int n){
	int trocou;
	for (int i = 0; i < n - 1; i++){
		trocou = 0;
		for(int j = 1; j < n - i; j++){
			if(A[j-1] > A[j]) {
				trocar(&A[j-1], &A[j]);
				trocou = 1;
			}
		}
		if(!trocou) break;
	}
}

void ordenacao_por_selecao(int A[], int n){
    for(int i=0; i < n-1; i++){
        int indice_menor = i;
        for(int j=(i+1); j < n; j++){
            if(A[i] > A[j]) indice_menor = j;
        }
        if(indice_menor != i) trocar(&A[indice_menor], &A[i]);
    }
}

void ordenacao_por_insersao(int A[],int n){
	int chave, i;
	for(int j=1; j < n; j++){
		chave = A[j];
		i = j - 1;
		while( i > -1 && A[i] > chave){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = chave;
		//imprimir(A,n,2);
	}
}

void trocar(int *x, int *y){
	int aux = *x;
	*x = *y;
	*y = aux;
}

int* criarArranjo(int n){
	int* arranjo = (int*) malloc(n*sizeof(int));
	if(arranjo == NULL){
		printf("Problema na alocacao de memohria.");
		exit(1);
	}
	srand(time(NULL));
	for(int i=0; i < n; i++){
		arranjo[i] = rand() % (n);
	}
	return arranjo; 
}

int* criarArranjoCrescente(int n){
	int* arranjo = (int*) malloc(n*sizeof(int));
	if(arranjo == NULL){
		printf("Problema na alocacao de memohria.");
		exit(1);
	}
	for(int i=0; i < n; i++){
		arranjo[i] = i + 1;
	}
	return arranjo; 
}

int* criarArranjoDecrescente(int n){
	int* arranjo = (int*) malloc(n*sizeof(int));
	if(arranjo == NULL){
		printf("Problema na alocacao de memohria.");
		exit(1);
	}
	for(int i=0; i < n; i++){
		arranjo[i] = n - i;
	}
	return arranjo; 
}

void imprimir(int A[], int n, int tempo){
	for(int i=0; i < n; i++){
		printf("%d ",A[i]);
	}
	delay(tempo);
	printf("\n");
}

void delay(int tempo_segundos){
	int tempo = 1000 * tempo_segundos;
	clock_t tempo_inicial = clock();
	while(clock() < tempo_inicial + tempo);  
}