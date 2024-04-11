#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];

void fillArr(int r,int c){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            arr[i][j]=(i-1)*c+j;
        }
    }
}

void arrPrinter(int r,int c){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int spin(int y1,int x1,int y2, int x2){
    int curY=y1;
    int curX=x1;
    int startNumber=arr[y1][x1];
    int minNum=startNumber;
    int savedNum=startNumber;
    int nxtY=0;
    int nxtX=0;
    bool flag=true;
    while(startNumber!=savedNum||flag){
        flag=false;
        if(curY==min(y1,y2)){
            if(curX==min(x1,x2)){
                //아래
                nxtX=curX;
                nxtY=curY+1;
            }else{
                //오른쪽
            nxtX=curX+1;
            nxtY=curY;
            }

            
        }if(curY==max(y1,y2)){
            if(curX==min(x1,x2)){
                //위
                nxtX=curX;
                nxtY=curY-1;
            }else{
                //왼쪽
            nxtX=curX-1;
            nxtY=curY;
            }
            
        }
        if(curX==min(x1,x2)){
            if(curY==min(y1,y2)){
                //오른쪽
                nxtX=curX+1;
                nxtY=curY;
            }else{
                //위
            nxtX=curX;
            nxtY=curY-1;
            }
            
        }
        if(curX==max(x1,x2)){
            if(curY==max(y1,y2)){
                //왼쪽
                nxtX=curX-1;
            nxtY=curY;
            }
            else{
               //아래
            nxtX=curX;
            nxtY=curY+1; 
            }
            
        }
        //cout<<"change"<<endl;
        int sav=savedNum;
        savedNum=arr[nxtY][nxtX];
        arr[nxtY][nxtX]=sav;
        minNum=min(savedNum,minNum);
        curY=nxtY;
        curX=nxtX;
    }
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    fillArr(rows,columns);
    arrPrinter(rows,columns);
    for(int i=0;i<queries.size();i++){
        int num=spin(queries[i][0],queries[i][1],queries[i][2],queries[i][3]);
        //arrPrinter(rows,columns);
        //cout<<"num is: "<<num<<endl;
        answer.push_back(num);
    }
    
    return answer;
}