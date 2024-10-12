#include <iostream>
using namespace std;

long long mult(int a,int b,int c){
    if(b==1)return a%c;
    long long tmp = mult(a,b/2,c);
    if(b%2==0)return tmp*tmp%c;
    return tmp*tmp%c*a%c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a;
    int b;
    int c;

    cin>>a>>b>>c;

    cout<<mult(a,b,c);

}