#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    int m1, m2, m3, m4;
    char dot;


    cout << "Enter IP Address: ";
    cin >> a >> dot >>  b >> dot >> c >> dot >> d;

    cout<<"Enter Subnet Mask : ";
    cin>>m1>>dot>>m2>>dot>>m3>>dot>>m4;

    // find ip class

    if (a >= 0 && a <= 127)
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
    cout<<endl;

    //find network Address
    cout<<"Network Address: "
        <<(a&m1)<<"."
        <<(b&m2)<<"."
        <<(c&m3)<<"."
        <<(d&m4)<<"."<<endl;

    return 0;
}