    #include <bits/stdc++.h>
    using namespace std;

    int gcd(int a, int b){
        if(b==0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }

    void show(vector<vector<int>>& v){
        cout<<"Matrix"<<endl;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                cout<<v[i][j]<<"|";
            }
            cout<<endl;
        }
    }

    //No procesado
    //False
    //True
    void dfs(vector<vector<int>>& v, vector<vector<int>>& visit, int i, int j, int n, int m, int G){
        if(v[i][j] % G == 0){
            visit[i][j] = 2;
            if(i+1<n && visit[i+1][j]==0){
                dfs(v,visit,i+1,j,n,m,G);
            }
            if(j+1<m && visit[i][j+1]==0){
                dfs(v,visit,i,j+1,n,m,G);
            }
        }else{
            visit[i][j] = 1;
        }
    }

    int solve(vector<vector<int>>& v, int n, int m){
        int G = gcd( v[0][0], v[n-1][m-1] );
        vector<int> divisors;
        for(int i=1;i*i<=G;i++){
            if(G%i == 0){
                divisors.push_back(i);
                divisors.push_back(G/i);
            }
        }
        int sz = divisors.size();

        vector<vector<int>> visit(n, vector<int>(m,0));
        sort(divisors.begin(), divisors.end(), greater<int>());

        /*cout<<"Arreglo"<<endl;
        copy( divisors.begin(), divisors.end(), ostream_iterator<int> (cout, "|") );
        cout<<endl;*/

        for(int i=0 ; i<sz ; i++){

            dfs(v,visit,0,0,n,m,divisors[i]);

            //show(visit);

            if(visit[n-1][m-1]==2){
                return divisors[i];
            }else{
                for(int k=0;k<n;k++){
                    visit[k].assign(m,0);
                }
            }
        }
        return -1;
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        int c;
        cin>>c;
        
        while(c--){    
            int n,m;
            cin>>n>>m;

            vector<vector<int>> v(n, vector<int>(m));
            //vector<vector<int>> dp(n,vector<int>(m,0));

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>v[i][j];
                }
            }
            cout<<solve(v,n,m)<<endl;
        }
        
        return 0;
    }