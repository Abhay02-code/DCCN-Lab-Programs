#include<iostream>
using namespace std;
int main(){
    int n, sum = 0, data;
    cout<<"Enter number of data blocks: ";
    cin>>n;
    cout<<"Enter data : ";
    for(int i = 0; i < n; i++){
        cin>>data;
        sum += data;
        if(sum > 255) sum = (sum & 255)+1;
    }
    int checksum = (~sum) & 255;
    cout<<"checksum: "<<checksum<<endl;
    //reciever side
    sum += checksum;
    if(sum>255) sum = (sum && 255)+1;
    if(sum == 255) cout<<"no error detected";
    else{
        cout<<"error detectyed";
    }
    return 0;
}