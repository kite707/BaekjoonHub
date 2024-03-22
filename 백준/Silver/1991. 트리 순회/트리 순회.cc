#include <iostream>
using namespace std;


char rc[27];
char lc[27];

void preorder(char start){
    int idx= start-'A'+1;
    cout<<start;
    if(lc[idx]!='.')preorder(lc[idx]);
    if(rc[idx]!='.')preorder(rc[idx]);

}

void inorder(char start){
    int idx= start-'A'+1;
    if(lc[idx]!='.')inorder(lc[idx]);
    cout<<start;
    if(rc[idx]!='.')inorder(rc[idx]);

}
void postorder(char start){
    int idx= start-'A'+1;
    if(lc[idx]!='.')postorder(lc[idx]);
    if(rc[idx]!='.')postorder(rc[idx]);
    cout<<start;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<27;i++){
        rc[i]='.';
        lc[i]='.';
    }
    int n;
    cin>>n;
    char a,b,c;
    while(n--){
     cin>>a>>b>>c;
     lc[a-'A'+1]=b;
     rc[a-'A'+1]=c;
    }
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');


}