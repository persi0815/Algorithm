import java.util.*; 

class Solution {
    
    boolean[] ticketUsed; 
    List<String> path;
    
    public String[] solution(String[][] tickets) { // 항공권 정보
        
        path = new ArrayList<>(); 
        ticketUsed = new boolean[tickets.length]; 
        
        // 각 list 알파벳 순으로 정렬
        Arrays.sort(tickets, (a, b) -> {
            if(!a[0].equals(b[0])) return (a[0]).compareTo(b[0]); 
            else return (a[1]).compareTo(b[1]); 
        });

        // 경로가 중요하니 dfs
        path.add("ICN");
        dfs("ICN", tickets);
        
        return path.stream().toArray(String[]::new);
    }
    
    public boolean dfs(String cur, String[][] tickets){
        // 티켓 전부 돌았다. 알파벳 순으로 가장 앞선 순서부터 방문 예정. 
        if(path.size() == tickets.length+1){
            return true;
        }
        // 다음 장소로 이동
        for(int t = 0; t < tickets.length; t++){
            String[] ticket = tickets[t]; 
            
            // 현재 출발지가 맞아야 함
            if(!ticket[0].equals(cur)) continue; 
            
            // 이미 사용했다면 사용하지 못함
            if(ticketUsed[t]) continue; 
            
            // 티켓 사용
            ticketUsed[t] = true; 
            path.add(ticket[1]); 
            
            // 다음 방문지 찾기
            if(dfs(ticket[1], tickets)) return true; 
            
            // 원상 복구
            path.remove(path.size()-1);
            ticketUsed[t] = false; 
        }
        return false;
    }
}