#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll INF_MUL = 1e13;
const ll INF_ADD = 1e18;
#define nline "\n"
#define f first
#define s second
#define sz(x) (ll)x.size()
#define vl vector<ll>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------     

const ll MOD=998244353;
const ll MAX=500500;


void solve(){
    ll n,ans=0; cin>>n;
    string s; cin>>s;
    s=" "+s;
    for(ll check:{0,1,2,3}){
        string t(n+5,'0');
        t[1]=(check&1)+'0';
        if(check&2){
            t[2]='1';
        }
        ll valid=1;
        for(ll i=3;i<=n;i++){
            t[i]='0'+'1'-t[i-2];
        }
        for(ll i=1;i<=n;i++){
            if(s[i]!='?'){
                valid&=(s[i]==t[i]);
            }
        }
        ans+=valid;
    }
    cout<<ans<<nline;
    return;
}
int main(){  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);                                    
    ll test_cases=1;
    cin>>test_cases;
    while(test_cases--){
      solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
} 