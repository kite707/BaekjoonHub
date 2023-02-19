import java.util.*;
class Main{
    static Vector<Integer> v = new Vector<Integer>();
    public static int getGCD(int a, int b){
        int m =Math.max(a, b);
        int n = Math.min(a, b);
        int t = m%n;
        while(t!=0){
            m=n;
            n=t;
            t=m%n;
        }
        return n;
    }
    public static long calculateSumOfGCD() {
        long answer=0;
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                answer+=getGCD(v.elementAt(i), v.elementAt(j));
            }
        }
        return answer;
    }
    
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t!=0){
            int n=sc.nextInt();
            while(n!=0){
                int a=sc.nextInt();
                v.add(a);
                n--;
            }
            //최대공약수 계산 및 합 출력
            System.out.println(calculateSumOfGCD());
            v.removeAllElements();
            t--;
        }
    }
}