import java.util.*; 
class Node{
    int y; int x; int num;
    public Node(int y, int x, int num){
        this.y = y; 
        this.x = x;
        this.num = num;
    } 
}
class Solution {
    int[][] graph; // [부모] = 자식(right, left) 연결리스트. 자식 개수가 정해져있으니 int[]로 설정
    
    List<Node> nodes = new ArrayList<>(); // [num, y, x] 저장 배열

    // 전위 순회
    List<Integer> pre = new ArrayList<>();
    public void prefixOrder(int r){
        // R-l-r
        if(r == 0) return;
        pre.add(r); 
        prefixOrder(graph[r][0]);
        prefixOrder(graph[r][1]);
    }
    
    // 후위 순회
    List<Integer> post = new ArrayList<>();
    public void postOrder(int r){
        // l-r-R
        if(r == 0) return;
        postOrder(graph[r][0]);
        postOrder(graph[r][1]);
        post.add(r); 
    }
    
    // 트리 만들기 - 범위 내에 노드가 있다면 연결관계 저장
    public int makeTree(int startX, int endX, int availIdx, int parentNum, int parentY){
        // startX ~ endX 사이에 노드 있는지 확인 (availIdx 부터)
        for(int i = availIdx; i < nodes.size(); i++){
            // 부모와 같은 높이이거나 더 높은 노드는 자식이 될 수 없음
            if(nodes.get(i).y >= parentY) continue;
            // 현재 서브트리의 x 범위에 포함되지 않음
            if(nodes.get(i).x < startX || nodes.get(i).x > endX) continue; 
            
            int currentNum = nodes.get(i).num;
            // 자식 찾아 연결(한 세대만)
            graph[currentNum][0] = makeTree(startX, nodes.get(i).x-1, i+1, nodes.get(i).num, nodes.get(i).y);
            graph[currentNum][1] = makeTree(nodes.get(i).x+1, endX, i+1, nodes.get(i).num, nodes.get(i).y);
            
            // 찾았으면 리턴
            return currentNum; 
        }
        // 못 찾았음
        return 0; 
    }
    
    
    public int[][] solution(int[][] nodeinfo) { // 노드들의 좌표가 담긴 배열 nodeinfo
        graph = new int[nodeinfo.length + 1][2];
        
        // {y, x}로 번호가 인덱스가 되도록 리스트에 저장
        for(int i = 1; i <= nodeinfo.length; i++) {
            int[] n = nodeinfo[i-1];
            nodes.add(new Node(n[1], n[0], i));
        }
        
        // [좌표로 트리 생성 (부모-자식 관계 찾기)]
        nodes.sort((a, b) -> {
            if(a.y != b.y) return b.y - a.y; // y 내림차순
            else return a.x - b.x; // x 오름차순
        });
        
        // 연결리스트 만들기
        int rootNum = nodes.get(0).num;
        graph[rootNum][0] = makeTree(0, nodes.get(0).x-1, 1, nodes.get(0).num, nodes.get(0).y); 
        graph[rootNum][1] = makeTree(nodes.get(0).x+1, 100000, 1, nodes.get(0).num, nodes.get(0).y); 
        
        // [전위 순회]
        prefixOrder(nodes.get(0).num); // root부터 시작
        
        // [후위 순회]
        postOrder(nodes.get(0).num); // root부터 시작
        
        // 노드들로 구성된 이진트리를 전위 순회, 후위 순회한 결과를 2차원 배열에 순서대로 담아 return
        int[][] answer = new int[2][]; // 바로 접근해야 하는 곳은 인덱스 설정해줘야 함. 
        answer[0] = pre.stream().mapToInt(i->i).toArray(); 
        answer[1] = post.stream().mapToInt(i->i).toArray(); 
        return answer;
    }
    
    
}