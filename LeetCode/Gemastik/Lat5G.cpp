#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/25
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
    int n;
    cin >> n;
    map<int, int> card;
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        card[input]++;
    }
    if (card.size() == 2 && card.begin()->second == n/2)
    {
        cout << "YES\n";
        for (auto i = card.begin(); i != card.end(); ++i)
        {
            cout << i->first << ' ';
        }
    }
    else
    {
        cout << "NO\n";
    }
    
}

/*

*/