#include <bits/stdc++.h>
using namespace std;

int calculateSteps(int forward, int backward)
{
    if (forward <= backward)
        return forward;
    return backward + backward - forward;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nForward, nBackward, bForward, bBackward, step;
    cin >> nForward >> nBackward >> bForward >> bBackward >> step;

    int stepBack = step;

    // process Nikky case
    int loopCount = 0;
    while (step >= (nForward + nBackward))
    {
        loopCount = loopCount + 1;
        step = step - (nForward + nBackward);
    }
    int nSteps = 0;
    if (step > 0)
        nSteps = calculateSteps(step, nForward);
    nSteps += (nForward - nBackward) * loopCount;

    // process Byron case
    step = stepBack;
    loopCount = 0;

    while (step >= (bForward + bBackward))
    {
        loopCount = loopCount + 1;
        step = step - (bForward + bBackward);
    }

    int bSteps = 0;
    if (step > 0)
        bSteps = calculateSteps(step, bForward);

    bSteps += (bForward - bBackward) * loopCount;

    if (bSteps > nSteps)
        cout << "Byron" << '\n';
    else if (bSteps == nSteps)
        cout << "Tied" << '\n';
    else
        cout << "Nikky" << '\n';
    return 0;
}