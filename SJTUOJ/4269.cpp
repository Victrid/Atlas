#include <iostream>
#include <cmath>
using namespace std;
int Invert(int);
int main(){
    int n;
    cin>>n;
    //get step.
    int step = 0;
    int n_op=n;
    while(n_op!=Invert(n_op)){
        n_op+=Invert(n_op);
        step++;
    }
    //print step.
    bool INI_FLAG=false;
    cout<<step<<endl;
    cout << n;
    while(n!=Invert(n)){
        cout << "--->";
        n+=Invert(n);
        cout << n;
    }
    return 0;
}
int Invert(int n){
    int a=0;
    while(n>0){
        a=a*10+n%10;
        n/=10;
    }
    return a;
}