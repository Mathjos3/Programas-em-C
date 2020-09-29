#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<windows.h>

	//um simples jogo da forca :)

	void gotoxy(int x, int y)
	{
		COORD c;
		c.X=x-1;
		c.Y=y-1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	}

	char texto[40]; //guarda um texto 
	char dica[80]; //e uma dica

	//Desenha uma cabeça
	void cabeca()
	{
		gotoxy(55,6); printf("O");
	}
	
	//desenha um corpo
	void meio()
	{
		gotoxy(55,7); printf("|");
		gotoxy(54,7); printf("/");
		gotoxy(56,7); printf("\\");
	}

	//desenha as pernas
	void pernas()
	{
		gotoxy(55,8); printf("|");
		gotoxy(54,9); printf("/");
		gotoxy(56,9); printf("\\");
	}

	//desenha a forca
	void forca()
	{
		int l,c;
		
		for(l=5;l<=11;l++)
		{  	
			gotoxy(50,l); printf("|");
		}
		
		for(c=50;c<=55;c++)
		{  	
			gotoxy(c,4); printf("_");
		}
		
		gotoxy(55,5); printf("|");
		gotoxy(49,11); printf("_|_");
	}

int main(){	

	int liberaLaco;
	int achou, acertos, erro, tentativas;
	int i,j,opc;
	char letra, opcao, palavra[40];
	char oculto[40],dicas[80];

	setlocale(LC_ALL,"Portuguese");
	
	//laço de repeticao principal
	do
	{
		system("cls");
		fflush(stdin);
	
		do
		{
			system("cls");
			fflush(stdin);
	
			gotoxy(40,8);
			printf("JOGO DA FORCA");
			
			gotoxy(40,10);
			printf("Insira uma palavra: ");
			gets(texto);
			
			gotoxy(40,12);
			printf("e uma dica: ");
			gets(dica);
	
			if(strlen(texto)>40)
			{
				printf("Escolha palavras menores que 40 letras");
				liberaLaco = 1;
			}
			else
			{
				liberaLaco = 0;
			}
	
		}while(liberaLaco!=0);

		//inicializando
		achou = 0;
		acertos = 0;
		erro = 0;
		tentativas = 3;
			
		strcpy(palavra,"");
		strcpy(dicas,"");
			
		system("cls");//limpa a tela
			
		strcpy(palavra,texto); // copiando valor string da variavel TEXTO para a variavel PALAVRA
		strcpy(dicas,dica); // copiando valor string da variavel DICA para a variavel DICAS
			
		forca(); //montando a forca
			
		j=48; //coluna na 48
		
		//montando os caracteres ocultos _
		for(i = 0; i<strlen(palavra); i++)
		{
			gotoxy(j,13);
			oculto[i]='_'; 
			printf("%c",oculto[i]);
			j = j + 2; //somando mais 2 na coluna j
		}
	
		gotoxy(42,19);
		printf("%s",dicas);
	
		do
		{ //laço para repetir tentativas
				
			gotoxy(50,15);
			printf("             "); //para esconder
			
			fflush(stdin);
			gotoxy(48,15);
			printf("resposta: ");
				
			opcao=getch();
				
			gotoxy(42,21);
			printf("Tentativa anterior: %c",opcao); //mostra valor do getch()
			
			j=48; //coluna na 48
		
			for(i = 0; i<strlen(palavra);i++)
			{
					
				letra = tolower(opcao); //pegando string convertida para minusculo
					
				if(letra == palavra[i])
				{ 	
					oculto[i] = palavra[i];
						
					gotoxy(j,13);
						
					printf("%c",palavra[i]);
						
					j=j+2;
						
					acertos++;
					achou=1;
						
					gotoxy(48,15);
			
				}
				else
				{
					gotoxy(j,13);
						
					printf("%c",oculto[i]);
						
					j=j+2;
						
					gotoxy(48,15);
				}
			}
			
			if(!achou == 1){ erro++; }
				
			gotoxy(42,17);
			
			printf("Faltam %d tentativas",tentativas-erro);
				
			if(erro==1){ cabeca(); }
			
			if(erro==2){ meio(); }
			
			if(erro==3){ pernas(); }
				
			achou=0; //zerando o contador achou
		
		}while(acertos!=strlen(palavra) && erro!=3 || erro<3 && acertos!=strlen(palavra));//fim do laço tentativas
		
		if(acertos == strlen(palavra))
		{	
			fflush(stdin);
					
			gotoxy(30,25);
			
			printf("Parabéns! você ganhou! Continuar? [1]Sim - [2]Não: ");
			scanf("%d",&opc);
				
		}
		else
		{
				
			fflush(stdin);
					
			gotoxy(30,21);
			printf("                                       ");//esconder
			gotoxy(40,21);
			
			printf("PALAVRA ESCOLHIDA:  %s",palavra);
			gotoxy(30,25);
			
			printf("Você perdeu! Repetir? [1]Sim - [2]Não: ");
			scanf("%d",&opc);
		}
				
	}while(opc != 2);
}
