#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;
    printf("Enter elements of the matrix:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX],
                      int r1, int c1, int c2)
{
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for transpose
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    int choice;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX], transpose[MAX][MAX];
    int r1, c1, r2, c2;

    do
    {
        printf("\n===== MATRIX OPERATIONS MENU =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if(r1 != r2 || c1 != c2)
                {
                    printf("Matrix addition not possible!\n");
                }
                else
                {
                    printf("Matrix A:\n");
                    inputMatrix(A, r1, c1);

                    printf("Matrix B:\n");
                    inputMatrix(B, r2, c2);

                    addMatrices(A, B, result, r1, c1);

                    printf("\nResult of Addition:\n");
                    displayMatrix(result, r1, c1);
                }
                break;

            case 2:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if(c1 != r2)
                {
                    printf("Matrix multiplication not possible!\n");
                }
                else
                {
                    printf("Matrix A:\n");
                    inputMatrix(A, r1, c1);

                    printf("Matrix B:\n");
                    inputMatrix(B, r2, c2);

                    multiplyMatrices(A, B, result, r1, c1, c2);

                    printf("\nResult of Multiplication:\n");
                    displayMatrix(result, r1, c2);
                }
                break;

            case 3:
                printf("Enter rows and columns of Matrix: ");
                scanf("%d%d", &r1, &c1);

                inputMatrix(A, r1, c1);

                transposeMatrix(A, transpose, r1, c1);

                printf("\nTranspose of Matrix:\n");
                displayMatrix(transpose, c1, r1);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}