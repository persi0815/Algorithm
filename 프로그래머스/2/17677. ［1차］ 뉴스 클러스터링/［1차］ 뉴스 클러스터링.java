import java.util.*;

class Solution {
    
    private boolean isAlphabet(char c) {
        return ('a' <= c && c <= 'z') ||
               ('A' <= c && c <= 'Z');
    }
    
    public int solution(String str1, String str2) { // 길이 각각 1,000 이하
        int answer = 0;
        
        // 두 문자열을 각각 두 글자씩 끊어서 다중집합의 원소로 만들기 (영문자로 된 쌍만 유효) - 전부 대문자로
        List<String> list1 = new ArrayList<>(); 
        List<String> list2 = new ArrayList<>(); 
        
        for(int i = 0; i < str1.length()-1; i++){
            String s = str1.substring(i, i+2);
            if (isAlphabet(s.charAt(0)) && isAlphabet(s.charAt(1))) {
                list1.add(s.toUpperCase());
            }
        }
        for(int i = 0; i < str2.length()-1; i++){
            String s = str2.substring(i, i+2);
            if (isAlphabet(s.charAt(0)) && isAlphabet(s.charAt(1))) {
                list2.add(s.toUpperCase());
            }
        }
        
        // 집합 사이의 자카드 유사도 구하기
        list1.sort((a, b) -> {return a.compareTo(b);});
        list2.sort((a, b) -> {return a.compareTo(b);});
        List<String> union = getUnion(list1, list2);
        List<String> intersection = getIntersection(list1, list2);
        
        // 자카드 유사도 값은 0에서 1 사이의 실수이므로, 
        // 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력
        if(intersection.size() == 0 && union.size() == 0) return 65536;
        else {
            return (int)(
                (double)intersection.size() / union.size() * 65536
            );
         }
    }
    
    public List<String> getIntersection(List<String> list1, List<String> list2){
        List<String> intersection = new ArrayList<>(); 
        int oneId = 0; int secId = 0; 
        while(oneId < list1.size() && secId < list2.size()){
            if(list1.get(oneId).equals(list2.get(secId))){
                intersection.add(list1.get(oneId));
                oneId++; secId++;
            }else{
                // 더 작은거 움직이기
                if(list1.get(oneId).compareTo(list2.get(secId)) < 0) oneId++;
                else secId++;
            }
        }
        // 반환
        return intersection;
    }
    
    public List<String> getUnion(List<String> list1, List<String> list2){
        List<String> union = new ArrayList<>(); 
        int oneId = 0; int secId = 0; 
        while(oneId < list1.size() && secId < list2.size()){
            if(list1.get(oneId).equals(list2.get(secId))){
                union.add(list1.get(oneId));
                oneId++; secId++;
            }else{
                // 더 작은거 움직이기
                if(list1.get(oneId).compareTo(list2.get(secId)) < 0) {
                    union.add(list1.get(oneId)); oneId++;
                }
                else {
                    union.add(list2.get(secId)); secId++;
                }
            }
        }
        // 하나만 넘어감
        while(oneId < list1.size()){
            union.add(list1.get(oneId)); oneId++;
        }
        while(secId < list2.size()){
            union.add(list2.get(secId)); secId++;
        }
        // 반환
        return union;
    }
    
}