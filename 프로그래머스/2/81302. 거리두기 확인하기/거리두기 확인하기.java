import java.util.*;
class Node{
    int y; int x; 
    public Node(int y, int x){
        this.y = y; this.x = x; 
    }
}
class Solution {
    

    public int[] solution(String[][] places) {
        List<Integer> ans = new ArrayList<>(); 

        // turn마다 반복
        for(int t = 0; t < 5; t++){
            boolean follow = true;
            
            List<Node> pList = new ArrayList<>(); 
            Character[][] area = new Character[5][5];
            // 배열 만들기 -> p들은 따로 모아두기
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    area[i][j] = places[t][i].charAt(j);
                    if(area[i][j].equals('P')) pList.add(new Node(i, j));
                }
            }
            
            // p들끼리 거리두기 지키고 있는지 확인
            for(int i = 0; i < pList.size()-1; i++){
                if(!follow) break;
                for(int j = i+1; j < pList.size(); j++){
                    int y1 = pList.get(i).y; 
                    int x1 = pList.get(i).x; 
                    int y2 = pList.get(j).y; 
                    int x2 = pList.get(j).x; 
                    
                    // 맨해튼 거리 2 이낸지
                    if(Math.abs(y1-y2) + Math.abs(x1-x2) > 2) continue; 
                    
                    // 그 거리 안에 대기실은 없는지
                    if(y1==y2){
                        if(area[y1][(x2+x1)/2].equals('X')) continue;
                    }else if(x1==x2){
                        if(area[(y1+y2)/2][x1].equals('X')) continue;
                    }else{
                        if(area[y1][x2].equals('X') && area[y2][x1].equals('X')) continue;
                    }
                    
                    // 거리두기 실패
                    ans.add(0);
                    follow = false;
                    break; 
                }
            }
            // 거리두기 성공
            if(follow) ans.add(1);
        }
        
        //  대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 배열에 담아 return 
        return ans.stream().mapToInt(s->s).toArray();
    }
}