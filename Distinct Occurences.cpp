// Question Statement : https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
// level : easy 
/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>

using namespace std;

#define ll long long
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

int dp[105][105];
// memoization 
int distinctOccurences(string &A,string&B,int i,int j){
    if(j==B.size()){return 1;}
    if(i==A.size()){return 0;}
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=0,b=0;
    if(A[i]==B[j]){
        a=distinctOccurences(A,B,i+1,j+1);
    }
    b=distinctOccurences(A,B,i+1,j);
    dp[i][j]=(a+b);
    return dp[i][j];
}


int subsequenceCount(string S, string T){
    memset(dp,-1,sizeof(dp));
    return distinctOccurences(S,T,0,0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string A,B;
        cin>>A>>B;
        cout<<distinctOccurences(A,B,0,0)<<endl;
    }
    return 0;
}
