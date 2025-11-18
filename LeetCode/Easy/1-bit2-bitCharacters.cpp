class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size() - 1; i++) {
            if (bits[i] && i < bits.size() - 2) {
                i++;
            }
            else if (bits[i] && i == bits.size() - 2) return false;
        }
        return true;
    }
};