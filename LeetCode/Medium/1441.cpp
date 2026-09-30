class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {        
        vector<string> ans;
        int ti = 0;
        int stream = 1;
        while (ti < target.size()) {
            if (target[ti] == stream) {
                ans.push_back("Push");
                ti++;
                stream++;
            }
            else {
                int diff = target[ti] - stream;
                for (int i = 0; i < diff; i++) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
                ans.push_back("Push");
                stream = target[ti] + 1;
                ti++;
            }
        }
        return ans;
    }
};