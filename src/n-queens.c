#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int     isSolved(int col, int row, int n ,int *cols, int *diag1, int *diag2)
{
    if (diag1[row + col] || cols[col] || diag2[row - col + ( n - 1)])
        return (0);
    return (1);
}

void    ft_print_board(int **board, int n)
{
    int     i;
    int     j;

    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            if (board[i][j] == 1)
                write(1, "Q", 1);
            else
                write(1, ".", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    write(1, "\n", 1);
}

void    solve(int   **board, int n, int *count, int *cols, int *diag1, int *diag2, int row)
{
    int     col;

    if (row == n)
    {
        (*count)++;
        ft_print_board(board, n);
        return ;
    }
    
    col = 0;
    while (col < n)
    {
        if (isSolved(col, row, n , cols, diag1, diag2))
        {
            cols[col] = 1;
            diag1[col + row] = 1;
            diag2[(row - col) + (n - 1)] = 1;
            board[row][col] = 1;
            solve(board, n, count, cols, diag1, diag2, row + 1);
            cols[col] = 0;
            diag1[col + row] = 0;
            diag2[(row - col) + (n - 1)] = 0;
            board[row][col] = 0;
        }
        col++;
    }
}

int     totalNQueens(int n) {
    
    int     **board;
    int     *diag1;
    int     *diag2;
    int     count;
    int     *cols;
    int     i;
    int     j;

    if (n == 1)
        return (1);
    if (n == 2 || n == 3)
        return (0);
    board = malloc(sizeof(int *) * n);
    i = 0;
    while (i < n)
    {
        board[i] = malloc(sizeof(int) * n);
        j = 0;
        while(j < n)
        {
            board[i][j] = 0;
            j++;
        }
        i++;
    }
    j = (2 * n) - 1;
    diag1 = malloc(sizeof(int) * j);
    diag2 = malloc(sizeof(int) * j);
    cols = malloc(sizeof(int) * n);
    i = 0;
    while (i  < n)
    {
        cols[i] = 0;
        i++;
    }
    i = 0;
    while (i < j)
    {
        diag1[i] = 0;
        diag2[i] = 0; 
        i++;
    }
    count = 0;
    solve(board, n, &count, cols, diag1, diag2, 0);
    free(diag1);
    free(diag2);
    free(cols);
    i = 0;
    while (i < n)
    {
        free(board[i]);
        i++;
    }
    free(board);
    return (count);
}

int     main(int argc , char *argv[])
{
    printf("%d\n", totalNQueens(atoi(argv[1])));
    return (0);
}