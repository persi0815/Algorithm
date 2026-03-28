#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) { // 1,000,000
    vector<int> answer;
    answer.assign(numbers.size(), -1); 
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap {수, 인덱스}
    
    for(int i = 0; i < numbers.size(); i++){
        int n = numbers[i];
        while(!pq.empty() && pq.top().first < n){
            answer[pq.top().second] = n; 
            pq.pop(); 
        }
        pq.push({n, i}); // {수, 인덱스}
    }
    
    
    return answer; // 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열
}