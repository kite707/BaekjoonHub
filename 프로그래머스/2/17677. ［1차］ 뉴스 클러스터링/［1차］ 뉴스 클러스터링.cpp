#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int arr1[705];
int arr2[705];

float sizeA, sizeB, sizeSame;

int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0;i<str1.size()-1;i++){
        if(isalpha(str1[i])&&isalpha(str1[i+1])){
            arr1[(str1[i]&31)*26+(str1[i+1]&31)]++;
            sizeA++;
        }
    }
    for(int i=0;i<str2.size()-1;i++){
        if(isalpha(str2[i])&&isalpha(str2[i+1])){
            arr2[(str2[i]&31)*26+(str2[i+1]&31)]++;
            sizeB++;
        }
    }
    for(int i=0;i<705;i++){
        if(arr1[i]!=0&&arr2[i]!=0)sizeSame+=min(arr1[i],arr2[i]);
    }
    return sizeA+sizeB==0?65536:(sizeSame/(sizeA+sizeB-sizeSame))*65536;
}