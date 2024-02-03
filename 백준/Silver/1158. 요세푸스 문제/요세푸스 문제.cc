#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   int N,K;
   cin>>N>>K;
   list<int> li;
    auto cursor = li.end();
    for(int i=1;i<=N;i++){
       li.insert(cursor,i);
   }
    cursor = li.begin();
   cout<<"<";
   while(li.size()!=1){
       for(int i=1;i<K;i++){
           if(cursor==--li.end()){
               cursor=li.begin();
           }
           else{cursor++;}
       }
       cout<<*cursor<<", ";
       cursor=li.erase(cursor);
       if(cursor==li.end()){
           cursor = li.begin();
       }
   }
   cout<<*li.begin()<<">";

}