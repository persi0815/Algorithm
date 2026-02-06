#include <string>
#include <vector>

using namespace std;

int findAndDestroy(vector<vector<char>>& space){
    int m = space.size();
    int n = space[0].size();
    vector<vector<bool>> willDestroy(m, vector<bool>(n, false));
    int blocks = 0;
    
    // 1. 2x2 찾기
    bool found = false;
    for(int y = 0; y < m - 1; y++){
        for(int x = 0; x < n - 1; x++){
            char cur = space[y][x];
            if(cur == '-') continue; // 이미 지워진 칸은 건너뜀
            
            // 4칸이 모두 같은지 확인
            if(space[y][x+1] == cur && space[y+1][x] == cur && space[y+1][x+1] == cur){
                willDestroy[y][x] = true;
                willDestroy[y][x+1] = true;
                willDestroy[y+1][x] = true; // 추가됨!
                willDestroy[y+1][x+1] = true;
                found = true;
            }
        }
    }
    
    if(!found) return 0; // 지울 게 없으면 0 리턴

    // 2. 블록 제거 및 개수 세기
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            if(willDestroy[y][x]) {
                blocks++; 
                space[y][x] = '-';
            }
        }
    }
    
    // 3. 중력으로 떨어뜨리기
    for(int x = 0; x < n; x++){
        int blankY = -1;
        for(int y = m - 1; y >= 0; y--){
            if(space[y][x] == '-'){
                if(blankY == -1) blankY = y;
            } else if(blankY != -1) {
                space[blankY][x] = space[y][x];
                space[y][x] = '-';
                blankY--;
            }
        }
    }
    
    return blocks;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> space(m, vector<char>(n));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            space[i][j] = board[i][j];
        }
    }
    
    // 루프 조건 수정
    while(true){
        int destroyed = findAndDestroy(space);
        if(destroyed == 0) break; // 이번 라운드에 지워진 게 없으면 종료
        answer += destroyed;
    }
    
    return answer;
}