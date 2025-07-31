import java.util.*; 
/*
n명의 권투 선수가 대회 참여. 1번부터 n번까지 번호 수령. 
경기 결과로 선수 순위 매김.
*/

class Solution {
    boolean[] visited = new boolean[101];
    void dfs(Set<Integer> arr[], int to, int now){
        List<Integer> copy = new ArrayList<>(arr[now]);
        for(int num : copy){
            if(visited[num]) continue; 
            
            visited[num] = true; 
            arr[to].add(num);
            dfs(arr, to, num);
            
        }
    }
    
    // 선수의 수, 경기 결과
    public int solution(int n, int[][] results) {
        
        Set<Integer> win[] = new HashSet[n+1];
        Set<Integer> lose[] = new HashSet[n+1];
        for(int i = 0; i <= n; i++){
            win[i] = new HashSet<>();
            lose[i] = new HashSet<>();
        }
        
        for(int[] res : results){
            int w = res[0]; int l = res[1];
            win[w].add(l);
            lose[l].add(w);
        }
        
        for(int i = 1; i <= n; i++){
            Arrays.fill(visited, false);
            visited[i] = true;
            dfs(win, i, i);
        }
        for(int i = 1; i <= n; i++){
            Arrays.fill(visited, false);
            visited[i] = true;
            dfs(lose, i, i);
        }
        
        
        int answer = 0;
        for(int i = 1; i <= n; i++){
            if(win[i].size() + lose[i].size() == n-1) answer++;
        }
        
        return answer; // 정확하게 순위 매길 수 있는 선수의 수
    }
}