#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

bool dfs(string &s, int index, vector<string> &word, vector<vector<int>> &dp, string &curr, vector<string> &ans);

bool check(string &s, vector<string> &word, vector<vector<int>> &dp, int itS, int itW, string &curr, vector<string> &ans)
{
    cout << "llega con Index: " << itS << endl;
    int sizeW = word[itW].length();
    if (s.length() - itS < sizeW)
        return false;

    int its1 = itS;
    for (int j = 0; j < sizeW; j++)
        if (s[itS++] != word[itW][j])
            return false;

    cout << "Pasa con index: " << itS << endl;
    string sAux = curr + s.substr(its1, itS - its1) + " ";
    if (dfs(s, itS, word, dp, sAux, ans))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dfs(string &s, int index, vector<string> &word, vector<vector<int>> &dp, string &curr, vector<string> &ans)
{
    if (index >= s.length())
    {
        curr.erase(curr.size() - 1, curr.size());
        ans.push_back(curr);
        return true;
    }

    for (int i = 0; i < word.size(); i++)
    {
        cout << "dp: " << dp[index][i] << endl;
        if (s[index] == word[i][0] && (dp[index][i] == 0 || dp[index][i] == 1))
        {
            cout << "Index: " << i << endl;
            if (check(s, word, dp, index, i, curr, ans))
            {
                cout << "entra" << endl;
                dp[index][i] = 1;
                // return true;
            }
            else
                dp[index][i] = 2;
        }
    }
    // return false;
}

int solve(string &s, vector<string> &word)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(word.size() + 1, 0));
    vector<string> ans;
    string curr = "";
    dfs(s, 0, word, dp, curr, ans);
    cout << "Answers" << endl;
    for (string cad : ans)
    {
        cout << cad << endl;
    }
    return 0;
}

int32_t main()
{
    // string s = "applepenapple";
    // vector<string> wordDict = {"apple", "pen"};
    // string s = "leetcode";
    // vector<string> wordDict = {"leet", "code"};
    // string s = "catsanddog";
    // vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    // string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    // vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    if (solve(s, wordDict))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}