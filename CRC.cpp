#include <iostream>
#include <string>
using namespace std;

int main() {
    string data, generator;
    cout << "Enter received data: ";
    cin >> data;
    cout << "Enter generator: ";
    cin >> generator;

    if (generator.size() < 2 || generator[0] != '1' ||
        data.size() < generator.size()) {
        cout << "Invalid input";
        return 0;
    }

    int n = data.size(), m = generator.size();

    for (int i = 0; i <= n - m; i++)
        if (data[i] == '1')
            for (int j = 0; j < m; j++)
                data[i+j] = (data[i+j] == generator[j]) ? '0' : '1';

    string remainder = data.substr(n - m + 1);
    cout << "Remainder: " << remainder << "\n";

    if (remainder.find('1') == string::npos)
        cout << "No error detected";
    else
        cout << "Error detected";

    return 0;
}