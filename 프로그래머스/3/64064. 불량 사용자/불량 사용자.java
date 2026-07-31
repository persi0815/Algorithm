import java.util.*; 

class Solution {
    
    HashMap<Integer, List<Integer>> available = new HashMap<>(); 
    HashSet<Integer> resultMasks = new HashSet<>(); 
    
    // 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return
    public int solution(String[] user_id, String[] banned_id) {

        
        // 불량 사용자 순회하면서 어떤게 가능한지 확인
        for(int b = 0; b < banned_id.length; b++){ // 8
            String banned = banned_id[b]; 
            for(int u = 0; u < user_id.length; u++){ // 8
                String user = user_id[u]; boolean avail = true;
                // 적합한지
                if(user.length() != banned.length()) continue; 
                for(int i = 0; i < user.length(); i++){ // 8
                    if(banned.charAt(i) != '*' && user.charAt(i) != banned.charAt(i)) {
                        avail = false; break; 
                    }
                }
                if(avail) {
                    available.computeIfAbsent(b, k -> new ArrayList<>()).add(u);
                    // System.out.println(banned + " " + user);
                }
            }
        }
        
        // 하나씩 고르는데 중복 안되도록 (비트마스킹 사용)
        dfs(0, 0, banned_id.length);
       
        
        return resultMasks.size();
    }
    
     public void dfs(int bannedIndex, int mask, int bannedCount) {
        // 모든 불량 사용자 패턴에 사용자 배정 완료
        if (bannedIndex == bannedCount) {
            resultMasks.add(mask);
            return;
        }

        for (int userIndex : available.get(bannedIndex)) {
            int bit = 1 << userIndex;

            // 이미 선택한 사용자
            if ((mask & bit) != 0) continue;

            dfs(bannedIndex + 1, mask | bit, bannedCount);
        }
    }
}