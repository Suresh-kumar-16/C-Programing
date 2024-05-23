#include <iostream>
#include <cmath>

// Returns gcd of a and b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Calculates modular inverse using extended Euclidean algorithm
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return -1; // Modular inverse doesn't exist
}

// Code to demonstrate RSA algorithm
int main() {
    // Two random prime numbers
    int p = 3;
    int q = 7;

    // First part of public key
    int n = p * q;

    // Finding other part of public key (e)
    int e = 2;
    int phi = (p - 1) * (q - 1);
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Private key (d)
    int d = modInverse(e, phi);

    // Message to be encrypted
    int msg = 12;
    std::cout << "Message data = " << msg << std::endl;

    // Encryption c = (msg ^ e) % n
    int c = pow(msg, e);
    c = c % n;
    std::cout << "Encrypted data = " << c << std::endl;

    // Decryption m = (c ^ d) % n
    int m = pow(c, d);
    m = m % n;
    std::cout << "Original Message Sent = " << m << std::endl;

    return 0;
}
