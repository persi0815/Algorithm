import java.util.*; 


class Solution {
    
    // HH:MM -> minute
    public Integer toMin(String time){
        int hour = Integer.parseInt(time.substring(0, 2)); 
        int min = Integer.parseInt(time.substring(3, 5)); 
        return hour * 60 + min; 
    }
    
    class Fee{
        String car; int fee; 
        Fee(String car, int fee){
            this.car = car; 
            this.fee = fee;
        }
    }
    
    // 차량별로 주차 요금 계산
    public int[] solution(int[] fees, String[] records) {
        int DEFAULT_TIME = fees[0];
        int DEFAULT_FEE = fees[1]; 
        int UNIT_TIME = fees[2]; 
        int UNIT_FEE = fees[3];
        
        HashMap<String, Integer> parkTime = new HashMap<>(); 
        HashMap<String, Integer> parkTimeSum = new HashMap<>(); 
        
        // 차량 누적 주차 시간 계산
        for(String r : records){
            Integer time = toMin(r.substring(0, 5)); 
            String car = r.substring(6, 10); 
            String order = r.substring(11); 
            
            if(order.equals("IN")){
                // MAP에 차 번호랑 시각 넣기
                parkTime.put(car, time); 
                
            }else if(order.equals("OUT")){
                // MAP에서 입차 시각 뽑아와서 시간 계산 후 저장
                int inTime = parkTime.remove(car); 
                parkTimeSum.merge(car, time - inTime, Integer::sum); 
            }
        }
        
        // 출차 안되었다면 23:59에 출차된 것으로 간주
        for(Map.Entry<String, Integer> e : parkTime.entrySet()){
            parkTimeSum.merge(e.getKey(), toMin("23:59") - e.getValue(), Integer::sum);
        }
        
        
        // 누적 주차 시간 -> 요금 정산
        List<Fee> carFees = new ArrayList<>(); 
        for(Map.Entry<String, Integer> e : parkTimeSum.entrySet()){
            String car = e.getKey(); 
            int totalParkTime = e.getValue(); 
            // 기본 시간 이하면, 기본 요금 청구 
            if(totalParkTime <= DEFAULT_TIME){
                carFees.add(new Fee(car, DEFAULT_FEE)); 
            }
            // 기본 시간 초과하면, 기본 요금 + 단위 시간마다 단위 요금 청구
            else{
                int excessTime = totalParkTime - DEFAULT_TIME;
                int unitCount = (int) Math.ceil((double) excessTime / UNIT_TIME);
                carFees.add(new Fee(car, DEFAULT_FEE + unitCount * UNIT_FEE)); 
            }

        }
        
        // 차량 번호 오름차순 정렬
        carFees.sort((a, b) -> {
           return (a.car).compareTo(b.car);  
        });
        
        // 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아서 return 
        List<Integer> answer = new ArrayList<>(); 
        for(Fee f : carFees){
            answer.add(f.fee); 
        }
        // list -> array
        return answer.stream().mapToInt(i -> i).toArray();
    }
}