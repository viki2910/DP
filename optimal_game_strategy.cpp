//https://www.youtube.com/watch?v=WRXCwgdni90
//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int optimalGame(vector<int> a, int n){
    int dp[n][n];
    
    for(int i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    
    int option1,option2;
    
    int i=0;
    int j=1;
	while(i<n && j<n){
	    dp[i][j] = max(a[i],a[j]);
	    i++;
	    j++;
	}

	i=0;j=2;
	while(i<n && j<n){
	    int c = j;
	    while(i<n && j<n){
	        option1= a[i]+min(dp[i+2][j],dp[i+1][j-1]);
            option2= a[j]+min(dp[i][j-2],dp[i+1][j-1]); 
	        dp[i][j] = max(option1,option2);
	        i++;
	        j++;
	    }
	    i = 0;
	    j = c + 1;
    }    	

    return dp[0][n-1];
}


int main() {
	int t=0,n,x;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int>a;
	    a.clear();
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        a.push_back(x);
	    }
	    cout<<optimalGame(a,n)<<endl;
	}
	return 0;
}