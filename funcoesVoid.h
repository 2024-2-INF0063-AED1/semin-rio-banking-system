#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <time.h>

// Função que limpa a tela e atualiza
void limparTela(){
    system("CLS");
}

// Funçãp que adiciona barra no projeto
void barraNaTela(){
    printf("\n--------------------------------\n");
}

//Funçao para acessar a conta do usuario
void acessarConta(){
    barraNaTela();
    printf("\n          Acessar Conta       \n");
    barraNaTela();
}