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
    int x, y; cin >> x >> y;
 
    // num of poss 2x2 in each screen is 2
    // left over squares = 7
 
    int screens_filled_by_2 = floor((double)y/2);
 
    if (x == 0 && y == 0) {
        cout << 0 << ln;
        return;
    }
 
    int ret = 0;
    if (y == 0) {
        int x_left = 15 - (y*4); 
        ret = 1 + floor((x - 1)/(15-(y*4)));
        cout << ret << ln;
        return;
    } else if (y <= 2 ) {
        int x_left = x - 15 - (y*4); 

        if (x > 0) {
            ret =  1 + floor((x - 1)/(15));
        } else {
            ret = 1 + floor((x - 1)/(15-(y*4))); 
        }
        cout << ret << ln;
        return;

    } else if (y > 2 && y%2 == 0) {

        int squares_to_fill = 7*(y/2);

        if (x <= squares_to_fill) {
            cout << y/2 << ln;
        } else {
            int squares_left = x - squares_left;
            cout << (y/2) + 1 + floor((squares_left-1)/15);
            return;
        }

    } else {

        int squares_to_fill = 7*(y/2) + 11;
 
        if (x <= squares_to_fill) {
            cout << y/2 + y%2 << ln;
        } else {
            int squares_left = x - squares_left;
            cout << floor(y/2) + 1 + floor((squares_left-1)/15) + y%2;
            return;
        }
    }
 
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