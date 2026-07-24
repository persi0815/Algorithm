import java.util.*; 

class Body{
    String head; String number; String tail; 
    public Body(String head, String number, String tail){
        this.head = head; this.number = number; this.tail = tail; 
    }
}
class Solution {
    
    // 파일명에 포함된 숫자를 반영한 정렬 기능을 저장소 관리 프로그램에 구현
    public String[] solution(String[] files) {
        
        // HEAD, NUMBER, (TAIL)로 구분
        List<Body> splitedFiles = new ArrayList<>(); 
        for(String f : files){
            String head = "";
            String number = "";
            String tail = ""; 
            for(int i = 0; i < f.length(); i++){
                // head 시작 찾기 (수 시작)
                if(f.charAt(i) >= '0' && f.charAt(i) <= '9'){
                    if(head.equals("")) head = f.substring(0, i); 
                }
                // number 끝 찾기 (수 끝)
                else{
                    if(!head.equals("") && number.equals("")) { // 이미 head가 있음
                        number = f.substring(head.length(), i); 
                        tail = f.substring(i);
                    }
                }
            }
            // number가 아직 안들어왔다면 남은 조각이 number
            if(number.equals("")) number = f.substring(head.length()); 
            // list에 분리한거 삽입
            splitedFiles.add(new Body(head, number, tail)); 
        }
        
        // 정렬
        splitedFiles.sort((a, b) ->{
            String aLowerCaseHead = ""; String bLowerCaseHead = "";
            for(int i = 0; i < a.head.length(); i++) aLowerCaseHead += Character.toLowerCase(a.head.charAt(i));
            for(int i = 0; i < b.head.length(); i++) bLowerCaseHead += Character.toLowerCase(b.head.charAt(i));
            // HEAD 부분을 기준으로 사전 순으로 정렬 (대소문자 구분x)
            if(!aLowerCaseHead.equals(bLowerCaseHead)) return aLowerCaseHead.compareTo(bLowerCaseHead);
            // NUMBER의 숫자 순으로 정렬
            else return Integer.parseInt(a.number) - Integer.parseInt(b.number);
            // HEAD, NUMBER 모두 같을 경우 원래 입력에 주어진 순서를 유지 = stable sort(java는 기본적으로 제공)
        });        
        
        // 다시 합치기 (head + number + tail)
        List<String> answer = new ArrayList<>(); 
        for(Body b : splitedFiles){
            answer.add(b.head + b.number + b.tail);
        }
        
        
        // 정렬된 배열을 출력
        return answer.stream().toArray(String[]::new);
    }
}