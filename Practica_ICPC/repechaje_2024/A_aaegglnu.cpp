#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;

    vector< pair< string, string> > dic(N);

    for( int i = 0; i < N; i++ ){
        string s,s1;
        cin>>s;
        s1 = s;
        sort( s.begin(), s.end() );
        dic[i] = {s, s1};
    }

    sort( dic.begin(), dic.end() );

    int Q;
    cin>>Q;
    for( int i = 0; i < Q; i++ ){
        string b, b1;

        cin>>b;
        b1 = b;
        sort(b.begin(), b.end());

        int total = upper_bound(dic.begin(), dic.end(), make_pair(b, b1)) - dic.begin();

        cout<<total<<endl;
    }

    return 0;
}