#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 실패율: 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // 스테이지별 진행 중 명수 구하기
    vector<int> ing(N+2, 0);
    for(auto& s : stages){
        ing[s]++;
    }
    // 누적합 구하기
    vector<int> sum(N+2, 0);
    int s = 0; 
    for(int i = N+1; i > 0; i--){
        s += ing[i];
        sum[i] = s;
    }
    // 실패율 구하기
    vector<vector<double>> failure(N, vector<double>(2, 0.0));
    for(int i = 1; i <= N; i++){
        if(sum[i] == 0) failure[i-1] = {(double)i, 0.0};
        else failure[i-1] = {(double)i, (double)ing[i]/sum[i]};
    }
    // 실패율 높은 것부터 내림차순으로 정렬, 같은 스테이지면 작은 번호로 정렬
    sort(failure.begin(), failure.end(), [](const auto&a, const auto&b){
        // 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 
        if(a[1]==b[1]) return a[0] < b[0];
        return a[1] > b[1];
    });

    for(auto & f: failure){
        answer.push_back(f[0]);
    }
    return answer;
}