/* Cpp code to verify the valid anagram*/

#include<bits/stdc++.h>
using namespace std;

void checkAnagram(string s,string t){
    if(s.length()!=t.length()){
        cout<<0<<endl;
    }

    unordered_map<char,int> m;

    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }

    for(int i=0;i<t.length();i++){
        if(m.find(t[i])==m.end()){
            cout<<0<<endl;
            return;
        }
        m[t[i]]--;
        if(m[t[i]]<0){
            cout<<0<<endl;
            return;
        }
    }
    cout<<1<<endl;

}

int main(){
    string s="maha";
    string t="ahaa";

    checkAnagram(s,t);
    return 0;


}