// ЛР 8.1, варіант 6 (стандартні функції C++ для string).
// 1. Вияснити, чи є серед символів пара сусідніх букв "SQ" або "QS".
// 2. Замінити кожну пару сусідніх букв "SQ" або "QS" трійкою зірочок "***".

#include <iostream>
#include <string>

using namespace std;

// Повертає true, якщо пара символів (a, b) є "SQ" або "QS".
bool IsSQPair(char a, char b)
{
    return (a == 'S' && b == 'Q') || (a == 'Q' && b == 'S');
}

// Повертає true, якщо в рядку s є пара "SQ" або "QS" (за допомогою find).
bool HasSQPair(const string& s)
{
    return s.find("SQ") != string::npos || s.find("QS") != string::npos;
}

// Повертає новий рядок, у якому кожну пару "SQ" або "QS" замінено на "***"
// (за допомогою find_first_of та replace).
string ReplaceSQPairs(string s)
{
    size_t pos = 0;
    while ((pos = s.find_first_of("SQ", pos)) != string::npos)
    {
        if (pos + 1 < s.size() && IsSQPair(s[pos], s[pos + 1]))
        {
            s.replace(pos, 2, "***");
            pos += 3;
        }
        else
        {
            ++pos;
        }
    }
    return s;
}

#ifndef UNIT_TEST
int main()
{
    string input;

    cout << "Enter string: ";
    getline(cin, input);

    if (HasSQPair(input))
    {
        cout << "String contains pair \"SQ\" or \"QS\"." << endl;
    }
    else
    {
        cout << "String does not contain pair \"SQ\" or \"QS\"." << endl;
    }

    string modified = ReplaceSQPairs(input);
    cout << "Modified string: " << modified << endl;

    return 0;
}
#endif
