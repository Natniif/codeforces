#include <bits/stdc++.h>

using namespace std;

using lli = long long int;
using uInt = unsigned int;
using ulli = unsigned long long int;
using vi = vector<int>;
using vii = vector<lli>;
using vc = vector<char>;
using udouble = long double;
using vd = vector<double>;
using vs = vector<string>;

#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define F0R(i, a) for(int i=0l i<(a); i++)
#define trac(a, x) for(auto& a : x)
#define uid(a, b) uniform_int_distribution(a, b)(rng)


#define ln                "\n"
#define flush             endl
#define sz(x)             (int)(x).size()

#define bin_sc(a, x)      binary_search(All(a), x)

#define scanv(x)          for(auto &i: x) cin >> i
#define msg(x)            cout << (#x) << ln
#define printv(v)         cout << "[ ";for(auto j: v) cout << j << ' '; cout << "]" << ln
#define printvv(v)        cout << "["; for(auto i: v) {printv(i);} cout << "........]\n"

#define mp                make_pair
#define pb                push_back
#define lb                lower_bound
#define up                upper_bound

bool isUp(char ch){locale loc; return isupper(ch, loc);}
void debug() {cout << "#------------------#\n";}

template<typename T> T LOG(T base, T power){return log2(power) / log2(base);}

//--------- overloaded << operator to print stl containers.. cout << container << ln
// for vector(1D, 2D), vector of pair & set....
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "]";
    return out;
}

// for set & set of ....
template <typename T> 
ostream& operator<<(ostream& os, const set<T>& v){ 
    os << "{"; 
    for (auto it : v) { 
        os << it; 
        if (it != *v.rbegin()) 
            os << ", "; 
    } 
    os << "}"; 
    return os; 
} 
// for map, map of vector & .....
template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v){ 
    for (auto it : v)  
        os << it.first << " : " 
           << it.second << "\n"; 
    return os; 
}
// for pair & pair of .......
template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v){ 
    os << "("; 
    os << v.first << ", " 
       << v.second << ")"; 
    return os; 
}

int find_winners(vi cows, int cow_idx) {
  vi winners(cows.size(), 0);
  int i = 0; 
  FOR(j, 1, (int)cows.size()) {
    // no equal numbers in list?
    if (cows[i] < cows[j]) {
      i = j;
      winners[j]++; 
    } else {
      winners[i]++;
    }
  }
  
  return winners[cow_idx];
}

void solve() {
  int n, k; cin >> n >> k;
  k -= 1;
  vi cows;
  while (n--) {
    int cow; cin >> cow;
    cows.push_back(cow);
  }
  
  int cow_val = cows[k];
  bool swapped = false;
  // if k in position 1 then already optimal
  if (k != 0) {
    FOR(i, 0, k) {
      if (cows[i] > cow_val) {
        swap(cows[i], cows[k]);
        k = i;
        swapped = true;
        break;
      }
    }
    if (!swapped) {
      swap(cows[0], cows[k]);
    }
  }

  cout << find_winners(cows, k) << ln;
  
  //
  // pair<int, int> val_pos = {0, 0};
  // FOR(i, 0, (int)cows.size()) {
  //   vi new_cows = cows; 
  //   swap(new_cows[i], new_cows[k]);
  //   int our_cow_wins = find_winners(new_cows, i);
  //   if (our_cow_wins > val_pos.first) {
  //     val_pos.first = our_cow_wins; 
  //     val_pos.second = i;
  //     cout << val_pos << ln;
  //   }
  // }
} 

int main() {
  #ifndef ONLINE_JUDGE
		//freopen("generator.txt", "r", stdin);
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
