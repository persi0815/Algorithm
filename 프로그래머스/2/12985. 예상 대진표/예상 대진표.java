import java.util.*; 

class Solution
{
    public int solution(int n, int a, int b)
    {

        int round = 1; 
        while(true){                
            // 이긴다면 다음에 어떤 번호를 받게 될지   
            a = (a%2 == 0) ? a/2 : (a+1)/2; 
            b = (b%2 == 0) ? b/2 : (b+1)/2; 
            // 같은 번호를 받는다 = 이전에 경쟁자였다. 
            if(a == b){
                break; 
            }
            // 다음 라운드로
            round++;
        }

        // 처음 라운드에서 A번을 가진 참가자는 경쟁자로 생각하는 B번 참가자와 몇 번째 라운드에서 만나는지 return
        return round;
    }
}