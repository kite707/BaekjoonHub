#include <string>
#include <vector>
#include <iostream>

using namespace std;
int SIZE = 3;

bool test(vector <string> board, int oNumber, int xNumber){
    int sameO = 0;
    int sameX = 0;
    //가로
    for(int i=0;i<SIZE;i++){
        string curLine = board[i];
        if(curLine == "OOO"){
            sameO++;
        }
        if(curLine =="XXX"){
            cout<<"가로"<<endl;
            sameX++;
        }
    }
    //세로
    string tmp="";
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            string curLine = board[j];
            char current = curLine[i];
            tmp+=current;
        }
        if(tmp =="OOO"){
            sameO++;
        }
        if(tmp=="XXX"){
            cout<<"세로"<<endl;
            sameX++;
        }
        tmp="";
    }
    //대각
    for(int i=0;i<SIZE;i++){
        tmp+=board[i][i];
    }
    if(tmp=="OOO"){
        sameO++;
    } else if(tmp=="XXX"){
        cout<<"대각1"<<endl;
        sameX++;
    }
    tmp="";
    for(int i=SIZE-1;i>=0;i--){
     tmp+=board[i][2-i];   
    }
    if(tmp=="OOO"){
        sameO++;
    } else if(tmp=="XXX"){
        cout<<"대각2"<<endl;
        sameX++;
    }
    
    cout<<"sameX is "<<sameX<<endl;
    cout<<"sameO is "<<sameO<<endl;
   if(sameO==0&&sameX==0){
       return false;
   }
    if(sameO ==0&&sameX==1&&(oNumber == xNumber)){
        return false;
    }
    if(sameO>0&&sameX==0&&(oNumber==xNumber+1)){
        return false;
    }
    return true;
}

int solution(vector<string> board) {
    int answer = 1;
    int oNumber = 0;
    int xNumber = 0;
    for(int i=0;i<SIZE;i++){
        string curLine = board[i];
        for(int j=0;j<SIZE;j++){
            char current = curLine[j];
            if(current == 'O'){
                oNumber++;
            }else if (current =='X'){
                xNumber++;
            }
        }
    }
    int sub = oNumber-xNumber;
    if(sub<0 || sub >1){
        answer = 0;
    }else{
        if(test(board,oNumber,xNumber)){
            answer = 0;
        }
    }
    return answer;
}