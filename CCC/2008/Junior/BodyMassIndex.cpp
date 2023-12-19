#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    float weight, height;
    cin >> weight >> height;

    float bmi = weight / (height * height);

    if (bmi > 25)
        cout << "Overweight" << '\n';
    else if (bmi < 18.5)
        cout << "Underweight" << '\n';
    else
        cout << "Normal weight" << '\n';

    return 0;
}