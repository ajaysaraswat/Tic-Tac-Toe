#include <iostream>
using namespace std;

void printPattern(int n)
{
    int half = (n + 1) / 2;

    // Print the first half of the pattern
    for (int i = 1; i <= half; i++)
    {
        for (char ch = 'A'; ch < 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }

    // Print the second half of the pattern
    if (n % 2 == 0)
    {
        for (int i = half; i > 0; i--)
        {
            for (char ch = 'A'; ch < 'A' + i; ch++)
            {
                cout << ch;
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = half - 1; i > 0; i--)
        {
            for (char ch = 'A'; ch < 'A' + i; ch++)
            {
                cout << ch;
            }
            cout << endl;
        }
    }
}

int main()
{
    int n;

    // Ask the user to enter the value of N
    cout << "Enter the value of N: ";
    cin >> n;

    // Print the pattern
    printPattern(n);

    return 0;
}
