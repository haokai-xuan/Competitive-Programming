#include <bits/stdc++.h>
using namespace std;

bool isWinning(string s, int t)
{
    int score[4] = {0, 0, 0, 0};
    if (s[0] == 'W')
    {
        score[0] += 3;
    }
    else if (s[0] == 'L')
    {
        score[1] += 3;
    }
    else
    {
        score[0]++;
        score[1]++;
    }

    if (s[1] == 'W')
    {
        score[0] += 3;
    }
    else if (s[1] == 'L')
    {
        score[2] += 3;
    }
    else
    {
        score[0]++;
        score[2]++;
    }

    if (s[2] == 'W')
    {
        score[0] += 3;
    }
    else if (s[2] == 'L')
    {
        score[3] += 3;
    }
    else
    {
        score[0]++;
        score[3]++;
    }

    if (s[3] == 'W')
    {
        score[1] += 3;
    }
    else if (s[3] == 'L')
    {
        score[2] += 3;
    }
    else
    {
        score[1]++;
        score[2]++;
    }

    if (s[4] == 'W')
    {
        score[1] += 3;
    }
    else if (s[4] == 'L')
    {
        score[3] += 3;
    }
    else
    {
        score[1]++;
        score[3]++;
    }

    if (s[5] == 'W')
    {
        score[2] += 3;
    }
    else if (s[5] == 'L')
    {
        score[3] += 3;
    }
    else
    {
        score[2]++;
        score[3]++;
    }

    if (score[t] == *max_element(score, score + 4) && count(score, score + 4, *max_element(score, score + 4)) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, g;
    cin >> t >> g;

    t -= 1; // fav

    string original = "------"; // 0-1, 0-2, 0-3, 1-2, 1-3, 2-3
    for (int i = 0; i < g; i++)
    {
        int team1, team2;
        cin >> team1 >> team2;
        team1 -= 1;
        team2 -= 1;

        int score1, score2;
        cin >> score1 >> score2;

        char letter;

        if (score1 > score2)
        {
            letter = 'W';
        }
        else if (score1 < score2)
        {
            letter = 'L';
        }
        else
        {
            letter = 'T';
        }

        if (team1 == 0 && team2 == 1)
        {
            original = letter + original.substr(1);
        }
        else if (team1 == 0 && team2 == 2)
        {
            original = original.substr(0, 1) + letter + original.substr(2);
        }
        else if (team1 == 0 && team2 == 3)
        {
            original = original.substr(0, 2) + letter + original.substr(3);
        }
        else if (team1 == 1 && team2 == 2)
        {
            original = original.substr(0, 3) + letter + original.substr(4);
        }
        else if (team1 == 1 && team2 == 3)
        {
            original = original.substr(0, 4) + letter + original.substr(5);
        }
        else if (team1 == 2 && team2 == 3)
        {
            original = original.substr(0, 5) + letter;
        }
    }

    // cout << original << '\n';

    string choice = "WLT";
    vector<string> possible;
    vector<int> combination;

    for (int i = 0; i < 6; i++)
    {
        if (original[i] == '-')
        {
            combination.push_back(3); // not played
        }
        else
        {
            combination.push_back(1); // played
        }
    }

    for (int a = 0; a < combination[0]; a++)
    {
        for (int b = 0; b < combination[1]; b++)
        {
            for (int c = 0; c < combination[2]; c++)
            {
                for (int d = 0; d < combination[3]; d++)
                {
                    for (int e = 0; e < combination[4]; e++)
                    {
                        for (int f = 0; f < combination[5]; f++)
                        {
                            string s;
                            if (combination[0] == 1)
                            {
                                s = s + original[0];
                                // cout << "game 1 played, possible outcome: " << s << '\n';
                            }
                            else
                            {
                                s = s + choice[a];
                                // cout << "game 1 not played, possible outcome: " << s << '\n';
                            }
                            if (combination[1] == 1)
                            {
                                s = s + original[1];
                                // cout << "game 2 played, possible outcome: " << s << '\n';
                            }
                            else
                            {
                                s = s + choice[b];
                                // cout << "game 2 not played, possible outcome: " << s << '\n';
                            }
                            if (combination[2] == 1)
                            {
                                s = s + original[2];
                                // cout << "game 3 played, possible outcome: " << s << '\n';
                            }
                            else
                            {
                                s = s + choice[c];
                                // cout << "game 3 not played, possible outcome: " << s << '\n';
                            }
                            if (combination[3] == 1)
                            {
                                s = s + original[3];
                                // cout << "game 4 played, possible outcome: " << s << '\n';
                            }
                            else
                            {
                                s = s + choice[d];
                                // cout << "game 4 not played, possible outcome: " << s << '\n';
                            }
                            if (combination[4] == 1)
                            {
                                s = s + original[4];
                                // cout << "game 5 played, possible outcome: " << s << '\n';
                            }
                            else
                            {
                                s = s + choice[e];
                                // cout << "game 5 not played, possible outcome: " << s << '\n';
                            }
                            if (combination[5] == 1)
                            {
                                s = s + original[5];
                                // cout << "game 6 played, possible outcome: " << s << '\n';
                            }
                            else
                            {
                                s = s + choice[f];
                                // cout << "game 6 not played, possible outcome: " << s << '\n';
                            }
                            possible.push_back(s);
                        }
                    }
                }
            }
        }
    }

    int wins = 0;
    for (string s : possible)
    {
        if (isWinning(s, t))
        {
            wins++;
        }
    }

    cout << wins << '\n';

    return 0;
}