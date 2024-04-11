#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[12] = {1,0,-1,0,1,1,-1,-1,2,0,-2,0};
int dy[12] = {0,1,0,-1,1,-1,1,-1,0,2,0,-2};

int arr[5][5];



vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int t=0;t<places.size();t++){
        //케이스 하나
        int result = 1;
        if(result){
            for(int kk=0;kk<places[0].size();kk++){
                if(result){
                    for(int j=0;j<places[0][0].size();j++){
                        if(result){
                            if(places[t][kk][j]=='P'){
                                int curY=kk;
                int curX=j;
                //상하좌우 체크
                for(int i=0;i<12;i++){
                    int nxtY=curY+dy[i];
                    int nxtX=curX+dx[i];
                    if(nxtX<0||nxtY<0||nxtX>=5||nxtY>=5)continue;
                    if(places[t][nxtY][nxtX]=='P'){
                        //cout<<"nxtY nxtX : "<<nxtY<<" "<<nxtX<<"  "<<i<<"에서 P발견"<<endl;
                        //멘헤튼거리 2일경우 파티션 확인
                        if((dy[i]*dx[i]==0)&&(dy[i]==1||dx[i]==1)){
                            result=0;
                            break;
                        }
                        if((dy[i]*dx[i]==0)){
                            int toCheckY=curY+dy[i]/2;
                            int toCheckX=curX+dx[i]/2;
                            if(places[t][toCheckY][toCheckX]!='X'){
                                result=0;
                                break;
                            }
                        }
                        else{
                            if(places[t][nxtY][curX]!='X'||places[t][curY][nxtX]!='X'){
                                result=0;
                                break;
                            }
                        }
                    }
                }
            }
                        }


        }
                }

    } 
        }

        answer.push_back(result);
    }

    return answer;
}
