#include <iostream>
using namespace std;

int main() {
    int n, ack;
    cout << "Enter number of frames: ";
    cin >> n;

    for (int i = 1; i <= n; ) {
        cout << "\nSending frame " << i;
        cout << "\nACK received? (1 = Yes, 0 = No): ";
        cin >> ack;

        if (ack == 1) {
            cout << "Frame " << i << " acknowledged.\n";
            i++;
        } else {
            cout << "Timeout! Retransmitting frame " << i << "\n";
        }
    }

    cout << "\nAll frames transmitted successfully.";
    return 0;
}