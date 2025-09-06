#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n;

	m = sqrt(n) + 1;

	int a[n], blocks[m];
	memset(blocks, 0, sizeof(blocks));

	for (int i = 0; i < n; i++){
		cin >> a[i];
		blocks[i / m] += a[i];
	}

	int q;
	cin >> q;
	while (q--){
		int opt, l, r, ans = 0;
		cin >> opt >> l >> r;
		if (opt == 2){ // QUERY
			for (int i = l; i <= r;){
				if (i % m == 0 && i + m - 1 <= r){
					// lies completely inside the [l...r]
					ans += blocks[i / m];
					i += m;
				}
				else{
					ans += a[i];
					i++;
				}
			}

			cout << ans << endl;
		}
		else{ // Update
			int idx = l;
			int value = r;
			blocks[idx / m] += (value - a[idx]);
			a[idx] = value;
		}
	}

	return 0;
}