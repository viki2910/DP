//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include<bits/stdc++.h>
using namespace std;

string isEqualSumSubset(vector<int> a ,int n,int total){

   if(total%2!=0){
       return "NO";
   }
    
   int sum=total/2;//only taking half sum dp to avoid extra computation        
           
   bool dp[n][sum+1];
   for(int i=0;i<n;i++){
       dp[i][0]=true;
   }
   for(int j=1;j<sum+1;j++){
       if(j==a[0]){
           dp[0][j]=true;
       }
       else
           dp[0][j]=false;
   }
   
   for(int i=1;i<n;i++){
       for(int j=1;j<=sum;j++){
           if(j<a[i]){
               dp[i][j]=dp[i-1][j];
           }
           else{
               dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]];
           }
       }
   }
   
   if(dp[n-1][sum])
   return "YES"; 
   
   return "NO";
}

int main(){
    int t=0,x,total=0,n;
    
    cin>>t;
    while(t--){
        total=0;
        cin>>n;
        vector<int>a;
        a.clear();
        for(int i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
            total+=x;
        }
        
        cout<<isEqualSumSubset(a,n,total)<<endl;
    }
}