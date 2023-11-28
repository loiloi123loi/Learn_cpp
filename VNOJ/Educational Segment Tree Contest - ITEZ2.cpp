#include <bits/stdc++.h>
using namespace std;

#define for0(i,n) for(int i=0; i<n; i++)

long long tree[400005]={0}, a[100005]={0}, n;

void build(int id, int l, int r) {
    if(l==r) {
        tree[id]=a[l];
        return;
    }

    int mid = l+r >> 1;
    build(id*2+1,l,mid);
    build(id*2+2,mid+1,r);

    tree[id] = min(tree[id*2+1],tree[id*2+2]);
}

void update(int id, int l, int r, int i, long long val) {
    if(i<l || i>r) return;
    if(l==r){
        tree[id] = val;
        return;
    }

    int mid = l+r >> 1;
    update(id*2+1,l,mid,i,val);
    update(id*2+2,mid+1,r,i,val);

    tree[id] = tree[id*2+1]+tree[id*2+2];
}

long long get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return 0;
    if(u<=l && r<=v) return tree[id];

    int mid = l+r >> 1;
    long long get1 = get(id*2+1,l,mid,u,v);
    long long get2 = get(id*2+2,mid+1,r,u,v);

    return get1+get2;
}

int main()
{
    // freopen("in.inp","r",stdin);
    // freopen("out.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    long long t;
    cin>>t;
    while(t-->0) {
        int ac;
        cin>>ac;
        if(ac==1){
            long long x,y;
            cin>>x>>y;
            update(0,0,n-1,x-1,y);
        }
        else {
            long long l,r;
            cin>>l>>r;
            cout<<get(0,0,n-1,l-1,r-1)<<"\n";
        }
    }
    return 0;
}
