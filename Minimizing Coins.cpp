// Consider a money system consisting of n coins. Each coin has a +ve integer value. Your task is to 
// produce a sum/target of money x using the available coins in such a way that the no. of coins is minimal. 
// Print one integer-> the minimum no. of coins. If it is not possible to produce the desired sum , print -1. 


// ex- coins={1,5,7}, target sum = 11, sol. = 5+5+1=11, ans = 3 coins required.
// this is ques. same as previous ques. i.e. => Removing Digits 

// used 1D dp (make an extra array dp) -> used Dyna.Prog. in two lines only. 



#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> coins; // globally declared array of coins, // array of coins, arr[i]==coins[i] 
// we make an extra array dp(1D dp) with size 10000 and -2 default val, globally
vector<int> dp(10000,-2);

int minimize(int x){
    // base case 
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x]; // DP used -> found the calcu values from the dp array 

    int result=INT_MAX; // becoz to find minimum value 
    for(int i=0; i<coins.size(); i++){ // loop apply on coins array 
        if(x-coins[i]<0) continue;
        result=min(result,minimize(x-coins[i]));
    }

    if(result==INT_MAX) return dp[x]=INT_MAX; // values is not updated in for loop 
    return dp[x]=1+result; // DP used -> store the calcu values in the dp array 
}
int main(){
    int n,x; // x=size of coins array , x = target/sum 
    cin>>n>>x;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }
    int ans=minimize(x);
    if(ans==INT_MAX) cout<<"-1";
    else cout<<ans;
}

// 3 11 => size,sum 
// 1 5 7 => money of coins array 
// 3 => minimum coins it takes to convert 11 to 0, (5+5+1)-> 3 coins 
