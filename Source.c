#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	run();
}

int run(void)
{
	int taskNumber;
	printf("Task number: "); scanf_s("%d", &taskNumber);

	switch (taskNumber)
	{
	case 0:
		exit(1);
	case 1:
		task1(); printf("\n"); run();
	case 11:
		task1_1(); printf("\n"); run();
	default:
		printf("error");
	}
}


#define I1 7
#define I2 7
int task1_1(void)
{
	int M[I1][I2];
	unsigned i, j;
	for (i = 0; i < I1; i++)     //rows
		for (j = 0; j < I2; j++) //cols
			M[i][j] = i * j;
	do {
		printf("Enter indexes:\n");
		printf("Exit: enter indexes > 7 \n");
		scanf_s("%d", &i);
		scanf_s("%d", &j);
		if (i <= I1 && j <= I2)
			printf("M[%d][%d] == %d\n", i, j, M[i][j]);
		else break;
	} while (1);

	for (i = 0; i < I1; i++)
	{
		for (j = 0; j < I2; j++)
			printf("\t%d", M[i][j]);
		printf("\n");
	}   printf("For exit enter any key...\n");

	getch();
}

#define MI1 4
#define MI2 6
int task1(void)
{
	int M[MI1][MI2];
	int sum = 0, minSum;
	int i, j;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10; // % 10 - from 0 to 10
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}	

	for (j = 0; j < MI2; j++) {
		sum = sum + M[0][j]; 
	}
	minSum = sum;

	for (i = 0; i < MI1; i++) {
		sum = 0;
		for (j = 0; j < MI2; j++) {
			sum = sum + M[i][j]; 
		}
		printf("%d", sum); printf("\n");

		if (minSum > sum) {
			minSum = sum;
		}
	}

	printf("min sum = %d", minSum); printf("\n");
}