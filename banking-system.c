#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <time.h>

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
    float rendaMensal;
    char tipoConta[12];
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
        printf("Renda Mensal: R$ %.2f\n", atual->cliente.rendaMensal);
        printf("Tipo de Conta: %s\n", atual->cliente.tipoConta);
        printf("Numero da Conta: %d\n", atual->cliente.numeroConta);
        atual = atual->proximo;
    }
    barraNaTela();
}

//Funçao com a logica para validacao do CPF informado
bool validaCpf(Cliente *cliente){
    if(strlen(cliente->cpf) != 11){
        printf("CPF invalido\n");
        return false;
    }

    else if((strcmp(cliente->cpf,"00000000000") == 0) || (strcmp(cliente->cpf,"11111111111") == 0) || (strcmp(cliente->cpf,"22222222222") == 0) ||
            (strcmp(cliente->cpf,"33333333333") == 0) || (strcmp(cliente->cpf,"44444444444") == 0) || (strcmp(cliente->cpf,"55555555555") == 0) ||
            (strcmp(cliente->cpf,"66666666666") == 0) || (strcmp(cliente->cpf,"77777777777") == 0) || (strcmp(cliente->cpf,"88888888888") == 0) ||
            (strcmp(cliente->cpf,"99999999999") == 0)){
        
                printf("CPF invalido\n");
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
            printf("CPF VALIDADO!\n");
            return true;
        }
        else{
            printf("CPF INVALIDO\n");
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

    printf("Nome: ");
    getchar();
    fgets(cliente->nome,sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; // remove o '\n' residual
    puts(cliente->nome);


    printf("Email: ");
    scanf("%s", cliente->email);
    printf("%s\n",cliente -> email);

    printf("Senha(max. 8): ");
    scanf("%s", cliente->senha);
    printf("%s\n", cliente->senha);


    printf("Genero feminino(F)/Masculino(M)/Outro(O): ");
    getchar();
    scanf("%c", &cliente->genero);
    printf("%c\n",cliente->genero);

    printf("Telefone:");
    scanf("%s", cliente->telefone);
    printf("%s\n",cliente->telefone);

    do{
        printf("CPF: ");
        scanf("%s", cliente->cpf);
    }while(!validaCpf(cliente));
    
    
    
    printf("%s\n", cliente->cpf);

    printf("Renda Mensal: R$ ");
    scanf("%f", &cliente->rendaMensal);
    printf("%f\n", cliente->rendaMensal);

    printf("Tipo De Conta:\n");
    printf("1. Corrente;\n");
    printf("2. Juridica;\n");
    printf("3. Poupanca;\n");
    scanf("%s", cliente->tipoConta);


    numeroConta(cliente);
    printf("\nNumero Conta: %d\n", cliente->numeroConta);

    printf("Cadastro feito com sucesso!!!\n");

    system("PAUSE");
    barraNaTela();
    limparTela();

}

// Funcao para buscar cliente por CPF
No *buscarPorCPF(No *cabeca, const char *cpf) {
    No *atual = cabeca;
    while (atual != NULL) {
        if (strcmp(atual->cliente.cpf, cpf) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void acessarConta(No *cabeca) {
    char cpf[12];  // Define um array para armazenar o CPF do cliente a ser buscado

    // Solicita o CPF para buscar a conta
    barraNaTela();
    printf("        Acesso  a Conta     ");
    barraNaTela();

    printf("Digite o CPF para acessar a conta: ");
    scanf("%s", cpf);

    limparTela();

    // Busca o cliente na lista de contas
    No* clienteEncontrado = buscarPorCPF(cabeca, cpf);

    if (clienteEncontrado != NULL) {
        
        printf("\nConta Encontrada:\n");
        printf("Nome: %s\n", clienteEncontrado->cliente.nome);
        printf("Email: %s\n", clienteEncontrado->cliente.email);
        printf("Genero: %c\n", clienteEncontrado->cliente.genero);
        printf("Telefone: %s\n", clienteEncontrado->cliente.telefone);
        printf("CPF: %s\n", clienteEncontrado->cliente.cpf);
        printf("Renda Mensal: R$ %.2f\n", clienteEncontrado->cliente.rendaMensal);
        printf("Tipo de Conta: %s\n", clienteEncontrado->cliente.tipoConta);
        printf("Numero da Conta: %d\n", clienteEncontrado->cliente.numeroConta);
    } else {
        
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    }

    barraNaTela();
    system("PAUSE");
    limparTela();

    getchar();  
    getchar();  
}

//Funçao que inicializa o menu principal
void menuPrincipal(int *escolha, Cliente *cliente, No** cabeca) {

    do { 
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
        acessarConta(*cabeca);
        break;

        case 3:
            /*encerrar programa*/
            break;
        default:
            printf("\nPor favor, digite 1 ou 2\n");
            break;
    }

} while (*escolha != 3);
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