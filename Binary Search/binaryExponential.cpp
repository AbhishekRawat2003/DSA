#include<iostream>
using namespace std;

long long binaryExponential(long long base, long long exponent) {
    if (exponent == 0) return 1;
    long long half = binaryExponential(base, exponent / 2);
    if (exponent % 2 == 0) {
        return half * half;
    } else {
        return half * half * base;
    }
}

int main() {
    long long base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << "Result: " << binaryExponential(base, exponent) << endl;
    return 0;
}