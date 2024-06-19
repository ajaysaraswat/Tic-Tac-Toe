#include <iostream>
using namespace std;

void printPattern(int n)
{
    char ch = 'A';
    int rowLength;

    if (n % 2 == 0)
    {
        // N is even
        rowLength = 4; // Start with 4 characters in the first row
    }
    else
    {
        // N is odd
        rowLength = 3; // Start with 3 characters in the first row
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < rowLength && ch <= 'Z'; j++)
        {
            cout << ch++;
        }
        cout << endl;

        // Adjust the row length for the next row
        if (n % 2 == 0)
        {
            // For even N, alternate row lengths between 4 and 3, starting with 4
            rowLength = (rowLength == 4) ? 3 : 4;
        }
        else
        {
            // For odd N, alternate row lengths between 3 and 2, starting with 3
            rowLength = (rowLength == 3) ? 2 : 3;
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
