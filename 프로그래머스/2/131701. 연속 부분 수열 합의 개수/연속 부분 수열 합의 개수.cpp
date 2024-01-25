#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000001];


int solution(vector<int> elements) {
    int answer = 0;
    for(int i=0;i<elements.size();i++){
        if(arr[elements[i]]==0){
            arr[elements[i]]++;
            answer++;
        }
    }
    //cout<<"answer is "<<answer<<endl;
    for(int depth = 2;depth<=elements.size();depth++){
        
        for(int j=0;j<elements.size();j++){
            int sum = 0;
            for(int i=0;i<depth;i++){
            sum+= elements[i];
        }
            //cout<<"sum is "<<sum<<endl;
        if(arr[sum]==0){
            arr[sum]++;
            answer++;
        }
        int num = elements[0];
        elements.erase(elements.begin());
        elements.push_back(num);
        }
        
    }
    return answer;
}