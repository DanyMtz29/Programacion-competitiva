#include <bits/stdc++.h>
using namespace std;

/*  0
    2 4 5 0 1 2 2
*/

bool solve(vector<int>& nums, int target){
    int ls = nums[0];
    int index = 0;
    if(nums[nums.size()-1]>ls){
        ls = nums.size()-1;
    }else if(nums[nums.size()-1]==ls){
        if(target==ls) return true;
        if(target>ls){
            index = nums.size()-1;
        }else{
            index=0;
        }
    }
    int l = 0;
    int r = nums.size()-1;
    int middle;
    while(l<=r){
        middle = (l+r)/2;
        if(nums[middle]==target){
            return true;
        }

        if(nums[middle]==nums[l] && nums[middle]==nums[r]){
            l++;
            r--;
            continue;
        }

        if(target>=ls){
            if(nums[middle]>=ls && middle){
                if(nums[middle]>target){
                    r = middle-1;
                }else{
                    l = middle+1;
                }
            }else{
                l = middle+1;
            }
        }else{
            if(nums[middle]<=ls){
                if(nums[middle]>target){
                    r = middle-1;
                }else{
                    l = middle+1;
                }
            }else{
                r = middle-1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> v = {2,5,6,0,1,2,2};
    cout<<(solve(v,0)?"True":"False")<<endl;
    return 0;
}
