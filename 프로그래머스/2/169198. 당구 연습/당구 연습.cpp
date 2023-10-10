#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(int x, int y){
    return x*x+y*y;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i=0;i<balls.size();i++){
        int ballX=balls[i][0];
        int ballY=balls[i][1];
        
        int ans=0;
        //상
        int ux=ballX;
        int uy=2*n-ballY;
        int up=calculate(ux-startX,uy-startY);
        
        //하
        int dx = ballX;
        int dy = 0-ballY;
        int down=calculate(dx-startX,dy-startY);
        
        //좌
        int lx=0-ballX;
        int ly=ballY;
        int left = calculate(lx-startX,ly-startY);
        //우
        int rx=2*m-ballX;
        int ry=ballY;
        int right=calculate(rx-startX,ry-startY);
    
    
    if (ballX == startX)
		{
			if (ballY > startY)
				ans = min(min(left, right), down);
			else
				ans = min(min(left, right), up);
		}
		else if (ballY == startY)
		{
			if (ballX > startX)
				ans = min(min(up, down), left);
			else
				ans = min(min(up, down), right);
		}
		else
		{
			ans = min(min(left, right), min( up, down));
		}
		answer.push_back(ans);
    }
    return answer;
}