#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int getLargest(int a, int b){
    if(a<b){
        int tmp = a;
        a=b;
        b=tmp;
    }
    while(true){
        int tmp = a%b;
        if(tmp == 0){
            return b;
        }
        a=b;
        b=tmp;
    }
}

int getVectorLargest(vector<int> array){
    int startNum = array[0];
    for(int i=1;i<array.size();i++){
     startNum = getLargest(startNum, array[i]);
    }
    return startNum;
}

bool isDividable(vector<int> array, int num){
    for(int i =0 ;i<array.size();i++){
        if(array[i]%num==0){
            return true;
        }
    }
    return false;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int aLargest, bLargest;
    if(arrayA.size()==1){
        aLargest=arrayA[0];
    }else{
        aLargest = getVectorLargest(arrayA);
    }
    
    if(arrayB.size()==1){
        bLargest=arrayB[0];
    }else{
        bLargest = getVectorLargest(arrayB);
    }
    if(aLargest==1&&bLargest!=1){
        if(isDividable(arrayA,bLargest)){
            return 0;
        }else{
            return bLargest;
        }
    }
    if(aLargest > bLargest){
    }
    if(aLargest!=1&&bLargest==1){
        if(isDividable(arrayB,aLargest)){
            return 0;
        }else{
            return aLargest;
        }
    }
    if(aLargest==1&&bLargest==1){
        return 0;
    }
    if(aLargest!=1 && bLargest!=1){
        if(aLargest>bLargest){
            if(!isDividable(arrayB, aLargest)){
               return aLargest; 
            }
            else if(!isDividable(arrayA,bLargest)){
                return bLargest;
            }
            return 0;
        }
         else{
            if(!isDividable(arrayA, bLargest)){
               return bLargest; 
            }
            else if(!isDividable(arrayB,aLargest)){
                return aLargest;
            }
            return 0;
        }
        
    }
    return answer;
}