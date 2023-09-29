#include <iostream>
#define N 9
using namespace std;

int grid[N][N] = {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
};



bool isPresentInCol(int col, int num) {    
   
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   
   return false;
}



bool isPresentInRow(int row, int num) {   
   
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}



bool isPresentInBox(int boxStartRow, int boxStartCol, int num) {   
   
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}



void sudokuGrid() {    
   for (int row = 0; row < N; row++) {
      cout<<"[ ";
      for (int col = 0; col < N; col++) {
        
         cout << grid[row][col] <<" ";
      }
      cout<<"]"<<endl;

      }
      cout << endl;
   
}



bool findEmptyPlace(int &row, int &col) {    
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) 
            return true;
   return false;
}




bool isValidPlace(int row, int col, int num) {
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 , col - col%3, num);
}





bool solveSudoku() {
   int row, col;
   if (!findEmptyPlace(row, col))
      return true;     
   for (int num = 1; num <= 9; num++) {     
      if (isValidPlace(row, col, num)) {    
         grid[row][col] = num;
         if (solveSudoku())     
            return true;
         grid[row][col] = 0;    
      }
   }
   return false;
}





int main() {
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}
