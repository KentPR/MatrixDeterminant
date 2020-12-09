#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> // чтобы использовать функцию time()
#include "Msg.h"

int input(void);
int** memory_allocation(int N);
int** filling_matrix(int** A, int N);
int** Fill_new(int** A, int N, int column, int raw);
int Finding_det(int** A, int N);
void print(int** A, int N);

int main()
{
    srand(time(NULL));
    sizing_msg();
    int N = input();
    int** Matrix = memory_allocation(N);
    filling_msg();
    Matrix = filling_matrix(Matrix, N);
    print(Matrix, N);
    _getch();
    int D = Finding_det(Matrix, N);

    answer_msg(D);

    return 0;
}

int input(void)
{
    int N = 0;
    scanf("%d", &N); 
    return N;
}

int** memory_allocation(int N)
{
    int** A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) 
    {
        A[i] = (int*)malloc(N * sizeof(int));
    }
    return A;
}

int** filling_matrix(int** A, int N)
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            A[j][i]=rand() % (9 - -9 + 1) + -9;
        }
    }
    return A;
}

void print(int** A,int N)
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
    //printf("\nEnd\n");
}

void freedom(int** A,int N)
{
    for (int i = (N - 1); i >= 0; i--)
    {
        free(A[i]);
    }
    free(A);
    A = NULL;
}

int** Fill_new(int **A, int N, int raw, int column)
{
    int** B = memory_allocation(N - 1);

    int k = 0;
    for (int j = 1; j < N; j++)
    {
        int l = 0;
        if (j != raw); 
        {
            for (int i = 0; i < N; i++)
            {
                if (i != column)
                {
                    B[k][l] = A[j][i];
                    l++;
                }
            }
            k++;
        }
    }
    //printf("%dst minor\n", column + 1);
    //print(B, N - 1);
    //printf("\n");
    return B;
}

int C(int j,int i,int N)
{
    int place = j * N + i;
    if (!(place % 2))
        return 1;
    else
        return -1;
}

int Finding_det(int** A, int N)
{
    if (N == 1)
    {
        //printf("bottom");
        return A[0][0];
    }

    int current_det = 0;
    for (int i = 0; i < N; i++)
    {
        int** B = Fill_new(A, N, 0, i);
        //print(B, N - 1);
        int c = C(0, i, N);
        int tmp = c * A[0][i] * Finding_det(B, N-1);
        freedom(B, N-1);
        current_det += tmp;
    }
    return current_det;
}