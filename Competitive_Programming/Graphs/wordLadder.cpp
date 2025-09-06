#include <bits/stdc++.h>
#define int long long int
using namespace std;

int bfs(string beginWord, string endWord, vector<string> &wordList)
{
    int sz = wordList.size();
    int sz2 = beginWord.length();
    unordered_map<string, int> hashSet;
    for (int i = 0; i < sz; i++)
    {
        hashSet[wordList[i]] = i;
    }

    if (!hashSet.count(endWord))
        return 0;

    queue<string> q;
    q.push(beginWord);
    vector<bool> visited(sz, false);
    vector<int> path(sz, 0);
    path[hashSet[beginWord]] = 1;

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        string aux = curr;
        int pat = path[hashSet[curr]];
        cout << "Aux: " << aux << endl;
        cout << "Path: " << pat << endl;
        for (int i = 0; i < sz2; i++)
        {
            char letter = curr[i];
            for (int j = 0; j < 26; j++)
            {
                if (letter == ('a' + j))
                    continue;

                curr[i] = 'a' + j;
                if (hashSet.count(curr) && !visited[hashSet[curr]])
                {
                    cout << "Curr: " << curr << endl;
                    q.push(curr);
                    path[hashSet[curr]] = pat + 1;
                    cout << "Path: " << path[hashSet[curr]] << endl;
                    visited[hashSet[curr]] = true;
                    if (curr.compare(endWord) == 0)
                        return path[hashSet[curr]];
                }
            }
            curr[i] = letter;
        }
    }
    return -1;
}

int32_t main()
{
    // string b = "hit";
    // string e = "cog";
    // vector<string> word = {"hot", "dot", "dog", "lot", "log", "cog"};
    string b = "a";
    string e = "c";
    vector<string> word = {"a", "b", "c"};
    cout << bfs(b, e, word) + 2 << endl;
    return 0;
}