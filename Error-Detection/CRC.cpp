#include <iostream>
using namespace std;

int main() {
    string data, key;

    cout << "Enter data: ";
    cin >> data;

    cout << "Enter generator: ";
    cin >> key;

    int n = data.length();
    int k = key.length();

    // Append zeros
    string temp = data;
    for (int i = 0; i < k - 1; i++)
        temp += '0';

    // CRC division
    for (int i = 0; i <= temp.length() - k; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < k; j++) {
                temp[i + j] =
                    (temp[i + j] == key[j]) ? '0' : '1';
            }
        }
    }

    // Get remainder
    string crc = temp.substr(n, k - 1);

    cout << "CRC: " << crc << endl;

    // Codeword
    string codeword = data + crc;
    cout << "Transmitted Data: " << codeword << endl;

    return 0;
}