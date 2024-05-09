#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getStep(char b){
    int tmp = b-'A';
    return min(26-tmp, tmp);
}

int solution(string name) {
    int answer = 0;
    int turn=name.length()-1;
    for(int i=0;i<name.length();i++){
        answer+=getStep(name[i]);
        
        int n=i+1;
        while(n<name.length()&&name[n]=='A')n++;
        int a=i;
        int b=name.length()-n;
        turn=min(turn, a+b+min(a,b));
    }
    return answer+turn;
}