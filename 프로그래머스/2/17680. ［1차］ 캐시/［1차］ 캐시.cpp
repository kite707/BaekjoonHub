#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    for(int i=0;i<cities.size();i++){
        string city=cities[i];
        for(int j=0;j<city.size();j++){
            city[j]=toupper(city[j]);
        }
        auto iter=find(cache.begin(),cache.end(),city);
        if(iter==cache.end()){
            answer+=5;
            if(cache.size()==cacheSize&&!cache.empty())cache.erase(cache.begin());
            if(cacheSize!=0)cache.push_back(city);
        }
        else{
            answer+=1;
            cache.erase(iter);
            cache.push_back(city);
        }
    }
    
    
    return answer;
}