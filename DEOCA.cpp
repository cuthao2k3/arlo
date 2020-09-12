#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e5+5;
int a[N],b[N],n,id[N],ans,f[N],c[N];
int get_max(int u)
{
    int t=0;
    while (u>=1)
    {
        t=t+f[u];
        u=u-(u&-u);
    }
    return t;
}
void update(int u, int v)
{
    c[u]=v;
    while (u<=n)
    {
        f[u]= f[u] + 1;
        u=u+(u&-u);
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("vao.inp","r",stdin);

    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        id[a[i]]=i;
        c[i]=0;
        f[i]=0;
    }

    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        b[i]=id[b[i]];
    }


     for (int i=n;i>=1;i--)
     {
         update(b[i],1);
        // if (b[i]==1) continue;
         int sum=get_max(b[i] -1);
         if (sum>0) ans++;
     }

     cout<<ans;
  //  return 0;
}
