#include <stdio.h> //Biblioteca que posiibilita o Printf
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o (acentos e �)
#include <string.h> // biblioteca responsavel pelo String



int registro(){
	
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria uma pasta
	file = fopen(arquivo, "w"); //cria um novo arquivo dentro dessa pasta
	fprintf(file,cpf); //armazena o dado no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //voc� est� atualizando o arquivo dentro da pasta
	fprintf(file, ", ");	//virgula colocada para separar
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf ("%s", sobrenome);
	
	file =fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
}

int consulta(){

char cpf[40];
char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file = fopen(cpf, "r"); //leia o arquivo de cadastro
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado\n"); //se o CPF estiver cadstrado digite essa menssagem
		
	}
	while(fgets(conteudo, 200, file) != NULL) //pesquisa dentro dos arquivos o cpf
	{
		printf("\n Essas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
			
	 } 
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado (apenas n�meros): ");
	scanf("%s", cpf);	
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		fclose(file);
		printf("O arquivo a ser deletado n�o existe. \n");
		system("pause");
	}
	
	else if (file != NULL)
	{
		fclose(file);
		printf("O arquivo foi deletado. Espero que voc� tenha digitado certo! :) \n");
		system("pause");
		remove (cpf);
	}
	
}



int main(){
	int opcao=0;
	int repeat=1;
	for(repeat=1; repeat=1;){
	
	
	system("cls");
	setlocale(LC_ALL, "Portuguese"); 
	
		printf("Escolha uma das op��es desejada no menu:\n\n"); //\n pula uma linha
		printf("============Cart�rio da EBAC ============\n|\t\t\t\t\t|\n");
		printf("|\t 1 - Registrar nomes\t\t|\n");
		printf("|\t 2 - Consultar nomes\t\t|\n");
		printf("|\t 3 - Deletar nomes\t\t|\n");
		printf("|\t 4 - Sair do Sistema\t\t|\n");
		printf("=========================================\n\n");
		//printf("Op��o: ");

	scanf("%d", &opcao);
	system("cls");
	
	switch(opcao)
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
		
		case 4:
		printf("Obrigado por utilizar o sistema");
		return 0;
		break;
		
		default: printf("!!ERRO!! !!ERRO!! !!ERRO!! !!ERRO!!\n");
		printf("A OP��O DIGIADA N�O EXISTE\n");	
		system("Pause");
		break;
		
		
	}
}
}
 

