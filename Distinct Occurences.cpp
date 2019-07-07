// Question Statement : https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
// level : easy 
// time complexity :O(sizeof(A)*sizeof(B))
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

int memo[105][105];
//memoi
int distinctOccurences(string &A,string&B,int i,int j){
    if(j==B.size()){return 1;}
    if(i==A.size()){return 0;}
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    int a=0,b=0;
    if(A[i]==B[j]){
        a=distinctOccurences(A,B,i+1,j+1);
    }
    b=distinctOccurences(A,B,i+1,j);
    memo[i][j]=(a+b);
    return memo[i][j];
}

// tabular meathod

int distinctOccurences(string &A,string&B){
    int N=A.size();
    int M=B.size();
    int dp[N+1][M+1];
    dp[0][0]=1;
    for(int i=1;i<=N;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=M;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dp[i][j]=dp[i-1][j];
            if(A[i-1]==B[j-1]){
                dp[i][j]+=dp[i-1][j-1];
            }
        }
    }
    return dp[N][M];
}

int subsequenceCount(string S, string T){
    // Memoization
    //memset(memo,-1,sizeof(dp));
    //return distinctOccurences(S,T,0,0);
    //Tabular Method
    return distinctOccurences(S,T);
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
        cout<<subsequenceCount(A,B)<<endl;
    }
    return 0;
}
