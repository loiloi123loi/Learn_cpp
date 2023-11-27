#include<bits/stdc++.h>
using namespace std;

const string NAME="TASK";
typedef long long ll;
#define TIME (1.0*clock())
#define FOR(i,a,b) for(ll i=(a); i<=(b); i++)
#define el '\n'

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll h) {
    assert(l <= h);
    return l + rd() % (h - l + 1);
}

const ll Ntest=100;

void sinhtest() {
    ofstream inp(NAME+".inp");

    

    inp.close();
}

int main(){
    for(int test=1; test<=Ntest; test++){
        sinhtest();
        cout << "\t";

        long t1, t2, t3;
        t1 = TIME;
        system((NAME+".exe").c_str());
        t2 = TIME;
        system((NAME+"_trau.exe").c_str());
        t3 = TIME;

        if (system(("fc " + NAME + ".out " + NAME + ".ans > nul").c_str()) != 0)
        {
            cout << "Test " << test << ": WRONG! " << "(" << (t2-t1) <<") " << "(" << (t3-t2) <<")\n";
            return 0;
        }
        cout << "Test " << test << ": CORRECT! " << "(" << (t2-t1) <<") " << "(" << (t3-t2) <<")\n";
    }
}
