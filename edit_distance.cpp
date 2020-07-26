//https://practice.geeksforgeeks.org/problems/edit-distance/0
#include <bits/stdc++.h>
using namespace std;

int minOf3(int a,int b,int c){
    return min(min(a,b),c);
}

int findMinOps(string a,string b,int l1,int l2){
    vector <vector<int>>dp(l1+1,vector<int>(l2+1,0));
    dp[0][0]=0;
    
    a="0"+a;
    b="0"+b;
    
    for(int i=1;i<=l1;i++){
        dp[i][0]=i;
    }
    for(int j=1;j<=l2;j++){
        dp[0][j]=j;
    }
    
    for(int i=1;i<l1+1;i++){
        for(int j=1;j<l2+1;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=minOf3(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1;
            }
        }
    }
  
    return dp[l1][l2];
}

int main() {

	int t=0,l1,l2;
	string s1,s2;
	cin>>t;
	while(t--){
	    cin>>l1>>l2;
	    cin>>s1>>s2;
	    int result=findMinOps(s1,s2,l1,l2);
	    cout<<result<<endl;
	}
	return 0;
}