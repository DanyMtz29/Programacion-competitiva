#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void show(int mask)
{
    for (int i = 31; i >= 0; i--)
    {
        if ((mask >> i) & 1)
            cout << "1 ";
        else
            cout << "0 ";
    }
    cout << "" << endl;
}

int longestPalindromeReorderableSubstring(const string &s)
{
    unordered_map<int, int> firstPos;
    firstPos[0] = -1; // caso especial: prefijo completo desde el inicio

    int mask = 0;
    int maxLen = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        int bit = s[i] - 'a';
        cout << "Letra: " << s[i] << endl;
        cout << "Bit: " << s[i] - 'a' << endl;
        mask ^= (1 << bit); // alterna la paridad de la letra actual

        show(mask);

        // Caso 1: el mismo patrón de máscara ya fue visto
        if (firstPos.count(mask))
        {
            cout << "Entra" << endl;
            cout << "Valor de i: " << i << endl;
            cout << "Valor de firstPos: " << firstPos[mask] << endl;
            cout << "MaxLen: " << maxLen << endl;
            maxLen = max(maxLen, i - firstPos[mask]);
        }
        else
        {
            firstPos[mask] = i;
        }

        cout << endl;
        // Caso 2: probar permitir una sola letra con frecuencia impar
        for (int j = 0; j < 26; ++j)
        {
            int testMask = mask ^ (1 << j);

            // cout << "TestMask j: " << j << endl;
            //  show(testMask);

            if (firstPos.count(testMask))
            {
                cout << "Entra en test" << endl;
                cout << "Valor de i: " << i << endl;
                cout << "Valor de firstPos: " << firstPos[testMask] << endl;
                cout << "MaxLen: " << maxLen << endl;
                maxLen = max(maxLen, i - firstPos[testMask]);
                cout << "Max: " << maxLen << endl;
            }
        }
    }

    return maxLen;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindromeReorderableSubstring(s) << endl;
    return 0;
}
