// // Given an integer n on each step you may substract one of the digits from the no.
// // how many steps are required to make the no. equal to 0.

// // Given no. n and how many steps are required to make a no. 0 (n->0, tell the min steps)


// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;

// // to find all the digits of n, we write a fun which is return a vector,
// // and we also make a vector where we store all the digits of n 
// vector<int> get_digits(int n){
//     // we make a vector where we stored all the digits 
//     vector<int>result;
//     while(n>0){ // +ve no. 
//         if(n%10!=0){ // n%10 is the last digit, ex-> n=293,n%10=remainder=3(last digit), ex- n=290,n%10=rem=again 0(doesn't required)
//         // we store non-zero digit only
//             result.push_back(n%10);
//         }
//         // at the end remove last digit
//         n=n/10;
//     }
//     return result;
// }

// // Recursion solution 
// int remove(int n){
//     // base case 
//     if(n==0) return 0; // 0 steps
//     if(n<=9) return 1; // 1 steps, n=5,5-5=0, only 1 step it takes to make no. (n to 0).
    
//     // IMP-: 
//     // 1st we will find all the digits of n by using get_digits( ) fun.

//     // we store our all the digits of no. n in another vector named digit
//     vector<int>digit=get_digits(n);
//     // now we goes to each and every digits(by using loops) and subtract from n. then, find min of all the digits.
    
//     int result=INT_MAX;
//     for(int i=0; i<digit.size(); i++){
//         result=min(result,remove(n-digit[i]));
//     }
//     return 1+result;
// }
// int main(){
//     int n=27; // ans = 5 steps
//     cout<<remove(n)<<" steps"; 
// }


                              // OR 


// // Recursion Solution -: 
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// vector<int> get_digits(int n){
//     vector<int>result;
//     while(n>0){ 
//         if(n%10!=0){ 
//             result.push_back(n%10);
//         }
//         n=n/10;
//     }
//     return result;
// }
// int remove(int n){
//     if(n==0) return 0; 
//     if(n<=9) return 1; 
//     vector<int>digit=get_digits(n); 
//     int result=INT_MAX;
//     for(int i=0; i<digit.size(); i++){
//         result=min(result,remove(n-digit[i]));
//     }
//     return 1+result;
// }
// int main(){
//     int n=27;  // 5 steps
//     cout<<remove(n)<<" steps"; 
// }

                                      // OR 


// // Recursion solution is converted into DP solution -: 
// // DP Solution -: we make an extra array (1D dp) uesd 
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// vector<int> get_digits(int n){
//     vector<int>result;
//     while(n>0){ 
//         if(n%10!=0){ 
//             result.push_back(n%10);
//         }
//         n=n/10;
//     }
//     return result;
// }

// int remove(int n){
//     if(n==0) return 0; 
//     if(n<=9) return 1; 

//     // 1D DP uesd, we make an extra array of size n with default value -1.
//     vector<int> dp(10000,-1); // we make dp array/vector of large size i.e. n=10000
//     // IMP -:
//     if(dp[n]!=-1) return dp[n]; // (dp[n]!=-1) 
//     i.e some values is already stored inside the dp array then return that value./ calculated values alreday stored in dp. 

//     vector<int>digit=get_digits(n); 
//     int result=INT_MAX;
//     for(int i=0; i<digit.size(); i++){
//         result=min(result,remove(n-digit[i]));
//     }
//     // IMP -: 
//     return dp[n]=1+result; // store calculated value in the dp array / add values inside the dp array 
// }
// int main(){
//     int n=27;  // 5 steps
//     cout<<remove(n)<<" steps"; 
// }


                                         // OR 
                                        
// Top Down Approach-: f(n)=1+min(f(n-d0),f(n-d1),..)
                                        
// // Recursion solution is converted into DP solution -: 
// // DP Solution -: we also make an extra array (1D dp) globally -:
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// vector<int> get_digits(int n){
//     vector<int>result;
//     while(n>0){ 
//         if(n%10!=0){ 
//             result.push_back(n%10);
//         }
//         n=n/10;
//     }
//     return result;
// }

// // IMP -: 
// vector<int> dp; // we make an extra array dp globally and now we initilize this -:
//   int remove(int n){
//     // base case 
//     if(n==0) return 0; 
//     if(n<=9) return 1; 

//     if(dp[n]!=-1) return dp[n]; // (dp[n]!=-1) 
//     i.e some values is already stored inside the dp array then return that value./ calculated values alreday stored in dp. 

//     vector<int>digit=get_digits(n); 
//     int result=INT_MAX;
//     for(int i=0; i<digit.size(); i++){
//         result=min(result,remove(n-digit[i]));
//     }
//     // IMP -: 
//     return dp[n]=1+result; // store calculated value in the dp array / add values inside the dp array 
// }
// int main(){
//     int n=27;  // 5 steps
//     dp.resize(100000,-1); // initialize dp array of size = 100000
//     cout<<remove(n)<<" steps"; 
// }





// convert f(n) into dp(i) for bottom up sol.
// Bottom Up Approach -: dp(i)=1+min(dp(n-d0),dp(n-d1),...)            
                                        

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> get_digits(int n){
    vector<int>result;
    while(n>0){ 
        if(n%10!=0){ 
            result.push_back(n%10);
        }
        n=n/10;
    }
    return result;
}


int remove(int num){
    // we make an extra array dp 
    vector<int> dp(10000,-1); 
    // base case -:
    dp[0]=0;
    for(int i=1; i<=9; i++){
        dp[i]=1;
    }

    for(int n=10; n<=num; n++){ // n -> state
        vector<int>digit=get_digits(n); 
        int result=INT_MAX; // becoz to find minimum value 
        // we find small value of n to found the ans. of n then we go left to right 
        for(int i=0; i<digit.size(); i++){ // calcu dp[i] i.e. all the digits , apply loop till digits
            result=min(result,dp[n-digit[i]]);
        }
        dp[n]=1+result;
    }
    return dp[num];
}
int main(){
    int n=27; // 5 steps
    cout<<remove(n)<<" steps"; 
}


