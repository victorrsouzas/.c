#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Usando o argv para colocar as linhas e colunas e o scanf para colocar os argumentos
int main(int argc, char *argv[]){
    
        int i, j,h,m, c, d,total1,total2,t,soma = 0;
        int matriz1[10][10];
        int matriz2[10][10];
        int matrizfinal[10][10];
        FILE *arquivo;
        char matrix[10000];
    
        i = atoi(argv[1]);
        j = atoi(argv[2]);
        total1 = i * j;
    
        printf("Escolha ate %d de elementos para matriz 1 [%d][%d]\n",total1,i,j);
        for(c = 0; c < i;c++){
            for(d = 0; d < j;d++){
                scanf("%d", &matriz1[c][d]);
            }
        }
        for(c = 0; c < i; c++){
            for(d = 0;d < j;d++){
                printf("A matriz 1 na posição [%d][%d] é %d\n", c,d, matriz1[c][d]);
            }
        }
        printf("\n");
        h = atoi(argv[3]);
        m = atoi(argv[4]);
        total2 = h * m;
        printf("A matriz 2 é de [%d][%d]", h, m);
        
        if(j != h){
            printf("\nAs matrizes não compativeis\n");
        }else{
            printf("Escolha ate %d de elementos para matriz 2 [%d][%d]\n", total2,h,m);
            for(c = 0; c < h; c++){
                for(d = 0; d < m;d++){
                    scanf("%d", &matriz2[c][d]);
                }
            }
            for(c = 0; c < h; c++){
                for(d = 0; d < m;d++){
                    printf("A matriz 2 na posição [%d][%d] é %d\n", h,d,matriz2[c][d]);
                }
            }
            for (c = 0; c < i; c++) {
                for (d = 0; d < m; d++) {
                    for (t = 0; t < h; t++) {
                        soma = soma + matriz1[c][t]*matriz2[t][d];
                    }
                    matrizfinal[c][d] = soma;
                    soma = 0;
                }
            }
            
            
            arquivo = fopen("arquivo.txt", "w");
            for (c = 0; c < i; c++) {
                for (d = 0; d < m; d++){
                    fprintf(arquivo,"%d\t", matrizfinal[c][d]);
                }
                fprintf(arquivo,"\n");
            }
            fclose(arquivo);
            printf("A matriz Final é:\n");
            arquivo = fopen("arquivo.txt","r");
            fgets(matrix, 10000, arquivo);
            for(c = 0; c < i;c++){
                for(d = 0; d < m;d++){
                    fscanf(arquivo,"%d\t",&matrizfinal[c][d]);
                    printf("%d\t",matrizfinal[c][d]);
                }
                printf("\n");
            }
            fclose(arquivo);            
        }
        
    return 0;
}
        
/*Usando o argv para colocar as linhas, colunas e os argumentos
int main(int argc, char *argv[]){
    
    int i, j, c, d,t,matrix,total;//Linhas,colunas,variavel do primeiro FOR,variavel de segundo FOR,pra ler os argumentos,total de elementos
    int matriz[10][10];
    
    i = atoi(argv[1]);
    j = atoi(argv[2]);
    total = i * j;
    
    if(total != (argc - 3)){//argv[0],argv[1],argv[2]
        printf("Numero é maior ou menor de elementos suportados pela matriz\n");
    }else{
        for(c = 0; c < i; c++){
            for(d = 0;d < j;d++){
                for(t = 3; t < argc; t++){
                printf("A matriz na posição [%d][%d] é %d\n", c,d, atoi(argv[t]));
                }
            }
        }
    }
    return 0;
}*/
                    
