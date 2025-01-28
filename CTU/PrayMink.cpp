#include <iostream>
using namespace std;

// Problem statement:
//   https://contest.felk.cvut.cz/24prg/solved/mink/problem.pdf

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

string remove_leading_zeros(string s)
{
    int i = 0;
    while (s[i] == '0') {
        i++;
    }

    return s.substr(i);
}

unordered_map<string, int> memo;

int max_primes(string &s)
{
    if (s.empty())
    {
        return 0;
    }

    else if (memo.find(s) != memo.end())
    {
        return memo[s];
    }

    int ans = 0;
    int num = stoi(s);

    if (is_prime(num))
    {
        for (int i = 0; i < s.length(); i++)
        {
            string temp = s;
            temp.erase(temp.begin() + i);
            temp = remove_leading_zeros(temp);

            int num = temp.empty() ? 0 : stoi(temp);

            ans = max(ans, 1 + max_primes(temp));
        }
    }

    memo[s] = ans;
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << max_primes(s) << '\n';

    return 0;
}