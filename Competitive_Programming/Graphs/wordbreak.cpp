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
    int it;
    bool isTerminal;

    Node(char s, int i)
    {
        this->s = s;
        isTerminal = false;
        it = i;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0', -1);
    }

    void addWord(string word, int it)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
                temp->children[ch] = new Node(ch, -1);

            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->it = it;
    }
};

bool dfs(string &s, Trie &t, Node *node, int i, int sz, vector<vector<bool>> &dp)
{
    // cout << "Llega con letra: " << s[i] << endl;
    if (i >= sz)
        return false;
    // cout << "pasa1" << endl;
    if (node->children.count(s[i]) == 0)
        return false;

    // cout << "pasa2" << endl;
    node = node->children[s[i]];
    if (node->isTerminal)
    {
        if (node->it != -1)
        {
            if( dp[i][node->it] ){
                
            }
        }

        if (i == sz - 1)
            return true;

        if (dfs(s, t, t.root, i + 1, sz, dp))
            return true;
    }

    // cout << "pasa3" << endl;
    if (dfs(s, t, node, i + 1, sz, dp))
        return true;

    // cout << "pasa4" << endl;
    return false;
}

bool solve(string &s, vector<string> &word)
{
    Trie t;
    vector<vector<bool>> dp(s.length(), vector<bool>(word.size(), true));
    for (int i = 0; i < word.size(); i++)
        t.addWord(word[i], i);

    int sz = s.length();
    if (dfs(s, t, t.root, 0, sz, dp))
        return true;

    return false;
}

int32_t main()
{
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    if (solve(s, wordDict))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}