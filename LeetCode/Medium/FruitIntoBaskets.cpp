class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;
            while (mp.size() > 2) {
                int type = fruits[left];
                mp[type]--;
                if (mp[type] <= 0)
                    mp.erase(type);

                left++;
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};