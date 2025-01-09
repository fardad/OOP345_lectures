#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

typedef unsigned long long ull;

void sum( promise<ull>&& sum_prom, ull beg, ull end ) {
   ull sum = 0, i;
   for ( i = beg; i <= end; sum += i, i++ );
   sum_prom.set_value( sum );
}

using clk = std::chrono::steady_clock;
int main( ) {
   auto st = clk::now( );
   ull beg = 0, end = 12312312311;
   ull sm = 0;
   for ( ull i = beg; i <= end; sm += i, i++ );
   cout << sm << endl;
   auto en = clk::now( );
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(en - st);
   cout << duration << endl;

   promise<ull> sumPromise;
   future<ull> sumFuture = sumPromise.get_future( );
   promise<ull> sumPromise2;
   future<ull> sumFuture2 = sumPromise2.get_future( );
   promise<ull> sumPromise3;
   future<ull> sumFuture3 = sumPromise3.get_future( );
   promise<ull> sumPromise4;
   future<ull> sumFuture4 = sumPromise4.get_future( );


   st = clk::now( );
   ull chunk = end / 4;
   thread t1( sum, move( sumPromise ), beg, chunk );
   thread t2( sum, move( sumPromise2 ), chunk + 1, chunk * 2 );
   thread t3( sum, move( sumPromise3 ), chunk * 2 + 1, chunk * 3 );
   thread t4( sum, move( sumPromise4 ), chunk * 3 + 1, end );


   cout << "Math is being done!" << endl;
   cout << "the Sum is: " << sumFuture.get( ) + sumFuture2.get( ) + sumFuture3.get( ) + sumFuture4.get( ) << endl;
   cout << "Done!" << endl;
   t1.join( );
   t2.join( );
   t3.join( );
   t4.join( );
   en = clk::now( );
   duration = std::chrono::duration_cast<std::chrono::milliseconds>(en - st);
   cout << duration << endl;
   return 0;
}
