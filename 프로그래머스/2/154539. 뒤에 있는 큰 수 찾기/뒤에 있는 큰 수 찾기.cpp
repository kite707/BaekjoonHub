#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> tmp;
    int curMax = 0;
    for(int i=numbers.size()-1;i>=0;i--){
        while(true){
            if(tmp.empty()){
                answer[i]=-1;
                break;
            }
            if(tmp.top()>numbers[i]){
                answer[i]=tmp.top();
                break;
            }
             tmp.pop();
        }
        tmp.push(numbers[i]);
        
    }
    return answer;
}