#include <bits/stdc++.h>
#define int long long int
using namespace std;

void transform(int sum)
{
    int hours = sum / 3600000;
    sum %= 3600000;
    if (hours >= 10)
        cout << hours;
    else
        cout << "0" << hours;
    cout << ":";
    int minutes = sum / 60000;
    sum %= 60000;
    if (minutes >= 10)
        cout << minutes;
    else
        cout << "0" << minutes;
    cout << ":";
    int seconds = sum / 1000;
    sum %= 1000;
    if (seconds >= 10)
        cout << seconds;
    else
        cout << "0" << seconds;

    cout << ",";

    if (sum < 100)
    {
        cout << "0";
        if (sum < 10)
            cout << "0" << sum;
        else
            cout << sum;
    }
    else
        cout << sum;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;

    string added;
    getline(cin, added);
    int ad = ((added[1] - '0') * 1000) + ((added[3] - '0') * 100) + ((added[4] - '0') * 10) + (added[5] - '0');

    // fflush(stdin);
    string s;
    // getline(cin, s);
    fflush(stdin);
    while (getline(cin, s))
    {
        if (s.length() == 29 && s[2] == ':' && s[13] == '-' && s[15] == '>')
        {
            int sum1 = 0;
            sum1 += (((s[0] - '0') * 10) + (s[1] - '0')) * (3600000);
            sum1 += (((s[3] - '0') * 10) + (s[4] - '0')) * (60000);
            sum1 += (((s[6] - '0') * 10) + (s[7] - '0')) * (1000);
            sum1 += ((s[9] - '0') * 100) + ((s[10] - '0') * 10) + (s[11] - '0');

            int sum2 = 0;
            sum2 += (((s[17] - '0') * 10) + (s[18] - '0')) * (3600000);
            sum2 += (((s[20] - '0') * 10) + (s[21] - '0')) * (60000);
            sum2 += (((s[23] - '0') * 10) + (s[24] - '0')) * (1000);
            sum2 += ((s[26] - '0') * 100) + ((s[27] - '0') * 10) + (s[28] - '0');

            int res = sum2 - sum1;
            sum1 += ad;
            transform(sum1);
            cout << " --> ";
            transform(sum1 + res);
            cout << endl;
        }
        else
        {
            cout << s << endl;
        }
        fflush(stdin);
    }

    return 0;
}