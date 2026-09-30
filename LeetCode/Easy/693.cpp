class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prevBitSet = n % 2 ? true : false;
        n >>= 1;
        while (n) {
            if ((prevBitSet && n % 2) || (!prevBitSet && n % 2 == 0)) return false;
            prevBitSet = !prevBitSet;
            n >>= 1;
        }
        return true;
    }
};