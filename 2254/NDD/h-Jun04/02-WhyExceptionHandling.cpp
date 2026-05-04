#include <iostream>
using namespace std;

int main( ) {
   try {
      openWebServiceConnection( );
      getSIN( );
      closeWebSericeConnection( );
      openDataBase( );
      retrieveSinINfo( );
      closeDataBse( );
      displayInformation( );
   }
   catch ( webServExcp e ) {

   }
   catch ( badSinExcep e ) {

   }
   catch(exception e ) {

   }
   return 0;
}