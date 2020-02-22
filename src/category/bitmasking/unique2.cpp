/**
 * Problem: All numbers occur twice expect two numbers which are unique.
 * 
 */
#include <iostream>
using namespace std;

int findFirstSetBit(int xo)
{
    int j = 0;
    while (xo != 0)
    {
        if (xo & 1)
        {
            return j;
        }
        xo = xo >> 1;
        j++;
    }
}

// Suppose arr = [1,5,3,2,6,3,1,2]
// So unique numbers are 5,6.
void findUnique2(int *arr, int n)
{
    int xo = 0;
    for (int i = 0; i < n; i++)
    {
        xo ^= arr[i];
    }
    // xo = 5^6.

    // finding 1st set bit (rightmost) because at that bit only one of the
    // two unique numbers have set bit.
    int pos = findFirstSetBit(xo);
    int num1 = 0;
    int mask = (1 << pos);

    // All numbers which has posth bit set.
    for (int i = 0; i < n; i++)
    {
        if (mask & arr[i])
        {
            num1 ^= arr[i];
        }
    }
    // num1 = 1^1^3^3^5 = 5
    //num2 = 5^5^6
    int num2 = num1 ^ xo;
    cout << num1 << " " << num2;
}

int main()
{
    int n;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findUnique2(arr, n);

    return 0;
}