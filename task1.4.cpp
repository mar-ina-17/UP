#include "iostream"

using namespace std;
int main(){
    int name_size;
    cin>>name_size;
    char* name= new char[name_size];
    int* code_name= new int[name_size];
    for(int i=0; i<name_size; i++){
        cin>>name[i];
        code_name[i]=int(name[i]);
    }
      for(int a=0; a<name_size; a++){
        cout<<code_name[a]<<" ";
        }
return 0;
}
