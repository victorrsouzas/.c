#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    void heapSort();
    
    int m;
    printf("Size: ");
    printf("Elements: ",scanf("%d", &m));// Quantidade de elementos/tamanho da array
    
    int v,vetor[m];    
    
    clock_t start,end;//pra guardar as variaveis de tempo inicial e final 

    for(v=0;v<m;v++){ //enquanto o meu v for menor que m vou incrementar um numero aleatorio usando a função rand.
        vetor[v]=rand()%m;
        printf("%d"",",vetor[v]);
    }
    printf("\nSorted: ");
    start=clock();//iniciar o tempo
    heapSort(vetor,m);//vai receber o vetor e o tamanho desse vetor
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();//encerrar o tempo
    printf("Tempo usando o Heap: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC)); //Para obter o tempo de execução(em ms *1000), necessário para ordenar o array dado como entrada.
    
    return 0;
}

void Heap(int array[], int inicio, int final){
    int raiz = array[inicio];
    int sub = inicio * 2 + 1;
    
    while(sub <= final){
        if(sub < final){                      // A raiz tem
            if(array[sub] < array[sub + 1]){  // 2 filhos?
                sub = sub + 1;                // Qual o maior?
            }
        }
        if(raiz < array[sub]){                   //Sub é maior que a raiz?
            array[inicio] = array[sub];          // Sub se torna a Raiz
            inicio = sub;                        // Repetir o processo
            sub = 2 * inicio + 1;                // ...
        }else{
            sub = final + 1;
        }
    }
    array[inicio] = raiz; // Antiga raiz ocupa lugar do ultima sub analisada
}
        

void heapSort(int array[], int x){ //vai receber o vetor e o tamanho desse vetor
    void Heap(); 
    int i, a, j=x-1;
    
    for(i=j/2; i >=0; i--){    // Criar heap a partir
        Heap(array, i, j);     // dos dados. Do meio pra trás
    }
    
    for (i=j; i >= 1; i--){
        a = array[0];           //Pega o maior elemento da heap
        array[0] = array[i];    // e coloca na sua posição corresp-
        array[i] = a;           //ondente no array.
        Heap(array, 0, i -1);   //Reconstruir a heap
        
    }
    
}
