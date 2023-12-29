#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
set<int> s;
int arr[1001];
long long combination(int n, int r)
{
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

long long solution(vector<int> weights) {
    long long answer = 0;
    vector <int> save;
    sort(weights.begin(),weights.end());
    for(int i = 0; i<weights.size();i++){
        arr[weights[i]]++;
        s.insert(weights[i]);
    }
    for(int i=0;i<1001;i++){
        if(arr[i]>=2){
            answer+=(long long)arr[i]*(arr[i]-1)/2;
        }
        
    }
    for(int curWeight : s){
        if(binary_search(s.begin(),s.end(),curWeight*2)){
            answer+=arr[curWeight*2]*arr[curWeight];
        }
        if(curWeight%2==0){
            if(binary_search(s.begin(),s.end(),curWeight*3/2)){
                answer+=arr[curWeight*3/2]*arr[curWeight];
            }
        }
         if(curWeight%3==0){
            if(binary_search(s.begin(),s.end(),curWeight*4/3)){
                answer+=arr[curWeight*4/3]*arr[curWeight];
            }
        }
    }


    return answer;
}