import java.util.*;

class Node {
    int y;
    int x;

    public Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Cost {
    int y;
    int x;
    int cost;

    public Cost(int y, int x, int cost) {
        this.y = y;
        this.x = x;
        this.cost = cost;
    }
}

class Solution {
    int n; // 카드 종류 개수

    int[][] directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    int[][] currentBoard;

    // 카드 제거 순서를 저장하는 순열
    List<List<Integer>> permutations;
    List<Integer> permutation = new ArrayList<>();
    boolean[] visited;

    public void makeOrder(List<Integer> cardTypes) {
        if (permutation.size() == cardTypes.size()) {
            permutations.add(new ArrayList<>(permutation));
            return;
        }

        for (int i = 0; i < cardTypes.size(); i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            permutation.add(cardTypes.get(i));

            makeOrder(cardTypes);

            permutation.remove(permutation.size() - 1);
            visited[i] = false;
        }
    }

    public int solution(int[][] board, int r, int c) {
        Set<Integer> cardSet = new HashSet<>();

        // 카드 번호별 두 카드의 위치
        List<Node>[] cardPositions = new ArrayList[9];

        for (int i = 0; i < cardPositions.length; i++) {
            cardPositions[i] = new ArrayList<>();
        }

        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                int cardNumber = board[y][x];

                if (cardNumber != 0) {
                    cardSet.add(cardNumber);
                    cardPositions[cardNumber].add(new Node(y, x));
                }
            }
        }

        // 카드 종류 목록
        List<Integer> cardTypes = new ArrayList<>(cardSet);
        cardTypes.sort(Integer::compareTo);

        n = cardTypes.size();

        // 카드 제거 순열 생성
        visited = new boolean[n];
        permutations = new ArrayList<>();
        permutation.clear();

        makeOrder(cardTypes);

        /*
         * 각 카드 쌍의 방문 방향
         * 0: 첫 번째 카드 → 두 번째 카드
         * 1: 두 번째 카드 → 첫 번째 카드
         */
        int[][] visitOrders = new int[1 << n][n];

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                visitOrders[mask][i] = (mask >> i) & 1;
            }
        }

        int answer = Integer.MAX_VALUE;

        // 카드 종류의 제거 순서
        for (List<Integer> order : permutations) {

            // 각 카드 쌍 내부의 방문 순서
            for (int[] turns : visitOrders) {
                currentBoard = copyBoard(board);

                int currentY = r;
                int currentX = c;
                int totalCost = 0;

                for (int i = 0; i < n; i++) {
                    int cardNumber = order.get(i);
                    int turn = turns[i];

                    Node first = cardPositions[cardNumber].get(turn);
                    Node second = cardPositions[cardNumber].get(1 - turn);

                    // 현재 위치에서 첫 번째 카드로 이동
                    totalCost += bfs(
                        currentY,
                        currentX,
                        first.y,
                        first.x
                    );
                    totalCost++; // Enter

                    // 첫 번째 카드에서 두 번째 카드로 이동
                    totalCost += bfs(
                        first.y,
                        first.x,
                        second.y,
                        second.x
                    );
                    totalCost++; // Enter

                    // 짝을 맞춘 카드 제거
                    currentBoard[first.y][first.x] = 0;
                    currentBoard[second.y][second.x] = 0;

                    // 커서는 두 번째 카드 위치에 있음
                    currentY = second.y;
                    currentX = second.x;
                }

                answer = Math.min(answer, totalCost);
            }
        }

        return answer;
    }

    // 현재 보드 상태를 독립적으로 복사
    public int[][] copyBoard(int[][] board) {
        int[][] copied = new int[4][4];

        for (int y = 0; y < 4; y++) {
            copied[y] = board[y].clone();
        }

        return copied;
    }

    // 두 위치 사이의 최소 키 조작 횟수
    public int bfs(int startY, int startX, int targetY, int targetX) {
        int[][] distance = new int[4][4];

        for (int y = 0; y < 4; y++) {
            Arrays.fill(distance[y], Integer.MAX_VALUE);
        }

        Queue<Cost> queue = new ArrayDeque<>();

        queue.offer(new Cost(startY, startX, 0));
        distance[startY][startX] = 0;

        while (!queue.isEmpty()) {
            Cost current = queue.poll();

            if (current.y == targetY && current.x == targetX) {
                return current.cost;
            }

            for (int d = 0; d < 4; d++) {
                // 방향키로 한 칸 이동
                int nextY = current.y + directions[d][0];
                int nextX = current.x + directions[d][1];

                if (isValid(nextY, nextX)) {
                    addNextPosition(
                        queue,
                        distance,
                        nextY,
                        nextX,
                        current.cost + 1
                    );
                }

                // Ctrl + 방향키로 이동
                Node ctrlPosition = ctrlMove(current.y, current.x, d);

                addNextPosition(
                    queue,
                    distance,
                    ctrlPosition.y,
                    ctrlPosition.x,
                    current.cost + 1
                );
            }
        }

        return -1;
    }

    // 더 적은 비용으로 도착한 경우만 큐에 추가
    public void addNextPosition(
        Queue<Cost> queue,
        int[][] distance,
        int y,
        int x,
        int newCost
    ) {
        if (distance[y][x] <= newCost) {
            return;
        }

        distance[y][x] = newCost;
        queue.offer(new Cost(y, x, newCost));
    }

    // 가장 가까운 카드 또는 마지막 칸까지 Ctrl 이동
    public Node ctrlMove(int y, int x, int direction) {
        while (true) {
            int nextY = y + directions[direction][0];
            int nextX = x + directions[direction][1];

            // 범위를 벗어나면 현재 칸이 해당 방향의 마지막 칸
            if (!isValid(nextY, nextX)) {
                return new Node(y, x);
            }

            y = nextY;
            x = nextX;

            // 가장 가까운 카드에서 정지
            if (currentBoard[y][x] != 0) {
                return new Node(y, x);
            }
        }
    }

    public boolean isValid(int y, int x) {
        return y >= 0 && x >= 0 && y < 4 && x < 4;
    }
}