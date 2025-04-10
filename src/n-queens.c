#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int isValidSolution(int *cols, int *diag1, int *diag2, int n, int row, int col)
{
    // Check if the column or diagonals are already attacked
    if (cols[col] || diag1[row + col] || diag2[row - col + (n - 1)])
        return (0);
    return (1);
}

void solve(int **board, int n, int row, int *count, int *cols, int *diag1, int *diag2)
{
    int col;

    // Base case: if we've placed queens in all rows
    if (row == n)
    {
        (*count)++;
        return;
    }

    for (col = 0; col < n; col++)
    {
        if (isValidSolution(cols, diag1, diag2, n, row, col))
        {
            // Place the queen at (row, col)
            cols[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + (n - 1)] = 1;
            board[row][col] = 1;  // Mark the position

            // Recursively place the next queen
            solve(board, n, row + 1, count, cols, diag1, diag2);

            // Backtrack: Remove the queen and reset the tracking arrays
            cols[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + (n - 1)] = 0;
            board[row][col] = 0;  // Backtrack and unmark the position
        }
    }
}

int totalNQueens(int n)
{
    int **board;
    int count = 0;
    int *cols;
    int *diag1;
    int *diag2;
    int i;

    if (n == 1)
        return (1);  // Special case for 1x1 board

    if (n == 2 || n == 3)
        return (0);  // No solution for 2x2 or 3x3

    // Allocate memory for the board
    board = malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        board[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }

    // Allocate arrays for column and diagonal checks
    cols = malloc(sizeof(int) * n);
    diag1 = malloc(sizeof(int) * (2 * n - 1));
    diag2 = malloc(sizeof(int) * (2 * n - 1));

    // Initialize all the tracking arrays to 0
    for (i = 0; i < n; i++)
    {
        cols[i] = 0;
    }
    for (i = 0; i < 2 * n - 1; i++)
    {
        diag1[i] = 0;
        diag2[i] = 0;
    }

    // Start solving from the first row
    solve(board, n, 0, &count, cols, diag1, diag2);

    // Free the allocated memory
    free(cols);
    free(diag1);
    free(diag2);
    for (i = 0; i < n; i++)
    {
        free(board[i]);
    }
    free(board);

    return (count);
}

int main()
{
    int n = 8;
    printf("Total solutions for n=%d: %d\n", n, totalNQueens(n));
    return 0;
}
