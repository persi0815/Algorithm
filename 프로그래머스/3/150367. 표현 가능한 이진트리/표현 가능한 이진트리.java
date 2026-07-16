import java.util.*;

class Solution {
    
    
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];

        for (int i = 0; i < numbers.length; i++) {
            String binary = Long.toBinaryString(numbers[i]);

            // 1, 3, 7, 15, 31, 63 중 필요한 최소 길이
            int treeLength = 1;
            // 길이 맞추기
            while (treeLength < binary.length()) {
                treeLength = treeLength * 2 + 1;
            }
            // String 반복에는 무조건 repeat!!! '*' 안됨!!
            binary = "0".repeat(treeLength - binary.length()) + binary;
            
            // 존재 여부 저장
            answer[i] = availableTree(binary, true) ? 1 : 0;
        }

        return answer;
    }
    
    // 부모 유무 확인
    public boolean availableTree(String tree, boolean parentExixts){
        // 현재 노드
        int mid = tree.length() / 2;
        boolean currentExists = tree.charAt(mid) == '1';
        
        // 부모 없는데 자식 있으면 안됨
        if(!parentExixts && currentExists) {
            return false; 
        }
        
        // 리프 노드(위 상황만 아니면 상관x)
        if (tree.length() == 1) {
            return true;
        }
        
        // 둘 중 하나라도 불가능하면 안됨
        return (availableTree(tree.substring(0, mid), currentExists) 
                && availableTree(tree.substring(mid + 1), currentExists));
    }
    
    
    // 10 -> 2진수
    // public String toBinary(long num){
    //     StringBuilder sb = new StringBuilder(); 
    //     while(num > 0){
    //         sb.append(num % 2); 
    //         num /= 2;
    //     }
    //     return sb.reverse().toString();
    // }

    
}