#include <stdio.h>

int main()
{
	int numeroAlunos, i;
	float prova1, prova2, prova3, trab1, trab2, trab3, exame, mediaProva, mediaTrab, mediaFinal;
	scanf("%d", &numeroAlunos);

	for(i = 0; i < numeroAlunos; i++)
	{
		scanf("%f %f %f %f %f %f %f", &prova1, &prova2, &prova3, &trab1, &trab2, &trab3, &exame);
		mediaProva =(3*prova1 + 3*prova2 + 4*prova3)/10;
		mediaTrab = (trab1+trab2+trab3)/3;
 		mediaFinal = (mediaProva*7 + mediaTrab*3)/10;

		if(mediaFinal < 5)
			mediaFinal = (mediaFinal+exame)/2;

		if(mediaFinal < 5 )
			printf("Reprovado\n");
		else
			printf("Aprovado\n");
	}

	return 0;
}
