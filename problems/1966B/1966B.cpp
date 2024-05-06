#include <bits/stdc++.h>
#include <unordered_map>
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

bool allTrue(const unordered_map<char, bool>& map)  {
  for (const auto& pair : map) {
    if (!pair.second) {
      return false;
    }
  }
  return true;
}

void solve() {
  int rows, cols; cin >> rows >> cols;

  vector<vector<char>> grid(rows,vector<char>(cols));
  
  FOR(i, 0, rows) {
    FOR(j, 0, cols) {
      char val; cin >> val;
      grid[i][j] = val; 
    }
  }

  // all you need to do is just find if there is the same colour on all four corners 

  unordered_map<char, bool> black = {{'t', false}, {'b', false}, {'l', false}, {'r', false}};
  unordered_map<char, bool> white = {{'t', false}, {'b', false}, {'l', false}, {'r', false}};


  FOR(i, 0, cols) {
    char top = grid[0][i];
    char bottom = grid[rows - 1][i];
    if (top == 'W' && !white['t']) { 
        white['t'] = true;
    }

    if (top == 'B' && !black['t']) { 
        black['t'] = true;
    }
    
    if (bottom == 'W' && !white['b']) { 
        white['b'] = true;
    }

    if (bottom == 'B' && !black['b']) { 
        black['b'] = true;
    }
  }

  FOR(i, 0, rows) {
    char left = grid[i][0];
    char right = grid[i][cols - 1];

    if (right == 'W' && !white['r']) { 
        white['r'] = true;
    }

    if (right == 'B' && !black['r']) { 
        black['r'] = true;
    }
    
    if (left == 'W' && !white['l']) { 
        white['l'] = true;
    }

    if (left == 'B' && !black['l']) { 
        black['l'] = true;
    }
  }
  
  if (allTrue(black) || allTrue(white)) {
    cout << "YES" << ln;
  } else {
    cout << "NO" << ln;
  }
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
