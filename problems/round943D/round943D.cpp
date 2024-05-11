// #include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

// using namespace std;

using lli = long long int;
// using uInt = unsigned int;
// using ulli = unsigned long long int;
using vi = std::vector<int>;
using vii = std::vector<lli>;
// using vc = vector<char>;
// using udouble = long double;
// using vd = vector<double>;
// using vs = vector<string>;

#define FOR(i, a, b) for(int i=a; i<(b); i++)
// #define F0R(i, a) for(int i=0l i<(a); i++)
// #define trac(a, x) for(auto& a : x)
// #define uid(a, b) uniform_int_distribution(a, b)(rng)
//
//
#define ln                "\n"
// #define flush             endl
// #define sz(x)             (int)(x).size()
//
// #define bin_sc(a, x)      binary_search(All(a), x)
//
// #define scanv(x)          for(auto &i: x) cin >> i
// #define msg(x)            cout << (#x) << ln
// #define printv(v)         cout << "[ ";for(auto j: v) cout << j << ' '; cout << "]" << ln
// #define printvv(v)        cout << "["; for(auto i: v) {printv(i);} cout << "........]\n"
//
// #define mp                make_pair
// #define pb                push_back
// #define lb                lower_bound
// #define up                upper_bound
//
// bool isUp(char ch){locale loc; return isupper(ch, loc);}
// void debug() {cout << "#------------------#\n";}
//
// template<typename T> T LOG(T base, T power){return log2(power) / log2(base);}

//--------- overloaded << operator to print stl containers.. cout << container << ln
// for vector(1D, 2D), vector of pair & set....
// template<typename T>
// ostream& operator<< (ostream& out, const vector<T>& v) {
//     out << "[";
//     size_t last = v.size() - 1;
//     for (size_t i = 0; i < v.size(); ++i) {
//         out << v[i];
//         if (i != last)
//             out << ", ";
//     }
//     out << "]";
//     return out;
// }
//
// // for set & set of ....
// template <typename T> 
// ostream& operator<<(ostream& os, const set<T>& v){ 
//     os << "{"; 
//     for (auto it : v) { 
//         os << it; 
//         if (it != *v.rbegin()) 
//             os << ", "; 
//     } 
//     os << "}"; 
//     return os; 
// } 
// // for map, map of vector & .....
// template <typename T, typename S> 
// ostream& operator<<(ostream& os, const map<T, S>& v){ 
//     for (auto it : v)  
//         os << it.first << " : " 
//            << it.second << "\n"; 
//     return os; 
// }
// // for pair & pair of .......
// template <typename T, typename S> 
// ostream& operator<<(ostream& os, const pair<T, S>& v){ 
//     os << "("; 
//     os << v.first << ", " 
//        << v.second << ")"; 
//     return os; 
// }

void solve() {
  int n; 
  lli k; 
  int pb, ps; std::cin >> n >> k >> pb >> ps;

  vi perm(n);
  vii a(n);

  FOR(i, 0, n) {
    std::cin >> perm[i];
  }

  FOR(i, 0, n) {
    std::cin >> a[i];
  }

  auto max_el = std::max_element(a.begin(), a.end());
  lli max = *max_el;

  // scores
  lli bs = 0;
  lli ss = 0;

  bool max_bs = false;
  bool max_ss = false;

  while (k--){

    // fix for 0 indexing 
    bs += a[pb-1];
    ss += a[ps-1];
    // cout << "bs " <<  bs << " ss " << ss << ln;
    if (!max_bs) {
      if (a[pb-1] < a[perm[pb-1] - 1]) {
        pb = perm[pb-1];
      }
      if (a[pb-1] == max) {
        max_bs = true;
      }
    }
    
    if (!max_ss) {
      if (a[ps-1] < a[perm[ps-1] - 1]) {
        ps = perm[ps-1];
      }

      if (a[ps-1] == max) {
        max_ss = true;
      }
    }
  }

  // cout << bs << " " << ss << ln;

  if (bs > ss) {
    std::cout << "Bodya" << ln;
  } else if (ss > bs) {
    std::cout << "Sasha" << ln;
  } else {
    std::cout << "Draw" << ln;
  }

} 

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0),std::cout.tie(0);

  #ifndef ONLINE_JUDGE
		//freopen("generator.txt", "r", stdin);
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif

  int T = 1;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
