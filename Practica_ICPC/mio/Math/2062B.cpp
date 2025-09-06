#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int x;cin>>x;
            int dist = 2*max(i, n-1-i);
            if( x <= dist ) flag = false;
        }

        cout<<( flag?"YES":"NO")<<endl;

    }

    return 0;
}
