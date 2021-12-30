#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)			// argv[0] -> 1º argumento
{
	if (argc == 4)		// 4 args, './calculadora', a1, op, a2
	{
		char op = *argv[2];		// op vai ser o 3º argumento posto (depois de ./caculadora e a1)
		double result;			// vai guardar o resultado

		char *pa1,*pa2;						// pa1 e pa2 sao os inputs dos numeros do utilizador, vao estar em string
		double a1 = strtod(argv[1],&pa1);
		double a2 = strtod(argv[3],&pa2);		// transformar pa1 e pa2 para integers
												// onde a1 é o 2º argumento e a2 o 4º
		if(a1 != 0.0 && a2 != 0.0 )				// se ambos numeros forem diferentes de 0 ( senao result = 0.0)
		{
			switch (op){
				case '+':
					result = a1 + a2;
					printf("%.1f %c %.1f = %.1f\n", a1, op, a2, result);
					break;
				case '-':
					result = a1 - a2;
					printf("%.1f %c %.1f = %.1f\n", a1, op, a2, result);
					break;
				case 'x':
					result = a1 * a2;
					printf("%.1f %c %.1f = %.1f\n", a1, op, a2, result);
					break;
				case 'p':
					result = pow(a1,a2);
					printf("%.1f %c %.1f = %.1f\n", a1, op, a2, result);
					break;
				case '/':
					result = a1 / a2;
					printf("%.1f %c %.1f = %.1f\n", a1, op, a2, result);
					break;
				default:
					printf("ERRO: Operação inválida!\n");
					break;
				
			}
			//printf("%.1f %c %.1f = %.1f\n", a1, op, a2, result);
		}
		else {
			if( a1 == 0.0 && a2 == 0.0){
				printf("%.1f %c %.1f = %.1f\n", a1, op, a2, 0.0);
			}
			else{
				printf("ERRO: Por favor introduza 2 números para efetuar a conta!\n");
			}
		}	
	}

	else		// caso n sejam usados 4 argumentos
	{
		printf("ERRO: Número errado de argumentos!\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


