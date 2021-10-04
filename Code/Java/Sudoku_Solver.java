/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
public class Sudoku_Solver{
    static boolean isSafe(char grid[][],int row,int col,char num)
    {
        for(int i=0;i<9;i++)
            if(grid[row][i]!='.'&&grid[row][i]==num)
                return false;
        for(int i=0;i<9;i++)
            if(grid[i][col]!='.'&&grid[i][col]==num)
                return false;
        int r=row-row%3,c=col-col%3;
        for(int i=r;i<r+3;i++)
            for(int j=c;j<c+3;j++)
               if(grid[i][j]!='.'&&grid[i][j]==num)
                return false;  
        return true;
    }
    public static boolean helpSudoku(char[][] grid)
    {
        int row=-1,col=-1;boolean empty=true;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(grid[i][j]=='.')
                {
                    row=i;
                    col=j;
                    empty=false;
                    break;
                }
            }
            if(!empty)
                break;
        }
        if(empty)
            return true;
        for(char i='1';i<='9';i++)
        {
            if(isSafe(grid,row,col,i))
            {
                grid[row][col]=i;
                if(helpSudoku(grid))
                    return true;
                else
                    grid[row][col]='.';
            }
        }
        return false;
    }
    public static boolean solveSudoku(char[][] grid) {
        boolean empty=helpSudoku(grid); 
        return empty; 
    }
    public static void print(char[][] grid)
    {
        int N=grid.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(grid[i][j] + " ");
            System.out.println();
        }
    }
    public static void main(String[] args)
    {
        char grid[][] = { { '3', '.', '6', '5', '.', '8','4', '.', '.' },
                         { '5', '.', '.', '.', '.', '.', '.', '.', '.' },
                         { '.', '8', '7', '.', '.', '.', '.', '3', '1' },
                         { '.', '.', '3', '.', '1', '.', '.', '8', '.' },
                         { '9', '.', '.', '8', '6', '3', '.', '.', '5' },
                         { '.', '5', '.', '.', '9', '.', '6', '.', '.' },
                         { '1', '3', '.', '.', '.', '.', '2', '5', '.' },
                         { '.', '.', '.', '.', '.', '.', '.', '7', '4' },
                         { '.', '.', '5', '2', '.', '6', '3', '.', '.' } };
 
        if (solveSudoku(grid))
            print(grid);
        else
            System.out.println("No Solution exists");
    }
}