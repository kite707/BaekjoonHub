#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> vec = {'A','C','F','J','M','N','R','T'};
    sort(vec.begin(),vec.end());
    do{
        bool flag=true;
        for(int i=0;i<n;i++){
            string cond=data[i];
            char fir=cond[0];
            char sec=cond[2];
            int cnt=cond[4]-'0';
            cnt++;

            int firIdx=find(vec.begin(),vec.end(),fir)-vec.begin();
            int secIdx=find(vec.begin(),vec.end(),sec)-vec.begin();

            if(cond[3]=='>'&&max(firIdx,secIdx)-min(firIdx,secIdx)<=cnt){
                flag=false;
                break;
            }
            if(cond[3]=='<'&&max(firIdx,secIdx)-min(firIdx,secIdx)>=cnt){
               flag=false;
                break; 
            }
            if(cond[3]=='='&&max(firIdx,secIdx)-min(firIdx,secIdx)!=cnt){
               flag=false;
                break; 
            }

        }
        if(!flag)continue;
        answer++;
    }while(next_permutation(vec.begin(),vec.end()));
    return answer;
}