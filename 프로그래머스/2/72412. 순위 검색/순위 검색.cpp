#include <string>
#include <vector>
#include <iostream> 
#include <unordered_map> 
#include <sstream>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> scores;

// 벡터에서 해당 score 이상인 지원자 수 리턴
int binary_search(vector<int> & scores, int score){
    int left = 0; int right = scores.size()-1;
    int point = scores.size(); 
    while(left <= right){
        int mid = (right + left)/2;
        if(scores[mid] >= score) {
            point = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    // cout << "p: " << point << endl;
    return scores.size() - point;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    // 24가지 map 중 한곳에 넣기 (5만*5)
    for(int i = 0; i < info.size(); i++){
        string content = info[i]; 
        stringstream ss(content);
        string value; 
        string key = "";
        for(int i = 0; i < 4; i++){
            ss >> value; 
            key += value; // 언어, 직군, 경력, 소울푸드
            key += "_";
        }
        ss >> value;
        scores[key].push_back(stoi(value));   
        // cout << key << " " << value << endl;
    }
    
    // 각 벡터 정렬(오름차순)
    for(auto & score : scores){
        sort(score.second.begin(), score.second.end());
    }
    
    // 각 조건에 따라 벡터 찾고 이진탐색으로 개수 찾기 (10만 * log(5만) * 24)
    for(int i = 0; i < query.size(); i++){ // 10만
        string content = query[i]; 
        stringstream ss(content);
        string value, score; 
        vector<string> q;
        for(int i = 0; i < 7; i++){
            ss >> value; 
            if(value != "-" && value != "and" && value != " ") q.push_back(value);
        }
        ss >> score;

        // 적합한 key 찾기
        vector<string> keys; 
        for(auto & m: scores){ // 24
            string key = m.first; 
            bool fit = true;
            for(int i = 0; i < q.size(); i++){ // 4 쿼리의 모든 조건에 맞아야 함. 
                // cout << key << " " << q[i] << endl;
                if(key.find(q[i]) == string::npos) {
                    fit = false; 
                    // cout << "false" << endl;
                    break;
                }
            }
            if(fit) {
                keys.push_back(key);
                // cout << key << endl;
            }
        }
        
        // key 순회하며 이진탐색으로 개수 찾아 합하기
        int sum = 0; 
        for(auto & k : keys){
            // cout << k << " " << score << endl;
            sum += binary_search(scores[k], stoi(score));
        }
        
        answer.push_back(sum); 
    }
    
    
    return answer; // 각 쿼리에 해당하는 인원 수
}

