//https://leetcode.com/problems/word-search/
#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<double>
#define vvb vector<vector<double>>
#define forN(n,v) for(int i=0;i<n;i++) cin>>v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())
#define umii unordered_map<int,int>
#define INFS 1e9
#define INFI -1e9
#define all(x) x.begin(), x.end()
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pb push_back
#define F first
#define S second
const int MOD=1e9+7;
using namespace std;

struct node{
    node *next[26];
    bool is_end;
    string suffix;
    node(){
        for( int i = 0; i < 26; i++ ) next[i]=NULL;
        is_end = false;
        suffix = "";
    }
};

node *root;
set<string> ans;

void insert(string s){
    node *cur = root;

    for( char c: s ){
        int character = c-'a';
        if( cur->next[character] == NULL )
            cur->next[character] = new node();

        string prevSuffix = cur->suffix;
        cur = cur->next[character];

        cur->suffix = prevSuffix;
        cur->suffix += (character+'a');
    }
    cur->is_end = true;
}

void search_word(int i, int j, vector<vector<char>>& board, node* cur){
    if( i >= board.size() || i < 0 || j >= board[i].size() || j < 0 ) return;

    char currChar = board[i][j]-'a';
    if( cur->next[currChar] == NULL) return;

    
    cur = cur->next[currChar];
    
    if( cur->is_end ) ans.insert(cur->suffix);


    search_word( i+1,j, board, cur );
    search_word( i,j+1, board, cur );
    search_word( i-1,j, board, cur );
    search_word( i,j-1, board, cur );
}

vector<string> solve(vector<vector<char>>& board, vector<string>& words){
    root = new node();
    for( string& s: words ) insert(s);

    for( int i = 0; i < board.size(); i++ ){
        for( int j = 0; j < board[i].size(); j++ ){
            node *cur = root;
            search_word(i,j,board, cur);
        }
    }

    int sz = ans.size();
    vector<string> res(sz);
    int i = 0;
    for( auto s: ans){
        res[i++] = s;
    }
    return res;
}

int32_t main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T--){
        vector<vector<char>> board = {{'o','a','a','n'},
                                      {'e','t','a','e'},
                                      {'i','h','k','r'},
                                      {'i','f','l','v'}};
        vector<string> words = {"eat", "oath"};
        vector<string> res = solve(board,words);
        for( auto s: res )
            cout<<s<<"\n";
    }
    return 0;
}