class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            vector<int> v;
            int target = dig_sum({stoi(s)});
            int num = check_magic(i, target, s, v);
            ans += num * num;
        }

        return ans;
    }

private:
    int check_magic(int n, int target, string s, vector<int> &partitions) {
        // check if at leaf and got answer
        if (target == dig_sum(partitions) && sum(partitions) == n) {
            return n;
        }

        for (int i = 0; i < s.size(); i++) {
            int prtn = stoi(s.substr(0, i + 1));
            string rest = s.substr(i + 1);
            partitions.push_back(prtn);
            if (check_magic(n, target, rest, partitions) == 0) {
                continue;
            }
            return n;
        }

        partitions.pop_back();
        return 0;
    }

    int sum(vector<int> &v) {
        int ans = 0;
        for (int i : v) {
            ans += i;
        }

        return ans;
    }

    int dig_sum(vector<int> v) {
        int ans = 0;
        for (int i : v) {
            while (i / 10) {
                ans += i % 10;
                i /= 10;
            }
            ans += i % 10;
        }

        return ans;
    }
};