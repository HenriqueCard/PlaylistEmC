#include<stdio.h>
#include<stdlib.h>
#include<string.h>//BIBLIOTECAS

int menu(int op);
void adicionar(char proximaMusica[], char proximoArtista[], float tempoMusica);
void listagem(char proximaMusica[], char proximoArtista[], float tempoMusica);//CABEÇALHOS DAS FUNÇÕES


struct playlist {
	char artista[50], musica[50];//ESTRUTURA HETEROGÊNEA DE DADOS
	float duracao;
	playlist* segundoItem;
}*HEAD;

int main() //FUNÇÃO PRINCIPAL
{
	char proximaMusica[50],proximoArtista[50];//DECLARAÇÃO DE VARIÁVEIS
	float tempoMusica;
	int op=0,c;
	op = menu(op);
	while (1)//LAÇO DE REPETIÇÃO
	{
		switch (op)//ESTRUTURA DE SELEÇÃO
		{
		case 1:
			
			printf("Nome do artista:\n");
			gets_s(proximoArtista);
			printf("Nome da musica:\n");
			gets_s(proximaMusica);
			printf("Duracao da musica:\n");
			scanf_s("%f", &tempoMusica);
			while ((c = getchar())!='\n'&&c!= EOF) {}//LIMPA BUFFER DE TECLADO
			
			
			adicionar(proximaMusica, proximoArtista, tempoMusica);//CHAMANDO FUNÇÃO

			break;
		case 2:
			printf("MINHA PLAYLIST:\n\n");
			listagem(proximaMusica, proximoArtista, tempoMusica);//CHAMANDO FUNÇÃO

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
int menu(int op)//FUNÇÃO MENU
{
	int c;
	printf("1-Adicionar nova musica\n");
	printf("2-Mostrar playlist\n");
	printf("3-Sair\n");
	printf("Escolha uma opcao:");
	scanf_s("%d", &op);
	while ((c=getchar())!='\n'&&c!=EOF){}//LIMPA BUFFER DE TECLADO
	

	return op;//RETORNO DA FUNÇÃO DO TIPO INTEIRO
}
void adicionar(char proximaMusica[],char proximoArtista[],float tempoMusica)//FUNÇÃO E SEUS RESPECTIVOS PARÂMETROS
{
	playlist* novaMusica;//CRIAÇÃO DE UM PONTEIRO
	novaMusica = (playlist*)malloc(sizeof(playlist));//ALOCAÇÃO DE MEMÓRIA
	strcpy_s(novaMusica->musica , proximaMusica);
	strcpy_s(novaMusica->artista , proximoArtista);//COPIANDO CONTEÚDO DE UMA STRING PARA OUTRA
	novaMusica->duracao = tempoMusica;//TRANFERÊNCIA DE DADO PARA MEMBRO DA STRUCT

	if (HEAD == NULL)//CONDIÇÃO
	{
		HEAD = novaMusica;
		novaMusica->segundoItem = NULL;
	}
	else {
		novaMusica->segundoItem = HEAD;
		HEAD = novaMusica;
	}
}
void listagem(char proximaMusica[], char proximoArtista[], float tempoMusica)//FUNÇÃO E SEUS RESPECTIVOS PARÂMETROS
{
	
	playlist* iterador;//CRIAÇÃO DE UM PONTEIRO
	iterador = (playlist*)malloc(sizeof(playlist));//ALOCAÇÃO DE MEMÓRIA//

	iterador = HEAD;
	if (iterador == NULL)//CONDIÇÃO
	{
		printf("Playlist vazia");//IMPRESSÃO NA TELA
	}
	else {
		while (iterador != NULL)//CONDIÇÃO
		{
			printf("musica-> %s\ncantor-> %s\nduracao-> %.2f\n\n", iterador->musica, iterador->artista, iterador->duracao);
			iterador = iterador->segundoItem;//PONTEIRO APONTANDO PARA PRÓXIMO ITEM DA LISTA
		}
	}

}
