import java.util.*; 

class Solution {
    /*
    각 종류별로 1가지 의상만 착용 가능. 하루에 한개의 의상은 입음
    매일 다른 의상 입음. 
    
    */
    
    // 의상 이름, 의상 종류
    public int solution(String[][] clothes) {
        int answer = 0; // 서로 다른 옷의 조합의 수
        
        // {종류, 종류 개수}으로 변경
        Map<String, Integer> nums = new HashMap<>();
        for(int i = 0; i < clothes.length; i++){
            nums.put(clothes[i][1], nums.getOrDefault(clothes[i][1], 0) + 1);
        }
        
        // value 값 + 1 들을 전부 곱하고 -1(안 입는 경우)
        answer = 1;
        for(Map.Entry<String, Integer> entry: nums.entrySet()){
            answer *= (entry.getValue() + 1);
        }
        
        return answer - 1;
    }
}