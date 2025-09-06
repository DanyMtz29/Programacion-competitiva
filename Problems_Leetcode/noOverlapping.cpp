#include <bits/stdc++.h>

using namespace std;

/* ll = 1, lr == 2
    1,2
    1,3 
    2,3
    3,4
 */

int solve(vector<vector<int>>& intervals){
    cout<<"Normal vector"<<endl;
    for(vector<int> v: intervals){
        copy(v.begin(),v.end(),ostream_iterator<int>(cout,","));
        cout<<endl;
    }

    sort(intervals.begin(),intervals.end());

    cout<<"\n\nSort vector"<<endl;
    for(vector<int> v: intervals){
        copy(v.begin(),v.end(),ostream_iterator<int>(cout,","));
        cout<<endl;
    }

    int lr = INT_MIN;
    int ll = INT_MIN;
    int cont = 0;
    for(int i = 0 ; i<intervals.size();i++){
        vector<int>v = intervals[i];
        int left = v[0];
        int rigth = v[1];
        if(left==ll){
            cont++;
        }else{
            if(left>=lr){
                ll = left;
                lr = rigth;   
            }else{
                cont++;
            }
        }
    }

    return cont;
}

int main(){

    //vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3},{2,4},{4,5}};
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4}};
    cout<<"Solve: "<<solve(intervals)<<endl;
    return 0;
}