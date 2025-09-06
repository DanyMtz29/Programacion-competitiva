#include <bits/stdc++.h>

using namespace std;

const int sz = 2;

struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }
    void identity(){
        for(int i=0;i<sz;i++){
            m[i][i] = 1;
        }
    }
    Mat operator*(Mat a){
        Mat res;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                for(int k=0;k<sz;k++)
                    res.m[i][j] += m[i][k] * a.m[k][j];
        return res;
    }
};

int main(){
    return 0;
}