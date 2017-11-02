#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[501][501], dp[501][501];
int main(){
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            cin>>arr[i][j];
        }
    }
    int _max = -1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
            if(i==N) {
                _max = max(_max, dp[i][j]);
            }
        }
    }
    cout<<_max;
}
