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

int highest_bit_position(int value) {
    int pos = 0;
    while (value > 0) {
        value >>= 1;
        pos++;
    }
    return pos - 1; // zero-based position
}

void solve() {
    int n; cin >> n;

    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
    }

    int max_value = *std::max_element(a.begin(), a.end());
    int max_bit_pos = highest_bit_position(max_value);

    int first_occurrence_index = -1;
    for (int i = 0; i < n; ++i) {
        if ((a[i] & (1 << max_bit_pos)) != 0) {
            first_occurrence_index = i;
            break;
        }
    }

    int k = (first_occurrence_index > 0) ? first_occurrence_index : 1;

    auto lowest = min(a.begin(), a.end()); 
    
    int min_index = distance(a.begin(), lowest);

    k = k - min_index;

    while (true) {
        int match = 0; 
        FOR(i, 0, k) {
            match |= a[i];
        }

        int matched = true;

        FOR(i, 0, n-k + 1) {
            int left = 0;
            FOR(j, i, i + k) {
                left |= a[j];
            }

            if (left != match) {
                matched = false;
                break;
            }
        }

        if (matched) {
            cout << k << ln;
            return;
        }

        k++;
        if (k >= n) {
            cout << k << ln;
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
