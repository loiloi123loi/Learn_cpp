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

bool cp(const pair<ll,ll> a, const pair<ll,ll> b) {
    if(a.second <= b.second) return true;
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    const ll maxN = 1e2+5;
    ll n,m; cin >> n >> m;
    vector<pair<ll,ll>> a1;
    FOR(i,1,n) {
        ll x; cin >> x;
        a1.push_back({i-1,x});
    }
    sort(a1.begin(),a1.end(),cp);
    vector<ll> a,b,c;
    ll s1=0,s2=0,s3=0;
    FOD(i,n-1,0) {
        if(s1<=s2 && s1<=s3){
            s1+=a1[i].second;
            a.push_back(a1[i].first);
        }
        else if(s2<=s1 && s2<=s3){
            s2+=a1[i].second;
            b.push_back(a1[i].first);
        }
        else if(s3<=s2 && s3<=s1){
            s3+=a1[i].second;
            c.push_back(a1[i].first);
        }
    }
    ll maxx = max({s1,s2,s3});
    cout << maxx << el;
    FOR(i,0,a.size()-1) cout << a[i]+1 << " "; cout << el;
    FOR(i,0,b.size()-1) cout << b[i]+1 << " "; cout << el;
    FOR(i,0,c.size()-1) cout << c[i]+1 << " "; cout << el;
}
