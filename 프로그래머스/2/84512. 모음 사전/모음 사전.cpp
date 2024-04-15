#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> vec;
vector <string> v={"","A","E","I","O","U"};

void maker(int curdepth,string curStr){
    if(curdepth==5){
        vec.push_back(curStr);
    }else{
        for(int i=0;i<v.size();i++){
            maker(curdepth+1,curStr+v[i]);
        }
    }
}

int solution(string word) {
    int answer = 0;
    maker(0,"");
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    return lower_bound(vec.begin(),vec.end(),word)-vec.begin();
    
    return answer;
}