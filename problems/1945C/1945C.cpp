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

void solve() {
  int n; 
  cin >> n;
  string votes; 
  cin >> votes;

  // cout << votes << ln;

  int sum_ones = count(votes.begin(), votes.end(), '1');
  int zeros_left = 0; 
  int ones_right = sum_ones;

  int answer = -1;
  double middle = (static_cast<double>(n)/2);
  // cout << "Middle " << (static_cast<double>(n)/2) << ln;
  // start off as max differen
  int min_diff = n;

  // starts from before the first house
  FOR(i, 0, n) {
    // cout << "zeros_left " << zeros_left << " ones_right " << ones_right << ln;
    // cout << "To beat " << (double)i / 2 << " To beat " << ((double)n - (double)i)/2 << ln;

    if (zeros_left >= (double)i/2 && ones_right >=((double)n - (double)i)/2) {
      // cout << "Solution " << i << " difference " << abs(middle-i) << ln;
      if (abs(middle - i) == min_diff) {
        if (i < answer) {
          answer = i;
        }
      } else if (abs(middle - i) <= min_diff) {
        // cout << "New Ans " << i << ln;
        answer = i;
        min_diff = abs(middle - i);
      }
    }
    if (votes[i] == '0'){
      zeros_left++;
    }
    if (votes[i] == '1') {
      ones_right--;
    }
  }
  
  if (answer == - 1) {
    cout << n << ln;
  } else {
    cout << answer << ln;
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
