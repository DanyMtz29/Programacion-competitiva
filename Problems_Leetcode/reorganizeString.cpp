#include <bits/stdc++.h>

using namespace std;

string reorganizeString(string& s){
    vector<int> letters(26,0);
    int a = 'a';
    int maxLetters = 0;
    int maxL = 0;
    vector<char> lets;
    for(char c: s){
        letters[c-a]++;
        if(letters[c-a]>maxL){
            lets.clear();
            maxLetters = 1;
            maxL = letters[c-a];
            lets.push_back(c);
        }else if(letters[c-a]==maxL){
            maxLetters++;
            lets.push_back(c);
        }
    }

    int spaces = s.size()-(maxL*maxLetters);

    if(maxLetters==1 && maxL-1>spaces){
        return "";
    }

    string ss = s;
    for(int i=0;i<maxLetters;i++){
        ss[s.size()-1-i] = lets[i];
    }

    spaces = (s.size()-maxLetters)/2;

    for(int i=0;i<s.size();i++){
        
    }

    lets.clear();

    while(true){
        for(int i=0;i<26;i++){
            letters[i]++;
            if(letters[i]>maxL){
                lets.clear();
                maxLetters = 1;
                maxL = letters[i];
                lets.push_back(i+a);
            }else if(letters[i]==maxL){
                maxLetters++;
                lets.push_back(i+a);
            }   
        }
    }

    //aaabbbcccdd = 11
    //abcdabcdabc


    //aaacd = 5
    //acada


    return s;
    
}

int solve2(string &s){
    vector<int> letters(26,0);
    int a = 'a';
    for(char c: s){
        letters[c-a]++;
    }
    priority_queue<tuple<int,char>, vector<tuple<int,char>>> pq;
    for(int i=0;i<26;i++){
        if(letters[i]!=0){
            pq.emplace(letters[i],i+a);
        }
    }
    
    priority_queue<tuple<int,char>, vector<tuple<int,char>>> pq2;
    int i=0;
    while(!pq.empty()){
        if(pq.size()==1){
            auto[total,c]=pq.top();
            if(total>1) return "";
        }
        auto [total, c] = pq.top();
        pq.pop();
        s[i++] = c;
        if(--total>0) pq2.emplace(total,c); 
        if(pq.empty()){
            swap(pq,pq2);
        }
    }
    return s;

}

int main(){
    
    return 0;
}