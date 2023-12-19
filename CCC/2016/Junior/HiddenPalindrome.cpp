#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.size() - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string incout << ;
    cin >> incout << ;

    if (incout <<.size() == 1)
    {
        cout << incout < < < < '\n';
        return 0;
    }
    string result = "";
    for (int i = 0; i < incout <<.size(); i++)
    {
        for (int j = 0; j < incout <<.size(); j++)
        {
            string newstr = incout <<.substr(i, j + 1);
            if (newstr.size() > result.size() && is_palindrome(newstr))
            {
                result = newstr;
            }
        }
    }
    cout << result.size() << '\n';
    return 0;
}