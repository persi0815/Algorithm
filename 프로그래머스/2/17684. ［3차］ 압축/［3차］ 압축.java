import java.util.*; 

class Solution {
    HashMap<String, Integer> index = new HashMap<>();
    
    // msg에서 idx가 i부터 인 단어중 사전에 있는 가장 긴 문자열 찾아 반환
    public String findW(int i, String msg){
        int len = 1;
        while(i+len <= msg.length() && index.containsKey(msg.substring(i, i+len))) {
            len++;
        }
        return msg.substring(i, i+len-1);
    }
        
    public int[] solution(String msg) {
        List<Integer> answer = new ArrayList<>();
        // map 만들기
        for(int a = 0; a < 26; a++){
            index.put(String.valueOf((char)(a+'A')), a+1);
        }
        
        int nxt_id = 27;
        
        int i = 0; 
        while(i < msg.length()){
            // 가장 긴 w 찾기. 길이 늘리다가 index에 없으면 멈추기
            String w = findW(i, msg); 
            
            // w의 색인을 answer에 넣기, i를 출력 다음 인덱스로 이동
            answer.add(index.get(w)); 
            i += w.length();
            
            // msg에서 아직 남은 글자가 있다면, w+c를 사전에 등록
            if(i < msg.length()) index.put(w+msg.charAt(i), nxt_id++);
        }
        
        
        //  문자열을 압축한 후의 사전 색인 번호를 배열로 출력
        return answer.stream().mapToInt(k->k).toArray();
    }
}