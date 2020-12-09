#include <stdio.h>
#include <inttypes.h>

void sizing_msg(void)
{
	printf("Enter size of matrix: \n");
}

void filling_msg(void)
{
	printf("Fill the matrix:\n");
	printf("Row by row\n");
}

void answer_msg(long long int D)
{
	printf("Determinant = %lld", D);
}

print(int** A, int N)
{
    printf("det{");
    for (int j = 0; j < N; j++)
    {
        printf("{");
        for (int i = 0; i < N; i++)
        {
            printf("%d", A[j][i]);
            if (i != N - 1) printf(",");
        }
        printf("}");
        if (j != N - 1)
        {
            printf(" ");
            printf(",");
        }

    }
    printf("}");
}

void print_for_calc(int** A, int N)
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            printf("%d", A[j][i]);
            if (i != N - 1) printf(" ");
        }
        printf("\n");
    }
}