#include <iostream>
using namespace std;

int main() {
    string data, stuffed = "";
    int count = 0;

    cout << "Enter data: ";
    cin >> data;

    for (int i = 0; i < data.length(); i++) {

        stuffed += data[i];

        if (data[i] == '1') {
            count++;

            // After 5 consecutive 1s, insert 0
            if (count == 5) {
                stuffed += '0';
                count = 0;
            }
        }
        else {
            count = 0;
        }
    }

    cout << "Original Data : " << data << endl;
    cout << "Stuffed Data  : " << stuffed << endl;

    return 0;
}