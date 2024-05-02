#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isPrime(long long n){
    if(n<2)return false;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s="";
    while(n!=0){
        int c=n%k;
        s+=to_string(c);
        n/=k;
    }
    string s2="";
    for(int i=s.length()-1;i>=0;i--){
        s2+=s[i];
    }
    unordered_map<long long,int> mp;
    string tmp="";
    for(int i=0;i<s2.length();i++){
        if(s2[i]=='0'){
            if(tmp!=""){
              mp[stoll(tmp)]++;
            tmp="";  
            }
        }else{
           tmp+=s2[i]; 
        }
    }
    if(tmp!=""){
        mp[stoll(tmp)]++;
    }
    for(auto k: mp){
        if(isPrime(k.first)){
            answer+=k.second;
        }
    }
    return answer;
}