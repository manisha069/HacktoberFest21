#include<iostream>
using namespace std;

bool danger(int **board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
        if (board[i][col] && row!=i)
            return true;

    for (int i=row-1, j=col-1 ; i>=0 && j>=0 ; i--, j--)
        if (board[i][j])
            return true;

    for (int i=row-1, j=col+1 ; i>=0 && j<n ; i--, j++)
        if (board[i][j])
            return true;
    return false;
}

void nQueen(int **board, int row, int col, int n)
{
    if (row>=n)
    {
        for (int i = 0; i < n; i++)
        {
            cout<<"("<<i<<",";
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                    cout<<j<<")"<<endl;
            }
            cout<<endl;
        }
        exit(0);
        return;
    }
    for (int i=0; i<n; i++)
        if (!danger(board,row,i,n))
        {
            board[row][i] = 1;
            nQueen(board,row+1,0,n);
            board[row][i] = 0;
        }
}

int main()
{
    int n;
    cin>>n;

    int** board;
    board = new int*[n];
    for (int i=0; i<n; i++)
        board[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    nQueen(board,0,0,n);

    return 0;
}