using ll = long long;
const ll MOD = 1e9 + 7;

struct Mat {
    ll a[2][2];
};

Mat multiply(Mat x, Mat y) {
    Mat res = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return res;
}

Mat power(Mat base, int exp) {
    Mat res{{{1, 0}, {0, 1}}};
    while (exp) {
        if (exp % 2 == 1) res = multiply(res, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}

class Solution {
public:
    int numOfWays(int n) {
        Mat m{{{3, 2}, {2, 2}}};
        Mat exp_m = power(m, n - 1);
        ll a = (exp_m.a[0][0] * 6 + exp_m.a[0][1] * 6) % MOD;
        ll b = (exp_m.a[1][0] * 6 + exp_m.a[1][1] * 6) % MOD;
        return (a + b) % MOD;
    }
};