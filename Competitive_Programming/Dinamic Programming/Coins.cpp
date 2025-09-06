#include <bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 3001;

ld p[N], memo[N][N];
int n;

ld dp(int i, int h, int t)
{
	cout << "\ni: " << i << endl;
	if (i == n)
		return 1.00;
	ld &ans = memo[i][h];
	if (ans != -1.00)
		return ans;
	ans = 0.00;
	cout << "h: " << h << endl;
	if (h)
	{
		cout << "Entra en h" << endl;
		ans += dp(i + 1, h - 1, t) * p[i];
	}
	cout << "Ans + h: " << ans << endl;
	cout << "\nT: " << t << endl;
	if (t)
	{
		cout << "Entra en t" << endl;
		ans += dp(i + 1, h, t - 1) * (1.00 - p[i]);
	}
	cout << "Ans + T: " << ans << endl;
	return ans;
}

void showMemo()
{
	cout << "MEMO" << endl;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << memo[i][j] << " ";
		}
		cout << "" << endl;
	}
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			memo[i][j] = -1.00;

	ld ans = 0;
	for (int i = (n / 2 + 1); i <= n; i++)
	{
		cout << "\n\ni: " << i << endl;
		ans += dp(0, i, n - i);
		showMemo();
	}

	cout << setprecision(10) << fixed;

	cout << ans;

	return 0;
}