#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Adicionando arquivos externos(modularização);
#include "funcoesVoid.h"

//Estrutura para armazenar os dados referentes ao cliente
typedef struct{
    char nome[50];
    char email[50];
    char senha[8];
    char genero; 
    char telefone[12];
    char cpf[12];
    float saldo;
    char tipoConta;
    int numeroConta;
    
}Cliente;

//Estrutura para a lista
typedef struct No{
    Cliente cliente;
    struct No *proximo;

}No;


// alocacao dinamica para os nos 
No *criarNo(Cliente cliente){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->cliente = cliente;
    novo -> proximo = NULL;
    return novo;
}

// inserindo clientes na lista
void inserirCliente(No** cabeca, Cliente cliente){
    No* novo = criarNo(cliente);
    
    if(*cabeca == NULL){
        *cabeca = novo;
    }
    else{
        No* atual = *cabeca;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    
    
}

// funcao que exibe os clientes que estao na lista
void exibirClientes(No* cabeca) {

    if (cabeca == NULL) {
        printf("Nenhuma conta cadastrada!\n");
        return;
    }
    
    No* atual = cabeca;

    printf("\nLista de Clientes Cadastrados:\n");
    while (atual != NULL) {
        barraNaTela();
        printf("Nome: %s\n", atual->cliente.nome);
        printf("Email: %s\n", atual->cliente.email);
        printf("Genero: %c\n", atual->cliente.genero);
        printf("Telefone: %s\n", atual->cliente.telefone);
        printf("CPF: %s\n", atual->cliente.cpf);
        printf("Saldo da conta: R$ %.2f\n", atual->cliente.saldo);
        printf("Tipo de Conta: %c\n", atual->cliente.tipoConta);
        printf("Numero da Conta: %d\n", atual->cliente.numeroConta);
        atual = atual->proximo;
    }
    barraNaTela();
}

// funcao com a logica de validacao do nome
bool validaNome(Cliente *cliente){
    if(strlen(cliente->nome) < 3){
        printf("O nome deve ter pelo menos 3 caracteres");
        return false;
    }
    for(int i = 0; cliente->nome[i] != '\0'; i++){
        if((!isalpha(cliente->nome[i]) && !isspace(cliente->nome[i]))){

             printf("O nome deve conter apenas letras e espacos\n");
             return false;
        }
    }
        
    return true;
    
}

// funcao com a logica de validacao da senha
bool validaSenha(Cliente *cliente){
    int temNumero = 0, temCaractere = 0, temMaiuscula = 0;
    if(strlen(cliente->senha) < 8){
        printf("A senha deve ter pelo menos 8 caracteres");
        return false;
    }
    for(int i = 0; cliente->senha[i] != '\0'; i++){
        if(isdigit(cliente->senha[i])){
            temNumero = 1;
        }
        if(!isalnum(cliente->senha[i])){
            temCaractere = 1;
        }
        if(isupper(cliente->senha[i])){
            temMaiuscula = 1;
        }
    }
    if((!temNumero) || (!temMaiuscula) || (!temCaractere)){
        printf("A senha deve ter pelo menos um numero, uma maiuscula e um caractere\n");
        return false;
    }
    
    return true;
}

// funcao com a logica de validacao do genero

bool validaGenero(Cliente *cliente){
    cliente->genero = tolower(cliente->genero);
    if((cliente->genero != 'm') && (cliente->genero != 'f') &&(cliente->genero != 'o')){
        printf("Informe uma das opcoes validas");
        return false;
        
    }
    return true;
}

// funcao com a logica de validacao do telefone
bool validaTelefone(Cliente *cliente){
    if(strlen(cliente->telefone) != 11){
        printf("O telefone deve ter 11 digitos");
        return false;
    }

    for(int i = 0; cliente->telefone[i] != '\0'; i++){
        if(!isdigit(cliente->telefone[i])){
            printf("O telefone deve conter apenas numeros");
            return false;
        }
    }
    return true;

}

// funcao com a logica de validacao de tipo de conta
bool validaTipoDeConta(Cliente *cliente){
    cliente->tipoConta = tolower(cliente->tipoConta);
    if((cliente->tipoConta != 'c') && (cliente->tipoConta != 'j') &&(cliente->tipoConta != 'p')){
        printf("Informe uma das opcoes validas");
        return false;
        
    }
    return true;

}

//funcao com a logica de validacao do saldo informado pelo usuario
bool validaSaldoDaConta(Cliente *cliente){
    if(cliente->saldo < 0){
        printf("Informe um valor valido para deposito inicial");
        return false;
    }
    return true;
}



//Funçao com a logica para validacao do CPF informado
bool validaCpf(Cliente *cliente){
    if(strlen(cliente->cpf) != 11){
        printf("O CPF deve ter 11 digitos e ser valido. Verifique e tente novamente.\n");
        return false;
    }

    else if((strcmp(cliente->cpf,"00000000000") == 0) || (strcmp(cliente->cpf,"11111111111") == 0) || (strcmp(cliente->cpf,"22222222222") == 0) ||
            (strcmp(cliente->cpf,"33333333333") == 0) || (strcmp(cliente->cpf,"44444444444") == 0) || (strcmp(cliente->cpf,"55555555555") == 0) ||
            (strcmp(cliente->cpf,"66666666666") == 0) || (strcmp(cliente->cpf,"77777777777") == 0) || (strcmp(cliente->cpf,"88888888888") == 0) ||
            (strcmp(cliente->cpf,"99999999999") == 0)){
        
                printf("O CPF não pode conter uma sequência de números repetidos. Verifique e tente novamente.\n");
                return false;
    }
    else{
        int soma, j, dig1, dig2;
        int resto = 0;
        

        // 1 digito
        soma = 0;
        j = 10;
        for(int i = 0; i < 9; i++){
            soma += (cliente->cpf[i] - '0') * j;
            j--;
        }
       resto = soma % 11;
       
       if(resto < 2){
        dig1 = 0;
       }
        
       else{
        dig1 = 11 - resto;
       }
        

        // 2 digito
        soma = 0;
        j = 11;
        for(int i = 0; i < 10; i++){
            soma += (cliente->cpf[i] - '0') * j;
            j--;

        }
        resto = soma % 11;
        if(resto < 2){
            dig2 = 0;
        }
            
        else
            dig2 = 11 - resto;

        if((cliente->cpf[9] - '0' == dig1) && (cliente->cpf[10] - '0' == dig2)){
            return true;
        }
        else{
            printf("CPF invalido. Por favor, insira um numero de CPF correto\n");
            return false;
        }

    }
}

// Função que gera numero aleatorio da conta
void numeroConta(Cliente *cliente) { 
    srand(time(NULL));  

    
    cliente->numeroConta = (rand() % 999999) + 100000;  
}

//Funçao para criaçao de conta
void criarConta (Cliente *cliente){
    
    barraNaTela();
    printf("\n           Criar  Conta       \n");
    barraNaTela();
    do{
        printf("Nome: ");
        fflush(stdin);
        fgets(cliente->nome,sizeof(cliente->nome), stdin);
        cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
        puts(cliente->nome);
    }while(!validaNome(cliente));
    


    printf("Email: ");
    scanf("%s", cliente->email);
    printf("%s\n",cliente -> email);

    do{
        printf("Senha(min. 8): ");
        scanf("%s", cliente->senha);
        printf("%s\n", cliente->senha);
    }while(!validaSenha(cliente));

    

    do{
        printf("Genero feminino(F)/Masculino(M)/Outro(O): ");
        getchar();
        scanf("%c", &cliente->genero);
        printf("%c\n",cliente->genero);
    }while(!validaGenero(cliente));
    
    do{
        printf("Telefone:");
        scanf("%s", cliente->telefone);
        printf("%s\n",cliente->telefone);
    }while(!validaTelefone(cliente));
   

    do{
        printf("CPF: ");
        scanf("%s", cliente->cpf);
        printf("%s\n", cliente->cpf);
    }while(!validaCpf(cliente));
    
    do{
        printf("Insira um valor para abrir a conta: R$ ");
        scanf("%f", &cliente->saldo);
        printf("%f\n", cliente->saldo);
    }while(!validaSaldoDaConta(cliente));
    

    do{
        printf("Tipo De Conta:\n");
        printf("[C] - Corrente;\n");
        printf("[J] - Juridica;\n");
        printf("[P] - Poupanca;\n");
        getchar();
        scanf("%c", &cliente->tipoConta);
        printf("%c\n",cliente->tipoConta);
    }while(!validaTipoDeConta(cliente));
    


    numeroConta(cliente);
    printf("\nNumero Conta: %d\n", cliente->numeroConta);

    printf("Cadastro feito com sucesso!!!\n");

    system("PAUSE");
    barraNaTela();
    limparTela();

}

//Funçao que inicializa o menu principal
void menuPrincipal(int *escolha, Cliente *cliente, No** cabeca){
    barraNaTela();
    printf("\n          Sistema Bancario     \n");
    barraNaTela();
    printf("1. Criar Conta;\n");
    printf("2. Acessar Conta;\n");
    printf("3. Sair do programa;\n");
    printf("Digite o numero de uma das opcoes validas: ");
    scanf("%d", escolha);

    limparTela();

    switch(*escolha){
        case 1:
            criarConta(cliente);
            inserirCliente(cabeca, *cliente);
            break;

        case 2:
            
            exibirClientes(*cabeca);  // Exibe a lista de clientes cadastrados
            
            break;

        case 3:
            /*encerrar programa*/
            break;
        default:
            printf("\nPor favor, digite 1 ou 2\n");
            break;
    }

}

//Funçao principal
int main() {

    int escolha;
    Cliente cliente;
    No* cabeca = NULL;
    
    do{
        menuPrincipal(&escolha, &cliente, &cabeca);

    }while(escolha != 3);


    return 0;
}