#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int key[2][2];
    string message, text, encrypted;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter 2x2 key matrix:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> key[i][j];

    for (unsigned char ch : message)
        if (isalpha(ch))
            text += toupper(ch);

    if (text.size() % 2) text += 'X';

    for (int i = 0; i < text.size(); i += 2) {
        int a = text[i] - 'A', b = text[i + 1] - 'A';

        int x = (key[0][0] * a + key[0][1] * b) % 26;
        int y = (key[1][0] * a + key[1][1] * b) % 26;

        encrypted += char((x + 26) % 26 + 'A');
        encrypted += char((y + 26) % 26 + 'A');
    }

    cout << "Encrypted message: " << encrypted;
    return 0;
}