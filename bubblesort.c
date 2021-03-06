#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    void bubbleSort();
    
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
    bubbleSort(vetor,m);//vai receber o vetor e o tamanho desse vetor
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();//encerrar o tempo
    printf("Tempo usando o Bubble: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC)); //Para obter o tempo de execução(em ms *1000), necessário para ordenar o array dado como entrada.
    
    return 0;
}

void bubbleSort(int array[], int x){ //vai receber o vetor e o tamanho desse vetor
    int i,j, aux;
    for(i=0;i<x;i++){
        for(j=0;j<x-1-i;j++){//j<x-1-i pq no inicio meu i=0 ai depois vai fazer alteração ordenação**
            if(array[j]>array[j+1]){// array[j] é o valor inicial e compara com o da frente ou seguinte elemento array[j+1] 5 > 3
                aux=array[j];//se for maior ele faz uma troca, criamos o auxiliar pra receber o array[j] 5 fica armazenado no aux
                array[j]=array[j+1];//pra fazer a troca da nova posição 3 vai para posição do 5
                array[j+1]=aux;// 5 passa para posição do 3.Ex: i0 5-7-4-3-1 => i1 5-7-4-3-1 => i2 5-4-7-3-1 => i3 5-4-3-7-1 => i4 5-4-3-1-7 ai volta tudo de novo menos o ultimo termo
              
            }
        }
    }
}
