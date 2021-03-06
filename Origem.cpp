#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>


/*Item 3 - Quais os n�meros com maior frequ�ncia sorteados p�r m�s em cada ano.
Complemento: Mostrar todas as poss�veis combina��es do jogo da Mega Sena.
Autoras do codigo: Adriana Dahmer e Rosiane Quenia Pereira de Almeida
Eng da Computa��o UNINTER*/

void jogosmensal()
{
	FILE* fp;

	errno_t err;

	err = fopen_s(&fp, "temp.csv", "r");//nome do arquivo que desejo abrir

	if (err != 0) {
		printf("Can't open file\n");//quando nao consegue abrir o arquivo retorna zero
		return;
	}
	char buf[CHAR_MAX];
	int row_count = 0;
	int field_count = 0;
	char* next_token1 = NULL;
	int mes = 5, ano = 2020;
	int vetor[60], i, j = 0, maior[6], posi��o, vetormaior[60];
	for (i = 0; i < 60; i++)
	{
		vetor[i] = 0;
		vetormaior[i] = 0;
		if (i < 6)
		{
			maior[i] = 0;
		}
	}

	while (fgets(buf, sizeof(buf), fp)) {
		field_count = 0;
		row_count++;

		if (row_count == 1) {
			continue;
		}

		char* field = strtok_s(buf, " /;\t\n", &next_token1);
		while (field)
		{
			if (field_count == 2)//2 corresponde ao mes
			{
				if (atof(field) != mes)
				{
					do
					{
						for (i = 0; i < 60; i++)
						{
							if (vetor[i] > vetor[maior[j]])
							{
								maior[j] = i;
							}
						}
						vetor[maior[j]] = 0;
						j++;
					} while (j < 6);
					printf("ANO: %d\n", ano);
					printf("MES: %d\n", mes);
					for (i = 0; i < 6; i++)
					{
						printf("BOLA %d : %d\n", i + 1, maior[i] + 1);
					}
					printf("\n\n");
					for (i = 0; i < 60; i++)
					{
						vetor[i] = 0;
						if (i < 6)
						{
							maior[i] = 0;
						}
					}
					mes = atof(field);
					j = 0;
				}
			}
			if (field_count == 3)
			{
				if (atof(field) != ano)
				{
					ano = atof(field);
				}
			}
			if ((field_count > 3) && (field_count < 10))
			{
				posi��o = atoi(field);
				if (posi��o > 0)
				{
					vetor[posi��o - 1] ++;
					vetormaior[posi��o - 1] ++;
				}
			}
			field = strtok_s(NULL, " /;\t\n", &next_token1);
			field_count++;
		}
		// system("pause");
	}
	system("Pause");



}

void analisecombinatoria()

{
	printf("S�o cinco as possibilidades de se realizar um jogo\n");
	printf("- 6 \n- 7\n- 8\n- 9\n- 10\n n�meros\n");

	short QuantJogada;
	do
	{
		printf("Entre com a Quantidade jogada: ");
		scanf_s("%hd", &QuantJogada);
	} while (QuantJogada < 6 || QuantJogada > 10);

	printf("\n\n");

	//Vari�veis que armazenam os c�lculos:
	long n = 1;
	int p = 1;
	long Combinacao;

	//Fatorial de 60
	for (int i = 60; i > (60 - 6); i--)
		n *= (long)i;

	//Fatorial da quantidade jogada
	for (int i = 1; i <= 6; i++)
		p *= i;

	// printf("N: %ld\n", n);
	// printf("P: %d\n", p);


	//C 60,6 = 60! / 6!(60-6)!
	Combinacao = n / p;

	if (QuantJogada == 6)
	{
		printf("Combina��es poss�veis: 1/%ld\n", Combinacao);
	}
	else if (QuantJogada == 7)
	{
		n = 1;
		p = 1;
		for (int i = QuantJogada; i > (QuantJogada - 6); i--)
			n *= (long)i;
		for (int i = 2; i <= 6; i++)
			p *= i;

		printf("Chance � de: %ld / %ld\n", (n / p), Combinacao);
	}
	else if (QuantJogada == 8)
	{
		n = 1;
		p = 1;
		for (int i = QuantJogada; i > (QuantJogada - 6); i--)
			n *= (long)i;
		for (int i = 2; i <= 6; i++)
			p *= i;

		printf("Chance � de: %ld / %ld\n", (n / p), Combinacao);

	}
	else if (QuantJogada == 9)
	{
		n = 1;
		p = 1;
		for (int i = QuantJogada; i > (QuantJogada - 6); i--)
			n *= (long)i;
		for (int i = 2; i <= 6; i++)
			p *= i;

		printf("Chance � de: %ld / %ld\n", (n / p), Combinacao);

	}
	else
	{
		n = 1;
		p = 1;
		for (int i = 10; i > (4); i--)
			n *= (long)i;
		for (int i = 2; i <= 6; i++)
			p *= i;

		printf("Chance � de: %ld / %ld\n", (n / p), Combinacao);
	}


	printf("Pressione enter para ver todas as jogadas poss�veis: \n");
	getchar();

	for (int n1 = 1; n1 <= 60; n1++)
	{
		for (int n2 = n1 + 1; n2 <= 60; n2++)
		{
			for (int n3 = n2 + 1; n3 <= 60; n3++)
			{
				for (int n4 = n3 + 1; n4 <= 60; n4++)
				{
					for (int n5 = n4 + 1; n5 <= 60; n5++)
					{
						for (int n6 = n5 + 1; n6 <= 60; n6++)
						{
							printf("%d - %d - %d - %d - %d -%d\n", n1, n2, n3, n4, n5, n6);
						}
					}
				}
			}

		}
	}
	return;
}

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	int op��o;


	FILE* fp;

	errno_t err;

	err = fopen_s(&fp, "temp.csv", "r");// para abrir o arquivo que desejo

	//     = fopen_s("C:\Aula\Prova\temp.csv", "r");

	if (err != 0) {
		printf("Can't open file\n");//quando nao consegue abrir o arquivo retorna zero
		return 0;
	}

	char buf[CHAR_MAX];
	int row_count = 0;
	int field_count = 0;
	char* next_token1 = NULL;
	int dia = 0;
	do
	{
		printf("Aperte 1 para mostrar todos os sorteios: \n");
		printf("Aperte 2 para mostrar os seis n�meros mais frequentemente sorteados por m�s em cada ano: \n");
		printf("Aperte 3 para mostrar todas as poss�veis combina��es do jogo Mega sena \n");
		scanf_s("%d", &op��o);
		system("CLS");
	} while ((op��o < 1 || op��o > 3));
	if (op��o == 1)
	{
		while (fgets(buf, sizeof(buf), fp)) {
			field_count = 0;//field sao os campos
			row_count++;

			if (row_count == 1) {
				continue;
			}

			char* field = strtok_s(buf, " /;\t\n", &next_token1);
			while (field) {
				if (field_count == 0) {
					printf("Concurso:\t");
				}
				if (field_count == 1) {
					printf("Dia:\t");
					//dia = atoi(field);
				}
				if (field_count == 2) {
					printf("Mes:\t");
				}
				if (field_count == 3) {
					printf("Ano:\t");
				}
				if (field_count == 4) {
					printf("Bola1:\t");
				}
				if (field_count == 5) {
					printf("Bola2:\t");
				}
				if (field_count == 6) {
					printf("Bola3:\t");
				}
				if (field_count == 7) {
					printf("Bola4:\t");
				}
				if (field_count == 8) {
					printf("Bola5:\t");
				}
				if (field_count == 9) {
					printf("Bola6:\t");
				}


				printf("%s\n", field);
				//  printf("dia - int: %d \n\n", dia);
				field = strtok_s(NULL, " /;\t\n", &next_token1);

				field_count++;


			}
			printf("\n");
			// system("pause");
		}
	}
	else if (op��o == 2)
	{
		// abrir fun��es;
		jogosmensal();
	}

	else
	{


		analisecombinatoria();

	}
	fclose(fp);
	system("pause");

	return 0;

}



