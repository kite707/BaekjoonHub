// 시작점 y, x인곳의 길이가 n이고 시작숫자는 k인 함수
// y,x / y,x+n/2 / y+n/2,x / y+n/2, x+n/2
//숫자는 n*n/4씩 추가됨

#include <iostream>
using namespace std;

int N,r,c;

int zMove(int y, int x, long long n){
    if(n==1){
        return 0;
    }
    long long block = (n/2)*(n/2);
    if(y<n/2&&x<n/2)return zMove(y,x,n/2);
    else if(y<n/2&&x>=n/2)return zMove(y,x-n/2,n/2)+block;
    else if(y>=n/2&&x<n/2)return zMove(y-n/2,x,n/2)+block*2;
    else return zMove(y-n/2,x-n/2,n/2)+block*3;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>r>>c;
    long long len=2<<(N-1);
    cout<<zMove(r,c,len);


}