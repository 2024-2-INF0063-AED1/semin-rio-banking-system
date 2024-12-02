# Sistema Bancário
Sistema Bancário para gerenciamento e criações contas 

## Autores: 


- 202302570 - Matheus Teles Marques 
- 202307122 - Victor Alves Freire De Queiroz
- 202302594 - Yan Santos Leite



## Resumo

O projeto do Sistema Bancário busca simular as principais funcionalidades de um aplicativo moderno de bancos, permitindo saques, depósitos,transferências entre contas, consultas de saldo, criação e exclusão de contas bancárias.

### Palavras-chave: 
Sistema Bancário, Otimização , Modularização, Transações e Segurança; 



## Introdução

### Problema
Os sistemas bancários desempenham um papel fundamental ao permitir que os clientes realizem operações financeiras de forma rápida e prática, como saques, depósitos, transferências e consultas. No entanto, esses sistemas ainda hoje enfrentam desafios relacionados à segurança, eficiência e necessidade de manutenção constante.Nesse contexto,sistemas que garantam maior proteção ao usuário, adotando tecnologias de segurança e métodos de autenticação adequados, e que melhorem a velocidade das transações devem ser implementados.

### Literatura

* Estruturas de Dados e Seus Algoritmos - Jayme Luiz Szwarcfiter e Lilian Markenzon
* 

### Dataset

O dataset utilizado no projeto contém informações fornecidas pelos clientes no momento do cadastro (criação da conta), incluindo dados como nome, telefone, CPF, e-mail, gênero, tipo de conta, saldo, senha e um número de conta gerado automaticamente e aleatoriamente na hora do cadastro da conta.

### Métodos

O sistema bancário utiliza conceitos de estrutura de dados e algoritmos na linguagem C garantindo assim uma maior performance e um nível de controle maior,o que é útil para sistemas bancários que precisam ser otimizados e protegidos contra falhas de segurança como gerenciamento inadequado de memória.Para esse fim, utilizamos 

* Listas Ligadas (Linked Lists) :

### Avaliação:

Os critérios utilizados para avaliar serão:
   * Tempo de Execução;
   * Uso de Memória; 
   * Nível de manutenção e modularidade;

## Fundamentos Teóricos


Os fundamentos teóricos são conceitos essenciais que guiam o desenvolvimento, influenciando as decisões técnicas. Nesse sentido, o sistema desenvolvido visa assegurar robustez, segurança e eficiência da aplicação, prezando pela rapidez durante as transações. Para se alcançar tal resultado esperado,faz-se necessário a utilização de Estrutura de Dados elementares.Para fins didáticos, mas que ainda assim possa garantir o que foi prometido aos usuários utilizaremos as listas encadeadas.

* Listas Encadeadas (Linked Lists) :
Uma estrutura de dados dinâmica onde cada elemento (nó) aponta para o próximo. Histórico de transações: Usar uma lista ligada permite que o histórico cresça ou diminua dinamicamente sem necessidade de redimensionar arrays. Gestão de usuários: Para sistemas com muitos usuários, uma lista ligada facilita adicionar, remover e pesquisar informações;

Na optica da avaliação, o sistema será avaliado pelas seguintes técnicas:

* Tempo de Resposta:
Mede a rapidez em processar operações críticas, como saques, depósitos e consultas, garantindo uma experiência ágil para os usuários.
* Uso de Memória:
Avalia a eficiência no consumo de recursos, priorizando a otimização para gerenciar grandes volumes de contas e transações.
* Escalabilidade:
Analisa como o sistema se comporta à medida que cresce o número de usuários e transações, assegurando estabilidade e eficiência.

* Testes de Performance:
Medem o tempo de execução e o uso de recursos sob condições normais de operação.

Assim, a fim de obter feedbacks que possam nortear as próximas versões e consequentemente permitir um melhor desenvolvimento da aplicação, proporcionando uma melhor experiência aos usuários, os testes tem uma grande importância dentro do projeto.


## Metodologia


Para o  desenvolvimento do sistema bancário foram seguidos os seguintes passos:

### Planejamento:

Essa etapa  consistiu da análise do funcionamento de Sistemas Bancários, onde foram identificadas as seguintes funcionalidades essenciais:
* Criação e acesso à conta;
* Saque, depósito, transferências, deleção de contas;

### Implementação:

* Tela de Menu e Opções:

  A tela de menu inicial apresenta as opções de cadastro de conta e acesso a conta (caso a conta já esteja ativa no sistema);

* Cadastro de Conta:

  Ao selecionar a opção de cadastro de conta, o usuário informa seus dados pessoais, especifica o tipo de conta a ser criada e a quantia que deseja abrir na conta;
  Esses dados são armazenados em uma struct;

* Geração de Número de Conta e PIN:

  Após o cadastro, o número da conta do usuário é gerado por meio de um algoritmo de randomização;
  
* Acesso à Conta:

  O usuário tem a opção de acessar sua conta;
  Para isso, passa por uma etapa de autenticação utilizando a funcionalidade de busca das listas, que utiliza o CPF e senha do usuário para validar sua entrada no      sistema;

* Operações na Conta:

Após a autenticação, o usuário pode realizar as seguintes operações:Depósito; Saque; Transferência; Consultar saldo;

* Exclusão de Conta:

  O usuário também tem a opção de deletar a conta, caso deseje;

* Estrutura de Dados do Sistema:

  A atualização do conjunto de usuários do sistema será feita utilizando listas;
  
### Testes:

* Gerenciamento de contas:

  Garantir que as contas bancárias sejam localizadas de forma rápida e eficiente, com tratamento adequado de possíveis colisões de dados;

* Processamento de transações:

  Assegurar que as transações como saques e depósitos estejam funcionais, com suas devidas autenticações funcionando;

* Armazenamento de informações de conta:

  Validar que os dados da conta bancária sejam armazenados corretamente e possam ser acessados facilmente;

### Resultados: 
O desenvolvimento do programa utilizando listas encadeadas resultou em um sistema funcional e eficiente, capaz de gerenciar dados dinâmicos de maneira prática e estruturada. O código foi projetado para executar operações essenciais, como adicionar elementos ao final da lista, exibir os valores armazenados e liberar a memória utilizada. Durante os testes, ficou evidente que o programa faz um uso eficiente da memória, aproveitando as características dinâmicas das listas encadeadas, que eliminam a necessidade de pré-alocar grandes blocos de memória.

Cada elemento alocado foi liberado corretamente ao final da execução, prevenindo vazamentos de memória, o que é essencial em linguagens como C, nas quais a gestão manual da memória é obrigatória. A função responsável pela liberação percorreu toda a lista, nó a nó, garantindo que todos os recursos alocados fossem devolvidos ao sistema.

A escolha pelas listas encadeadas é respaldada teoricamente pelo renomado livro Algoritmos: Teoria e Prática, de Thomas H. Cormen, que destaca as vantagens dessa estrutura em cenários que demandam flexibilidade no uso da memória e eficiência em operações dinâmicas. A implementação também foi fundamentada em princípios discutidos em recursos confiáveis, como o site Gabriel Bueno - REA/AED e o portal de algoritmos do IME USP, ambos focados na aplicação prática de estruturas de dados em C.A orientação teórica fornecida pelos professores Bruna Michelly de Oliveira Silva e Aldo André Díaz Salazar foi crucial para o sucesso do projeto. As aulas e materiais disponibilizados por eles enfatizaram a importância da modularidade e do uso eficiente de estruturas dinâmicas.

### Conclusão:
Os resultados demonstraram que o programa atende plenamente aos critérios de eficiência, segurança e modularidade, evidenciando sua viabilidade para aplicações práticas, como sistemas bancários. O projeto destacou a importância de um planejamento cuidadoso e de uma estrutura modular, que não apenas facilita a manutenção, mas também possibilita a expansão do sistema. Além disso, reforçou o papel fundamental das listas encadeadas como uma solução flexível e eficaz para lidar com problemas que envolvem dados dinâmicos.

Fluxograma:
Segue o Fluxograma do projeto: 

![Fluxograma do Projeto](assets/FluxogramaFinal.jpg)


