#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void dfs(vector<vector<char>> &board, vector<vector<int>> &m, int i, int j, int mx){
    if(i<0 || j<0 || i>m.size() || j>m[0].size() || board[i][j]=='P' || m[i][j]<mx) return;

    board[i][j] = 'P';
    dfs(board,m,i+1,j,m[i][j]);
    dfs(board,m,i-1,j,m[i][j]);

    dfs(board,m,i,j+1,m[i][j]);
    dfs(board,m,i,j-1,m[i][j]);
}

void show(vector<vector<char>> &board){
    cout<<"Matriz"<<endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void dfsC(vector<vector<char>> &board, vector<vector<int>> &m,vector<vector<int>> r, int i, int j, int mx){
    if(i<0 || j <0 || i>m.size() || j>m[0].size() || board[i][j]=='C' || m[i][j]<mx) return;

    if(board[i][j]=='P'){
        r.push_back(vector<int>{i,j});
    }
    board[i][j] = 'C';

    dfsC(board,m,r,i+1,j,m[i][j]);
    dfsC(board,m,r,i-1,j,m[i][j]);

    dfsC(board,m,r,i,j+1,m[i][j]);
    dfsC(board,m,r,i,j-1,m[i][j]);
}

vector<vector<int>> solve(vector<vector<int>>& m){
    vector<vector<char>> board(m.size(), vector<char>(m[0].size(),'#'));
    vector<vector<int>> res;
    
    for(int i=0;i<=m.size()-1;i++)
        dfs(board,m,i,0,-1);

    for(int i=0;i<=m[0].size()-1;i++)
        dfs(board,m,0,i,-1);

    for(int i=m.size()-1;i>=0;i--)
        dfsC(board,m,res,i,m[0].size()-1,-1);
    
    for(int i=m[0].size()-1;i>=0;i--)
        dfsC(board,m,res,m.size()-1,i,-1);

    return res;
}

int main(){


    return 0;
}