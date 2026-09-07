#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    cout << "Enter IP Address: ";
    cin >> a >> b >> c >> d;

    cout << "IP Address: "
         << a << "." << b << "." << c << "." << d << endl;

    if (a >= 1 && a <= 126)
        cout << "Class A";
    else if (a >= 128 && a <= 191)
        cout << "Class B";
    else if (a >= 192 && a <= 223)
        cout << "Class C";
    else if (a >= 224 && a <= 239)
        cout << "Class D";
    else if (a >= 240 && a <= 255)
        cout << "Class E";
    else
        cout << "Invalid IP Address";

    return 0;
}