#include <iostream>
using namespace std;
int arr[201][201];

int dp(int i,int j){
    if(arr[i][j]!=0){
        return arr[i][j];
    }
    arr[i][j]=dp(i,j-1)%1000000000+dp(i-1,j)%1000000000;
    return arr[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    for(int j=1;j<=b;j++){
        arr[1][j]=j;
    }
    for(int i=1;i<=a;i++){
        arr[i][1]=1;
    }

    cout<<dp(a,b)%1000000000;
}