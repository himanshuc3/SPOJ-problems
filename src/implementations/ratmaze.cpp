/**
 * Problem: Rat maze. 
 * Lesson: Implementing 2-D grid recursion is kind of difficult for me at this point. But getting hang of it.
 * 
 */
#include<bits/stdc++.h>
using namespace std;



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
bool ratMaze(int board[10][10],int sol[][10], int i,int j, int n){
    // Reached the end point
    // Print the board and return
    if(i==n-1&&j==n-1){
        // Print the board
        printBoard(sol,n);
        return true;
    }
    
    // Outside grid 
    if(i>=n||j>=n){
        return false;
    }
    
    //blocked point
    if(board[i][j]==-1){
        sol[i][j] = -1;
        return false;
    }
    
    
    // Assume solution exists through current cell
    sol[i][j] = 1;
    
    bool rightSuccess = ratMaze(board,sol,i,j+1,n);
    bool downSuccess = ratMaze(board,sol,i+1,j,n);
    
    // Backtracking
    // Always comes after recursion call.
    // Basically, we are setting current solution point to 0 because we are returning from 
    // function call and therefore setting sol 0 before returning.
    sol[i][j] = 0;
    
    if(rightSuccess||downSuccess){
        return true;
    }else{
        return false;
    }
    
    
    
    // for(int j=0;j<n;j++){
    //     //Place queen at (i,j)th index
    //     if(isSafePoint(board,i,j,n)){
    //         board[i][j] = 1;
    //         //Recursive call - Check for the next rows
    //         bool IsNextQueenPossible = solveNQueens(board, i+1, n);
    //         if(IsNextQueenPossible){
    //             return true;
    //         }
    //         //Next queen not possible, so backtrack and find another solution
    //         board[i][j] = 0;
    //     }
    // }
    // All positions tried, every one of them failed
    return false;
}

void setBlocks(int board[][10], int n){
    board[1][2] = -1;
    board[2][3] = -1;
    board[3][1] = -1;
}


int main() {
    int board[10][10] = {0}, sol[10][10] = {0};
    int n;
    cin>>n;
    setBlocks(board,n);
    bool isSolved = ratMaze(board,sol, 0 , 0, n);
    
    
    
    
	return 0;
}