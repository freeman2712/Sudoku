#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define GRID 9

int sudokuSolver(int ar[][GRID], int, int);
int isValid(int ar[][GRID], int, int, int);
void takeInput(int ar[][GRID])
{
    int i = 0;
    int j = 0;
    for(i = 0; i<GRID; i++){
        for(j = 0; j<GRID; j++){
            scanf("%d", &ar[i][j]);
        }
    }
    return;
}
void printAnswer(int ar[][GRID]);
int main(){
    std::cout << "Enter the Sudoku. 0 if is empty: \n";
    int ar[GRID][GRID] = {0};
    takeInput(ar);
    std::cout << "\n\n";
   // printAnswer(ar);
   sudokuSolver(ar, 0, 0);
    printAnswer(ar);
}
void printAnswer(int ar[][GRID])
{
    for(int i = 0; i<GRID; i++)
    {
        for(int j = 0; j<GRID; j++)
        {
            std::cout << ar[i][j] << " ";
        }
        std::cout << "\n";
    }
    return;
}
int sudokuSolver(int ar[][GRID], int row, int col)
{
    if(row == 9)
        return 1;
    for(int i = 1; i<=GRID; i++)
    {
        if(col == GRID)
        {
            if(sudokuSolver(ar, row+1, 0))
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
        if(ar[row][col])
        {
            if(sudokuSolver(ar, row, col+1))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }    
        else
        {
            if(isValid(ar, row, col, i))
            {
                ar[row][col] = i;
                if(sudokuSolver(ar, row, col+1))
                {
                    return 1;
                }
                else
                {
                    ar[row][col] = 0;
                }
                
            }
        }
        
    }
    return 0;
    
}
int isValid(int ar[][GRID], int row, int col, int num)
{
    for(int i = 0; i<GRID; i++)
    {
        if(ar[row][i] == num && i !=col)
            return 0;
        if(ar[i][col] == num && i != row)
            return 0;
    }
    int row_c = row - row%3;
    int col_c = col - col%3;
    for(int i = row_c; i<(row_c+3); i++)
    {
        for(int j = col_c; j<(col_c+3); j++)
        {
            if(ar[i][j] == num && i !=row && j!=col)
                return 0;
        }
    }
    return 1;
}