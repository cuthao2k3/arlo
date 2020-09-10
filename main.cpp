#include <bits/stdc++.h>

using namespace std;
long int n,a[5][10001],mina,sl_am;
long long ans,f[10001][20],sum;
int getbit(int Bit, int tthai)
{
    return (tthai>>Bit) & 1;
}
bool hopli_trangthai(int trangthai)
{
    for (int bi=0;bi<=3;bi++)
        if (getbit(bi,trangthai)==getbit(bi+1,trangthai) && getbit(bi,trangthai)==1) return false;
    return true;
}
long long tong_trangthai_coti(int trangthai,int cot)
{
     long long s=0;
    for (int j=1;j<=4;j++)
        if (getbit(j-1,trangthai)==1) s+=a[j][cot];
    return s;
}
bool hopli_2cot( int tt1,int tt2)
{
    for (int bi=1;bi<=4;bi++)
        if (getbit(bi-1,tt1)==getbit(bi-1,tt2) && getbit(bi-1,tt1)==1) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("vao.inp","r",stdin);
    cin>>n;
    mina=-1e9+13122003;
    for (int i=1;i<=4;i++)
        for (int j=1;j<=n;j++) {cin>>a[i][j]; if ( a[i][j] < 0) sl_am++; mina=max(a[i][j],mina); }
if (sl_am==4*n)
     cout<<mina<<endl; else
{
    for (int i=1;i<=n;i++)
      for (int s=0;s<=16;s++)
         if ( hopli_trangthai(s)==true )
    {
        sum=tong_trangthai_coti(s,i);
        for (int s1=0;s1<=16;s1++)
            if (hopli_2cot(s1,s)==true)
        {
            f[i][s]=max(f[i][s],f[i-1][s1] + sum);
        }
    }
ans=0;
for (int s=0;s<=16;s++) ans=max(ans, f[n][s]);
cout<<ans<<endl;
}
    return 0;
}
