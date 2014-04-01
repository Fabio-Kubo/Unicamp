#include <stdio.h>

int main()
{
	float   prova1, prova2, prova3, trab1, trab2, trab3, exame,
		mediaProva, mediaTrab,
		mediaParcial, mediaFinal;	
	
	scanf("%f %f %f %f %f %f %f", &prova1, &prova2, &prova3, &trab1, &trab2, &trab3, &exame);

	mediaProva = (3*prova1 + 3*prova2 + 4*prova3)/10;
	mediaTrab = (trab1 + trab2 + trab3)/3;

	mediaParcial = (7*mediaProva + 3*mediaTrab) / 10;

	if (mediaParcial <  5 && mediaParcial >= 2.5)	
		mediaFinal = (exame + mediaParcial) / 2;	
	else	
		mediaFinal = mediaParcial;
	

	if (mediaFinal >= 5)
		printf("Aprovado\n");
	else
		printf("Reprovado\n");

	return 0;
}
