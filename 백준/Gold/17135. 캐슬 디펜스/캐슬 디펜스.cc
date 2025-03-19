#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

/* 캐슬 디펜스
성을 향해 몰려오는 적을 잡는 턴 방식.
n*m판. 궁수를 성이 있는 칸에 1명씩 배치하려함. 3명
n번째 행 밑에 성이 있음
궁수는 적 하나씩을 공격 가능. 모든 궁수 동시 공격
공격하는 적: 거리가 d이하인 적 중 가장 가까운 적. 여럿인 경우 가장 왼쪽의 적 공격. 여러 궁수가 같은 적을 공격 가능
공격 당하면 제외됨. 
궁수의 공격이 끝나면 적 아래로 한 칸 이동. 성이 있는 칸으로 이동한 경우 게임에서 제외
모든 적이 격자판에서 제외되면 게임 끝남. 
궁수의 공역으로 제거할 수 있는 적의 최대 수는?
*/

int n, m, d;
vector<vector<int>> MAP;

vector<vector<int>> get_combinations(vector<int> &Castle, int num){
    vector<vector<int>> combinations; 
    vector<bool> select(Castle.size(), false);
    fill(select.end()-num, select.end(), true);
    
    do{
        vector<int> comb;
        for(int i = 0; i < Castle.size(); i++){
            if(select[i] == true) comb.push_back(Castle[i]);
        }
        combinations.push_back(comb);
        
    } while(next_permutation(select.begin(), select.end()));
    
    return combinations;
}


int simulate(const vector<int> &archers){
    int kill = 0; // 죽일 수 있는 적의 수
    vector<vector<int>> arr = MAP;
    
    while (true) {
            
        bool flag = false;

        // 적이 남아 있는지 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) flag = true;
            }
        }
        if (!flag) break;  // 적이 없으면 종료

        vector<int> dist(3, d + 1);
        vector<pair<int, int>> enemy(3, {-1, -1});

        // 적 탐색
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (arr[i][j] == 1) { // 적
                    for (int k = 0; k < 3; k++) {
                        int ax = n, ay = archers[k];
                        int ex = i, ey = j;
                        int distance = abs(ax - ex) + abs(ay - ey);

                        if (distance <= d && distance < dist[k]) {
                            dist[k] = distance;
                            enemy[k] = {ex, ey};
                        }
                    }
                }
            }
        }

        // 공격 수행
        for (auto en : enemy) {
            if (en.first != -1 && en.second != -1) {
                if (arr[en.first][en.second] == 1) kill++;
                arr[en.first][en.second] = 0;
            }
        }

        // 적 이동 (한 칸 아래로)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
    }
    
    return kill;
}

int main(){
    cin >> n >> m >> d;
    MAP.resize(n, vector<int>(m));
    
    // 맵 입력받기
    for(int i = 0; i < n; i++){ // 적1, 빈칸0
        for(int j = 0; j < m; j++){
            cin >> MAP[i][j];
        }
    }
    
    // 궁수 위치 구하기 - 조합
    vector<int> Castle(m);
    for(int i = 0; i < m; i++){
        Castle[i] = i;
    }
    
     vector<vector<int>> archers_combinations = get_combinations(Castle, 3);
    int ans = 0;
    
    // 죽일 수 이는 적의 최댓값 구하기
    for (const auto& archers : archers_combinations) {
        ans = max(ans, simulate(archers));
    }

    cout << ans << endl;
    return 0;
}
