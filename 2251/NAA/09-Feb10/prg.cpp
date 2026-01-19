#include <iostream>
#include <vector>
using namespace std;
int main( ) {
   bool* flag = nullptr;
   cout << (flag == nullptr ? "flag is null" : "flag is not null") 
        << endl;
   initializePointer( flag );
   cout << (flag == nullptr ? 
               "flag is still null" : 
               "flag is no longer null"
           ) << endl;
}