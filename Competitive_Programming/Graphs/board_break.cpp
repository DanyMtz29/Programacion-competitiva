#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

class Node
{
public:
    char s;
    unordered_map<char, Node *> children;
    string word;
    bool isTerminal;

    Node(char s)
    {
        this->s = s;
        isTerminal = false;
        word = "";
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void addWord(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
                temp->children[ch] = new Node(ch);

            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};

void dfs(char board[3][4], Node *node, int i, int j, bool visited[3][4], unordered_set<string> &ans)
{
    char ch = board[i][j];
    if (node->children.count(ch) == 0) // No lo contiene
        return;
    // cout << "Llega con" << board[i][j] << endl;

    visited[i][j] = true;
    node = node->children[ch];
    if (node->isTerminal)
    {
        ans.insert(node->word);
    }

    // Explorar todos los vecinos en las 8 direcciones
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    for (int k = 0; k < 8; k++)
    {
        int newI = i + dx[k];
        int newJ = j + dy[k];

        if (newI >= 0 && newJ >= 0 && newI < 3 && newJ < 4 && !visited[newI][newJ])
            dfs(board, node, newI, newJ, visited, ans);
    }
    visited[i][j] = false;
    return;
}

int32_t main()
{
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};
    char board[3][4] = {{'S', 'E', 'R', 'T'},
                        {'U', 'N', 'K', 'S'},
                        {'T', 'C', 'A', 'T'}};

    // Crear Arbol
    Trie t;
    for (string word : words)
        t.addWord(word);

    // Un set para volver a colocar las palabras ya encontradas
    unordered_set<string> ans;

    bool visited[3][4] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dfs(board, t.root, i, j, visited, ans);
        }
    }

    cout << "Answer" << endl;
    for (auto s : ans)
        cout << s << endl;

    return 0;
}