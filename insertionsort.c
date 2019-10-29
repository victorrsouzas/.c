#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    void insertionSort();
    
    int m;
    printf("Size: ");
    printf("Elements: ",scanf("%d", &m));// Quantidade de elementos/tamanho da array
    
    int v,vetor[m];    
    
    clock_t start,end;//pra guardar as variaveis de tempo inicial e final

    for(v=0;v<m;v++){//enquanto o meu v for menor que m vou incrementar um numero aleatorio usando a função rand.
        vetor[v]=rand()%m;
        printf("%d"",", vetor[v]);
    }
    printf("\nSorted: ");
    start=clock();//iniciar o tempo
    insertionSort(vetor,m);//vai receber o vetor e o tamanho desse vetor
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();//encerrar o tempo
    printf("Tempo usando no Insertion: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));//Para obter o tempo de execução(em ms *1000), necessário para ordenar o array dado como entrada.
    
    return 0;
}

void insertionSort(int array[], int x){//vai receber o vetor e o tamanho desse vetor
    int i,j, aux;
    for(i=1;i<x;i++){//Pecorre o vetor do segundo valor ate o ultimo
        aux = array[i];//Pegando esse valor e armazenando
        j = i - 1;                                                                                                            //v           v            v 
        while(j>=0 && array[j] > aux){//o segundo laço pecorre o vetor para trás empurrando o numero para o inicio do vetor - 5-3-4-1 = 3-5-4-1 => 3-4-5-1 => 1-3-4-5  
            array[j+1] = array[j];
            j = j - 1;//decrementar
        }
        array[j+1] = aux;
    }
}
