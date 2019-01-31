/**
 * Problem: Solve n queen. Multiple combinations printed instead of just 1 configuration.
 * 
 */
#include<bits/stdc++.h>
using namespace std;


bool isSafe(int board[][10], int i,int j, int n){
    
    // Checking for columns
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    
    // Check left diagonal
    int x = i,y = j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    
    // Check right diagonal
    x = i;
    y = j;
    while(x>-0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    
    return true;
}

void printBoard(int board[10][10], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// Recursive
bool solveNQueens(int board[10][10], int i, int n){
    // Base case
    if(i==n){
        // Print the board
        printBoard(board,n);
        return false;
    }
    
    // Recursively place queens
    for(int j=0;j<n;j++){
        //Place queen at (i,j)th index
        if(isSafe(board,i,j,n)){
            board[i][j] = 1;
            //Recursive call - Check for the next rows
            bool IsNextQueenPossible = solveNQueens(board, i+1, n);
            if(IsNextQueenPossible){
                return true;
            }
            //Next queen not possible, so backtrack and find another solution
            board[i][j] = 0;
        }
    }
    // All positions tried, every one of them failed
    return false;
}




int main() {
    int board[10][10] = {0};
    int n;
    cin>>n;
    bool isSolved = solveNQueens(board, 0 , n);
    
    
    
    
	return 0;
}