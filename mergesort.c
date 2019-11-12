#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    void mergeSort();//algoritmo recursivo, ideia de dividir, agrupar e combinar
    
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
    mergeSort(vetor,0,m-1);//vai receber o vetor e o tamanho desse vetor
    for(v=0;v<m;v++){
        printf("%d"",",vetor[v]);
    }
    printf("\n");
    end=clock();//encerrar o tempo
    printf("Tempo usando o Merge: %g ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC)); //Para obter o tempo de execução(em ms *1000), necessário para ordenar o array dado como entrada.
    
    return 0;
}

void merge(int array[], int comeco, int meio, int fim) {
    int end1 = 0;
    int end2 = 0;
    int tamanho = fim - comeco + 1;
    int *x;
    int p1 = comeco;
    int p2 = meio + 1;
    int a, b, c;
    x = (int *) malloc(tamanho*sizeof(int));
    if(x != NULL){
        for(a = 0; a < tamanho; a++){
            if(!end1 && !end2){               //!variavel é igual a negação
                if(array[p1] < array[p2])     //combinar ordenação
                    x[a] = array[p1++];
                else
                    x[a] = array[p2++];
                if(p1 > meio) end1 = 1;      //vetor acabou?
                if(p2 > fim) end2 = 1;
            }else{
                if(!end1)                   //copia o que sobra
                    x[a] = array[p1++];
                else
                    x[a] = array[p2++];
            }
        }
        for(b = 0, c = comeco; b < tamanho; b++, c++){ //Copiar do auxiliar para o
            array[c] = x[b];                           // original.
        }
        free(x);
}
}

void mergeSort(int array[], int comeco, int fim){

    int metade;
    if(comeco < fim){
        metade = floor((comeco + fim)/2);    //função floor ele arredonda para baixo  
        mergeSort(array, comeco, metade);    //chama a função para as
        mergeSort(array, metade + 1, fim);   // 2 metades.
        merge(array, comeco, metade, fim);   // Função para Combinar as 2 metades de forma ordenada.
    }
}

/*
 * 
 * 
 *                  50|25|90|0|15|80|70 - array desordenada
 *                  50|25|90|*0*|15|80|70 - dividir a array ao meio
 *                          /    \
 *                         /      \
                          v        v
                   50|25|90|0      15|80|70 ---- função mergeSort
                       / \           /  \ 
                      /   \         /    \
                  50|25   90|0    15|80   70 ---- função mergeSort
                  /  \    /  \     /  \    \ 
                 50  25  90   0   15   80   70  -- ai começo a pegar de dois em dois (blocos)
                  \ /     \  /     \  /     /
                 25|50    0|90     15|80   70  --  função merge
                    \     /          \    /
                     \   /            \  /
                   0|25|50|90       15|70|80 -- função merge
                        \              /
                         \            /
                          \          /
                        0|15|25|50|70|80  -- array ordenada        */
