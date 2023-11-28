#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FOD(i,a,b) for(int i=(a); i>=(b); --i)
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define el '\n'
#define INF LLONG_MAX
using namespace std;

const ll maxN = 1e5+5;
ll a[maxN],n,k, tree[maxN*4],f[maxN];

void build(ll id, ll l, ll r) {
    if(l==r) {
        tree[id] = max(0LL,a[l]);
        return;
    }
    ll mid = (l+r) >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id] = max({0LL,tree[id*2],tree[id*2+1]});
}

void update(ll id, ll l, ll r, ll i, ll v) {
    if(i<l || i>r) return;
    if(l==r) {
        tree[id] = v;
        a[l] = v;
        return;
    }
    ll mid = (l+r) >> 1;
    update(id*2,l,mid,i,v);
    update(id*2+1,mid+1,r,i,v);
    tree[id] = max({0LL,tree[id*2],tree[id*2+1]});
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if(v<l || r<u) return -INF;
    if(u<=l && r<=v) return tree[id];
    ll mid = (l+r) >> 1;
    return max({0LL,get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v)});
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    build(1,1,n);
    FOR(i,2,n) {
        ll res = max(0LL,get(1,1,n,max(1LL,i-k),i-1)+a[i]);
        update(1,1,n,i,res);
    }
    cout << get(1,1,n,1,n);
}
