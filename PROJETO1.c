#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>  //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
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
	scanf("%s",nome); //"%s" todos vez que é preciso salvar uma string
	
	file = fopen(arquivo, "a");//abrindo arquivo para atualização de dados
	fprintf(file,nome);//salva o nome dentro do arquivo 
	fclose(file);//fecha o arquvio
	
	file = fopen(arquivo, "a");// "a" atualiza o arquivo
	fprintf(file,","); // coloca uma "," para separar os dados
	fclose(file);//fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abrindo arquivo para atualização de dados
	fprintf(file,sobrenome);//salva o sobrenome dentro do arquivo 
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");// "a" atualiza o arquivo
	fprintf(file,",");// coloca uma "," para separar os dados
	fclose(file);//fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abrindo arquivo para atualização de dados
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
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
	
	if(file == NULL)//quando o file é = a NULL 
	{
		printf("O usuario não se encontra no sistema!.\n");
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
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
   	    printf("\t1 - Registar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: "); 	//fim do menu
 
	    scanf("%d", &opcao); //armazenando escolhas do usuario
	
	    system("cls"); //responsavel por limpar a tela 
	 
	    switch(opcao)//inicio da seleção
	    {
	    	case 1:
	        registro();//chamada de funções
	    	break;
		
	    	case 2:
	     	consulta();//chamada de funções
	    	break; 
		
	    	case 3:
	    	deletar();//chamada de funções
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	    	
		
	    	default:
     		printf("Essa opção não está disponivel!\n");
	    	system("pause");
	    	break;//fim da seleção 
	    }	
    } 
}
