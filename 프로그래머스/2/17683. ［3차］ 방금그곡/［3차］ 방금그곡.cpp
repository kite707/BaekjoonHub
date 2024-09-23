#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// m	musicinfos	answer
// "ABCDEFG"	["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]	"HELLO"
// "CC#BCC#BCC#BCC#B"	["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]	"FOO"
// "ABC"	["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]	"WORLD"
int timeToMinute(string s){
    int hour = stoi(s.substr(0,2));
    int minute= stoi(s.substr(3,2));

    int time = hour*60+minute;
    return time;
}


string replaceS(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'){
            s[i-1]=tolower(s[i-1]);
            s.erase(i,1);
        }
    }
    return s;
}
string playMusic(string s, int playTime){
    s=replaceS(s);
    int musicLen = s.size();
    int repeat = playTime/musicLen;
    for(int i=0;i<repeat;i++){
        s+=s;
    }
    return s.substr(0,playTime);
}



string solution(string m, vector<string> musicinfos) {
    int answertime=0;
    string answer="(None)";
    m=replaceS(m);

    for(int i=0;i<musicinfos.size();i++){
        istringstream ss(musicinfos[i]);
        string tmp;
        vector<string> res;
        while(getline(ss,tmp,',')){
        res.push_back(tmp);
        }
        int start=timeToMinute(res[0]);
        int end=timeToMinute(res[1]);
        int playTime = end - start;
        string title = res[2];
        string song = res[3];
        song=replaceS(song);

        while (song.size() <= playTime) {
            song += song;
        }
        song = song.substr(0, playTime);
        if(song.find(m) != string::npos&&answertime < playTime){
            answertime=playTime;
            answer=title;
        }
    }
    return answer;
    
}