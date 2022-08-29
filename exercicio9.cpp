#include<stdio.h>
#include<stdlib.h>
#include<string.h>//BIBLIOTECAS

int menu(int op);
void adicionar(char proximaMusica[], char proximoArtista[], float tempoMusica);
void listagem(char proximaMusica[], char proximoArtista[], float tempoMusica);//CABE�ALHOS DAS FUN��ES


struct playlist {
	char artista[50], musica[50];//ESTRUTURA HETEROG�NEA DE DADOS
	float duracao;
	playlist* segundoItem;
}*HEAD;

int main() //FUN��O PRINCIPAL
{
	char proximaMusica[50],proximoArtista[50];//DECLARA��O DE VARI�VEIS
	float tempoMusica;
	int op=0,c;
	op = menu(op);
	while (1)//LA�O DE REPETI��O
	{
		switch (op)//ESTRUTURA DE SELE��O
		{
		case 1:
			
			printf("Nome do artista:\n");
			gets_s(proximoArtista);
			printf("Nome da musica:\n");
			gets_s(proximaMusica);
			printf("Duracao da musica:\n");
			scanf_s("%f", &tempoMusica);
			while ((c = getchar())!='\n'&&c!= EOF) {}//LIMPA BUFFER DE TECLADO
			
			
			adicionar(proximaMusica, proximoArtista, tempoMusica);//CHAMANDO FUN��O

			break;
		case 2:
			printf("MINHA PLAYLIST:\n\n");
			listagem(proximaMusica, proximoArtista, tempoMusica);//CHAMANDO FUN��O

			break;
		case 3:
			return 0;
			break;

		default:
			printf("opcao invalida");
			break;
		}
		op = menu(op);
	}


	system("pause");//PAUSA A TELA
	return 0;
}
int menu(int op)//FUN��O MENU
{
	int c;
	printf("1-Adicionar nova musica\n");
	printf("2-Mostrar playlist\n");
	printf("3-Sair\n");
	printf("Escolha uma opcao:");
	scanf_s("%d", &op);
	while ((c=getchar())!='\n'&&c!=EOF){}//LIMPA BUFFER DE TECLADO
	

	return op;//RETORNO DA FUN��O DO TIPO INTEIRO
}
void adicionar(char proximaMusica[],char proximoArtista[],float tempoMusica)//FUN��O E SEUS RESPECTIVOS PAR�METROS
{
	playlist* novaMusica;//CRIA��O DE UM PONTEIRO
	novaMusica = (playlist*)malloc(sizeof(playlist));//ALOCA��O DE MEM�RIA
	strcpy_s(novaMusica->musica , proximaMusica);
	strcpy_s(novaMusica->artista , proximoArtista);//COPIANDO CONTE�DO DE UMA STRING PARA OUTRA
	novaMusica->duracao = tempoMusica;//TRANFER�NCIA DE DADO PARA MEMBRO DA STRUCT

	if (HEAD == NULL)//CONDI��O
	{
		HEAD = novaMusica;
		novaMusica->segundoItem = NULL;
	}
	else {
		novaMusica->segundoItem = HEAD;
		HEAD = novaMusica;
	}
}
void listagem(char proximaMusica[], char proximoArtista[], float tempoMusica)//FUN��O E SEUS RESPECTIVOS PAR�METROS
{
	
	playlist* iterador;//CRIA��O DE UM PONTEIRO
	iterador = (playlist*)malloc(sizeof(playlist));//ALOCA��O DE MEM�RIA//

	iterador = HEAD;
	if (iterador == NULL)//CONDI��O
	{
		printf("Playlist vazia");//IMPRESS�O NA TELA
	}
	else {
		while (iterador != NULL)//CONDI��O
		{
			printf("musica-> %s\ncantor-> %s\nduracao-> %.2f\n\n", iterador->musica, iterador->artista, iterador->duracao);
			iterador = iterador->segundoItem;//PONTEIRO APONTANDO PARA PR�XIMO ITEM DA LISTA
		}
	}

}
