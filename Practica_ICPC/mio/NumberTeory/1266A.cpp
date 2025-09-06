//Problem: https://codeforces.com/problemset/problem/1266/A

#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

bool solve( string number ){
    vec numbers( 10,0 );

    for( char c: number ){
        numbers[ c - '0' ]++;
    }

    if( numbers[0]==0 ) return false; // If it doesn't contain a Zero
    numbers[ 0 ]--;

    if( numbers[0]==0 && numbers[ 2 ]==0 && numbers[ 4 ]==0 && numbers[ 6 ]==0 && numbers[ 8 ]==0 ) return false; // If it doesn't contain multiplo of 4

    int sum = 0;
    for( int i = 0; i < numbers.size(); i++ ){
        while( numbers[i]>0 ){
            sum += i;
            numbers[i]--;
        }
    }

    if( sum%3 != 0 ) return false;

    return true;
}

int32_t main(){

    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
 
    int N; cin>>N;
    while( N-- ){
        string number; cin>>number;
        if( solve( number ) ){
            cout<<"red"<<endl;
        }else{
            cout<<"cyan"<<endl;
        }
    }
    
    return 0;
}