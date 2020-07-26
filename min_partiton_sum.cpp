//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include <bits/stdc++.h>
using namespace std;

int minPartitionDiff(vector<int>a,int n,int total){
    int sum=floor(total/2);
    //vector<vector<bool>> dp(n,vector<bool>(total+1,false));
    //finding all possible sum values of subsets with sum <=half
    bool dp[n][sum+1];
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    
    for(int j=1;j<=sum;j++)
    {
        if(j==a[0])
        {
            dp[0][j]=true;
        }
        else 
            dp[0][j]=false;
    }

    for (int i=1; i<n; i++) 
    { 
        for (int j=1; j<sum+1; j++) 
        { 
            if(j<a[i])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]];
            }
           
        } 
    }
    int result;    
    for(int j=sum;j>=0;j--)
    {
        if(dp[n-1][j]==true)
        {
            result=total-j*2;
            break;
        }
    }
    return result;
    
}



int main() {
    int t,n,total;
    cin>>t;
    
    while(t--){
        cin>>n;
        vector<int> a;
        total=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
            total+=x;
        }
        
        
        cout<<minPartitionDiff(a,n,total)<<endl;
        
    }
	return 0;
}