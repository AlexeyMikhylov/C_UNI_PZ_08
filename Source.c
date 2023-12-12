#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MI1 4
#define MI2 4

//task 12
#define ansSize MI1+MI2+2

//task 6
#define MI6 4
#define MJ6 4
#define N 100

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
	case 2:
		task2(); printf("\n"); run();
	case 3:
		task3_1(); printf("\n"); run();
	case 4:
		task4(); printf("\n"); run();
	case 5:
		task5(); printf("\n"); run();
	case 6:
		task6_1(); printf("\n"); run();
	case 7:
		task7(); printf("\n"); run();
	case 8:
		task8(); printf("\n"); run();
	case 9:
		task9(); printf("\n"); run();
	case 10:
		task10(); printf("\n"); run();
	case 11:
		task11(); printf("\n"); run();
	case 12:
		task12(); printf("\n"); run();
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

int task2(void)
{
	int M[MI1][MI2];
	int total = 0, closest = 0, closestElt;
	float average;
	int i, j, x = 0, y = 0;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10; // % 10 - from 0 to 10
		}
	}
	closestElt = M[0][0];

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			total += M[i][j];
		}
	}

	printf("total = %d", total); printf("\n");

	average = ((float)total / (MI1 * MI2));
	printf("avg = %.2lf", average); printf("\n");

	closest = abs((average - M[0][0]));

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			if (closest > abs((average - M[i][j]))) {
				closest = abs((average - M[i][j]));
				closestElt = M[i][j];
				x = i; y = j;
			}
		}
	}

	printf("closest to average is M[%d][%d] = %d", x, y, closestElt);
}

int task3(void)
{
	int M[MI1][MI2];
	int count = 0;
	int final = 0;
	int i, j, x, y;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}


	
	for (i = 0; i < MI1; i++)
	{
		for (j = i+1; j < MI2; j++)
		{
			if (M[i] == M[j]) {
				count++;
				break;
			}
		}
	}

	printf("%d", count);
}

#define ROWS 3
#define COLS 3
int task3_1(void)
{
	int array[ROWS][COLS];
	int i, j, total = 0;
	int counts[10] = { 0 };


	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			array[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("\t%d", array[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {

			int currentDigit = array[i][j];
			counts[currentDigit]++;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (counts[i] > 1) {
			printf("Digit %d repeats %d times.\n", i, counts[i]);
			total += counts[i];
		}
	}

	printf("total - %d", total);

	return 0;
}

int task4(void)
{
	int M[MI1][MI2];
	int k = 0, i, j, index = -1;
	int a;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	printf("input a: "); scanf("%d", &a);

	for (i = 0; i < MI1; i++) {
		k = 0;
		for (j = 0; j < MI2; j++) {
			if (M[i][j] % a == 0) {
				k++;
			}
			if (k == MI2) {
				if (index < i) {
					index = i;
				}
			}
		}
	}
	printf("%d", index);
}

int task5(void)
{
	int M[MI1][MI2];
	int positive, negative, i, j, i2[MI2], cnt = 0;

	for (i = 0; i < MI2; i++) {
		i2[i] = -1;
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = -10 + rand() % 20;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (j = 0; j < MI2; j++)
	{
		positive = 0;
		negative = 0;
		for (i = 0; i < MI1; i++)
		{
			if (M[i][j] > 0)
			{
				positive++;
			}
			if (M[i][j] < 0)
			{
				 negative++;
			}
		}
		if (positive == negative)
		{
			i2[j] = j;
		}
	}

	printf("\ncols with equal pos and neg numbers:\n");
	for (i = 0; i < MI2; i++) {
		if (i2[i] >= 0)
		{
			printf("%d", i2[i]);
		}
		else {
			cnt++;
		}
	}
	if (cnt == MI2) {
		printf("no such cols");
	}
}

int task6_1(void)
{
	int n, i, j;

	int matrix[MI6][MJ6] = {
		{1, 2, 2, 2},
		{2, 1, 5, 2},
		{2, 5, 1, 3},
		{2, 2, 3, 1}
	};

	for (i = 0; i < MI6; i++) {
		for (j = 0; j < MJ6; j++) {
			printf("\t%d", matrix[i][j]);
		}
		printf("\n");
	}

	if (checkSymmetric(matrix, MI6)) {
		printf("sym.\n");
	}
	else {
		printf("non sym.\n");
	}
}

int checkSymmetric(int matrix[MI6][MJ6], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (matrix[i][j] != matrix[j][i])
				return 0; //no sym
		}
	}
	return 1; //sym
}

int task7(void)
{
	int M[MI1][MI2];
	int i, j, topQuartSum = 0, cnt = 0;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			if (i == j) {
				M[i][j] = 0;
			}
			else if ((0 + i) == (MI2 - 1 - j))
			{
				M[i][j] = 0;
			}
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	//easy way
	for (i = 0; i < MI1; i++) {
		for (j = i + 1; j < MI1 - i - 1; j++) {
			cnt += M[i][j];
		}
	}
	printf("%d", cnt);

	printf("\n");

	for (i = 0; i < MI1; i++) {
		M[i][0] = 0;
	}

	for (i = 0; i < MI1; i++) {
		M[i][MI2-1] = 0;
	}

	printf("\n\n");

	//nuls under main diagonal
	for (i = 1; i < MI1; i++)
	{
		for (j = i; j < MI2; j++)
		{
			if (M[i][j] == M[j][i]) {
				for (i = j; j < MI1; j++)
				{
					M[j][i] = 0;
				}
			}
		}
	}
	//nulls under sub diagonal
	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			if ((i + j) >= MI1)
			{
				M[i][j] = 0;
			}
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			topQuartSum += M[i][j];
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	printf("%d", topQuartSum);
}

int task8(void)
{
	int M[MI1][MI2];
	int i, j, firstNeg = -1, lastNull = -1;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = -10 + rand() % 20;
		}
	}

	/*int M[MI1][MI2] = {
		{1, -1, 0, -1, 0},
		{-2, 0, -1, -2, 0},
		{-3, -2, 0, -3, 0},
		{0, -3, 0, -4, 0},
		{0, 0, -2, -5, 0}
	};*/

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (j = 0; j < MI2; j++)
	{
		firstNeg = -1;
		lastNull = -1;

		for (i = 0; i < MI1; i++)
		{
			if (M[i][j] < 0 && firstNeg == -1)
			{
				firstNeg = i;
			}
			if (M[i][j] == 0)
			{
				lastNull = i;
			}
		}
		if (firstNeg != -1 && lastNull != -1)
		{
			M[lastNull][j] = M[firstNeg][j];
			M[firstNeg][j] = 0;
		}
	}

	printf("\n");

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}
}

int task9(void)
{
	int M[MI1][MI2];
	int i, j, topQuartSum = 0, subDig[MI1] = { 0 };

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			if ((i + j) == MI1-1)
			{
				subDig[i] = M[i][j];
			}
		}
	}

	for (i = 0; i < MI1; i++) {
		printf("%d", subDig[i]);
	}
}

int task10(void)
{
	int M[MI1][MI2];
	int i, j, sum[MI1] = { 0 }, minSum;
	int ans1[2] = { 0, 1 };

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (j = 0; j < MI1; j++)
	{
		for (i = 0; i < MI2; i++)
		{
			sum[j] += M[i][j];
		}
	}

	printf("\n");

	for (i = 0; i < MI1; i++)
	{
		printf("\t%d", sum[i]);
	}

	minSum = sum[0] + sum[1];
	for (i = 1; i < MI1 - 1; i++)
	{
		if ((sum[i] + sum[i + 1]) < minSum)
		{
			minSum = sum[i] + sum[i + 1];

			ans1[0] = i;
			ans1[1] = i + 1;
		}
	}

	printf("\n");

	for (i = 0; i < 2; i++)
	{
		printf("\t%d", ans1[i]);
	}
}

int task11(void)
{
	int M[MI1][MI2];
	int i, j, a, cnt = 0;
	int ans[MI2] = { 0 };

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			M[i][j] = rand() % 99;
		}
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	printf("input a: "); scanf_s("%d", &a);
	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			if (M[i][j] % 10 == a || M[i][j] == a)
			{
				ans[i]++;
			}
		}
	}

	for (i = 0; i < MI2; i++)
	{
		printf("\n%d", ans[i]);
	}
}

int task12(void)
{
	int M[MI1][MI2];
	int i, j;
	int ans[ansSize] = { 0 };

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			M[i][j] = rand() % 10;
		}
	}

	/*int M[MI1][MI2] = {
		{2, 3, 4},
		{5, 3, 1},
		{2, 3, 4}
	};*/

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			ans[j] += M[i][j];
		}
	}

	for (j = 0; j < MI2; j++)
	{
		for (i = 0; i < MI1; i++)
		{
			ans[MI1+j] += M[j][i];
		}
	}

	for (j = 0; j < MI2; j++)
	{
		for (i = 0; i < MI1; i++)
		{
			if (i == j)
			{
				ans[MI1+MI2] += M[j][i];
			}
		}
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			if ((i + j) == MI1 - 1)
			{
				ans[MI1+MI2+1] += M[i][j];
			}
		}
	}

	printf("\n");
	for (i = 0; i < ansSize; i++)
	{
		printf("\t%d", ans[i]);
	}

	if (isequal(ans)) {
		printf("\nmagical :)");
	}
	else
	{
		printf("\nnot magical :(");
	}
}

int isequal(int array[ansSize])
{
	for (int i = 0; i < ansSize-1; i++)
	{
		if (array[i] != array[i+1])
		{
			return 0;
		}
	}
	return 1;
}