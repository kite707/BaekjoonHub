#include <string>
#include <vector>
#include <iostream>
using namespace std;

double getHour(int h, int m, int s){
    return (30*(h%12)+(double)m/2+(double)s/120);
}

double getMinute(int m, int s){
    return (6*m+(double)s/10);
}

double getSecond(int s){
    return (6*s);
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    bool secHour, secMinute;
    
    //현재(시작시점) 겹치는지 확인
    if(getHour(h1,m1,s1)==getSecond(s1))answer++;
    if(getMinute(m1,s1)==getSecond(s1))answer++;
    if(getHour(h1,m1,s1)==getSecond(s1)&&getMinute(m1,s1)==getSecond(s1))answer--;
    
    
    while(h1!=h2||m1!=m2||s1!=s2){
        double sHour=getHour(h1,m1,s1);
        double sMin=getMinute(m1,s1);
        double sSec=getSecond(s1);
                
        s1++;
        double sNxtHour,sNxtMin,sNxtSec;
        if(s1==60){
            s1=0;
            m1++;
            if(m1==60){
                h1++;
                m1=0;
            }
        }
        getHour(h1,m1,s1)!=0?sNxtHour=getHour(h1,m1,s1):sNxtHour=360;
        getMinute(m1,s1)!=0?sNxtMin=getMinute(m1,s1):sNxtMin=360;
        getSecond(s1)!=0?sNxtSec=getSecond(s1):sNxtSec=360;
         
        if(sSec<sHour&&sNxtSec>=sNxtHour)answer++;
        if(sSec<sMin&&sNxtSec>=sNxtMin)answer++;
        if(sNxtSec==sNxtMin&&sNxtSec==sNxtHour)answer--;
        
    }
    return answer;
}