#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>

using namespace std;
using variaveis = unordered_map<string, int>;

int main()
{
    int n;
    cin >> n;
    vector<string> code1(n);

    cin.ignore();

    for (int i = 0; i < n; i++)
        getline(cin, code1[i]);

    int m;
    cin >> m;
    vector<string> code2(m);

    cin.ignore();

    for (int i = 0; i < n; i++)
        getline(cin, code2[i]);

    if (n != m)
    {
        cout << "NO\n";
    }
    else
    {
        bool eh_igual (true);
        variaveis *lista = new variaveis[2];
        int contador = 0;
        for (int k = 0; k < n; k++)
        {
            istringstream lines1(code1[k]), lines2(code2[k]);
            string cmd1, cmd2;
            lines1 >> cmd1;
            lines2 >> cmd2;
            if (cmd1.find('+') != string::npos && cmd2.find('+') != string::npos)
            {
                char a[11], b[11], c[11], d[11], e[11], f[11];
                sscanf(cmd1.data(), "%[a-z]=%[a-z]+%[a-z]", a, b, c);
                sscanf(cmd2.data(), "%[a-z]=%[a-z]+%[a-z]", d, e, f);
                if (lista[0][string(a)] != lista[1][string(d)] || lista[0][string(b)] != lista[1][string(e)]
                || lista[0][string(c)] != lista[1][string(f)])
                {
                    eh_igual = false;
                    break;
                }
            }
            else if (cmd1 == cmd2)
            {
                    string a, b;
                    int c, d;

                    lines1 >> a;
                    lines2 >> b;

                    c = lista[0][a] - 1;
                    d = lista[1][b] - 1;

                    if (c == -1)
                    {
                        // cout << "lista0 = " << lista[0].size() << "\n";
                        c = lista[0].size() - 1;
                        lista[0][a] = lista[0].size();
                    }
                    if (d == -1)
                    {
                        // cout << "lista1 = " << lista[1].size() << "\n";
                        d = lista[1].size() - 1;
                        lista[1][b] = lista[1].size();
                    }
                    if (c != d)
                    {
                        eh_igual = false;
                        break;
                    }

                
            }
            else
            {
                eh_igual = false;
                break;
            }

        }
        if (eh_igual)
            cout << "YES\n";
        else
            cout << "NO\n";
        delete[] lista;
    }
    
    return 0;
}