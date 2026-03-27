#include<bits/stdc++.h>
//#include<numbers>
//#include<chrono>

using namespace std;

#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define vecin(name, len) vector<int> name(len); for (auto &x : name) cin >> x;
#define vecout(v) for (auto x : v) cout << x << " "; cout << endl;
#define Sort(x) sort(all(x))
#define DEBUG(x...)x
#define WW(x) DEBUG(cout<<#x" = "<<x<<endl)
#define LB(x, y) lower_bound(all(x), y)
#define UB(x, y) upper_bound(all(x), y)
#define BS(x, y) binary_search(all(x), y)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
const double EPS = 1e-12;
const int INF = 0x3f3f3f3f;

ll zeros_ate(ll x, ll k) {
    return (x/(1LL<<(k+1LL)))*(1LL<<k) + min((x%(1<<(k+1)) + 1), (1LL<<k)) - 1LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin>>n;
    vvi prefix(3, vi(n+1));
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i][j-1] + (v[j-1] == 'H' && i == 0)+
                (v[j-1] == 'P' && i == 1) + (v[j-1] == 'S' && i == 2);
        }
    }

    int resp = 0;

    for (int i = 1; i <= n; i++) {
        int aux = max({prefix[0][i], prefix[1][i], prefix[2][i]});
        int temp = max({prefix[0][n]-prefix[0][i], prefix[1][n]-prefix[1][i],
        prefix[2][n]-prefix[2][i]});

        resp = max(resp, aux+temp);
    }

    cout<<resp<<endl;

    return 0;
}

// Pre computamos todos os momentos em que há vitórias e a cada momento pegamos a maior quantidade de vitórias
// e somamos a ela a quantidade de vitórias que resta em cada um e pegamos o max isso, a soma é a resposta.
// resumo: pega a maior quantidade atual e ve qual que eh a maior que resta, a resposta e a soma das partes.

