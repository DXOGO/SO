#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc){
	
	srand(time(0));						// random seed generator
	int num, guess, tries = 0;			// inicializar variaveis
	char term;							// verificaçao q faz o rpgrama continuar apos escrer o numero e clicar ENTER
	num = rand() % 100 + 1;				// random number between 0 and 100

	if (argc < 2){                               // num de argumentos passados
            printf("Insira argumentos! \n");
            return EXIT_FAILURE;
    }
	
	printf("Enter a number betweeen 0 and 100: ");
		
	do{
		
		if( ( scanf("%d%c", &guess, &term) == 2 ) && term == '\n'){	// so continua se houverem 2 argumentos e forem numero e paragrafo

			tries++;						// every time a guess is given +1 tries
			if(guess < num){
				printf("Too low! Try again: ");
			}
			else if (guess > num){
				printf("Too high! Try again: ");
			}
			else{
				printf("Congratulations! You guessed it in %d tries!\n", tries);
			}
		}

		else{
			printf("Invalid input!\n");
			return EXIT_FAILURE;
		}

	} while (guess != num);		//  loop while user guess != number
	
	return EXIT_SUCCESS;
}
