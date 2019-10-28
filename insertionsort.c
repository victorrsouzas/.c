#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    void insertionSort();
    
    int m;
    printf("Size: ");
    printf("Elements: ",scanf("%d", &m));
    
    int v,vetor[m];    
    
    clock_t end,start;
    start=clock();

    for(v=0;v<m;v++){
        vetor[v]=rand()%m;
        printf("%d"",", vetor[v]);
    }
    printf("\nSorted: ");
    start=clock();
    insertionSort(vetor,m);
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();
    printf("Tempo usando no Insertion: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));  
    
    return 0;
}

void insertionSort(int array[], int x){
    int i,j, aux;
    for(i=1;i<x;i++){
        aux = array[i];
        j = i - 1;
        while(j>=0 && array[j] > aux){
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = aux;
    }
}
