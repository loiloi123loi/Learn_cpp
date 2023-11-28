#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FOD(i,a,b) for(int i=(a); i>=(b); i--)
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define el '\n'
#define INF 1e15
using namespace std;

int main(){
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.ans","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    const ll maxN = 1e5+5;
    ll a[maxN], n, q;
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    cin >> q;
    while(q--){
        int ac; cin >> ac;
        if(ac==1) {
            int x,y,val; cin >> x >> y >> val;
            FOR(i,x,y) a[i]+=val;
        }
        else {
            ll l,r, res = -INF; cin >> l >> r;
            FOR(i,l,r) res = max(res,a[i]);
            cout << res << el;
        }
    }
}
