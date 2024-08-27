#include <string>
#include <vector>
#include <iostream>

using namespace std;
//만약 동그라미 완성이라면 x하나 적기. x완성이라면 o와 x개수 같기

int countValidator(vector<string> board){
    int circle=0;
    int x=0;
    for(int i=0;i<board.size();i++){
        for(auto k: board[i]){
            if(k=='O')circle++;
            if(k=='X')x++;
        }
    }
    return circle-x;
}

bool completeValidator(vector<string> board, char c){
    //가로
    for(int i=0;i<3;i++){
        bool flag=true;
        for(int j=0;j<3;j++){
            if(board[i][j]!=c){flag=false;continue;}
        }
        if(flag)return true;
    }
    //세로
    for(int i=0;i<3;i++){
        bool flag=true;
        for(int j=0;j<3;j++){
            if(board[j][i]!=c){flag=false;continue;}
        }
        if(flag)return true;
    }
    //대각선
    bool flag1=true;
    for(int i=0;i<3;i++){
        if(board[i][i]!=c)flag1=false;
    }
    if(flag1)return true;
    
    bool flag2=true;
    for(int i=0;i<3;i++){
        if(board[2-i][i]!=c)flag2=false;
    }
    if(flag2)return true;
    return false;
}


int solution(vector<string> board) {
    int answer = -1;
    answer=countValidator(board);
    cout<<answer<<endl;
    if(answer!=0&&answer!=1)return 0;
    
    if(completeValidator(board,'O')&&answer!=1) return 0;
    if(completeValidator(board,'X')&&answer!=0) return 0;
    return 1;
    
}