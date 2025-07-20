import java.util.*; 
/*
체육복 빌려줘. 바로 앞이나 뒷번호의 학생에게만 빌려줄 수 있음. 
최대한 많은 학생이 체육 수업을 들어야 함. 
여벌 체육복이 있는데 도난당했다면, 빌려줄 수 없음. 
*/

class Solution {
    
    // 전체 학생 수, 도난 당한 학생 번호들, 여벌의 체육복 가조은 학생 번호들
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0; // 체육복 있거나 받을 수 있는 학생 수의 최댓값
        
        // reserve에서 lost에도 있는 학생들은 제거 -> set으로 관리
        Set<Integer> reserve_id = new HashSet<>();
        List<Integer> lost_id = new ArrayList<>(); 
        for (int l : lost) lost_id.add(l);
        
        for(int id : reserve){
            if(lost_id.contains(id)){
                lost_id.remove(Integer.valueOf(id)); 
            }else{
                reserve_id.add(id);
            }
            // lost에도 있으면 lost와 reserve에서 모두 제거
            // lost에 없으면 reserve에 넣기
        }
        //System.out.println(reserve_id);
        
        // lost 앞부터 앞번호, 뒷번호 차례로 묻기
        Collections.sort(lost_id); // 오름차순 정렬
        int no = 0; 
        for (int id : lost_id) {
            if (reserve_id.contains(id - 1)) {
                reserve_id.remove(id - 1);
            } else if (reserve_id.contains(id + 1)) {
                reserve_id.remove(id + 1);
            } else {
                no++;
            }
        }
        
        return answer = n-no;
    }
}