#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

void usage()
{
	printf("Uso:\n");
	puts("calculadora -s -a num -b num");
	puts("calculadora -r -a num -b num");
	puts("calculadora -m -a num -b num");
	puts("calculadora -d -a num -b num");
}

float suma(float a, float b)
{
	return a + b;
}

float resta(float a, float b)
{
	return a - b;
}

float multiplicacion(float a, float b)
{
	return a * b;
}

float division(float a, float b)
{
	if (b > 0)
		return a / b;
	return -1.f;
}

int main(int argc, char **argv)
{

	int option;
	int sflag = 0;
	int rflag = 0;
	int mflag = 0;
	int dflag = 0;
	float a = -1;
	float b = -1;

	while ((option = getopt(argc, argv, "srmda:b:")) != -1)
	{
		switch (option)
		{
		case 's':
			sflag = 1;
			break;

		case 'r':
			rflag = 1;
			break;

		case 'm':
			mflag = 1;
			break;

		case 'd':
			dflag = 1;
			break;

		case 'a':
			a = atof(optarg);
			break;

		case 'b':
			b = atof(optarg);
			break;

		default:
			usage();
			exit(EXIT_FAILURE);
		}
	}

	if (a == -1 || b == -1)
	{
		usage();
		exit(EXIT_FAILURE);
	}

	if (sflag)
		printf("Suma: %.2f + %.2f = %.2f\n", a, b, suma(a, b));

	if (rflag)
		printf("Resta: %.2f - %.2f = %.2f\n", a, b, resta(a, b));

	if (mflag)
		printf("Multiplicacion: %.2f * %.2f = %.2f\n", a, b, multiplicacion(a, b));

	if (dflag)
		printf("Division: %.2f / %.2f = %.2f\n", a, b, division(a, b));
}
