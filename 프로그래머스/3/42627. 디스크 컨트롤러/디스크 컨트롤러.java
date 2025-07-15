import java.util.*; 
/*
한번에 하나의 작업만 수행 가능
작업 번호, 요청 시각, 소요 시간 저장해두는 대기 큐 존재. 처음엔 비어있음
작업이 존재하고, 현재 작업이 없다면, 우선순위 높은 작업 대기 큐에서 꺼내어 실행
1. 소요 시간 짧은 것. 2. 요청 시각이 빠른 것 3. 작업의 번호가 작은 것
어떤 작업 마치고 나서 바로 다른 작업 시작할 수 있음
*/

class Job{
    int id; 
    int request; 
    int duration;
    
    Job(int id, int request, int duration){
        this.id = id; 
        this.request = request; 
        this.duration = duration;
    }
    
}

class Solution {
    // 작업이 요청되는 시점, 작업의 소요 시간
    public int solution(int[][] jobs) {
        int num = jobs.length;
        int answer = 0; // 각 작업에 대한 반환시간 평균의 정수 부분
        
        // 동적 배열에 작업 넣기. - 500
        List<List<Integer>> jobList = new ArrayList<>();
        for(int i = 0; i < num; i++){
            jobList.add(Arrays.asList(jobs[i][0], jobs[i][1]));
        }
        // 시간 순 정렬
        jobList.sort(Comparator.comparingInt(a -> a.get(0)));
        
        // 우선순위 큐 생성
        PriorityQueue<Job> pq = new PriorityQueue<>(
            (a, b) -> {
                if (a.duration == b.duration) {
                    if (a.request == b.request) {
                        return a.id - b.id; // id 작은 것 우선
                    }
                    return a.request - b.request; // 요청 시각 빠른 것 우선
                }
                return a.duration - b.duration; // 소요 시간 짧은 것 우선
            }
        );

        // 큐에서 하나씩 빼어 실행
        // 각 작업의 완료 시간 체크 -> id와 함께 list에 넣어두기
        List<List<Integer>> end = new ArrayList<>();
        
        // 시간 흐르면서 작업이 가능할때 pq에 넣기
        int time = 0; int nextJob = 0;
        int processingJobId = -1; int jobLeftTime = -1;
        boolean finish = false;
        
        while(!finish){ // 2000
            
            // 남은 작업이 있고, 현 시간에 요청했다면, 작업 큐에 넣기
            while(nextJob < jobList.size() && jobList.get(nextJob).get(0) <= time){       
                int requestTime = jobList.get(nextJob).get(0);
                int duration = jobList.get(nextJob).get(1);
                pq.offer(new Job(nextJob, requestTime, duration));
                nextJob++;
            }
            
            // 실행할 수 있는 작업 처리
            if(jobLeftTime <= 0){ // 작업 처리 중 아님
                if(jobLeftTime == 0){ // 막 처리 완료
                    // System.out.println("끝난 작업 id: " + processingJobId + " 현재 시각: "+ time);
                    end.add(Arrays.asList(processingJobId, time));
                    if(end.size() == num) {
                        finish = true; // 마지막 작업 처리 완료
                        // System.out.println("작업 끝");
                        break;
                    }
                }
                // 실행할 작업이 없다면
                if (pq.isEmpty()) {
                    if (nextJob < jobList.size()) {
                        int bef = time;
                        time = jobList.get(nextJob).get(0); // 다음 작업 시간으로 건너뜀
                        jobLeftTime -= (time - bef); // 흐른 시간만큼 더 빼기
                    }
                    continue;
                }
                // 실행할 작업이 있다면
                Job job = pq.poll(); 
                processingJobId = job.id; // 작업 있다면 실행
                jobLeftTime = job.duration;
                // System.out.println("시작한 작업 id: " + processingJobId + " 현재 시각: "+ time);
                
            }else{ // 작업 처리 중
                
            }
            
            // 시간 갱신
            time++; jobLeftTime--;
        }
        
        // 처리 완료되었다면 답 구하기
        int returnTime = 0; 
        for(int i = 0; i < end.size(); i++){
            // 끝난 시점 - 해당 작업의 id로 구한 작업 요청 시간
            returnTime += end.get(i).get(1) - jobs[end.get(i).get(0)][0];
        }
        
        answer = returnTime / num;
        
        return answer;
    }
}