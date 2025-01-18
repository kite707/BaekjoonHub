#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int toMake(char ch){
    return min(ch-'A','Z'+1-ch);
}


int solution(string name) {
    int answer = 0;
    
    int minMove=name.size()-1;
    for(int i=0;i<name.size();i++){
        answer+=toMake(name[i]);
        
        int j=i+1;
        while(j<name.size()&&name[j]=='A')j++;
        int tmp=min(i*2+name.size()-j,(name.size()-j)*2+i);
        minMove=min(minMove,tmp);
    }
    answer+=minMove;
    return answer;
}