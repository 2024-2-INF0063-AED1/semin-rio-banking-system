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

    barraNaTela();

    printf("Cadastro feito com sucesso!!!\n");

    barraNaTela();

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

void excluirConta(No **cabeca, No *clienteEncontrado) {
    char confirmacao;

    printf("\nTem certeza que deseja excluir a conta? (S/N): ");
    getchar(); 
    scanf("%c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        char cpfConfirmacao[12]; 


        printf("\nDigite o CPF para confirmar a exclusao: ");
        scanf("%s", cpfConfirmacao);

        if (strcmp(clienteEncontrado->cliente.cpf, cpfConfirmacao) == 0) {

            
            strcpy(clienteEncontrado->cliente.cpf, "00000000000");  
            strcpy(clienteEncontrado->cliente.nome, "");  
            strcpy(clienteEncontrado->cliente.email, "");  
            strcpy(clienteEncontrado->cliente.telefone, "");  
            strcpy(clienteEncontrado->cliente.senha, "");  
            clienteEncontrado->cliente.saldo = 0.0;  
            clienteEncontrado->cliente.tipoConta = '\0';  
            clienteEncontrado->cliente.numeroConta = 0;  

            if (*cabeca == clienteEncontrado) {
                *cabeca = clienteEncontrado->proximo;
            } else {
                No *atual = *cabeca;
                while (atual != NULL && atual->proximo != clienteEncontrado) {
                    atual = atual->proximo;
                }
                if (atual != NULL) {

                    atual->proximo = clienteEncontrado->proximo;
                }
            }

            free(clienteEncontrado);
            printf("\nConta excluida com sucesso!!\n");
        } else {
            printf("\nCPF não corresponde. Excluindo operaçao.\n");
        }
    } else {
        printf("\nOperacao de exclusao cancelada.\n");
    }

    system("PAUSE");
    limparTela();
}

void DadosConta(No *clienteEncontrado) {

    barraNaTela();
    printf("    Dados Da Conta Pessoal  ");
    barraNaTela();

    printf("Nome: %s\n", clienteEncontrado->cliente.nome);
    printf("Email: %s\n", clienteEncontrado->cliente.email);
    printf("Genero: %c\n", clienteEncontrado->cliente.genero);
    printf("Telefone: %s\n", clienteEncontrado->cliente.telefone);
    printf("CPF: %s\n", clienteEncontrado->cliente.cpf);
    printf("Saldo: R$ %.2f\n", clienteEncontrado->cliente.saldo);
    printf("Tipo de Conta: %c\n", clienteEncontrado->cliente.tipoConta);
    printf("Numero da Conta: %d\n", clienteEncontrado->cliente.numeroConta);

    barraNaTela();
    system("PAUSE");
    limparTela();
}


// funcao para deposito de valores na conta
void depositar(No *clienteEncontrado){
    float valorDepositado;
    char cpfConfirmacao[12];
   
    
    do{
        barraNaTela();
        printf("    Deposito   ");
        barraNaTela();
        printf("Por favor, informe o CPF para validar a operação: \n");
        scanf("%s", cpfConfirmacao);

        
        if (strcmp(cpfConfirmacao, clienteEncontrado->cliente.cpf) == 0) {

            printf("Digite o valor do deposito R$ \n");
            scanf("%f", &valorDepositado);

            clienteEncontrado->cliente.saldo +=  valorDepositado;

            printf("Valor depositado com seu sucesso!\n");
            printf("Seu saldo atual R$ %.2f", clienteEncontrado->cliente.saldo);

            barraNaTela();
            system("PAUSE");
            limparTela();
        }
        else {
            printf("Conta inexistente com esse CPF.Tente novamente\n");
            system("PAUSE");
            limparTela();

        }
    }while(strcmp(cpfConfirmacao, clienteEncontrado->cliente.cpf) != 0);
    

}
// funcao que calcula um juros para o saque a depender do tipo da conta
void calcularJuros(No *clienteEncontrado, float *juros){
    
    if(clienteEncontrado->cliente.tipoConta == 'p'){
        *juros = 0.005;
    }
    else if(clienteEncontrado->cliente.tipoConta == 'c'){
        *juros = 0.01;
    }
    else if(clienteEncontrado->cliente.tipoConta == 'j'){
        *juros = 0.02;
    }
   
}
// funcao para sacar um valor
void sacar(No *clienteEncontrado){
    float valorSacado;
    char cpfConfirmacao[12];
    float juros;
    do{
        barraNaTela();
        printf("    Saque   ");
        barraNaTela();
        printf("Por favor, informe o CPF para validar a operação: \n");
        scanf("%s", cpfConfirmacao);

        if (strcmp(cpfConfirmacao, clienteEncontrado->cliente.cpf) == 0) {

            printf("Digite o valor para o saque R$ \n");
            scanf("%f", &valorSacado);
            calcularJuros(clienteEncontrado, &juros);
            clienteEncontrado->cliente.saldo = clienteEncontrado->cliente.saldo - (valorSacado + (valorSacado * juros));

            printf("Valor sacado com sucesso!\n");
            printf("Seu saldo atual R$ %.2f", clienteEncontrado->cliente.saldo);

            barraNaTela();
            system("PAUSE");
            limparTela();
        }
        else {
            printf("Conta inexistente com esse CPF.Tente novamente\n");
            system("PAUSE");
            limparTela();

        }
    }while(strcmp(cpfConfirmacao, clienteEncontrado->cliente.cpf) != 0);
}
void acessarConta(No *cabeca) {
    char cpf[12];  

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

    int escolha; // Declaração da variável escolha fora do loop

    do {
        barraNaTela();
        printf("      Menu Da Conta:    ");
        barraNaTela();

        printf("1. Dados Da Conta;\n");
        printf("1. Dados Da Conta;\n");
        printf("2. Transferencias;\n");
        printf("3. Depositos;\n");
        printf("4. Saques;\n");
        printf("5. Sair;\n");
        printf("6. Excluir Conta;\n");
        printf("*Digite um dos valores: ");
        scanf("%d", &escolha);

        limparTela();

        switch (escolha) {
            // Dados Contas
            case 1:
                DadosConta(clienteEncontrado);
                break;
            // Transferencias
            case 2:
                printf("Transferencia\n");
                system("PAUSE");
                break;
            // Depositos
            case 3:
                depositar(clienteEncontrado);
                break;
            // Saques
            case 4:
                sacar(clienteEncontrado);
                break;
            // Sair
            case 5:
                printf("Saindo Da Conta;\n");
                system("PAUSE");
                break;
            // Excluir Conta
            case 6:
                excluirConta(&cabeca, clienteEncontrado);
                
                return;
                break;
            default:
                printf("\nPor favor, digite um valor de 1 a 6.\n");
                system("PAUSE");
                break;
        }

    } while (escolha != 5); 
    } 
    else {
        
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    }

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
    scanf("%d", escolha);

        limparTela();

        switch(*escolha){   
            case 1:
                criarConta(cliente);  // Criação de conta
                inserirCliente(cabeca, *cliente);  // Inserção de cliente na lista
                break;

            case 2: 
                acessarConta(*cabeca);  // Acesso à conta, passando a lista de clientes
                break;

            case 3:
                /* Encerrar o programa */
                break;

            default:
                printf("\nPor favor, digite 1 ou 2\n");
                break;
        }

    } while (*escolha != 3);  // Loop até que o usuário escolha sair (opção 3)
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