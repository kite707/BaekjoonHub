#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

bool isNumber(char c){
    return (c-'0'>=0&&c-'0'<=9);
}

bool comp(tuple<string,int,int,string> a,tuple<string,int,int,string> b){
    if(get<0>(a)==get<0>(b)){
        if(get<1>(a)==get<1>(b)){
            return get<2>(a)<get<2>(b);
        }
        return get<1>(a)<get<1>(b);
    }
    return get<0>(a)<get<0>(b);
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string,int,int,string>> idx;
    for(int i=0;i<files.size();i++){
        tuple<string, int,int,string> tp;
        string curFile=files[i];
        string tmp="";
        string head="";
        string number="";
        string tail="";
        for(int j=0;j<curFile.length();j++){
            if(head==""&&isNumber(curFile[j])){
                head=tmp;
                tmp="";
            }else if(head!=""&&number==""&&!isNumber(curFile[j])){
                number=tmp;
                tmp="";
            }
            tmp+=toupper(curFile[j]);
        }
        //cout<<head<<" "<<stoi(number)<<" "<<tmp<<endl;
        if(number==""){
            number=tmp;
        }
        tp={head,stoi(number),i,tmp};
        idx.push_back(tp);
    }
    sort(idx.begin(),idx.end(),comp);
    for(int i=0;i<idx.size();i++){
        int ix= get<2>(idx[i]);
        answer.push_back(files[ix]);
    }

    return answer;
}