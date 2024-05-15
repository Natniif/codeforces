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

bool is_zero_XOR(vi arr) {
    vi xor_arr; 
    FOR(i, 0, 4) {
        if (arr[i]%2 != 0) {
            xor_arr.push_back(i + 1);
        }
    }

    if (xor_arr.empty()) {
        return true;
    } else if (xor_arr.size() == 1) {
        return false;
    } else {
        int result = 0;
        for(int num : xor_arr) {
            result ^= num;
        }
        return result == 0 ? true : false;
    }
}

void solve() {
    vi p(4);
    FOR(i, 0, 4) {
        cin >> p[i];
    }

    // 0 0 1 = 1
    // 0 1 0 = 2
    // 0 1 1 = 3
    // 1 0 0 = 4

    // Scenarios where it will equal 0
    // when all are even 
    // e.g. 
    // 2 2 2 2 
    // 0 0 2 0 
    // 1 1 1 0 

    int rounds = accumulate(p.begin(), p.end(), 0);


    vi dp(rounds + 1);
    dp[0] = 0;

    int ret = 0;


    FOR(i, 0, rounds) {
        if (is_zero_XOR(p)) {
            ret++;
        }

        bool found_odd = false;

        // remove by one to make even if odd 
        for(int j = 3; j >= 0; j--){
            if (p[j]%2 != 0 && p[j] != 0) {
                p[j]--;
                found_odd = true;
                break;
            }
        } 

        if (!found_odd) {
           for(int j = 3; j >= 0; j--){
                if (p[j] > 0) {
                    p[j]--;
                    found_odd = true;
                    break;
                }
            }  
        }
    }

    cout << ret << ln;

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
