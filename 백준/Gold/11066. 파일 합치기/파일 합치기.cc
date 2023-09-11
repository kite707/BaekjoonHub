#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int store[501]={0,};
        int sum[501]={0,};
        int opt[501][501]={0,};
        for(int i=1;i<=n;i++){
            cin>>store[i];
            sum[i]=sum[i-1]+store[i];
        }

        for(int i=1;i<n;i++){
            for(int start=1;start<=n-i;start++){
                int end=start+i;
                opt[start][end]=INT_MAX;
                for(int j=start;j<=end-1;j++){
                    opt[start][end]=min(opt[start][end],opt[start][j]+opt[j+1][end]+sum[end]-sum[start-1]);
                }
            }
        }
        cout<<opt[1][n]<<"\n";
    }
}
