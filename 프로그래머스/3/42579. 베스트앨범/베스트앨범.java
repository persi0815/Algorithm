import java.util.*; 

// 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시
// 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return
class Solution {
    class Song{
        int num; int played; 
        public Song(int num, int played){
            this.num = num; this.played = played; 
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
                
        HashMap<String, List<Song>> played = new HashMap<>(); 
        for(int i = 0; i < plays.length; i++){
            played.computeIfAbsent(genres[i], v -> new ArrayList<>())
                .add(new Song(i, plays[i])); 
        }
        
        // 장르별 재생 수 총합 구하기 -> 장르 순서 구하기
        HashMap<String, Integer> genrePlayed = new HashMap<>(); 
        
        for(Map.Entry<String, List<Song>> entry: played.entrySet()){
            String genre = entry.getKey(); 
            List<Song> songs = entry.getValue(); 
            
            // 각 장르마다 재생된 수로 내림차순 & 수 같으면 고유 번호 낮은 순
            songs.sort((a, b) -> {
                if(a.played != b.played) return Integer.compare(b.played, a.played); 
                else return Integer.compare(a.num, b.num); 
            }); 
            
            // 장르마다 총 재생 수
            int sumPlayed = songs.stream().mapToInt(i->i.played).sum();
            genrePlayed.put(genre, sumPlayed); 
        }
        
        List<Map.Entry<String, Integer>> entries = new ArrayList<>(genrePlayed.entrySet());
        entries.sort((a, b) -> {
            return Integer.compare(b.getValue(), a.getValue()); // 장르 총 재생 수로 내림차순 정렬
        });
        
        
        // 장르별 두개씩
        List<Integer> answer = new ArrayList<>(); 
        for(Map.Entry<String, Integer> entry: entries){
            String genre = entry.getKey(); 
            // 해당 장르마다 두개씩
            List<Song> songs = played.get(genre); 
            answer.add(songs.get(0).num); 
            if(songs.size() >= 2) answer.add(songs.get(1).num); 
        }
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}