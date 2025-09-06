#include <bits/stdc++.h>
using namespace std;

//A:4, B:1, C:1, D:1, G:1
//A_A_A_A
//mpartCount = mx-1;3
//partLEngth = n-(maxCount-1);
//EmptySlots = partCount * partLength;
//availableSlots = tasks.length-max*maxCount;
//idles = max(0, emptySlots - availableSlots)
int solve(vector<char>& tasks, int n){
    vector<int> letters(26,0);
    int mx = 0;
    int mxCount = 0;
    for(char c: tasks){
        letters[c-'A']++;
        if(mx<letters[c-'A']){
            mx = letters[c-'A'];
            mxCount=1;
        }else if(mx==letters[c-'A']){
            mxCount++;
        }
    }
    
    int maximos = mx-1;
    int resto = n-(mxCount-1);
    int espacios = maximos * resto;

    return 1;
}

int main(){
    vector<char> a = {'A','A','A','B','B','B'};
    cout<<solve(a,3)<<endl;
    return 0;
}