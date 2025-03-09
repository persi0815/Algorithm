#include<iostream>
#include<algorithm>
 
using namespace std;
 
int binary_search(int start, int end, int s[])
{
    if((s[start]+s[end])%2) return 0; // 두 좌표의 합이 홀수라면 간격을 같게 나누는 정수가 없다.
 
    int target=(s[start]+s[end])/2;
    int mid=(start+end)/2;
 
    while(start<=end)
    {
        if(s[mid]==target) return 1;
        else if(s[mid]<target) start=mid+1;
        else end=mid-1;
 
        mid=(start+end)/2;
    }
 
    return 0;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int T;
    cin>>T;
 
    for(int t=0; t<T; t++)
    {
        int N;
        cin>>N;
        
        int s[N], ans=0;
 
        for(int i=0; i<N; i++)
            cin>>s[i];
 
        sort(s, s+N); // 이분탐색을 위해 정렬해둔다.
 
        for(int i=0; i<N; i++) // N개의 점 중에서 두 점 i, j를 고르는 모든 경우의 수
        {
            for(int j=i+2; j<N; j++) // i와 j사이에 적어도 하나의 점이 있도록 j=i+2부터 시작한다.
            {
                ans+=binary_search(i, j, s); // 두 점 사이의 간격을 반으로 나누는 점을 찾는다면 +1
            }
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}