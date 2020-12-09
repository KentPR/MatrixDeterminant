#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "Msg.h"

int input(void);
int** memory_allocation(int N);
int** fiiling_matrix(int** A, int N);
void print(int** A, int N);

int main()
{
    sizing_msg();
    int N = input();
    int** Matrix = memory_allocation(N);
    filling_msg();
    fiiling_matrix(Matrix, N);
    print(Matrix, N);
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

int** fiiling_matrix(int** A, int N)
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[j][i]);
        }
    }
    return A;
}

void print(int** A,int N)
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            printf("%d", A[j][i]);
        }
        printf("\n");
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
