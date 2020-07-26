//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
    int t=0;
    int l1,l2;
    string a,b;
    cin>>t;
    while(t--){
        cin>>l1>>l2;
        cin>>a>>b;
        
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        
        a="0"+a;
        b="0"+b;
        
        for(int i=1;i<l1+1;i++){
            for(int j=1;j<l2+1;j++){
                
                if(a[i]==b[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
       cout<<dp[l1][l2]<<endl; 
        
    }
	return 0;
}