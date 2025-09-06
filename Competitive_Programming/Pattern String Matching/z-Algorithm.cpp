#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;



vector<int> zAlgorithm(vec &arr)
{
    vector<int> z(arr.size());
    int left = 0, right = 0;
    for (int k = 0; k < arr.size(); k++)
    {
        if (k > right) // Si no hubo coincidencias antes, hay que comparar
        {
            left = right = k;
            while (right < arr.size() && arr[right] == arr[right - left])
            {
                right++;
            }
            z[k] = right - left;
            right--;
        }
        else
        {
            int k1 = k - left; // Ver desde donde ya se comprobo
            if (z[k1] < right - k + 1)
            {
                z[k] = z[k1]; // Asignar automaticamente sin comprobar lo que ya se comprobo antes
            }
            else // EMpezar a comparar desde tal posiciones donde se quedo la comprobacion anterior
            {
                left = k;
                while (right < arr.size() && arr[right] == arr[right - left])
                {
                    right++;
                }
                z[k] = right - left;
                right--;
            }
        }
    }
    return z;
}

int buildArray(vec &a, vec &b)
{
    vec newArray(a.size() + 1 + b.size());
    int i = 0;
    for (int num : a)
    {
        newArray[i++] = num;
    }
    newArray[i++] = -1;

    for (int num : b)
    {
        newArray[i++] = num;
    }

    vec z = zAlgorithm(newArray);
    int count = 0;
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == a.size())
        {
            count++;
        }
    }
    return count;
}

int32_t main()
{
    vec a = {1, 1, 1};
    vec b = {1, 1, 1, 1, 1};
    cout << "Total matches: " << buildArray(a, b) << endl;
    return 0;
}