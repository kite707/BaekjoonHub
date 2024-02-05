#include <queue>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    queue<int> q;
    int N;
    cin>>N;
    string s;
    int n;
    while(N--){
        cin>>s;
        if(s=="push"){
            cin>>n;
            q.push(n);
        }else if(s=="pop"){
            if(q.empty()){
                cout<<-1<<"\n";
            }else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(s=="size"){
            cout<<q.size()<<"\n";
        }else if(s=="empty"){
            cout<<q.empty()<<"\n";
        }else if(s=="front"){
            if(q.empty()){
                cout<<-1<<"\n";
            }else {
                cout << q.front() << "\n";
            }
        }else if("back"){
            if(q.empty()){
                cout<<-1<<"\n";
            }else{
                cout<<q.back()<<"\n";
            }
        }
    }

}