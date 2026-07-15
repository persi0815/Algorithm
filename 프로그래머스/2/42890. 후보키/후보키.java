import java.util.*;

class Solution {
    
    // 정답 배열
    HashSet<Integer> candidateKeys = new HashSet<>(); 
    
    public int solution(String[][] relation) {
        int columnNum = relation[0].length; 
        int rowNum = relation.length;
        
        // 가능한 후보들 하나씩 검증
        for(int mask = 1; mask < (1 << columnNum); mask++){ // 2^8 = 256
            
            // 유일성인지
            HashSet<String> data = new HashSet<>(); // 비교해야 할 값들
            for(int row = 0; row < rowNum; row++){ // 20
                String d = "";
                for(int col = 0; col < columnNum; col++){ // 8
                    if(((1 << col) & mask) != 0) d += relation[row][col]; 
                }   
                data.add(d + "-");
            }
            if(data.size() != rowNum) continue;
            
            // 최소성인지
            boolean isMinimal = true;
            for (int ck : candidateKeys) {
                if ((ck & mask) == ck) {
                    isMinimal = false; 
                }
            }
            if(!isMinimal) continue;
            
            // 후보로 저장
            candidateKeys.add(mask); 
        }
        
        // 후보 키의 개수
        return candidateKeys.size();
    }
}