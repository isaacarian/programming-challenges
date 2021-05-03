#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t rand_seed = time(NULL);
	srand(rand_seed);
	char lcase_letters[26]  = "abcdefghijklmnopqrstuvwxyz";
	char numbers[10] = "0123456789";
	char ucase_letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char special[12] = "@#$%^&*()-_+";

	int select = 0;

	for (int i = 0; i < 16; i++)
	{
		select = rand() % 4;

		switch(select)
		{
			case 0:
				printf("%c", lcase_letters[rand() % 26]);
				break;
			case 1:
				printf("%c", ucase_letters[rand() % 26]);
				break;
			case 2: 
				printf("%c", numbers[rand() % 10]);
				break;
			case 3: 
				printf("%c", special[rand()%12]);
				break;
			default:
				break;
		}	
	}
	printf("\n");
	
	return 0;

}
