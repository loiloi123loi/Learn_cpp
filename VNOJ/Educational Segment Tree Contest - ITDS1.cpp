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

const int maxN = 1e5+5;
int a[maxN],n,m;
multiset<int> st[maxN*4];

void build(int id, int l, int r) {
    if(l==r) {
        st[id].insert(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id];
    for (auto x : st[2 * id + 1]) st[id].insert(x);
}

void update(int id, int l, int r, int i, int old, int val) {
    if(i<l || r<i) return;
    if(l==r) {
        st[id] = multiset<int>();
        st[id].insert(val);
        return;
    }
    int m = (l+r) >> 1;
    update(id*2,l,m,i,old,val);
    update(id*2+1,m+1,r,i,old,val);
    st[id].erase(st[id].find(old));
    st[id].insert(val);
}

int query(int id, int l, int r, int u, int v, int k) {
    if(v<l || r<u) return INT_MAX;
    if(u<=l && r<=v) {
        auto res = st[id].lower_bound(k);
        if (res != st[id].end()) return *res;
        return INT_MAX;
    }
    int m = (l+r) >> 1;
    return min(query(id*2,l,m,u,v,k),query(id*2+1,m+1,r,u,v,k));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i,1,n) cin >> a[i];
    build(1,1,n);
    while(m--) {
        int ac,l,r,k; cin >> ac;
        if(ac==1) {
            cin >> l >> k;
            update(1,1,n,l,a[l],k);
            a[l] = k;
        }
        else {
            cin >> l >> r >> k;
            ll res = query(1,1,n,l,r,k);
            if(res==INT_MAX) cout << -1 << el;
            else cout << res << el;
        }
    }
}
