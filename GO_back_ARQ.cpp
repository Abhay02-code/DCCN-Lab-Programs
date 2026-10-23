#include <iostream>
using namespace std;

int main() {
    int n, window, base = 1, ack;

    cout << "Enter number of frames and window size: ";
    cin >> n >> window;
    if (n <= 0 || window <= 0) return 0;

    while (base <= n) {
        int end = min(base + window - 1, n);

        cout << "\nSending frames: ";
        for (int i = base; i <= end; i++)
            cout << i << " ";

        cout << "\nEnter last in-order frame acknowledged";
        cout << " (" << base - 1 << "-" << end << "): ";
        cin >> ack;

        if (ack < base - 1 || ack > end) {
            cout << "Invalid ACK.\n";
            continue;
        }

        base = ack + 1;

        if (base <= end)
            cout << "Timeout! Going back to frame " << base << "\n";
        else
            cout << "All frames in this window acknowledged.\n";
    }

    cout << "\nAll frames transmitted successfully.";
    return 0;
}