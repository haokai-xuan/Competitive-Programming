class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ((n % 2 && n != 1) || n <= 0)
            return false;
        if (n <= 2)
            return true;
        
        return isPowerOfTwo(n / 2);
    }
};