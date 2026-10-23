#include<iostream>
using namespace std;
int main(){
    int h[8];
    cout<<"Enter 4  data bits : ";
    cin>>h[3]>>h[5]>>h[6]>>h[7];
    // calculate parity bit 
    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    cout<<"Hamming Code : ";
    for(int i = 1; i <= 7; i++){
        cout<<h[i];
    }

    cout<<endl;
    // Enter recieved seven bits
    cout<<"Enter recieved 7 bits : ";
    for(int i = 1; i <= 7; i++){
        cin>>h[i];
    }
    //calculate error position
    int p1 = h[1] ^ h[3] ^ h[5] ^ h[7];
    int p2 = h[2] ^ h[3] ^ h[6] ^ h[7];
    int p4 = h[4] ^ h[5] ^ h[6] ^ h[7];

    int error = p4 * 4 + p2 * 2 + p1;
    if(error == 0){ cout<<"No error detected "<<endl;
    }
    else{
        cout<<"Error at position : "<< error <<endl;
        //corrected errorh

        h[error] = h[error] ^ 1;
        cout<< "corrected code: ";
        for(int i = 1; i <= 7; i++){
            cout<<h[i];

        }
        cout<<endl;
    }

    return 0;
}