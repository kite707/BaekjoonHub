#include <iostream>
using namespace std;

int m,n;

int parent[500000];

int findParent(int x){
    if(x!=parent[x])parent[x]=findParent(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    int rootX=findParent(x);
    int rootY=findParent(y);

    rootX<rootY?parent[rootY]=rootX:parent[rootX]=rootY;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int a,b;
    int T=m;

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    while(T--){
        cin>>a>>b;

        if(findParent(a)!=findParent(b)){
            Union(a,b);
            continue;
        }
        break;
    }
    if(T==-1)cout<<"0";
    else cout<<m-T;
}