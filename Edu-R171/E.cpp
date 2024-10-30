#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e2+11;
const int M=5e3+11;
int n,m,s,t;
int tot,fir[N],cur[N];
struct edge{
	int v,nxt;
	ll w;
}a[M*2];
void addedge(int x,int y,ll w){
	++tot;a[tot].v=y;a[tot].nxt=fir[x];a[tot].w=w;fir[x]=tot;
	++tot;a[tot].v=x;a[tot].nxt=fir[y];a[tot].w=0;fir[y]=tot;
}
int dep[N];
queue<int>q;
bool bfs(){
	for(int i=1;i<=max(n,t);i++)
	dep[i]=0,cur[i]=fir[i];
	dep[s]=1;q.push(s);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int now=fir[p];now;now=a[now].nxt){
			if(a[now].w&&!dep[a[now].v]){
				dep[a[now].v]=dep[p]+1;
				q.push(a[now].v);
			}
		}
	}
	if(dep[t])return 1;
	return 0;
}
ll dfs(int p,ll f){
	if(p==t)return f;
	ll res,ret=0;
	for(int now=cur[p];now;now=a[now].nxt){
		int v=a[now].v;
		cur[p]=now;
		if(dep[v]!=dep[p]+1||a[now].w==0)continue;
		res=dfs(v,min(f,a[now].w));
		a[now].w-=res;
		a[now^1].w+=res;
		f-=res;ret+=res;
	}
	return ret;
}
int nn;
ll aa[N];
void solve() {
    tot=1;
    cin>>nn; 
    s=nn+60+1, t=s+1, n=t;
    // cout<<s<<' '<<t<<endl;
    ll ans=0;
    for(int i=1;i<=nn;i++) {
        cin>>aa[i];
        // cout<<i<<':'<<aa[i]<<endl;
        for(int j=0;j<60;j++){
            if(aa[i]&(1ll<<j)) {
                addedge(i,nn+1+j,1e9);
                // cout<<i<<"=>"<<nn+1+j<<endl;
            }
        }
        addedge(s,i,1);
        // cout<<s<<"=>"<<i<<endl;
    }
    for(int j=1;j<=60;j++) {
        addedge(nn+j,t,1);
        // cout<<nn+j<<"=>"<<t<<endl;
    }
	while(bfs())ans-=dfs(s,1e18);
	cout<<ans+nn<<endl;
    for(int i=1;i<=n;i++) fir[i]=cur[i]=dep[i]=0;
}
int main() {
    ios::sync_with_stdio(false);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
