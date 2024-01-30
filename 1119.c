/*
Beecrowd 1119 - A Fila dos Desempregados
Em uma séria tentativa de reduzir a fila de desempregados, o novo Partido Nacional Trabalhista dos Rinocerontes Verdes decidiu uma estratégia pública.
Todos os dias, todos os candidatos desempregados serão colocados em um grande círculo, voltados para dentro. Alguém é escolhido arbitrariamente como número 1,
e os outros são numerados no sentido horário até N (os quais estarão à esquerda do 1°). Partindo do 1° e movendo-se no sentido horário, um contador oficial
do laboratório conta k posições e retira um candidato, enquanto outro oficial começa a partir de N e se move no sentido anti-horário, contando m posições
e retirando outro candidato. Os dois que são escolhidos são então enviados como estagiários para a reciclagem e se ambos os funcionários escolherem a mesma
pessoa, ela (ele) é enviado para se tornar um político. Cada funcionário, em seguida, começa a contar novamente com a pessoa próxima disponível e o processo
continua até que não reste ninguém. Note-se que as duas vítimas (desculpe, estagiários) deixam o anel ao mesmo tempo, por isso é possível que um 
funcionário conte a pessoa já selecionado pelo outro funcionário.

Entrada
Escreva um programa que leia sucessivamente três números (N, k e m; k, m > 0, 0 < N < 20) e determina a ordem no qual os candidatos são retirados 
para treinamento . Cada conjunto de três números estará em uma linha distinta e o final da entrada de dados é sinalizado por três zeros (0 0 0).

Saída
Para cada conjunto de três números de entrada, imprima uma linha de números especificando a ordem na qual as pessoas são escolhidas. 
Cada número pode ter até 3 dígitos. Liste o par escolhido partindo da pessoa escolhida pelo contador do sentido horário. 
Os pares sucessivos são separados por vírgula (mas não deverá haver vírgula após o último escolhido).
*/

#include <stdio.h>

struct node {
    int value;
    int prev;
    int next;
};

int main()
{
    int N, k, m;

    while (1) {
        struct node candidatos[21];
        int i, j1, j2;
        int resto;

        scanf("%d%d%d", &N, &k, &m);

        if (!(N || k || m))
            break;

        for (i = 1; i <= N; ++i) {
            candidatos[i].value = i;
            candidatos[i].prev = (i == 1) ? N : i - 1;
            candidatos[i].next = (i == N) ? 1 : i + 1;
        }
        candidatos[0].next = 1;
        candidatos[N + 1].prev = N;

        resto = N;
        j1 = 0;
        j2 = N + 1;

        while (1) {
            for (i = 0; i < k; ++i)
                j1 = candidatos[j1].next;
            for (i = 0; i < m; ++i)
                j2 = candidatos[j2].prev;

            printf("%3d", candidatos[j1].value);
            --resto;
            if (j1 != j2) {
                printf("%3d", candidatos[j2].value);
                --resto;
            }

            if (candidatos[j1].prev == j2 || candidatos[j1].next == j2) {
                if (candidatos[j1].prev == j2) {
                    candidatos[j1].prev = candidatos[j2].prev;
                    candidatos[j2].next = candidatos[j1].next;
                }
                if (candidatos[j1].next == j2) {
                    candidatos[j1].next = candidatos[j2].next;
                    candidatos[j2].prev = candidatos[j1].prev;
                }
            }

            candidatos[candidatos[j1].prev].next = candidatos[j1].next;
            candidatos[candidatos[j1].next].prev = candidatos[j1].prev;
            if (j1 != j2) {
                candidatos[candidatos[j2].prev].next = candidatos[j2].next;
                candidatos[candidatos[j2].next].prev = candidatos[j2].prev;
            }

            if (resto > 0)
                putchar(',');
            else {
                putchar('\n');
                break;
            }
        }
    }

    return 0;
}