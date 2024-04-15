#include <string>
#include <vector>

using namespace std;
int cnt[2];

void quad(int startY, int startX,int size,vector<vector<int>> &arr){
    if(size==1){
        cnt[arr[startY][startX]]++;
        return;
    }
    int curNum=arr[startY][startX];
    for(int i=startY;i<startY+size;i++){
        for(int j=startX;j<startX+size;j++){
            if(arr[i][j]!=curNum){
                quad(startY,startX,size/2,arr);
                quad(startY+size/2,startX,size/2,arr);
                quad(startY+size/2,startX+size/2,size/2,arr);
                quad(startY,startX+size/2,size/2,arr);
                return;
            }
        }
    }
    cnt[curNum]++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    quad(0,0,arr.size(),arr);
    answer.push_back(cnt[0]);
    answer.push_back(cnt[1]);
    return answer;
}