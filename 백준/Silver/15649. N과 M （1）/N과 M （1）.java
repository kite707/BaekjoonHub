import java.util.*;

class Main{
    static int a;
    static int b;
    public static int[] arr;
    static boolean[] visit;
    static void solution(int curdepth){
        if(curdepth==b){
            for(int k : arr){
                System.out.print(k+" ");
            }
            System.out.println();
        }
        else{
            for(int j=1;j<=a;j++){
                if(visit[j]==false){
                    visit[j]=true;
                    arr[curdepth]=j;
                    solution(curdepth+1);
                    visit[j]=false;
                }
            }
        }
    }
    public static void main(String[] args) {
       
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        arr=new int[b];
        visit = new boolean[a+1];
        solution(0);
        sc.close();
    }
}