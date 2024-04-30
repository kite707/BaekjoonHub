#include <string>
#include <vector>

using namespace std;

int arr[1001][51];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int k=1000000;
    t1+=10;
    t2+=10;
    temperature+=10;
    
    for(int i=0;i<1001;i++){
        fill(&arr[i][0],&arr[i][0]+51,k);
    }
    
    arr[0][temperature]=0;
    
    int flag=1;
    if(temperature>t2){
        flag=-1;
    }
    
    for(int i=1;i<onboard.size();i++){
        for(int j=0;j<51;j++){
            int minValue=k;
            if((onboard[i]==1&&t1<=j&&j<=t2)||onboard[i]==0){
                if(0<=j+flag&&j+flag<=50)minValue=min(minValue,arr[i-1][j+flag]);
                if(j==temperature)minValue=min(minValue,arr[i-1][j]);
                if(0<=j-flag&&j-flag<=50)minValue=min(minValue,arr[i-1][j-flag]+a);
                if(t1<=j&&j<=t2)minValue=min(minValue,arr[i-1][j]+b);
                arr[i][j]=minValue;
            }
        }
    }
    int i=onboard.size()-1;
    int answer=arr[i][0];
    for(int j=1;j<51;j++){
        answer=min(answer,arr[i][j]);
    }
    return answer;
    
}