#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FOD(i,a,b) for(int i=(a); i>=(b); --i)
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define TIME (1.0*clock())
#define el '\n'
#define INF LLONG_MAX
using namespace std;

//const ll maxN = 1e5+5;
//ll n,m;
//
//struct Node {
//    ll u,v,val;
//    Node(){ u=0; v=0; val=0; }
//    Node(ll u, ll v, ll val){ this->u=u; this->v=v; this->val=val; }
//} tree[maxN*4];
//
//void down(int id,int a, int b) {
//    tree[id<<1].val += tree[id].val;
//    tree[id<<1|1].val += (tree[id].u-1)*a+b+tree[id].val;
//    tree[id].val = 0;
//}
//
//void update(int id, int l, int r, int u, int v, int a, int b) {
//    if(v<l || r<u) return;
//    if(u<=l && r<=v) {
//        tree[id].val +=
//    }
//    down(id);
//    int m = (l+r) >> 1;
//
//}
//
//ll get(int id, int l, int r, int u, int v) {
//
//}

ll tong(ll l, ll r) {
    if(l>r) return LLONG_MAX;
    ll kc = l-1;
    return kc*(r-l+1)+(r+l-2*kc)*(r-l+1)/2;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll l,r,m; cin >> l >> r;
    ll l1 = l, r1 = r, minn=LLONG_MAX, id=l;
    while(l<r-1) {
        ll m = (l+r) >> 1;
        ll suml = tong(l1,m), sumr = tong(m+1,r1);
        if(suml == sumr) id = m, l = r;
        else if(suml < sumr)  l = m;
        else r = m;
        if(minn > abs(suml-sumr)) id = m, minn = abs(suml-sumr);
    }
    cout << id;
}
