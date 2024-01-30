/*
Beecrowd 1068 - Balanço de Parênteses I
Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. 
Por exemplo:

a+(b*c)-2-a        está correto
(a+b*(2-c)-2+a)*2  está correto

enquanto

(a*b-(2+c)         está incorreto
2*(3-a))           está incorreto
)3+b*(2-c)(        está incorreto

Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parenteses 
que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

Entrada
Como entrada, haverá N expressões (1 <= N <= 10000), cada uma delas com até 1000 caracteres.

Saída
O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras correct ou incorrect 
de acordo com as regras acima fornecidas.
*/

import java.io.IOException;
import java.io.*;

class PilhaSeq {
    private String dados[];
    private int topo;

    public PilhaSeq() {
        dados = new String[1000];
        topo = -1;
    }
    
    public boolean vazia() {
        if (topo == -1)
            return true;
        else
            return false;
    }
    
    public boolean cheia() {
        if (topo == (dados.length - 1))
            return true;
        else
            return false;
    }

    public int tamanho() {
        return topo + 1;
    }

    public boolean push(String valor) {
        if (cheia())
            return false;  // err: pilha cheia

        topo++;
        dados[topo] = valor;
        return true;
    }
    public String pop() {
        if (vazia())
            return "-1"; // Pilha vazia

        String valor = dados[topo];
        topo--;
        return valor;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        String N;
        PilhaSeq pilha = new PilhaSeq();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean verifica_erro = false;

        while ((N = br.readLine()) != null) {
            for (int i = 0; i < N.length(); i++) {
                char caracter = N.charAt(i);
                if (caracter == '(') {
                    pilha.push(String.valueOf(caracter));
                }
                else if(caracter == ')') {
                    if ((pilha.vazia())&&(verifica_erro==false)) {
                        System.out.println("incorrect");
                        verifica_erro = true;
                    } else {
                        pilha.pop();
                    }
                }
            }
            if((pilha.vazia()==false)&&(verifica_erro==false)){
                System.out.println("incorrect");
                verifica_erro = true;
            }
            else if(verifica_erro==false){
                System.out.println("correct");
            }
            for(int i=0;i<pilha.tamanho();i++){
                pilha.pop();
            }
            verifica_erro=false;
        }
    }
}