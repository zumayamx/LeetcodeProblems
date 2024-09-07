#include <iostream>
#include <vector>
using namespace std;

vector<int> fib_d(int n)
{
    if (n <= 1)
    {
        return {0};  // Caso base
    }

    vector<int> memo(n + 1);
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo;
}

void print_fibonacci(int n)
{
    vector<int> memo = fib_d(n);
    for (auto e : memo)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    print_fibonacci(n);
    return 0;
}