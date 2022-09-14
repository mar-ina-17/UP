#include "iostream"

using namespace std;
int main(){
    int i=1;
    int counter=0;
    do{
        if(i%2==0) cout<<i<<endl;
        i++;
        counter++;
    }while(i<40);
    return 0;
}
