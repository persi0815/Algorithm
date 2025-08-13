import java.util.*; 


class Solution {
    List<int[]> answer = new ArrayList<>(); 
    
    // 데이터들, 기준, 기준값, 정렬 기준
    // [코드 번호(code), 제조일(date), 최대 수량(maximum), 현재 수량(remain)] 
    public List<int[]> solution(int[][] data, String ext, int val_ext, String sort_by) {
        // data에서 ext 값이 val_ext보다 작은 데이터만 뽑은 후, 
        // sort_by에 해당하는 값을 기준으로 오름차순으로 정렬하여 return 
        
        
        // 필터링
        int filter_idx =
                ext.equals("code") ? 0 :
                ext.equals("date") ? 1 :
                ext.equals("maximum") ? 2 :
                ext.equals("remain") ? 3 : -1;
        
        // ext 값이 val_ext보다 작은 데이터 answer에 넣기
        for(int[] d : data){
            if(d[filter_idx] < val_ext) answer.add(d);
        }
        
        // 정렬
        int order_idx =
                sort_by.equals("code") ? 0 :
                sort_by.equals("date") ? 1 :
                sort_by.equals("maximum") ? 2 :
                sort_by.equals("remain") ? 3 : -1;
        
        // sort_by에 해당하는 값을 기준으로 오름차순으로 정렬
        answer.sort((a, b) -> Integer.compare(a[order_idx], b[order_idx]));
        
        // 타입 바꾸기
        
        
        return answer;
    }
}