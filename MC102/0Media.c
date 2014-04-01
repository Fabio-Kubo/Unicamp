#include <stdio.h>

int main()
{
	float prova1, prova2, prova3, trab1, trab2, trab3;
	float mediaProva, mediaTrab;
	float mediaFinal;	
	
	scanf("%f %f %f %f %f %f", &prova1, &prova2, &prova3, &trab1, &trab2, &trab3);
	mediaProva = (3*prova1 + 3*prova2 + 4*prova3)/10;
	mediaTrab = (trab1 + trab2 + trab3)/3;

	mediaFinal = (7*mediaProva + 3*mediaTrab) / 10;

	printf("%.2f\n", mediaFinal);
	return 0;
}
