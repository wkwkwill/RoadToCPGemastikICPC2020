#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/30
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
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

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}


void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<char, int> count;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); ++j)
            {
                count[s[j]]++;
            }
        }
        bool can = true;
        for (auto x : count)
        {
            if (x.second % n != 0) can = false;
        }
        if (can) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
/*
3 12 6
6 12 3
*/