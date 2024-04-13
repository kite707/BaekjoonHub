import java.util.*;
class Pair{
    private int x;
    private int y;
    public Pair(int x, int y){
        this.x=x;
        this.y=y;
    }
    public int first(){
        return this.x;
    }
    public int second(){
        return this.y;
    }
}

class Solution {
    int [][]arr=new int[101][101];
    int []dx={0,1,0,-1};
    int []dy={1,0,-1,0};
    public int solution(int[][] maps) {
        bfs(0,0,maps);
        if(arr[maps.length-1][maps[0].length-1]==0)return -1;
        return arr[maps.length-1][maps[0].length-1];

    }
    
    public void bfs(int startY,int startX,int[][] maps){
        Queue<Pair> q=new LinkedList<>();
        q.add(new Pair(startY,startX));
        arr[startY][startX]=1;
        while(!q.isEmpty()){
            int curX=q.element().second();
            int curY=q.element().first();
            q.remove();
            int curCost=arr[curY][curX];
            for(int i=0;i<4;i++){
                int nxtX=curX+dx[i];
                int nxtY=curY+dy[i];
                if(nxtX>=maps[0].length||nxtX<0||nxtY>=maps.length||nxtY<0)continue;
                if(maps[nxtY][nxtX]==0)continue;
                if(arr[nxtY][nxtX]!=0)continue;
                q.add(new Pair(nxtY,nxtX));
                arr[nxtY][nxtX]=curCost+1;
                
            }
        }
    }
}