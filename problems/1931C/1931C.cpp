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

#define FOR(i, a, b) for(int i=a; i<((int)b); i++)
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
  int n; cin >> n;
  vi nums; 
  while (n--) {
    int n; cin >> n;
    nums.push_back(n);
  }

  int ns = sz(nums);

  vi identical_forward;
  int first = nums[0];
  FOR(i, 0, (int)nums.size()) {
    if (identical_forward.empty() || first == nums[i]){
      identical_forward.push_back(nums[i]); 
    }
    else {
      break;
    }
  }
  
  vi identical_backward;
  int last = nums.back();
  for (int i = (int)nums.size() - 1; i >= 0; i--) {
    if (identical_backward.empty() || last == nums[i]){
      identical_backward.push_back(nums[i]); 
    }
    else {
      break;
    }
  }

  if (ns == sz(identical_forward)) {
    cout << 0 << ln;
  }
  else if (nums[0] == nums[ns - 1]) {
    cout << ns - (identical_forward.size() + identical_backward.size()) << ln;
  } else {
    cout << ns - max(identical_forward.size(), identical_backward.size()) << ln;
  }
}
  // ---------------------WRONG UNDERSTANDING OF QUESTION ---------------------
  // // cout << "ARRAY: " << nums << " "; 
  // 
  // unordered_map<int, int> hmap;
  // FOR(i, 0, nums.size()) {
  //   hmap[nums[i]]++;
  // }
  //
  // // if all different numbers
  // if (hmap.size() == nums.size()) {
  //   cout << nums.size() - 1 << ln;
  // }
  // else {
  //   int max_val = std::numeric_limits<int>::min();
  //   for (const auto& pair : hmap) {
  //       max_val = std::max(max_val, pair.second);
  //   }
  //   // if all numbers same
  //   if (max_val == (int)nums.size()) {
  //     cout << 0 << ln;
  //   } else {
  //     cout << nums.size() - max_val<< ln;
  //   }
  // }

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
