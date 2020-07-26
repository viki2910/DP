//https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
#include <iostream>
using namespace std;

int dp[51]={-1};

int ways(int n){
    
    if(n<0)
    return 0;
    
    if(n==0)
    return 1;
    
    if(dp[n]==1)
    return dp[n];

    dp[n]=1;
    dp[n]= ways(n-1)+ways(n-2)+ways(n-3);
    return dp[n];
}

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    cout<<ways(n)<<endl;
	}
	return 0;
}