class Solution {
public:
    string getHappyString(int n, int k) {
        string str = "";
        int rank = 0;
        solve(str, rank, n, k);

        return str;
    }

private:
    bool solve(string &curr_str, int &curr_rank, int n, int k) {
        if (curr_str.size() == n) {
            curr_rank++;
            if (curr_rank == k) {
                return true;
            }
            return false;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (!curr_str.empty() && curr_str.back() == c)
                continue;

            curr_str.push_back(c);
            if (solve(curr_str, curr_rank, n, k)) {
                return true;
            }
            curr_str.pop_back();
        }
        
        // curr_str = "";
        return false;
    }
};