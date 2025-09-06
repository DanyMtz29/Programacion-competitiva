#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int getGrid(int n){
    if( n < 3 ){
        return 0;
    }else if( n<6 ){
        return 3;
    }else{
        return 6;
    }

}

bool isValid( int row, int col, int digit,  vector< vector< char > >& board){
    //Check Row
    for( int i=0 ;  i < 9 ; i++ ){
        if( board[row][i]==digit) return false;
    }
    //Check col
    for( int i=0 ;  i < 9 ; i++ ){
        if( board[i][col]==digit) return false;
    }
    //Check matrix
    int i = 0 , j = 0;
    i = getGrid( row );
    j = getGrid( col );
    for( int r = i; r < i+3; r++ ){
        for( int c = j; c < j+3; c++ ){
            if( board[i][j]==digit ) return false;
        }
    }

    return true;
}

bool solve(vector< vector< char > >& board, int row, int col, vec& nums){
    
}

void sudokuSolver( vector< vector< char > >& board ){
    
}

int32_t main(){
    
    return 0;
}