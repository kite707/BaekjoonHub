import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> st = new Stack<>();
        
        for(int i=0;i<numbers.length;i++){
            while(!st.empty()&&numbers[st.peek()]<numbers[i]){
                answer[st.peek()]=numbers[i];
                st.pop();
            }
            
                st.push(i);
        }
        while(!st.empty()){
            answer[st.peek()]=-1;
            st.pop();
        }

        return answer;
    }
}