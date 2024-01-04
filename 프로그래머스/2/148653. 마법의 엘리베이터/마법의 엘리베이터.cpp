#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int storey) {
    if(storey/10==0){
       return min(10-storey+1,storey); 
    }else{
        return min(10-storey%10+solution(storey/10+1),storey%10+solution(storey/10));
    }
}