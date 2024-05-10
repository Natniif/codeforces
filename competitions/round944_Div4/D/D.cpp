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
    string s; cin >> s;

    bool first_zero_before_one = true;
    bool carrying_zero_cut = false;
    char prev = '1';
    int cuts = 0;

    if (!s.empty()) {
        FOR(i, 0, (int)s.length()) {
            // if 0 and prev is 1 then cut
            // if (i == ((int)s.length() - 1) && s[i] == '0' && prev!='0') {
            //     cuts++;
            // } 

            // ^ want this to trigger as well as below at same time possibly

            // if current is 0 and 1 prev you always cut 
            if (prev == '1' && s[i] == '0' && i != 0) {
                cuts++; 
            } 

            // dont cut if first zero before a 1 in sequence 
            // this will be the connection between the 0s and 1s 
            else if (s[i] == '1' && prev == '0' && first_zero_before_one) {
                first_zero_before_one = false;
                carrying_zero_cut = true;
            } 
            // if carrying zero cut doesnt hit a one and reaches end we need to count for the cut 
            // else if (carrying_zero_cut && i == ((int)s.length() - 1)) {
            //     carrying_zero_cut = false;
            // }
            
            // if reach end and all same then cut once 
            // else if (cuts == 0 && i == ((int)s.length() - 1)) {
            //     cuts++;
            // }

            // if current is 1 and prev is 0 and already done the middle cut then cut
            else if (s[i] == '1' && prev == '0' && !first_zero_before_one && i!=0) {
                cuts++;
            }
            
            prev = s[i];
        }
    }

    cuts++;
    cout << cuts << ln;

} 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

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
