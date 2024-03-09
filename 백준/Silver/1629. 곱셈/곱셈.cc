#include <iostream>
using namespace std;

long long num1,num2,num3;
long long solution(long long a, long long b, long long c){
    if(b==1)return a%c;
    long long tmp = solution(a,b/2,c);
    tmp = tmp*tmp%c;
    if(b%2==0)return tmp;
    return num1*tmp%c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>num1>>num2>>num3;
    cout<<solution(num1,num2,num3);
}
