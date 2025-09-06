#include <iostream>
#include <vector>
using namespace std;

void added(vector<int>& f, vector<int>& s,vector<vector<int>>& res, int& i, int& j){
    if(f[0]<=s[1]){
        if(f[1]>s[1]){
            res.push_back(vector<int>{f[0],s[1]});
            j++;
        }else if(f[1]==s[1]){
            res.push_back(vector<int>{f[0],s[1]});
            i++;
            j++;
        }else{
            res.push_back(vector<int>{f[0],f[1]});
            i++;
        }
    }
}

void added2(vector<int>& f, vector<int>& s,vector<vector<int>>& res, int& i, int& j){
    if(s[1]>=f[0]){
        if(s[1]>=f[1]){
            res.push_back(vector<int>{f[0],f[1]});
            i++;
        }else{
            res.push_back(vector<int>{f[0],s[1]});
            j++;
        }
    }else j++;
}

vector<vector<int>> solve(vector<vector<int>>& firstList, vector<vector<int>>& secondList){
    vector<vector<int>> res;
    int i,ii,j,jj;
    i = ii = j = jj = 0;
    int sz1 = firstList.size();
    int sz2 = secondList.size();
    while(i<sz1 && j<sz2){
        if(i==j){
            int mx = 0;
            if(firstList[i][ii]>secondList[j][jj]){
                added(firstList[i],secondList[j],res,i,j);
            }else{
                added(secondList[j],firstList[i],res,j,i);
            }
        }else{
            if(i>j){
                added2(firstList[i],secondList[j],res,i,j);
            }else{
                added2(secondList[j],firstList[i],res,j,i);
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondtList = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> res = solve(firstList,secondtList);
    //cout<<"asdasd"<<endl;
    cout<<"{ ";
    for(vector<int> vec: res){
        cout<<"{"<<vec[0]<<","<<vec[1]<<"},";
    }
    cout<<"}"<<endl;
    return 0;
}