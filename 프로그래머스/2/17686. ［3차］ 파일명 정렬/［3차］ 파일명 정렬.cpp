#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

bool isNum(char c){
    if(c<'0')return false;
    if(c>'9')return false;
    return true;
}

bool cmp(tuple<string,int,int> a, tuple<string,int,int> b){
    if(get<0>(a)==get<0>(b)){
        if(get<1>(a)==get<1>(b))return get<2>(a)<get<2>(b);
        return get<1>(a)<get<1>(b);
    }
    return get<0>(a)<get<0>(b);
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string,int,int>> vec;
    
    //파일 가공
    for(int i=0;i<files.size();i++){
        string file=files[i];
        string head="";
        string number="";
        string tail="";
        bool numberIsEmpty=true;
        bool numberIsFilled=false;
        for(int j=0;j<file.size();j++){
            if(isNum(file[j])&&!numberIsFilled){
                number+=file[j];
                numberIsEmpty=false;
            }else{
                if(!numberIsEmpty)numberIsFilled=true;
                if(numberIsEmpty){
                    head+=toupper(file[j]);
                }else{
                    tail+=file[j];
                }
            }
        }
        tuple<string,int,int> tmp ={head,stoi(number),i};
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        answer.push_back(files[get<2>(vec[i])]);
    }

    return answer;
}