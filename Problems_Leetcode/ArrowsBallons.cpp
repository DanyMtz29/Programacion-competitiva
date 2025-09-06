#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& points){
    sort(points.begin(),points.end());
    /*cout<<endl;
    for(vector<int> v: points){
        cout<<"{"<<v[0]<<","<<v[1]<<"}"<<endl;
    }
    cout<<endl;*/

    int arrows = 1;
    int ls = points[0][1];
    for(int i=1;i<points.size();i++){
        if(points[i][0]<ls){
            ls = min(points[i][1],ls);
        }else{
            //cout<<"{"<<points[i][0]<<","<<points[i][1]<<"}"<<endl;
            arrows++;
            ls = points[i][1];
        }
    }
    //cout<<"Arrows: "<<arrows<<endl;
    return arrows;
}

int main(){
    //vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> points = {{1,2},{2,8},{1,6},{7,12}};
    cout<<solve(points)<<endl;
}