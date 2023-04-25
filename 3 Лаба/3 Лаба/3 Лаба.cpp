#include <iostream>
#include "Time.h"

// Lab 3. Operations overloading

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");
    Time a;
    Time b(1, 45);

    cin >> a;

    Time sum = a + b;

    cout << a << " + " << b << " = " << sum << endl;

    cout << "a == b : " << (a == b);
}