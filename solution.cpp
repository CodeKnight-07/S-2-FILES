#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long int k;
    cin>>n>>k;
    vector<long long> a(n+1), b(n+1), c(n+1);
    long long m = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m = max(m,a[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        m = max(m,b[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        m = max(m,c[i]);
    }
    vector<vector<long long>> w(3, vector<long long>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>w[i][j];
        }
    }
    if(n==1){
        cout<<m<<"\n";
        if(m==a[1]){
            cout<<"A"<<"\n";
        }
        else if(m==b[1]){
            cout<<"B"<<"\n";
        }
        else {
            cout<<"C"<<"\n";
        }
        return;
    }
    long long l=0,r=m,mid;
    long long ans=0;
    char c1='A';
    vector<vector<char>> par(n+1, vector<char>(3));
    vector<vector<long long>> dp(n+1, vector<long long>(3));
    while(l<=r){
        mid = l+(r-l)/2;
        if(a[1]>=mid){
            dp[1][0]=0;
        }
        else dp[1][0] = k+1;
        if(b[1]>=mid){
            dp[1][1]=0;
        }
        else dp[1][1] = k+1;
        if(c[1]>=mid){
            dp[1][2]=0;
        }
        else dp[1][2] = k+1;
        vector<vector<char>> curr_par(n + 1, vector<char>(3));
        for(int i=2;i<=n;i++){
            if(a[i]<mid){
                dp[i][0]=k+1;
            }
            else{
                long long best=k+1;
                if(dp[i-1][0]<=k&&dp[i-1][0]+w[0][0]<best){best=dp[i-1][0]+w[0][0]; curr_par[i][0]='A';}
                if(dp[i-1][1]<=k&&dp[i-1][1]+w[1][0]<best){best=dp[i-1][1]+w[1][0]; curr_par[i][0]='B';}
                if(dp[i-1][2]<=k&&dp[i-1][2]+w[2][0]<best){best=dp[i-1][2]+w[2][0]; curr_par[i][0]='C';}
                dp[i][0]=best;
            }
            if(b[i]<mid){
                dp[i][1]=k+1;
            }
            else{
                long long best=k+1;
                if(dp[i-1][1]<=k&&dp[i-1][1]+w[1][1]<best){best=dp[i-1][1]+w[1][1]; curr_par[i][1]='B';}
                if(dp[i-1][0]<=k&&dp[i-1][0]+w[0][1]<best){best=dp[i-1][0]+w[0][1]; curr_par[i][1]='A';}
                if(dp[i-1][2]<=k&&dp[i-1][2]+w[2][1]<best){best=dp[i-1][2]+w[2][1]; curr_par[i][1]='C';}
                dp[i][1]=best;
            }
            if(c[i]<mid){
                dp[i][2]=k+1;
            }
            else{
                long long best=k+1;
                if(dp[i-1][2]<=k&&dp[i-1][2]+w[2][2]< best){best=dp[i-1][2]+w[2][2]; curr_par[i][2]='C';}
                if(dp[i-1][0]<=k&&dp[i-1][0]+w[0][2]< best){best=dp[i-1][0]+w[0][2]; curr_par[i][2]='A';}
                if(dp[i-1][1]<=k&&dp[i-1][1]+w[1][2]< best){best=dp[i-1][1]+w[1][2]; curr_par[i][2]='B';}
                dp[i][2]=best;
            }
        }
        long long x=LLONG_MAX;
        int last=-1;
        for(int i=0;i<3;i++){
            if(dp[n][i] <= k && dp[n][i]<x) {
                x = dp[n][i];
                last = i;
            }
        }
        if(last!=-1){
            l=mid+1;
            ans = mid;
            if(last==0)c1='A';
            if(last==1)c1='B';
            if(last==2)c1='C';
            for(int i=2;i<=n;i++) {
                for(int j=0;j<3;j++) {
                    par[i][j] = curr_par[i][j];
                }
            }
        }
        else r=mid-1;
    }
    cout<<ans<<"\n";
    vector<char> path(n+1);
    path[n]=c1;
    int j=c1-'A';
    for (int i=n;i>=2;i--) {
        char p=par[i][j];
        path[i-1]=p;
        j=p-'A';
    }
    for (int i=1;i<=n;i++) {
        cout<<path[i];
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}