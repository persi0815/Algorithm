import java.util.HashMap; 
import java.util.List; 
import java.util.Map; 

class Solution {
    
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        Map<String, Integer> map = new HashMap<>(); 
        for(String part : participant){
            map.put(part, map.getOrDefault(part, 0) + 1); 
        }
        
        for(String comp : completion){
            map.put(comp, map.get(comp)-1); 
        }
        
        for(Map.Entry<String, Integer> entry : map.entrySet()){
            if(entry.getValue() != 0){
                answer = entry.getKey(); 
                break; 
            }
        }
        
        return answer;
    }
}