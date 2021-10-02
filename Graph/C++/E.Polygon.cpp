    // https://codeforces.com/contest/1360/problem/E
    // https://codeforces.com/contest/1360/submission/129890032
    
    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define vi vector<int>
    #define pii pair<int,int>
    #define all(c) c.begin(),c.end()
    #define mem(a,val) memset(a,val,sizeof(a))
    #define ff first
    #define ss second
    #define FOR(i,k,n) for ( int i=k; i<n; i++ )
     
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    const int N=50;
    string mat[50];
    bool vis[N][N];
     
    void bfs(int srcx,int srcy)
    {
        pii u;
        queue<pii> Q;
        vis[srcx][srcy] = 1;
        Q.push({srcx,srcy});
        while(!Q.empty()) {
            u = Q.front(); 
            Q.pop();
            
            if ( u.ff>0 && mat[u.ff-1][u.ss]=='1')
            {
                pii v = {u.ff-1,u.ss};
                if (vis[v.ff][v.ss] == 0) {
                    vis[v.ff][v.ss] = 1;
                    Q.push(v);
                }
            }
            if ( u.ss>0 && mat[u.ff][u.ss-1]=='1')
            {
                pii v = {u.ff,u.ss-1};
                if (vis[v.ff][v.ss] == 0) {
                    vis[v.ff][v.ss] = 1;
                    Q.push(v);
                }
            }
        }
    }
     
    void fnc()
    {
        mem(vis,0);
        int n;
        cin>>n;
     
        FOR(i,0,n)
            cin>>mat[i];
     
        FOR(i,0,n)
            if ( mat[i][n-1] == '1' )
                bfs(i,n-1);
        FOR(i,0,n)
            if ( mat[n-1][i] == '1' )
                bfs(n-1,i);
        FOR(i,0,n)
            FOR(j,0,n)
                if ( !vis[i][j] && mat[i][j]=='1' )
                {
                    cout<<"NO";
                    return;
                } 
        cout<<"YES";
    }
     
    int main(){
        int n;
        cin>>n;
        FOR(i,0,n)
        {
            fnc();
            cout<<"\n";
        }
    }