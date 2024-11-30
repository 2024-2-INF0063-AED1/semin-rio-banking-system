#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <time.h>

//Estrutura para armazenar os dados referentes ao cliente
typedef struct{
    char nome[50];
    char email[50];
    char senha[8];
    char genero; 
    char telefone[9];
    char cpf[12];
    float rendaMensal;
    char tipoConta[12];
    int numeroConta;
    
}Cliente;

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
            printf("CPF VALIDADO!");
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
    
    printf("--------------------------------");
    printf("\n           Criar  Conta       \n");
    printf("--------------------------------\n");

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
    printf("\n Numero Conta: %d\n", cliente->numeroConta);

    printf("Cadastro feito com sucesso!!!\n");

}

//Funçao que inicializa o menu principal
void menuPrincipal(int *escolha, Cliente *cliente){
    printf("--------------------------------");
    printf("\n          Sistema Bancario     \n");
    printf("--------------------------------\n");
    printf("1. Criar Conta;\n");
    printf("2. Acessar Conta;\n");
    printf("3. Sair do programa;\n");
    printf("Digite o numero de uma das opcoes validas: ");
    scanf("%d", escolha);

    switch(*escolha){
        case 1:
            criarConta(cliente);
            break;

        case 2:
            /*acessarConta();
            break;
            */
        case 3:
            /*encerrar programa*/
            break;
        default:
            printf("\nPor favor, digite 1 ou 2\n");
            break;
    }

}

//Funçao para acessar a conta do usuario
void acessarConta(){
    printf("--------------------------------");
    printf("\n          Acessar Conta       \n");
    printf("--------------------------------\n");
}

//Funçao principal
int main() {

    int escolha;
    Cliente cliente;

    do{
        menuPrincipal(&escolha, &cliente);

    }while(escolha != 3);


    return 0;
}