#include <string>
#include <vector>
#include <stack>

using namespace std;

// "삭제된 칸은 아예 건너뛰고, 바로 앞뒤의 '생존한' 칸으로 순간이동"할 수 있는 연결 리스트
// 조회(find) 성능은 O(n)이지만, prev/next로만 이동하기에 괜찮음. 

// 처음 표의 행 개수를 나타내는 정수 n, 처음에 선택된 행의 위치를 나타내는 정수 k
string solution(int n, int k, vector<string> cmd) {
    string answer = string(n, 'O');
    // prev, next 배열 만들기
    vector<pair<int, int>> linkedList;
    for(int i = 0; i < n-1; i++){
        linkedList.push_back({i-1, i+1});
    }
    linkedList.push_back({n-2, -1});
    
    // 명령어 수행
    int id = k; stack<int> deletedId;
    for(auto&c: cmd){ // 200,000
        if(c[0] == 'U'){ // 현재 선택된 행에서 X칸 위에 있는 행을 선택
            int cnt = stoi(c.substr(2));
            while(cnt > 0) { // 300,000
                id = linkedList[id].first; cnt--;
            }
        }else if(c[0] == 'D'){ // 현재 선택된 행에서 X칸 아래에 있는 행을 선택
            int cnt = stoi(c.substr(2));
            while(cnt > 0){ // 300,000
                id = linkedList[id].second; cnt--;
            }
        }else if(c[0] == 'C'){ // 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택
            bool last = (linkedList[id].second == -1) ? true : false; 
            // 삭제
            answer[id] = 'X';
            deletedId.push(id);
            if(last){ // 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택
                int prev = linkedList[id].first; 
                linkedList[prev].second = -1; 
                id = linkedList[id].first;
            }else{ // 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택
                int prev = linkedList[id].first; 
                int next = linkedList[id].second; 
                if(prev == -1) linkedList[next].first = -1;
                else{
                    linkedList[prev].second = next; 
                    linkedList[next].first = prev;
                }
                id = linkedList[id].second;
            }
        }else if (c[0] == 'Z'){ // 가장 최근에 삭제된 행을 원래대로 복구
            int d = deletedId.top(); deletedId.pop(); 
            int prev = linkedList[d].first; 
            int next = linkedList[d].second;
            // 이전 노드가 존재할 때만 나(d)를 그 다음으로 연결
            if (prev != -1) linkedList[prev].second = d; 
            // 다음 노드가 존재할 때만 나(d)를 그 이전으로 연결
            if (next != -1) linkedList[next].first = d;
            answer[d] = 'O';
        }
    }
    
    // 삭제되지 않은 행은 O, 삭제된 행은 X로 표시하여 문자열 형태로 return
    return answer;
}