class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int size = pow(2, n) - 1;
        if (k == size / 2 + 1) return '1';

        if (k < size / 2 + 1) return findKthBit(n - 1, k);
        else return findKthBit(n - 1, (size / 2) - (k - (size / 2 + 1)) + 1) == '1' ? '0' : '1';
    }
};