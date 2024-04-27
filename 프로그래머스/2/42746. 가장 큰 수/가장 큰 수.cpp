#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    bool allZero=true;
    string answer = "";
    vector<string> nums;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]!=0){
            allZero=false;
        }
        nums.push_back(to_string(numbers[i]));
    }
    if(allZero){
        return "0";
    }
    sort(nums.begin(),nums.end(),cmp);
    for(int i=0;i<nums.size();i++){
        answer+=nums[i];
    }
    return answer;
}