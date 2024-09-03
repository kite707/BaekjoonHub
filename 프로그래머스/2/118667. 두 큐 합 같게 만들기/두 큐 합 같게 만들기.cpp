#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long getSum(vector<int> &v){
    long long ans=0;
    for(int i=0;i<v.size();i++){
        ans+=v[i];
    }
    return ans;
}

void printVec(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1=getSum(queue1);
    long long sum2=getSum(queue2);
    
    long long initSize=queue1.size();
    int idx1=0;
    int idx2=0;
    if((sum1+sum2)%2==1)return -1;
    while(idx1<queue1.size()&&idx2<queue2.size()&&sum1!=sum2&&answer<=initSize*3){
        if(sum1>sum2){
            int num=queue1[idx1];
            queue2.push_back(num);
            sum1-=num;
            sum2+=num;
            idx1++;
        }else{
            int num=queue2[idx2];
            queue1.push_back(num);
            sum1+=num;
            sum2-=num;
            idx2++;
        }
        // cout<<"\n queue1 is ";
        // printVec(queue1);
        // cout<<"\n queue2 is ";
        // printVec(queue2);
        // cout<<sum1<<" "<<sum2<<endl;
        answer++;
    }
    if(sum1!=sum2)return -1;
    return answer;
}