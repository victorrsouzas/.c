#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    void selectionSort();
    
    int m;
    printf("Size: ");
    printf("Elements: ",scanf("%d", &m));// Quantidade de elementos/tamanho da array
    
    int v,vetor[m];    
    
    clock_t end,start;////pra guardar as variaveis de tempo inicial e final

    for(v=0;v<m;v++){//enquanto o meu v for menor que m vou incrementar um numero aleatorio usando a função rand.
        vetor[v]=rand()%m;
        printf("%d"",", vetor[v]);
    }
    printf("\nSorted: ");
    start=clock();//iniciar o tempo
    selectionSort(vetor,m);//vai receber o vetor e o tamanho desse vetor
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();
    printf("Tempo usando o Selection: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));//Para obter o tempo de execução(em ms *1000), necessário para ordenar o array dado como entrada.  
    
    return 0;
}

void selectionSort(int array[], int x){//vai receber o vetor e o tamanho desse vetor
    int i,j,k, aux;
    for(i=0;i<x-1;i++){// Percorre todo o vetor até m-1, pois a ultima posição não precisa testar pois ja estara ordenada;
        k = i;// Menor valor recebe a posição que está passando;
        for(j=i+1;j<x;j++){// Percorre o vetor da posição i+1 até o final;
            if(array[j]<array[k])// Testa se a posição que está passando é menor que o menor valor;
                k=j;// o k recebe a posição do menor valor;
        }
        if(array[i] != array[k]){// Se a posição for diferente da que está passando, ocorre a troca; --> i=0 23-4-90-67-21 => i=1 4-23-90-67-21 => i=2 4-21-90-67-23 => i=3 4-21-23-67-90
            aux = array[k];
            array[k] = array[i];
            array[i] = aux;
        }
    }
}
