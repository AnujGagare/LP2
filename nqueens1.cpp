#include <iostream>
using namespace std;

bool isSafe(int row, int col, int **board, int n) {
  //Check row and column attacks
  for (int i = 0; i < n; i++) {
    if (board[row][i] == 1 || board[i][col] == 1) return false;
  }

  //diagonal attacks
  //top left diagonal
  int i = row, j = col;
  while (i >= 0 && j >= 0) {
    if (board[i][j] == 1) return false;
    i--;
    j--;
  }

  //bottom left diagonal
  i = row, j = col;
  while (i < n && j >= 0) {
    if (board[i][j] == 1) return false;
    i++;
    j--;
  }

  //top right diagonal
  i = row, j = col;
  while (i >= 0 && j < n) {
    if (board[i][j] == 1) return false;
    i--;
    j++;
  }

  //bottom right diagonal
  i = row, j = col;
  while (i < n && j < n) {
    if (board[i][j] == 1) return false;
    i++;
    j++;
  }

  return true;
}

void printSolution(int **board, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << "----------------------" << endl;
}

void solveNQueens(int **board, int col, int n, int &solutionCount) {
  if (col >= n) {
    solutionCount++;
    cout << "Solution #" << solutionCount << ":\n";
    printSolution(board, n);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (isSafe(i, col, board, n)) { 
      board[i][col] = 1;
      solveNQueens(board, col + 1, n, solutionCount); 
      board[i][col] = 0;
    }
  }
}

int main() {
  int n;
  cout << "Enter the board size (n): ";
  cin >> n;
  
  int** board = new int*[n];
  for (int i = 0; i < n; i++) {
      board[i] = new int[n];
      for (int j = 0; j < n; j++) {
          board[i][j] = 0;
      }
  }

  int solutionCount = 0;
  solveNQueens(board, 0, n, solutionCount);

  if (solutionCount == 0)
    cout << "No solution exists" << endl;
  else
    cout << "Total solutions: " << solutionCount << endl;

  return 0;
}

