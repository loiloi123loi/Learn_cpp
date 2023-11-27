#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FOD(i,a,b) for(int i=(a); i>=(b); i--)
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define el '\n'
#define INF 1e12
using namespace std;

const ll maxN = 1e5+5;
ll tree[4*maxN], a[maxN], n, q;

void build(int id, int l, int r) {
    if(l==r) {
        tree[id]=a[l];
        return;
    }

    int mid = l+r >> 1;
    build(id*2, l, mid);
    build(id*2+1,mid+1,r);
    tree[id] = max(tree[id*2],tree[id*2+1]);
}

void update(int id, int l, int r, int x, int y) {
    if(x<l || x>r) return;
    if(l==r) {
        tree[id]=y;
        return;
    }

    int mid = l+r >> 1;
    update(id*2, l, mid,x,y);
    update(id*2+1,mid+1,r,x,y);

    tree[id] = max(tree[id*2],tree[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if(v<l || u>r) return -INF;
    if(u<=l && r<=v) return tree[id];

    int mid = l+r >> 1;
    return max(get(id*2, l, mid, u, v),get(id*2+1, mid+1,r, u, v));
}

int main(){
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i,1,n) cin >> a[i];
    build(1,1,n);
//    FOR(i,1,4*n) cout << tree[i] << " ";
    cin >> q;
    while(q--) {
        int ac; cin >> ac;
        if(ac==1) {
            int x,y; cin >> x >> y;
            update(1,1,n,x,y);
        }
        else {
            int l,r; cin >> l >> r;
            cout << get(1,1,n,l,r) << el;
        }
    }
}
