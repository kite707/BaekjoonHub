#include <stack>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<pair<int,int> > st;
    st.push(make_pair(100000001,0));
    int N;
    cin>>N;
    int height;
    for(int i=1;i<=N;i++){
        cin>>height;
        while(st.top().first<height) st.pop();
        cout<<st.top().second<<" ";
        st.push(make_pair(height,i));
    }

}