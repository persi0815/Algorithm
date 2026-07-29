import java.util.*; 

class Solution {
    public int[] solution(String s) {
        
        // 길이 오름차순으로 정렬
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> l = new ArrayList<>();
        int num = 0; 
        for(int i = 1; i < s.length() - 1; i++){
            char cur = s.charAt(i);
            if(cur == '{'){
                l.clear(); 
            }else if(cur == '}'){
                l.add(num); num = 0;
                list.add(new ArrayList<>(l));
                i+=1;
            }else if(Character.isDigit(cur)){
                num = num * 10 + Integer.parseInt(String.valueOf(cur)); 
            }else{ // ,
                l.add(num); num = 0;
                
            }
        }
        
        // 배열 길이로 오름차순 정렬
        list.sort((a, b) -> {
            return Integer.compare(a.size(), b.size()); 
        });
        
        // 정답 배열 만들기
        HashSet<Integer> set = new HashSet<>(); 
        List<Integer> answer = new ArrayList<>();
        for(List<Integer> ll : list){
            for(int n : ll){
                if(!set.contains(n)){
                    answer.add(n); 
                    set.add(n); 
                    break;
                }
            }
        }
        
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}