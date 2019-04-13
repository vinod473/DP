#include<iostream>
#include<cstring>

using namespace std;

// Recursion O(length^n)
int maxProfit(int a[],int l){
    
    //base case
    if( l==0 )
        return 0;
    
    int best = 0;
    for( int i=1;i<=l;i++){
        int maxPr = a[i] + maxProfit(a,l-i); 
        best = max(best,maxPr);
    }
return best;
}

// Memoisation O(n^2)
int memo[100]={};
int maxProfit_memo(int a[],int l){

    if( l==0 )
        return 0;
    // check if already calculated
    if( memo[l]!=-1 )
        return memo[l];
    // else calculate
    int best = 0;
    for(int i=1;i<=l;i++){
        int maxPr = a[i] + maxProfit_memo(a,l-i);
        best = max(best,maxPr);
    }   
    memo[l] = best;
return memo[l];
}

// pure DP approach O(n^2)
int maxProfit_DP(int a[],int l){
    int dp[100]={0};
    for(int i=1;i<=l;i++){
        int best = 0;
        for(int cut=1;cut<=i;cut++ ){
            int maxPr = a[cut] + dp[i-cut]; 
            best = max(best,maxPr);
        }
        dp[i] = best;
    }
return dp[l];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int length,i;
    cin >> length;
    int a[length+1];
    for(i=1;i<=length;i++)
        cin >> a[i];
    cout<<"using recursion: "<<maxProfit(a,length)<<endl;
    memset(memo,-1,sizeof(memo));
    cout<<"using Memoisation(TD): "<<maxProfit_memo(a,length)<<endl;
    cout<<"pure DP approach(BU): "<<maxProfit_DP(a,length)<<endl;
return 0;
}