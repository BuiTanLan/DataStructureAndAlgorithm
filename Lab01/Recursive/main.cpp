#include <iostream>
using namespace std;


//Cau 1:
int sumOfSquares(int n)
{
    if (n == 1)
        return 1;
    return sumOfSquares(n - 1) + n * n;
}


// Cau 2:
int gcd(int a, int b)
{
    if( b==0)
        return a;
    return gcd(b, a % b);
}

//Cau 3:
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    return 1;
}