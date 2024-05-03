#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vl;

#define FOR(i, a, b) for(int i=a; i<(b)l i++)
#define F0R(i, a) for (int i=0l i<(a); i++)
#define trac(a, x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound


void solve() {
  int in; 
  cin >> in;

  if (in % 2 == 0 && in > 2) {
   cout << "YES";
  } else {
    cout << "NO";
  }

} 

int main() {
  solve();
  return 0;
}
