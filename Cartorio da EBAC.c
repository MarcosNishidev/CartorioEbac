#include <stdio.h>//biblioteca de comunicação ao usuário
#include <stdlib.h>// biblioteca de alocação de espaço de memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável de cuidar das string

int registro()//Função responsável por cadastrar os usuários no sitema
{
	//ínicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,"cpf: "); //Título do campo CPF
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e o "a" significa atualizar o arquivo
	fprintf(file,", Nome: ");//Título do campo Nome
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");// campo que o usuário irá digitar o nome a ser cadastrado
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre e o "a" significa atualizar o arquivo
	fprintf(file,nome);// salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o aqrquivo e o "a" significa atualizar o arquivo
	fprintf(file,", Sobrenome: ");//Título do campo Sobrenome
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//campo que o usuário irá digitar o sobrenome a ser cadastrado
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o aqrquivo e o "a" significa atualizar o arquivo
	fprintf(file,sobrenome);//Salva o valor da variavel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o aqrquivo e o "a" significa atualizar o arquivo
	fprintf(file,", Cargo: ");//Título do campo Cargo
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Campo que o usuário irá digitar o Cargo a ser cadastrado
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,cargo);//Salva o valor da variavel
	fclose(file);// Fecha o arquivo
	
    system("pause");//Pausa o sistema	
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[100];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
    {
	    printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }
	
    while(fgets(conteudo, 100, file) != NULL)
    {
	    printf("\nEssas são as informações do usuário: ");
	    printf("%s", conteudo);//%s refere-se a string
	printf("\n\n");
   }
  	
    system ("pause");	
    fclose(file);
   }

int deletar()
{

	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);//%s refere-se a string
		
	FILE *file;
	file = fopen(cpf,"r");
	if(file == NULL)
	
	{
		
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");//Pausa o sistema
		
	}
	
	else
	
	{
		
		fclose(file);
		remove(cpf);//comando para remover o arquivo selecionado...
		printf("Usuário deletado com sucesso!.\n");
		system("pause");//Pausa o sistema
		
	}
}


int main()
{
	int opcao=0;//definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpeza de tela

	    setlocale(LC_ALL, "Portuguese");//definindo as linguagens
	
    	printf("### Cartório da EBAC ###\n\n");//Inicio do menu
	    printf("Escolha a opção desejada do menu\n\n");
	    printf("\t1 - Registrar nome\n"); //opções do menu
	    printf("\t2 - Consultar nome\n"); //opções do menu
    	printf("\t3 - Deletar nome\n\n"); //opções do menu
    	
    	printf("Opção: ");// Fim do menu

    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); //limpeza de tela
	
	    switch(opcao) //inicio da seleção
    	{
	       case 1:
	       registro();
	       break;
		
	     	case 2:
    		consulta();
      		break;
		
    		case 3:
    	    deletar();
    		break;
    		
    		default:
    		printf("Essa opcão não está disponivel!\n");
    		system("pause");
    		break;
        } //fim da seleção
			
	}
	
}








