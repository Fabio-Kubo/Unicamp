#include <stdio.h>
#include <string.h>

int isVogal(char caracter)
{
	return caracter == 'a' || caracter == 'A'
		|| caracter == 'e' || caracter == 'E'
		|| caracter == 'i' || caracter == 'I'
		|| caracter == 'o' || caracter == 'O'
		|| caracter == 'u' || caracter == 'U';
}

char retornaCaracterMaisFrequente(int vetorCaracter[])
{
	int i, contador = 0;
	char charMaisFrequente;

	for(i = 0; i < 256; i++)
	{
		if(vetorCaracter[i] > contador)
		{
			contador = vetorCaracter[i];
			charMaisFrequente = i;				
		}
	}

	return charMaisFrequente;	
}

int main()
{
	char string[101], maiorPalavra[101], palavraAtual[101];
	int qtdCaracteres[256];
	int qtdVogais = 0, i;
	char charMaisFrequente;
	int tamanho = 0;

	//inicializando o contador de caracteres
	for(i = 0; i < 256; i++)
		qtdCaracteres[i] = 0;

	//Lendo o texto
	scanf("%[^\n]s", string);
	
	for(i = 0; string[i] !='\0'; i++)
	{
		if(isVogal(string[i]))		
			qtdVogais++;		

		qtdCaracteres[(int)string[i]]++;

		if(string[i] != ' ')
		{			
			palavraAtual[tamanho] = string[i];
			tamanho++;
			palavraAtual[tamanho + 1] = '\0';
		}
		else
		{

			if(strlen(maiorPalavra) < strlen(palavraAtual))
				strcpy(maiorPalavra, palavraAtual);
			palavraAtual[0] = '\0';
			tamanho = 0;
		}
	}
	
	palavraAtual[tamanho + 1] = '\0';
	if(strlen(maiorPalavra) < strlen(palavraAtual))
	{
		strcpy(maiorPalavra, palavraAtual);
	}

	charMaisFrequente = retornaCaracterMaisFrequente(qtdCaracteres);

	printf("%d; %s; %c; %d\n", qtdVogais, maiorPalavra, charMaisFrequente, qtdCaracteres[(int)charMaisFrequente]);

	return 0;
}
