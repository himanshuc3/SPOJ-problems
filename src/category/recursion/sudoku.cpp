/**
 * Problem: Sudoku solver.
 */
#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][9],int r,int c,int n, int number){
    // Row and column check
    for(int i=0;i<9;i++){
        if(board[r][i]==number||board[i][c]==number){
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = (r/rn)*rn;
    int sy = (c/rn)*rn;
    
    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(board[x][y]==number){
                return false;
            }
        }
    }
    
    return true;
}


void print(int board[][9], int n){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
// Row wise traversal in sudoku board
bool sudokuSolver(int board[][9],int r,int c,int n){
    // Base Case
    if(r==n){
        print(board,n);
        return true;
    }
    // Case row end
    if(c==n){
        return sudokuSolver(board,r+1,0,n);
    }
    
    // Skip prefilled sells
    if(board[r][c]!=0){
        return sudokuSolver(board,r,c+1,n);
    }
    
    // Recursive
    for(int number=1;number<=9;number++){
        if(canPlace(board,r,c,n,number)){
            // Assume this is the correct answer
            board[r][c] = number;
            
            bool aageNumberRakhPaRhe = sudokuSolver(board,r,c+1,n);
            if(aageNumberRakhPaRhe){
                return true;
            }
        }
    }
    
    // Backtrack
    board[r][c] = 0;
    return false;
}


int main() {
    int mat[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    
    sudokuSolver(mat,0,0,9);
	return 0;
}