import java.util.*; 
/*
주어진 항공권을 '모두' 이용하여 여행경로를 짜려고 함. ICN 공항에서 출발
단뱡향 이동. 
경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 리턴  -> 연결리스트에서 정렬
*/

class Solution {
    
    boolean[] visited;
    List<String> path = new ArrayList<>();

    public List<String> solution(String[][] tickets) { // String[]
        Arrays.sort(tickets, (a, b) -> a[0].equals(b[0]) ? a[1].compareTo(b[1]) : a[0].compareTo(b[0]));
        visited = new boolean[tickets.length];
        path.add("ICN");
        dfs("ICN", tickets, 0);
        return path;
        //return answer.toArray(new String[0]); // Object[]를 String[]로 바꿔줘야 함. 
    }
    
    public boolean dfs(String curr, String[][] tickets, int used) {
        if (used == tickets.length) {
            return true; // 사전순 가장 빠른 경로를 찾으면 바로 종료
        }

        for (int i = 0; i < tickets.length; i++) {
            if (!visited[i] && tickets[i][0].equals(curr)) {
                visited[i] = true;
                path.add(tickets[i][1]);
                if (dfs(tickets[i][1], tickets, used + 1)) return true;
                path.remove(path.size() - 1);
                visited[i] = false;
            }
        }

        return false;
    }
    
}