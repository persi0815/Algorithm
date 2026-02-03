#include <string>
#include <vector>
#include <iostream>

using namespace std;
int oNum = 0; 
int xNum = 0;

bool check_num(vector<string>& board){
    // 개수 확인 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'O') oNum++;
            else if(board[i][j] == 'X') xNum++;
        }
    }
    
    int avail = 0;
    if(oNum == xNum || oNum == xNum + 1) avail = 1;
    return avail;
}

bool check_have_winner(vector<string>& board){
    // 빙고 만들어지는지
    bool oBingo = false;
    bool xBingo = false; 
    // 가로
    for(int i = 0; i < 3; i++){
        char bef = board[i][0];
        for(int j = 0; j < 3; j++){
            if(board[i][j] != bef) break;
            else if(j == 2){
                if(bef=='O') oBingo = true; 
                else if(bef=='X') xBingo = true;
            }

        }
    }
    // 세로
    for(int j = 0; j < 3; j++){
        char bef = board[0][j];
        for(int i = 0; i < 3; i++){
            if(board[i][j] != bef) break;
            else if(i == 2){
                if(bef=='O') oBingo = true; 
                else if(bef=='X') xBingo = true;
            }
            
        }
    }
    // 대각선
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[1][1] == 'O') oBingo = true; 
        else if(board[1][1] == 'X') xBingo = true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[1][1] == 'O') oBingo = true; 
        else if(board[1][1] == 'X') xBingo = true;
    }
       
    // 만들어진다면 가능한 상황인지
    int avail = 1;
    if(xBingo && (oNum > xNum)) avail = 0;
    if((oNum == xNum) && oBingo) avail = 0;
    
    return avail;
}

// 규칙을 지켰다면 1, 아니라면 0 리턴
int solution(vector<string> board) {
    int answer = 1;
    
    // 개수 확인
    if(!check_num(board)) answer = 0;
    
    // 만들어지는지 확인 -> 가능한 상황인지
    if(!check_have_winner(board)) answer = 0;
    
    return answer;  
}