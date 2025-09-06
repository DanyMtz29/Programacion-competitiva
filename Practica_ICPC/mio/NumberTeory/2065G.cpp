#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 200001;

void primeSieve(vector<int> &primes)
{
    for (int i = 1; i <= N; i++)
        primes[i] = i;

    for (int i = 2; i <= N; i++)
        if (primes[i] == i)
            for (int j = i * i; j <= N; j += i)
                primes[j] = i;
}

vector<int> factors(int n, vector<int> &primes)
{
    vector<int> facts;
    while (n != 1)
    {
        facts.push_back(primes[n]);
        n /= primes[n];
    }
    return facts;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<int> primes(N + 1);
    primeSieve(primes);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        unordered_map<int, int> primos;
        unordered_map<int, vector<int>> semiPrimes;
        int count = 0;
        int countPrimes = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> facts = factors(arr[i], primes);
            if (facts.size() == 1)
            {
                if (semiPrimes.count(arr[i]))
                    count += semiPrimes[arr[i]].size();

                if (primos.count(arr[i]))
                    count += (countPrimes - primos[arr[i]]);
                else
                    count += countPrimes;
                primos[arr[i]]++;
                countPrimes++;
            }
            else if (facts.size() == 2)
            {
                count++;

                if (facts[0] != facts[1])
                {
                    if (primos.count(facts[1]))
                        count += (primos[facts[1]]);
                    semiPrimes[facts[1]].push_back(arr[i]);
                }

                if (primos.count(facts[0]))
                    count += (primos[facts[0]]);
                semiPrimes[facts[0]].push_back(arr[i]);
                if (primos.count(arr[i]))
                    count += primos[arr[i]];
                primos[arr[i]]++;
            }
        }
        cout << count << endl;
    }

    return 0;
}