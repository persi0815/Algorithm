import java.util.*;

class Song{
    int id;
    int playNum;

    public Song(int id, int playNum) {
        this.id = id;
        this.playNum = playNum;
    }
}

class Solution {
    /*
    장르별로 가장 많이 재생된 노래를 두개씩 모아 베스트 앨범으로 출시하려 함. 
    
    재생 횟수 높은 장르 > 재생 횟수 높은 노래 > 고유 번호 낮은 노래
    */
    // 장르와 재생 횟수
    public int[] solution(String[] genres, int[] plays) {
        int songNum = plays.length;
        
        int[] answer = {};
        List<Integer> result = new ArrayList<>();
        
        // 장르별 재생 횟수 파악 -> 장르 순 파악
        // {장르, 재생수}
        Map<String, Integer> playsByGenre = new HashMap<>();
        for(int i = 0; i < songNum; i++){
            playsByGenre.put(genres[i], playsByGenre.getOrDefault(genres[i], 0) + plays[i]); 
        }
        List<Map.Entry<String, Integer>> genrePlays = new ArrayList<>(playsByGenre.entrySet());
        genrePlays.sort((a, b)  -> b.getValue() - a.getValue()); 
        
        // 장르에서 노래들의 재생 횟수로 내림차순, 고유 번호로 오름차순 -> 앨범에서 노래 순 파악
        for (Map.Entry<String, Integer> entry : genrePlays) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
            String genre = entry.getKey(); 
            List<Song> songs = new ArrayList<>(); 
            
            for(int i = 0; i < songNum; i++){
                if(genres[i].equals(genre)) 
                    songs.add(new Song(i, plays[i])); 
            }
            
            songs.sort((a, b) -> {
                if(a.playNum != b.playNum){
                    return b.playNum - a.playNum; // 재생 수 내림차순
                }
                return a.id - b.id; // id 오름차순
            });
            
            
            for(int i = 0; i < Math.min(2, songs.size()); i++){
                result.add(songs.get(i).id);
            }

        }
        
        return answer = result.stream().mapToInt(i -> i).toArray();
    }
}