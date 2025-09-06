#include <bits/stdc++.h>
#define int long long int
using namespace std;

const char movs[] = {'L', 'D', 'R', 'U'};

void valid(vector<vector<char>> &map, vector<vector<int>> &visited, vector<vector<int>> &path, queue<pair<int, int>> &q, int R, int C, int r, int c, int i, int j, int car)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
    {
        if (visited[i][j] == 1)
            return;
        if (visited[i][j] == 2)
        {
            if (path[r][c] + 1 < path[i][j])
            {
                path[i][j] = path[r][c] + 1;
                map[i][j] = car + '0';
            }
            else if (path[r][c] + 1 == path[i][j])
            {
                if (car < map[i][j] - '0')
                {
                    map[i][j] = car + '0';
                }
            }
        }
        else
        {
            if (map[i][j] != '#' && map[i][j] != 'X')
            {
                visited[i][j] = 2;
                path[i][j] = path[r][c] + 1;
                map[i][j] = car + '0';
                q.push(make_pair(i, j));
            }
            else
            {
                visited[i][j] = 1;
            }
        }
    }
}
void fillMap(vector<vector<char>> &map, int R, int C, int iE, int jE)
{
    vector<vector<int>> visited(R, vector<int>(C, 0));
    queue<pair<int, int>> q;
    q.push(make_pair(iE, jE));
    vector<vector<int>> path(R, vector<int>(C, 0));
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        visited[i][j] = 2;
        q.pop();
        valid(map, visited, path, q, R, C, i, j, i, j + 1, 0); // Derecha
        valid(map, visited, path, q, R, C, i, j, i - 1, j, 1); // Arriba
        valid(map, visited, path, q, R, C, i, j, i, j - 1, 2); // Izquierda
        valid(map, visited, path, q, R, C, i, j, i + 1, j, 3); // Abajo
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int R, C;
    cin >> R >> C;
    vector<vector<char>> map(R, vector<char>(C));
    int iE = 0;
    int jE = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'E')
            {
                iE = i;
                jE = j;
            }
        }

    fillMap(map, R, C, iE, jE);
    int Q;
    cin >> Q;
    while (Q--)
    {
        int psI, psJ;
        cin >> psI >> psJ;
        psI--;
        psJ--;
        if (map[psI][psJ] == '.')
            cout << "?" << endl;
        else if (map[psI][psJ] == '#')
            cout << "W" << endl;
        else if (map[psI][psJ] == 'X')
            cout << "X" << endl;
        else if (map[psI][psJ] == 'E')
            cout << "E" << endl;
        else
        {
            int val = (map[psI][psJ] - '0');
            cout << movs[val] << endl;
        }
    }
    return 0;
}