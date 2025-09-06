#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newArray;
        if(intervals.size()==0){
            newArray.push_back(newInterval);
            return newArray;
        }
        int li = newInterval[0];
        int ls = newInterval[1];
        bool flag = false;
        
        int i = 0;
        for(;i<intervals.size();i++){
            if(intervals[i][1]>li){
                if(intervals[i][0]<li){
                    li = intervals[i][0];
                }
                break;
            }else{
                newArray.push_back(intervals[i]);
            }
        }
        for(;i<intervals.size();i++){
            if(intervals[i][0]>ls){
                newArray.push_back({li,ls});
                break;
            }else{
                if(intervals[i][1]>=ls){
                    ls = intervals[i][1];
                    newArray.push_back({li,ls});
                    i++;
                    break;
                }
            }
        }
        for(;i<intervals.size();i++){
            newArray.push_back(intervals[i]);
        }
        return newArray;
    }

int main(){
    
    vector<vector<int>> intervals ={{1,5}};
    vector<int> newInterval = {2,3};
    vector<vector<int>> n = insert(intervals,newInterval);
    cout<<"New intervals"<<endl;
    for(vector<int>& v: n){
        cout<<"{"<<v[0]<<","<<v[1]<<"}"<<endl;
    }
    cout<<endl;
    return 0;
}
