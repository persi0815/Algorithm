#include <string>
#include <vector>
#include <cmath>
#include <iostream>


using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = r1;
    long long R2 = r2;
   
    for(long long x = 0; x <= R2; x++){
        double max; double min;
        if(x <= R1){
            max = floor(sqrt(R2*R2 - x*x));
            min = ceil(sqrt(R1*R1 - x*x));
            answer += (max-min+1);
            // cout << x << " " << max << " " << min << " " << answer << endl;
        } else{
            max = floor(sqrt(R2*R2 - x*x));
            answer += (max+1);
            // cout << x << " " << max << " " << "-" << " " << answer << endl;
        }
    }
    answer -= (r2-r1 + 1);
    
    return answer*4 ;
}