#include <iostream>
#include <stdlib.h>
using namespace std;

int findSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num & 1 == 1)
            count++;
        num >>= 1;
    }
    return count;
}

int findNoOfTriplets(int A[], int na, int B[], int nb, int C[], int nc)
{
    int noOfTriplet = 0;
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            for (int k = 0; k < nc; k++)
            {
                int num = A[i] ^ B[j] ^ C[k];
                if ((findSetBits(num)) % 2 == 0)
                    noOfTriplet++;
            }
        }
    }
    return noOfTriplet;
}

int main()
{
    int a[3] = {1, 2, 3};
    int b[2] = {4, 5};
    int c[2] = {6, 7};
    int no = findNoOfTriplets(a, 3, b, 2, c, 2);
    cout << no;
    return no;
}