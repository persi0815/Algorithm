import java.util.*; 

class Solution {
    
    class Song{
        String name; int length; String song; 
        public Song(String name, int length, String song){
            this.name = name; this.length = length; this.song = song; 
        }
    }
    
    public int toTime(String time){
        int hour = Integer.parseInt(time.substring(0, 2)); 
        int min = Integer.parseInt(time.substring(3, 5));
        return hour*60 + min;
    }
    
    public String solution(String m, String[] musicinfos) {
        
        List<Song> songs = new ArrayList<>(); 
        
        for(String musicinfo : musicinfos){
            String[] music = musicinfo.split(","); 
            int length = toTime(music[1]) - toTime(music[0]); 
            String name = music[2]; 
            String lyrics = music[3];
            int nums = lyrics.replace("#", "").length();
            
            StringBuilder song = new StringBuilder(); 
            for(int i = 0; i < length/nums; i++){
                song.append(lyrics); 
            }
            if(length%nums != 0){
                int idx = 0;
                for(int i = 0; i < length%nums; i++){
                    if(idx+1 < lyrics.length() && lyrics.charAt(idx+1) == '#') {
                        song.append(lyrics.substring(idx, idx+2));
                        idx+=2;
                    }
                    else {
                        song.append(lyrics.substring(idx, idx+1));
                        idx+=1;
                    }
                }
            }
            
            String s = song.toString();
            int index = s.indexOf(m);
            while (index != -1) {
                int endIndex = index + m.length();
                if (endIndex == s.length() || s.charAt(endIndex) != '#') {
                    songs.add(new Song(name, length, s));
                    break;
                }

                // 현재 위치는 C#의 C에 잘못 일치했으므로 다음 위치 탐색
                index = s.indexOf(m, index + 1); // 탐색 시작 위치 변경
            }
            
        }
        
        // 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환
        // 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환
        songs.sort((a, b) -> { // 안정 정렬
            return Integer.compare(b.length, a.length); 
        });
    
        if(songs.size() != 0) return songs.get(0).name; 
        // 조건이 일치하는 음악이 없을 때에는 “(None)”을 반환
        return "(None)";
    }
}