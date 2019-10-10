//Anagrama

#include <stdio.h>
#include <string.h>

int main(void){
                                               
                char palavra1[256] = {};
                char palavra2[256] = {};                
                int string;
                
                
                printf("Digite duas strings e verifique se são anagramas.\n");
                printf("1ª String:\n");
                scanf("%s", &palavra1);
                printf("2ª String:\n");
                scanf("%s", &palavra2);                
                
                
                ////esse ponteiro esta apontando pro endereço de memoria das palavras
                void *sPalavra1 = &palavra1;
                void *sPalavra2 = &palavra2;
                
                int anagrama(char* sPalavra1,char* sPalavra2);
                
                int tamanho(char letra[]);
                
                int num = tamanho(sPalavra1);
                int num2 = tamanho(sPalavra2);
                
                string = anagrama(sPalavra1, sPalavra2);
                if (num == num2){                    
                    if (string == 1){
                        printf("\n1\n");
                    }
                    else{
                        printf("\n0\n");
                    }
                }
                else{
                    printf("\n0\n");
                }               
                                              
                            
                getchar();
                               
                                                
                
                return 0;               
                                              
}


int anagrama(char* sPalavra1,char* sPalavra2){ 
                
                
                int tamanho(char letra[]);
                
                int num = tamanho(sPalavra1);
    
                int numCaracteresPalavra1[256] = {};
                int numCaracteresPalavra2[256] = {};
                int i = 0;

                while (sPalavra1[i] != '\0'){
                    numCaracteresPalavra1[sPalavra1[i] - 'a']++;                    
                    ++i;                    
                }
                
                i = 0;
                
                while (sPalavra2[i] != '\0'){                    
                    numCaracteresPalavra2[sPalavra2[i] - 'a']++;
                    ++i;
                }
                
                for(i = 0; i < num ; i++){
                    if(numCaracteresPalavra1[i] != numCaracteresPalavra2[i])
                        return 0;
                }
                
                return 1;
                
}
                    
int tamanho(char letra[]){
                int caracteres = 0;
                while(letra[caracteres] != '\0'){
                    ++caracteres;
                }
                ++caracteres;
    
                return caracteres;
}
                



                
