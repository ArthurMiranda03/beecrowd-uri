/*
Beecrowd 1179 - Preenchimento de Vetor IV
Neste problema você deverá ler 15 valores colocá-los em 2 vetores conforme estes valores forem pares ou ímpares. Só que o tamanho de cada um dos dois vetores 
é de 5 posições. Então, cada vez que um dos dois vetores encher, você deverá imprimir todo o vetor e utilizá-lo novamente para os próximos números que forem 
lidos. Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos dois vetores, imprimindo primeiro os valores do vetor impar. 
Cada vetor pode ser preenchido tantas vezes quantas for necessário.

Entrada
A entrada contém 15 números inteiros.

Saída
Imprima a saída conforme o exemplo abaixo.
*/

#include <stdio.h>
#define TAM 5
 
int main() {
    
    int valor;
    int par[TAM], impar[TAM];
    int pos_par = 0, pos_impar = 0;

    for(int i=0;i<15;i++){
        scanf("%d", &valor);
        if(valor%2==0){
            par[pos_par]=valor;
            pos_par++;
            if(pos_par==TAM){
                pos_par = 0;
                for(int j = 0; j<TAM;j++){
                    printf("par[%d] = %d\n", j, par[j]);
                }
            }
        }
        else{
            impar[pos_impar]=valor;
            pos_impar++;
            if(pos_impar==TAM){
                pos_impar = 0;
                for(int j = 0; j<TAM;j++){
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
            }
        }
    }
    for(int i = 0; i<pos_impar;i++){
       printf("impar[%d] = %d\n", i, impar[i]);
    }
    for(int i = 0; i<pos_par;i++){
       printf("par[%d] = %d\n", i, par[i]);
    }

    
    return 0;
}