#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void generateFibonacci(int n) {
    cout << "Fibonacci Series up to " << n << " terms: ";
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cout<<"Enter the numnber of terms you want to generate in fibonacci series:"<<endl;
    cin>>num;
    generateFibonacci(num);
    return 0;
}