#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(auto k:arr1){
        vector<int> tmp;
            for(int i=0;i<arr2[0].size();i++){
            int saver=0;
            for(int j=0;j<arr2.size();j++){
             saver+= k[j]*arr2[j][i];  
            }
                tmp.push_back(saver);
        }
        
        answer.push_back(tmp);
    }
    return answer;
}