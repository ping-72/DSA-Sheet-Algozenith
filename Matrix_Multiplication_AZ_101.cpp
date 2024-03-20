#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n,m,p;
    cin>>n>>m>>p;
    int A[n][m],B[m][p];int C[n][p];
    for(int i=0;i<n;i++){
        for (int  j = 0; j < p; j++)
        {
            C[i][j] =0;
        }
        
    }

    // Tsking input for A and B
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin>>A[i][j];

    for (int i = 0; i < m; i++)
    for (int j = 0; j < p; j++)
        cin>>B[i][j];

        // Making multiplied matrix C 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            for(int k = 0; k <m; k++){
                //cout<<"A[i][k] * B[k][j] = "<<A[i][k]<<" * "<<B[k][j]<<" = "<<A[i][k] * B[k][j]<<endl;
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
                //cout<<"sum untill now - "<<C[i][j]<<endl;
        }
        cout<<C[i][j]<<" ";
        
        
    }cout<<endl;}

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}