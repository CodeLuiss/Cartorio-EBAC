#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h>  //biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsalvel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file, ","); // coloca uma "," para separar os dados
	fclose(file);//fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //"%s" todos vez que � preciso salvar uma string
	
	file = fopen(arquivo, "a");//abrindo arquivo para atualiza��o de dados
	fprintf(file,nome);//salva o nome dentro do arquivo 
	fclose(file);//fecha o arquvio
	
	file = fopen(arquivo, "a");// "a" atualiza o arquivo
	fprintf(file,","); // coloca uma "," para separar os dados
	fclose(file);//fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abrindo arquivo para atualiza��o de dados
	fprintf(file,sobrenome);//salva o sobrenome dentro do arquivo 
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");// "a" atualiza o arquivo
	fprintf(file,",");// coloca uma "," para separar os dados
	fclose(file);//fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abrindo arquivo para atualiza��o de dados
	fprintf(file,cargo);//salva o cargo dentro do arquivo 
	fclose(file);//fecha o arquivo 
	
	system("pause");//pausa para o usuario ter tempo de ler a resposta 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Difeinindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;//busca o arquivo na biblioteca/cria
	file = fopen(cpf,"r");//busca o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n");
	}
	
	system("pause");//pausa para o usuario ver a resposta 
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);//responsavel por buscar e deletar o usuario
	
	FILE *file;
	file = fopen(cpf, "r");//O "r" se refere a leitura do arquivo, ele abre o arquivo para ler
	
	if(file == NULL)//quando o file � = a NULL 
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");//pausa para o usuario ver a resposta 
	}
	
}

int main()
    {
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls");//responsavel por limpar a tela 
	    
	    setlocale(LC_ALL, "Portuguese"); //Difeinindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
   	    printf("\t1 - Registar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o: "); 	//fim do menu
 
	    scanf("%d", &opcao); //armazenando escolhas do usuario
	
	    system("cls"); //responsavel por limpar a tela 
	 
	    switch(opcao)//inicio da sele��o
	    {
	    	case 1:
	        registro();//chamada de fun��es
	    	break;
		
	    	case 2:
	     	consulta();//chamada de fun��es
	    	break; 
		
	    	case 3:
	    	deletar();//chamada de fun��es
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	    	
		
	    	default:
     		printf("Essa op��o n�o est� disponivel!\n");
	    	system("pause");
	    	break;//fim da sele��o 
	    }	
    } 
}
