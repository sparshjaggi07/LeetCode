#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int MAX = 1e5 + 10;
    vector<long long> fact, invfact;

    Solution() {
        // Precompute factorials and inverse factorials
        fact.resize(MAX);
        invfact.resize(MAX);
        fact[0] = 1;
        for (int i = 1; i < MAX; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;
        invfact[MAX - 1] = modpow(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; --i)
            invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        long long choose = comb(n - 1, k);
        long long powerPart = modpow(m - 1, n - 1 - k);
        long long result = m * choose % MOD * powerPart % MOD;
        return result;
    }
};