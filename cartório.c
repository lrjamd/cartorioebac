#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema

{	//inicio cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// fim cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf( "%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, o "w" � para escrever
	fprintf(file, cpf); // salvo o valor da vari�vel
	fclose (file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza informa��es, o "a" atualiza o arquivo criado anteriormente
	fprintf (file, ","); // criando a virgula entre as informa��es
	fclose (file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a"); // atualiza informa��es
	fprintf(file, nome);
	fclose (file);
	
	file = fopen(arquivo, "a"); //atualiza informa��es
	fprintf (file, ","); // criando a virgula entre as informa��es
	fclose (file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // atualiza informa��es
	fprintf(file, sobrenome);
	fclose (file);
	
	file = fopen(arquivo, "a"); //atualiza informa��es
	fprintf (file, ","); // criando a virgula entre as informa��es
	fclose (file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose (file);
	
	system("pause"); // pausando o sistema
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // difinindo lingua (para assentua��es)
	
	
	char cpf[40]; // criando vari�vel/string
	char conteudo [200]; 
	
	printf("Digite o CPF a ser consultado: "); //comunica��o com o usu�rio
	scanf("%s", cpf);
	
	FILE *file; // buscando arquivo
	file = fopen(cpf,"r"); // "r" significa read, assim l� os documentos da pasta
	
	
	if(file == NULL) // condi��o para arquivos n�o encontrados
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! . \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // busca das informa��es
	{ 
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40]; // cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio: ");
	scanf("%s", cpf);
	
	remove(cpf); // remove a vari�vel informada
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio informado n�o se encontra no sistem\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0; // definindo a variavel
	int laco=1;
	
	for(laco=1;laco=1;)

	{ 	
	
		system("cls");
		
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	  	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1.Registrar aluno\n");
		printf("\t2.Consultar aluno\n");
		printf("\t3.Deletar aluno\n\n\n\n\n");
		printf("Op��o:  "); // fim do menu
	
		scanf("%d" , &opcao ); // armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta ();
			break;
			
			case 3:
			deletar ();
			break;
			
			default:
			printf("essa op��o n�o est� disponivel\n");
			system("pause");
			break;
				
		}
	}
}
