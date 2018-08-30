#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 5
#define TAM_ARRAY 6

//int TAM_HEAP = 6;

void swap(int *x, int *y){ 
   int aux;
   aux=*x;
   *x=*y;
   *y=aux;
}

void CountingSort(int *A, int *B, int k, int n){ // k = maior valor do array
    int i = 0, j=0;
    int C[k];

    for (i=0 ; i<=k ; i++){
        C[i] = 0;
    }

    for (j=0 ; j<n ; j++){
        C[A[j]] = C[A[j]] + 1; //Acrescentando em C quantas vezes aparece os numeros do array A
    }
    
    for (i=1 ; i<=k ; i++){
        C[i] = C[i] + C[i-1]; //Ve quantos elementos tem antes dele 
    }

    for (j=(n-1); j>=0 ; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

} 

int Pai(int i){
    int a = (i-1)/2;
    return a;
}
int FilhoEsquerdo(int i){
    int a = (2*i)+1;

    return a;
}

int FilhoDireito(int i){
    int a = (2*i)+2;

    return a;
}

void MaxHeapfy(int tamanho, int *A, int i){
    int esquerdo = FilhoEsquerdo(i); 
    int direito = FilhoDireito(i);
    int maior = i; //maior indice
    
    int TAM_HEAP = tamanho - Pai(i) - 1;

    if(esquerdo<=TAM_HEAP && A[esquerdo]>A[maior]){
        maior = esquerdo;
    }

    if(direito<=TAM_HEAP && A[direito]>A[maior]){
        maior = direito;
    }

    if(maior!=i){
        swap(&A[i],&A[maior]);
        MaxHeapfy(TAM_HEAP, A,maior);
    }
}

void BuildMaxHeap(int *A){
    int i = 0;    
    int tamanho = 6;

    for (i = (TAM_ARRAY/2) - 1; i >=0; i--){
        MaxHeapfy(tamanho, A,i);
    }
}

void HeapSort(int *A){
    
    BuildMaxHeap(A);
    int i = 0;
    //printf("%d", TAM_HEAP);
for (i = TAM_ARRAY - 1; i>=0 ; i--){
        swap(&A[0], &A[i]);
        MaxHeapfy(i, A,0);
    }

}

//Funcao para imprimir o array
void Imprime(int *array){
    int k=0;
    
    for (k ; k<5 ; k++){
        printf(" |%d| ", array[k]);
    }
    puts("");
}

void Imprime2(int *array){
    int k=0;
    
    for (k ; k<6 ; k++){
        printf(" |%d| ", array[k]);
    }
    puts("");
}

int main(){
    
    int i = 0;
    int array[NUM_ELEMENTOS] = {21,2,34,17,33}; 
    int array2[NUM_ELEMENTOS];

    for (i=0 ; i<NUM_ELEMENTOS ; i++){
        array2[i] = 0;
    }

    //int array[NUM_ELEMENTOS] = {50,40,30,20,10};
    printf("\nArray 1 antes da troca:\n");
    Imprime(array);

    puts("Organizando o array 1 com o CountingSort:");
    CountingSort(array, array2, 34, 5 );
    Imprime(array2);

    //int array3[NUM_ELEMENTOS] = {21,2,34,17,33}; 
    //int array3[NUM_ELEMENTOS] = {1, 15, 2, 1, 89}; 
    //int array3[NUM_ELEMENTOS] = {50,40,30,20,10};
    int array3[TAM_ARRAY] = {1,15,2,47,89,25}; 

    printf("\nArray 2 antes da troca:\n");
    Imprime2(array3);

    puts("Organizando o array 2 com o HeapSort:");
    HeapSort(array3);
    Imprime2(array3);
    
    return 0;
}