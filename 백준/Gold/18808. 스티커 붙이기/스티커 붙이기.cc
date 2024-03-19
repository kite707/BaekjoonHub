#include <iostream>
#include <utility>
using namespace std;
int height,width,k;
int note[40][40];
int sticker[10][10];
int st_height,st_width;

void printer(){
    cout<<"note 출력"<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<note[i][j]<<" ";
        }cout<<endl;
    }
}

void sticker_printer(){
    cout<<"sticker 출력"<<endl;
    for(int i=0;i<st_height;i++){
        for(int j=0;j<st_width;j++){
            cout<<sticker[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotate(){
    int copy_sticker[10][10];
    //cout<<st_width<<" "<<st_height<<endl;
    for(int i=0;i<st_height;i++)
        for(int j=0;j<st_width;j++)copy_sticker[i][j]=sticker[i][j];
    for(int i=0;i<st_width;i++)
        for(int j=0;j<st_height;j++)sticker[i][j]=copy_sticker[st_height-1-j][i];
    swap(st_width,st_height);
    //sticker_printer();
}

bool stickable(int x,int y){
    for(int i=0;i<st_height;i++)
        for(int j=0;j<st_width;j++){
            if(note[y+i][x+j]==1&&sticker[i][j]==1){
                return false;
            }
        }
    for(int i=0;i<st_height;i++)
        for(int j=0;j<st_width;j++){
            if(sticker[i][j]==1){
                note[y+i][x+j]=1;
            }
        }
   //printer();
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width>>k;
    while(k--){
        cin>>st_height>>st_width;
        for(int i=0;i<st_height;i++)
            for(int j=0;j<st_width;j++)cin>>sticker[i][j];
        for(int rot = 0;rot<4;rot++){
            bool available = false;
            for(int i=0;i<=height-st_height;i++){
                if(available)break;
                for(int j=0;j<=width-st_width;j++){
                    if(stickable(j,i)){
                        available=true;break;
                    }
                }
            }
            if(available)break;
            rotate();
        }


    }


    int ans = 0;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)ans+=note[i][j];
    cout<<ans;

}