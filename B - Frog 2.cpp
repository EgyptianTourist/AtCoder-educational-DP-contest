    /*
    name:       Egyptian Tourist
    PlatForm:   CodeForces/SPOJ...etc
    LANG:       C++
    DIV:        Training
    TIME:       *
    RATE:       *
    */
     
    /*
    Time Consumed:*
    Problem Topics: *
    */
    #include <bits/stdc++.h>
    #include <iostream>
     
    using namespace std;
    //----------------------------------//
     
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    typedef vector<int> vi;
     
    //-------------------------------------------------------//
    #define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
    #define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
    #define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
    #define lpr(i,n) for (int i = (n) - 1; ~i; i--)
    #define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
    //-------------------------------------------------------------------------------------//
     
    #define clr(ar, val) memset(ar, val, sizeof(ar))
    //----------------------------------------------//
     
    #define inn freopen("in.in","r",stdin)
    #define outt freopen("out.out","w",stdout)
    #define PI 3.1415926535897932385
    #define ll long long
    #define ull unsigned long long
    #define mp make_pair
    #define pb push_back
    #define pob pop_back
    #define bit(n) (1<<(n))
    #define Last(i) ( (i) & (-i) )
    #define all(v) ((v).begin()), ((v).end())
    #define sq(x) ((x) * (x))
    #define INF INT_MAX
    #define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     
    //-------------------------------------------------------------//
    #ifndef DEBUG
    #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1)
    {
        cerr << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args)
    {
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
    #else
    #define debug(...)
    #endif
    //------------------------------------------------------------//
    template<class T, class T2>
    T _f_pow(T a, T2 b)
    {
        T res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    #define N (int)1e5 + 5
    int _h[N];
    int dp[N];
    int n, k;
     
    int solve()
    {
        //printf("Solve(%d)\n", i);
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + abs(_h[i] - _h[i-1]);
            for(int _k = 1; _k <= k && _k < i; _k++)
                    dp[i] = min(dp[i], dp[i - _k] + abs(_h[i] - _h[i -_k]));
        }
        return dp[n];
    }
    int main()
    {
        Ios;
        //inn;//outt;
        //auto tt = clock();
        cin >> n >> k;
        rep(i, 1, n)
            cin >> _h[i];
    //    lp(i, n)
    //      printf("%d\t", _h[i]);
    //      system("pause 5");
        //clr(dp, -1);
        printf("%d\n", solve());
        //cout << (double(clock() - tt)/CLOCKS_PER_SEC * 1.00) << endl;
        return 0;
    }
