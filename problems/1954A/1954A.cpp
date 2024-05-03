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
  int n, m, k; cin >> n >> m >> k;
  
 // n is how many parts of the ribbon 
 // m is how many colours of the ribbon 
 // k is how many parts can be destroyed 
  
  // if name colours -1 is not bigger than num of deletions then fail
  if (k >= n - 1) {
    cout << "YES";
  } else {
  
    cout << (m > 1 ? "YES" : "NO");
  }
  

} 

int main() {
  int T = 1;
  cin >> T;   
  while (T--) {
    solve();
  }

  return 0;
}
