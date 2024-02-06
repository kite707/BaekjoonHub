#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void parse(string& tmp, deque<int>& d){
    int cur = 0;
    for(int i = 1; i+1 < tmp.size(); i++)
    {
        if(tmp[i] == ','){
            d.push_back(cur);
            cur = 0;
        }
        else{
            cur = 10 * cur + (tmp[i] - '0');
        }
    }
    if(cur != 0)
        d.push_back(cur);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T,n,a;
    string p,s;
    cin>>T;
    while(T--){
        bool isError = false;
        cin>>p>>n>>s;
        deque<int> dq;
        parse(s,dq);
        int rev = 0;
        for(auto k:p){
            if(k=='R'){
               rev = 1-rev;
            }
            else{
                if(dq.empty()){
                    isError=true;
                    break;
            }
              if(!rev)dq.pop_front();
              else dq.pop_back();
            }
        }
        if(isError){
            cout<<"error\n";
        }else if(dq.empty()){
            cout<<"[]\n";
        }
        else{
            if(rev)reverse(dq.begin(),dq.end());
            cout<<"[";
            for(int i=0;i<dq.size()-1;i++){
                cout<<dq[i]<<",";
            }
            cout<<dq.back()<<"]\n";
        }

    }

}