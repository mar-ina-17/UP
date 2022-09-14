#include "iostream"

using namespace std;
int main(){
    int age;
    bool isUnderage;
    cin>>age;
    if (age< 18) isUnderage= true;
    else isUnderage=false;
    cout<<"Am I underage? : "<<boolalpha<<isUnderage<<endl;
return 0;
}
