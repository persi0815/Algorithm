import java.util.*; 

class Solution {
    HashMap<String, Integer> dictionary = new HashMap<>(); 
    
    public String getLongestStr(String msg, int msgId){
        String s = "";
        for(int len = 1; len <= (msg.length()-msgId); len++){
            if(dictionary.containsKey(msg.substring(msgId, msgId+len))) 
                s = msg.substring(msgId, msgId+len);
            else break;
        }
        return s;
    }
    
    public int[] solution(String msg) {
        List<Integer> ans = new ArrayList<>(); 
        
        // 길이가 1인 모든 단어를 포함하도록 사전을 초기화
        for(int alph = 0; alph < 26; alph++){
            dictionary.put(String.valueOf((char)('A'+alph)), alph+1); 
        }
        int num = 27;
        
        int msgId = 0;
        
        while(msgId < msg.length()){
            // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w 찾기
            String w = getLongestStr(msg, msgId); 
            // w에 해당하는 사전의 색인 번호를 출력
            ans.add(dictionary.get(w));
            // 입력에서 w를 제거
            msgId += w.length(); 

            // 입력에서 처리되지 않은 다음 글자가 남아있다면
            if(msgId < msg.length()){ 
                Character c = msg.charAt(msgId); 
                // w+c에 해당하는 단어를 사전에 등록
                dictionary.put(w+c, num++); 
            }
        }
        
        // 주어진 문자열을 압축한 후의 사전 색인 번호를 배열로 출력
        return ans.stream().mapToInt(i->i).toArray();
    }
}