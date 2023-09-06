#include <iostream>
using namespace std;

int N,M;
int answer[9];
int checker[9];

void backTracking(int start){
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(start>M){
     for(int i=1;i<=M;i++){
         cout<<answer[i]<<" ";
     }
     cout<<'\n';
    }else{
        for(int i=1;i<=N;i++){
            if(checker[i]==0){
                checker[i]=1;
                answer[start]=i;
                backTracking(start+1);
                checker[i]=0;
            }
        }
    }
}

int main(){
cin>>N>>M;
    backTracking(1);

}