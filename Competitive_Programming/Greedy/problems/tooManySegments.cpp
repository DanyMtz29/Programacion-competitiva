//https://codeforces.com/problemset/problem/1249/D2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<tuple<ll, ll, int>> seg(n);
    for (int i = 0; i < n; i++){
        ll l, r;
        cin >> l >> r;
        seg[i] = {l, r, i + 1};
    }

    sort(seg.begin(), seg.end(),
         [](auto &A, auto &B){
             return get<0>(A) < get<0>(B);
         });

    multiset<pair<ll, int>> st;
    vector<int> removed;

    for (auto &t : seg)
    {
        int l, r, id;
        tie(l, r, id) = t;
        while (!st.empty() && st.begin()->first < l){
            st.erase(st.begin());
        }

        st.insert({r, id});

        if ((int)st.size() > k){
            auto it = prev(st.end());
            removed.push_back(it->second);
            st.erase(it);
        }
    }

    cout << removed.size() << "\n";
    for (int x : removed)
        cout << x << " ";
    cout << "\n";

    return 0;
}
