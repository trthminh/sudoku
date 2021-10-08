// Truong Thanh Minh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define name "a"
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i>=b;--i)
#define pb push_back
typedef pair < ll , ll > ii;

const ll maxn=1e5+7,oo=1e18,aoo=-1e18;
ll t,a[10][10],hang[10][10],cot[10][10],anew[10][10],o[30][10],ok,st,en,thoat;
void solve()
{
    FOR(i,1,9)
        FOR(j,1,9)
            if(a[i][j]==0 && anew[i][j]==0)
                return;
    FOR(i,1,9)
    {
        FOR(j,1,9)
            if(a[i][j]==0)
                cout<<anew[i][j]<<" ";
            else cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    thoat=1;
}
void thu(int x,int y)
{
    if(thoat)
        return;
    if(x>9)
        solve();
    if(a[x][y]!=0)
    {
        if(y==9)
            thu(x+1,1);
        else thu(x,y+1);
    }
    FOR(i,1,9)
    {
        if(hang[x][i]==0 && cot[y][i]==0 && o[(ll)(3*ceil((double)x/3)+ceil((double)y/3))][i]==0)
        {
            anew[x][y]=i;
            hang[x][i]=1;
            cot[y][i]=1;
            o[(ll)(3*ceil((double)x/3)+ceil((double)y/3))][i]=1;
            if(y==9)
                thu(x+1,1);
            else thu(x,y+1);
            anew[x][y]=0;
            hang[x][i]=0;
            cot[y][i]=0;
            o[(ll)(3*ceil((double)x/3)+ceil((double)y/3))][i]=0;
        }
    }
}
int main()
{
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin>>t;
    while(t--)
    {
        FOR(i,1,9)
            FOR(j,1,9)
                FOR(k,1,9)
                {
                    hang[i][k]=cot[j][k]=0;
                    o[(ll)(3*ceil((double)i/3)+ceil((double)j/3))][k]=0;
                    anew[i][j]=0;
                }
        ok=0;
        thoat=0;
        FOR(i,1,9)
            FOR(j,1,9)
            {
                cin>>a[i][j];
                if(a[i][j]!=0)
                {
                    hang[i][a[i][j]]=1;
                    cot[j][a[i][j]]=1;
                    o[(ll)(3*ceil((double)i/3)+ceil((double)j/3))][a[i][j]]=1;
                }
                else if(ok==0)
                {
                    st=i;
                    en=j;
                    ok=1;
                }
            }
        thu(st,en);
        if(thoat==0)
            cout<<"No solution"<<'\n';
    }
}



