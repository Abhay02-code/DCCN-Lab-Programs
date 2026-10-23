#include<iostream>
using namespace std;
int main(){
    int n, bit, count = 0;
    cout<<"Enter the number of bits: ";
    cin>>n;
    cout<<"Enter the data bits: ";
    for(int i = 0; i < n; i++){
        cin>>bit;
        if(bit == 1) count++;
    }
    int parity;
    cout<<"Enter parity bit : ";
    cin>>parity;
    

    if(parity == 1) count++;

    if(count % 2 == 0) cout<<"no error detected. ";
    else cout<<"single bit error detected";
    return 0;
}