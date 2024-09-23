#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro() // função responsável por cadastrar os usuários no sistema

{	//inicio criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// fim criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf( "%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, o "w" é para escrever
	fprintf(file, cpf); // salvo o valor da variável
	fclose (file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza informações, o "a" atualiza o arquivo criado anteriormente
	fprintf (file, ","); // criando a virgula entre as informações
	fclose (file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a"); // atualiza informações
	fprintf(file, nome);
	fclose (file);
	
	file = fopen(arquivo, "a"); //atualiza informações
	fprintf (file, ","); // criando a virgula entre as informações
	fclose (file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // atualiza informações
	fprintf(file, sobrenome);
	fclose (file);
	
	file = fopen(arquivo, "a"); //atualiza informações
	fprintf (file, ","); // criando a virgula entre as informações
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
	setlocale(LC_ALL, "Portuguese"); // difinindo lingua (para assentuações)
	
	
	char cpf[40]; // criando variável/string
	char conteudo [200]; 
	
	printf("Digite o CPF a ser consultado: "); //comunicação com o usuário
	scanf("%s", cpf);
	
	FILE *file; // buscando arquivo
	file = fopen(cpf,"r"); // "r" significa read, assim lê os documentos da pasta
	
	
	if(file == NULL) // condição para arquivos não encontrados
	{
		printf("Não foi possivel abrir o arquivo, não localizado! . \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // busca das informações
	{ 
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40]; // criação de variáveis
	
	printf("Digite o CPF do usuário: ");
	scanf("%s", cpf);
	
	remove(cpf); // remove a variável informada
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário informado não se encontra no sistem\n");
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
	
	  	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1.Registrar aluno\n");
		printf("\t2.Consultar aluno\n");
		printf("\t3.Deletar aluno\n\n\n\n\n");
		printf("Opção:  "); // fim do menu
	
		scanf("%d" , &opcao ); // armazenando a escolha do usuário
	
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
			printf("essa opção não está disponivel\n");
			system("pause");
			break;
				
		}
	}
}
