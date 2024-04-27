#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<char> nums;
bool arr[8];
unordered_set<int> st;
//길이 1만들기 2만들기 ...n만들기

bool isPrime(int n){
    if(n<2)return false;
    if(n==3)return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

void numMaker(int goalDepth, string curStr){
    if(curStr.length()==goalDepth){
        st.insert(stoi(curStr));
    }else{
        for(int i=0;i<nums.size();i++){
            if(!arr[i]){
                arr[i]=true;
                numMaker(goalDepth,curStr+nums[i]);
                arr[i]=false;
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    for(int i=0;i<numbers.size();i++){
        nums.push_back(numbers[i]);
    }
    for(int i=1;i<=numbers.length();i++){
        numMaker(i,"");
    }
    for(auto k: st){
        //cout<<k<<endl;
        if(isPrime(k)){
            //cout<<k<<"는 소수입니다"<<endl;
            answer++;
        }
    }
    return answer;
}