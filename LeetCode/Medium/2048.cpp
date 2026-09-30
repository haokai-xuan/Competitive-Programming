class Solution {
    bool isBeautiful(vector<int>& v) {
        for (int i = 0; i < 10; i++) {
            if (v[i] > 0 && i != v[i]) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        n++;
        while (true) {
            int temp = n;
            vector<int> v(10);
            while (temp) {
                v[temp % 10]++;
                temp /= 10;
            }

            if (isBeautiful(v))
                break;
            n++;
        }

        return n;
    }
};