class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) {
            unordered_set<int> divisors;
            bool good = true;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    divisors.insert(i);
                    divisors.insert(num / i);
                }
                if (divisors.size() > 4) {
                    good = false;
                    break;
                }
            }
            if (!good || divisors.size() != 4) continue;
            int sum = accumulate(divisors.begin(), divisors.end(), 0);
            ans += sum;
        }
        return ans;
    }
};