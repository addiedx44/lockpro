//
// lock_pro.c
//
// Written by Der gruene V0gel (Adam Dunson)
//
// Purpose: To speed up the process of cracking a Master Lock
//          combination lock.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char buffer[4]; // stores input

	int i, j;       // counter
	int rem;        // stores the remainder, ie, the "magic number"

	int num1[10];   // possible first combination number array
	int num2[10];   // possible second combination number array
	int num3=0;     // third combination number specified by the user

	if(argc>1)      // if user specified input at command-line, read the input
	{
		sscanf(argv[1], "%d", &num3);
	}
	else {          // else, ask user for input
		printf("Input the combination's third number (must be between 0-39): ");
		fgets(buffer, 30, stdin);
		sscanf(buffer, "%d", &num3);
	}
	if(num3 < 0 || num3 > 39) exit(EXIT_FAILURE); // exit program and return EXIT_FAILURE if input is bad

	rem = num3 % 4;     // get the "magic number"

	num1[0] = rem;      // initialize possible first number array
	//
	for(i=1; i<10; i++) // create the rest of the first number array
	{
		if(num1[i-1] + 4 <= 39) num1[i] = num1[i-1] + 4;
	}
	// initialize second number array . . .
	if(rem == 0 || rem == 1) num2[0] = rem + 2;         // add 2 if "magic number" is 0 or 1
	else if(rem == 2 || rem == 3) num2[0] = rem - 2;    // else subtract 2 if it's 2 or 3

	for(i=1; i<10; i++) // create the rest of the second number array
	{
		if(((num2[i-1] + 4) <= 39)) num2[i] = num2[i-1] + 4;
	}

	printf("Possible first numbers:  ");    // print the first number array
	for(i=0; i<10; i++)
	{
		printf("%d  ", num1[i]);
	}

	printf("\nPossible second numbers: ");  // print the second number array
	for(i=0; i<10; i++)
	{
		switch(num3) // filter output
		{
			case 0:
				if(num2[i] != 38 && num2[i] != num3 + 2)
				{
					printf("%d  ", num2[i]);
				}
				break;
			case 1:
				if(num2[i] != 39 && num2[i] != num3 + 2)
				{
					printf("%d  ", num2[i]);
				}
				break;
			case 38:
				if(num2[i] != 0 && num2[i] != num3 - 2)
				{
					printf("%d  ", num2[i]);
				}
				break;
			case 39:
				if(num2[i] != 1 && num2[i] != num3 - 2)
				{
					printf("%d  ", num2[i]);
				}
				break;
			default:
				if(num2[i] != num3 - 2 && num2[i] != num3 + 2)
				{
					printf("%d  ", num2[i]);
				}
		}
	}

	printf("\nPossible combinations:\n"); // list all possible combination
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			if(num2[j] != num3 - 2 && num2[j] != num3 + 2)
			{
				switch(num3)    // filter output
				{
					case 0:
						if(num2[j] != 38 && num2[j] != num3 + 2)
						{
							printf("(%d, %d, %d)\n", num1[i], num2[j], num3);
						}
						break;
					case 1:
						if(num2[j] != 39 && num2[j] != num3 + 2)
						{
							printf("(%d, %d, %d)\n", num1[i], num2[j], num3);
						}
						break;
					case 38:
						if(num2[j] != 0 && num2[j] != num3 - 2)
						{
							printf("(%d, %d, %d)\n", num1[i], num2[j], num3);
						}
						break;
					case 39:
						if(num2[j] != 1 && num2[j] != num3 - 2)
						{
							printf("(%d, %d, %d)\n", num1[i], num2[j], num3);
						}
						break;
					default:
						if(num2[j] != num3 - 2 && num2[j] != num3 + 2)
						{
							printf("(%d, %d, %d)\n", num1[i], num2[j], num3);
						}
				}
			}
		}
	}

	return EXIT_SUCCESS;    // if the program has reached this point, go ahead and return EXIT_SUCCE
}
