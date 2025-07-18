import java.util.*; 
/*
n개의 송전탑이 전선 통해 하나의 트리 형태로 되어 있음. 
전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할 
-> 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞춘다. 
-> 두 전력망이 가지고 있는 송전탑 개수의 차이를 리턴

완탐해도 된다. 간선 번호를 인덱스로 잡자. 
일단 연결 리스트로 그래프 그리고, 
쪼갠 간선 기준으로 두 부분을 dfs나 bfs로 노드 개수 구하자.
*/

class Solution {
    int answer = Integer.MAX_VALUE;
    int cnt = 0;
    
    public int bfs(int start, int exceptNode, List<Integer>[] graph, int n){
        int cnt = 1; 
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start]= true;
        
        while(!q.isEmpty()){
            int now = q.poll();
            for(int next : graph[now]){
                if ((now == start && next == exceptNode) || 
                    (now == exceptNode && next == start)) continue;
                if(!visited[next]){
                    visited[next] = true;
                    //System.out.println(next);
                    q.add(next);
                    cnt++;
                }
            }
        }
        
        //System.out.println(start + " " + exceptNode + " " + cnt);
        return cnt;
    }
    
    // 송전탑의 개수(100)와 전선 정보
    public int solution(int n, int[][] wires) {
        
        
        // 연결 리스트 만들기
        List<Integer>[] graph = new ArrayList[n+1]; 
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>(); // 각 인덱스에 리스트 생성
        }
        
        // 양방향 그래프 구성
        for (int[] wire : wires) {
            int a = wire[0];
            int b = wire[1];
            graph[a].add(b);
            graph[b].add(a);
        }
        
        // 각 간선을 하나씩 끊어보며 차이 계산
        for (int[] wire : wires) {
            int a = wire[0];
            int b = wire[1];

            int countA = bfs(a, b, graph, n);
            int countB = n - countA;

            answer = Math.min(answer, Math.abs(countA - countB));
        }
        
        return answer;
    }
}