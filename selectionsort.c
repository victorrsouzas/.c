#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    void selectionSort();
    
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
    selectionSort(vetor,m);
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();
    printf("Tempo usando o Selection: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));  
    
    return 0;
}

void selectionSort(int array[], int x){
    int i,j,k, aux;
    for(i=0;i<x-1;i++){
        k = i;
        for(j=i+1;j<x;j++){
            if(array[j]<array[k])
                k=j;
        }
        if(array[i] != array[k]){
            aux = array[k];
            array[k] = array[i];
            array[i] = aux;
        }
    }
}
