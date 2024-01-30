/*
Beecrowd 1238 - Combinador

Implemente um programa denominado combinador, que recebe duas strings e deve combiná-las, alternando as letras de cada string, começando com a primeira letra 
da primeira string, seguido pela primeira letra da segunda string, em seguida pela segunda letra da primeira string, e assim sucessivamente. As letras restantes 
da cadeia mais longa devem ser adicionadas ao fim da string resultante e retornada.

Entrada
A entrada contém vários casos de teste. A primeira linha contém um inteiro N que indica a quantidade de casos de teste que vem a seguir. Cada caso de teste 
é composto por uma linha que contém duas cadeias de caracteres, cada cadeia de caracteres contém entre 1 e 50 caracteres inclusive.

Saída
Combine as duas cadeias de caracteres da entrada como mostrado no exemplo abaixo e exiba a cadeia resultante.
*/
#include <stdio.h>
#include <string.h>

void main (void){
  char str1[60], str2[60];
  int i = 0, repeticoes = 1, str_maior, tam1, tam2;

  while (repeticoes){
    scanf("%d", &repeticoes);

    scanf("%s %s", str1, str2);
    tam1 = strlen(str1);
    tam2 = strlen(str2);

    if (tam1 > tam2)
     str_maior = tam1;
    else
     str_maior = tam2;

    while(str_maior)
    {

      if (i < tam1)
        printf("%c", str1[i]);
      if (i < tam2)
        printf("%c", str2[i]);

      i++;
      str_maior--;
    }
    printf("\n");
    i = 0;
    repeticoes--;
  }
  return 0;
}