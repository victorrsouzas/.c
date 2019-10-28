#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    void bubbleSort();
    
    int m;
    printf("Size: ");
    printf("Elements: ",scanf("%d", &m));
    
    int v,vetor[m];    
    
    clock_t end,start;
    start=clock();

    for(v=0;v<m;v++){
        vetor[v]=rand()%m;
        printf("%d"",",vetor[v]);
    }
    printf("\nSorted: ");
    start=clock();
    bubbleSort(vetor,m);
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();
    printf("Tempo usando o Bubble: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));  
    
    return 0;
}

void bubbleSort(int array[], int x){
    int i,j, aux;
    for(i=0;i<x;i++){
        for(j=0;j<x-1-i;j++){
            if(array[j]>array[j+1]){
                aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
              
            }
        }
    }
}
