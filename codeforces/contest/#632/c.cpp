#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (long long)(x).size()
typedef long long ll;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;
typedef vector<vector <long long> > vvi;
typedef vector<ll> vll;

int main() 
{ 
    long long n;
    cin >> n;

    vll arr(n + 1);
    vll ps(n + 1);
    arr[0] = 0;
    ps[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
        ps[i] = ps[i - 1] + arr[i];
    }


    int l = 0;
    map<ll, ll> freq;
    freq[0] = 1;
    ll ans = 0;

    for (int r = 1; r < n + 1; r++) {
        while (freq[ps[r]] > 0) {
            freq[ps[l++]]--;
        }
        freq[ps[r]]++;
        ans += r - l;
    }
    

    cout << ans << endl;
	return 0; 
} 

