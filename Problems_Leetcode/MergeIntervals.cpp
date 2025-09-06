#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& intervals){
    vector<vector<int>> res;
    //Sort intervals
    sort(intervals.begin(), intervals.end());

    //Merge Intervals
    for(int i=0;i<intervals.size();i++){
            int limit = intervals[i][1];
            int j = i+1;
            int li = intervals[i][1];
            cout<<"jIni: "<<j<<endl;
            cout<<"li: "<<li<<endl;
            while(j<intervals.size() && limit>=intervals[j][0]){
                li = max(intervals[j][1],li);
                limit = max(intervals[j][1],limit);
                j++;
            }
            cout<<"Limit right: "<<li<<endl;
            cout<<"j: "<<j<<endl;
            res.push_back(vector<int>{intervals[i][0], li});
            i = j-1;
        }

    //Show Intervals
    for(vector<int> vec: intervals){
        cout<<"["<<vec[0]<<","<<vec[1]<<"]"<<endl;
    }
    cout<<"\n\tMerge intervals"<<endl;
    for(vector<int> vec: res){
        cout<<"["<<vec[0]<<","<<vec[1]<<"]"<<endl;
    }

    return res;
}

int main(){
    // vector<vector<int>> intervals = {{2,6},{1,3},{15,18},{8,10}};
    vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    solve(intervals);
    return 0;
}