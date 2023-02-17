import java.lang.reflect.Array;
import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a,b;
        a = sc.nextInt();
        b = sc.nextInt();
        String[] arr = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
        int[] fix = {0,0,31,59,90,120,151,181,212,243,273,304,334};
        System.out.println(arr[(fix[a] + b) % 7]);
        sc.close();
    }
}