#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector<int> graph[N];
vector<int> topologicalOrder;
int visited[N];
// The states will be handled as follows
// 0-unvisited, 1-visiting, 2-visited
bool hasCycle = false;
void dfs(int cur, int par){
	visited[cur] = 1; // In visiting
	for (auto x : graph[cur]){
		if (visited[x] == 0)
			dfs(x, cur);
		else if (visited[x] == 1){ // There is a cycle in the graph
			hasCycle = true;
			return;
		}
	}
	visited[cur] = 2;
	topologicalOrder.push_back(cur);
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	for (int i = 1; i <= n; i++){
		if (visited[i] == 0)
			dfs(i, 0);
		if (hasCycle)
			break;
	}

	if (hasCycle)
		cout << "There is a cycle" << endl;
	else{
		reverse(topologicalOrder.begin(), topologicalOrder.end());
		for (auto x : topologicalOrder)
			cout << x << " ";
	}
	return 0;
}