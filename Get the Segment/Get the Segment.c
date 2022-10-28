#include <bits/stdc++.h>

using namespace std;

#define int long long



mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());



map<pair<int, int>, int> mp;



int ask(int l, int r)

{

    if(mp.count({l, r})) return mp[{l, r}];

    cout << "1 " << l << " " << r << endl;

    int ans;

    cin >> ans;

    mp[{l, r}] = ans;

    return ans;

}



int output(int l, int r)

{

    cout << "2 " << l << " " << r << endl;

    int ans;

    cin >> ans;

    return ans;

}



void Solve() 

{

    mp.clear();

    int n, k;

    cin >> n >> k;

    int ans = ask(1, n);

    if(ans == n * 2)

    {

        ans = output(1, k / 2);

        return;

    }

    int l = 1, r = n, ans2 = n;

    while(l <= r) // approx 17 queries

    {

        int mid = (l + r) / 2;

        ans = ask(l, mid);

        if(ans == k)

        {

            ans = output(l, mid);

            return;

        }

        if(ans == (mid - l + 1) * 2)

        {

            l = mid + 1;

        }

        else

        {

            r = mid - 1;

            ans2 = mid;

        }

    }

    if(k % 2 == 0 && k / 2 < ans2)

    {

        // cout << "holyfuck" << endl;

        ans = output(1, k / 2);

        return;

    }

    ans = ask(ans2, n); // +1 = 18 queries

    // cout << "ans = " << ans << endl;

    if(ans < k)

    {

        int devoid = k - ans;

        // cout << "devoid = " << devoid << endl;

        if(devoid % 2 == 0)

        {

            ans = output(ans2 - devoid / 2, n);

            return;

        }

        else // approx 17 more queries = 35

        {

            int l = ans2 - devoid / 2;

            int siz = n - l;

            int ll = 1, rr = l;

            ans = ask(l, n);

            bool f = (ans > k) ? true : false;

            if(ans == k)

            {

                output(l, n);

                return;

            }

            // cout << "ll = " << ll << ", rr = " << rr << ", siz = " << siz + 1 << endl;

            // cout << "l = " << l << endl;

            // cout << "siz = " << siz << endl;

            while(ll <= rr)

            {

                int mid = (ll + rr) / 2;

                ans = ask(mid, mid + siz);

                if(ans == k)

                {

                    ans = output(mid, mid + siz);

                    return;

                }

                if((ans > k && !f) || (ans < k && f))

                {

                    ll = mid + 1;

                }

                else

                {

                    rr = mid - 1;

                }

            }

        }

    }

    else // approx 17 more queries = 35

    {

        l = ans2, r = n;

        // cout << "l = " << l << ", r = " << r << endl;

        while(l <= r)

        {

            int mid = (l + r) >> 1;

            // cout << "mid = " << mid << endl;

            ans = ask(ans2, mid);

            // cout << "[" << ans2 << ", " << mid << "]" << endl;

            if(ans == k)

            {

                ans = output(ans2, mid);

                return;

            }

            if(ans == k + 1)

            {

                ans = output(ans2 + 1, mid);

                return;

            }

            if(ans < k)

            {

                l = mid + 1;

            }

            else

            {

                r = mid - 1;

            }

        }

        assert(false);

    }

}



int32_t main() 

{

    auto begin = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int t = 1;

    cin >> t;

    for(int i = 1; i <= t; i++) 

    {

        //cout << "Case #" << i << ": ";

        Solve();

    }

    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 

    return 0;

}
