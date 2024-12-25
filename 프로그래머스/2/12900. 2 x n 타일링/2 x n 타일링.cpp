#include <string>
#include <vector>

using namespace std;

int arr[60001];

int solution(int n) {
    
    arr[1]=1;
    arr[2]=2;
    
    if(arr[n]!=0)return arr[n];
    arr[n]=(solution(n-1)+solution(n-2))%1000000007;
    return arr[n];
    
}