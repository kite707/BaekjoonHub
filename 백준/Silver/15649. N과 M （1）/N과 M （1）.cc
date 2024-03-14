#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
bool checker[9];
int saver[9];
int N,M;
void solution(int depth){
    if(depth==M){
        for(int i=0;i<M;i++){
            cout<<saver[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        if(!checker[i]){
            saver[depth]=i;
            checker[i]=true;
            solution(depth+1);
            checker[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>N>>M;
    solution(0);
}