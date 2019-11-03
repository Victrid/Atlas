//not so beautiful

#include <iostream>
#include <cstring>
using namespace std;
void Printinvert(string &input,int printcount){
    if(printcount+1!=input.length())
    Printinvert(input,printcount+1);
    cout << input[printcount];
}
int main(){
    string n;
    string a;
    getline(cin,n);
    getline(cin,a);
    Printinvert(a,0);
    return 0;
}