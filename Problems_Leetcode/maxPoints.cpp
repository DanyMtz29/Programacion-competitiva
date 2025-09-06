#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& points){ 
    unordered_map<double,int> mp;
    double m = 0;
    int mxPoints = 0;
    for(int i=0;i<points.size();i++){
        int x1 = points[i][0];
        int y1 = points[i][1];
        
        for(int j=i+1;j<points.size();j++){
            int x2 = points[j][0];
            int y2 = points[j][1];
            double x = x2-x1;
            double y = y2-y1;
            if(x==0) m=0;
            else m = y/x;

            if(y==0) m=10001;

            mp[m]++;
            mxPoints = max(mp[m],mxPoints);
        }
        
        mp.clear();
    }
    return mxPoints+1;
}

int main(){
    
    return 0;
}