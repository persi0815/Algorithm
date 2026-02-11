#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    // moves에 따라 이동시키기 -> 뽑은거 board에서 없애고, 바구니에 넣기
    vector<int> box; 
    for(auto& m: moves){
        int place = m-1; 
        for(int i = 0; i < board.size(); i++){
            int charac = board[i][place];
            if(charac != 0) {
                if((box.size() > 0 && box[box.size()-1] != charac) ||  box.size() == 0)
                    box.push_back(charac);
                else {
                    box.pop_back(); answer += 2;
                }
                
                board[i][place] = 0;
                break;
            }
        }
    }
    
    // 터트려져 사라진 인형의 개수
    return answer;
}