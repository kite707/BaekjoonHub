#include <iostream>
using namespace std;
int N;
bool checker1[15];
bool checker2[30];
bool checker3[30];
int sum = 0;
void solution(int depth){
    if(depth==N){
       sum++; return;
    }
    for(int i=0;i<N;i++){ //x좌표
       if(!checker1[i]&&!checker2[depth+i]&&!checker3[depth-i+N-1]){
           checker1[i]=true;
           checker2[depth+i]=true;
           checker3[depth-i+N-1]=true;
           solution(depth+1);
           checker1[i]=false;
           checker2[depth+i]=false;
           checker3[depth-i+N-1]=false;
       }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    solution(0);
    cout<<sum<<"\n";
}