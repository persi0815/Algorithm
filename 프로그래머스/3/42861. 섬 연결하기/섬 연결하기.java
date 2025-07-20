import java.util.*;
/*
프림 알고리즘으로 가중치가 낮은 것부터 선택해 나감
-> 모든 섬을 최소 비용으로 연결하는 MST 구하기!!
*/
class Node { //  implements Comparable<Node>
    int to, cost;

    Node(int to, int cost) {
        this.to = to;
        this.cost = cost;
    }

    // @Override
    // public int compareTo(Node o) {
    //     return Integer.compare(this.cost, o.cost);
    // }
}

class Solution {
    public int prim(int n, List<Node>[] graph) {
        boolean[] visited = new boolean[n];
        PriorityQueue<Node> pq = new PriorityQueue<>((n1, n2) -> Integer.compare(n1.cost, n2.cost));
        pq.offer(new Node(0, 0)); // 시작 노드
        int totalCost = 0;

        while (!pq.isEmpty()) {
            Node current = pq.poll();

            if (visited[current.to]) continue;

            visited[current.to] = true;
            totalCost += current.cost;

            for (Node next : graph[current.to]) {
                if (!visited[next.to]) {
                    pq.offer(next);
                }
            }
        }

        return totalCost;
    }

    public int solution(int n, int[][] costs) {
        List<Node>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();

        for (int[] edge : costs) {
            graph[edge[0]].add(new Node(edge[1], edge[2]));
            graph[edge[1]].add(new Node(edge[0], edge[2]));
        }

        return prim(n, graph);
    }
}
