#include <string>
#include <vector>
#include <stack>
using namespace std;




string solution(string number, int k) {
    string answer = "";
    stack<int> st;
    for(int i=0;i<number.length();i++){
        if(answer.length()==0)answer+=number[i];
        else{
            int curNum=number[i]-'0';
            while(answer.length()!=0&&answer[answer.length()-1]-'0'<curNum&&k>0){
                answer.erase(answer.begin()+answer.length()-1);
                k--;
            }
            answer+=number[i];
        }
        
    }
    while(k>0){
        answer.erase(answer.begin()+answer.length()-1);
        k--;
    }
    
    return answer;
}