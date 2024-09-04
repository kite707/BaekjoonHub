#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isValid(char a){
    if(a<'A')return false;
    if(a>'Z')return false;
    return true;
}

unordered_map<string,int> tokenize(string str){
    unordered_map<string,int> mp;
    for(int i=0;i<str.size()-1;i++){
        char cur=str[i];
        char nxt=str[i+1];
        if(!isValid(cur)||!isValid(nxt))continue;
        string s;
        s.push_back(cur);
        s.push_back(nxt);
        mp[s]++;
    }
    return mp;

}

int solution(string str1, string str2) {
    int answer = 65536;
    for(int i=0;i<str1.size();i++){
        str1[i]=toupper(str1[i]);
    }
    for(int i=0;i<str2.size();i++){
        str2[i]=toupper(str2[i]);
    }
    unordered_map<string,int> mp1=tokenize(str1);
    unordered_map<string,int> mp2=tokenize(str2);
    int sameSize=0;
    
    int mp1Size=0;
    int mp2Size=0;
    for(auto &k:mp1){
        mp1Size+=mp1[k.first];
    }
    
    for(auto &k:mp2){
        string key=k.first;
        mp2Size+=mp2[key];
        if(mp1[key]!=0){
            sameSize+=min(mp1[key],mp2[key]);
        }
    }
    int add=mp1Size+mp2Size-sameSize;
    
    if(add==0){
        return answer;
    }
    
    float ans=(float)sameSize/(float)add;
    return answer*ans;
}