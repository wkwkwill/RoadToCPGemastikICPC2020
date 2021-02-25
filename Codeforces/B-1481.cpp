#include <bits/stdc++.h>
#include <chrono>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/12/01
*/
using namespace std;
using ll = long long int;

/*===================== CONSTANT =====================*/

const ll BIG = 1e18 + 1;
const ll MOD = 1e9 + 7;
const int m = 998244353;

/*============== FUNCTION INITIALIZATION =============*/

void solve();

/*================ IMPORTANT FUNCTION ================*/

ll fastpow(ll x, ll y, ll n = m) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}
 
bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}
 
bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
 
bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
 
int main()
{
    //input output optimization
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(10);
    
    //debug time
    /*
    auto start = chrono::high_resolution_clock::now();
    freopen("input.txt", "r", stdin);
    */

    //solve function
    solve();
    
    //debug time
    /*
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    ofstream file;
    file.open("time.txt");
    file << duration.count() << " ms.";
    file.close();
    */
    return 0;
}
  
ll factorial(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return factorial(n) / ((factorial(r) * factorial(n - r)) % MOD); 
} 

bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


bool stringSort(string &a, string &b)
{
    if (a.length() > b.length()) return a.length() > b.length();
    return a > b;
}

void binsearch(int n, int x)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int middle = (left + right) / 2;
        //cout << middle << '\n';
        //if (middle == x) break;
        if (middle <= x)
        {
            left = middle + 1;
            if (x != middle);
        }
        else
        {
            right = middle;
        }
    }
}

int sequence(int a, int b)
{
    ll res = 1; 
    for (ll i = b; i <= a; i++) 
        res = (res * i) % MOD; 
    return res; 
}

int gcd(ll a, ll b) 
{
    while (b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*===================== SOLUTION =====================*/



void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for (int i = 0;i < n; ++i)
        {
            cin >> h[i];
        }
        int pos = 0;
        int step = 0;
        int ans = -1;
        while (pos < n-1)
        {
            if (step == k)
            {
                ans = pos + 1;
                break;
            }
    
            if (h[pos] < h[pos+1])
            {
                if (pos > 0)
                {
                    if (h[pos-1] < h[pos])
                    {
                        pos--;
                        continue;
                    }
                }
                h[pos]++;
                step++;
            }
            else if (h[pos] == h[pos+1])
            {
                if (pos == 0)
                {
                    pos++;
                    continue;
                }
                if (h[pos-1] < h[pos])
                {
                    pos--;
                }
                else pos++;
            }
            else
            {
                pos++;
            }
        }
        cout << ans << '\n';
    }
}
 
/* ==================== KOTRETAN ===================== *\

5 3 5
3 1 3 5 
1 4 
1 2
3 3 2
3 2 1
3 1 2
3 2 3
3 3 1

4
add = 2
ans += 2*3
ans = 16

4 2 1 3 5
1 5 4 3 2

4
ans += 2*0
ans = 18



6 2 2 3 
5 5 8 6

2 2 3 5
5 8 6 6


1 3 5 4 2

2: 2 4 8 10 3 1 5 6 7
2: 2 4 8 10 3 1 5 6

*/