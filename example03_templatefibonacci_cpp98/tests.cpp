#include "fibonacci.h"
#include <catch.hpp>

SCENARIO( "Test with 0" )  { unsigned long long result=Fibonacci<0>::value;  CHECK( result==0u ); }
SCENARIO( "Test with 1" )  { unsigned long long result=Fibonacci<1>::value;  CHECK( result==1u ); }
SCENARIO( "Test with 2" )  { unsigned long long result=Fibonacci<2>::value;  CHECK( result==1u ); }
SCENARIO( "Test with 3" )  { unsigned long long result=Fibonacci<3>::value;  CHECK( result==2u ); }
SCENARIO( "Test with 4" )  { unsigned long long result=Fibonacci<4>::value;  CHECK( result==3u ); }
SCENARIO( "Test with 5" )  { unsigned long long result=Fibonacci<5>::value;  CHECK( result==5u ); }
SCENARIO( "Test with 6" )  { unsigned long long result=Fibonacci<6>::value;  CHECK( result==8u ); }
SCENARIO( "Test with 7" )  { unsigned long long result=Fibonacci<7>::value;  CHECK( result==13u ); }
SCENARIO( "Test with 8" )  { unsigned long long result=Fibonacci<8>::value;  CHECK( result==21u ); }
SCENARIO( "Test with 9" )  { unsigned long long result=Fibonacci<9>::value;  CHECK( result==34u ); }
SCENARIO( "Test with 10" ) { unsigned long long result=Fibonacci<10>::value; CHECK( result==55u ); }
SCENARIO( "Test with 11" ) { unsigned long long result=Fibonacci<11>::value; CHECK( result==89u ); }
SCENARIO( "Test with 12" ) { unsigned long long result=Fibonacci<12>::value; CHECK( result==144u ); }
SCENARIO( "Test with 13" ) { unsigned long long result=Fibonacci<13>::value; CHECK( result==233u ); }
SCENARIO( "Test with 14" ) { unsigned long long result=Fibonacci<14>::value; CHECK( result==377u ); }
SCENARIO( "Test with 15" ) { unsigned long long result=Fibonacci<15>::value; CHECK( result==610u ); }
SCENARIO( "Test with 16" ) { unsigned long long result=Fibonacci<16>::value; CHECK( result==987u ); }
SCENARIO( "Test with 17" ) { unsigned long long result=Fibonacci<17>::value; CHECK( result==1597u ); }
SCENARIO( "Test with 18" ) { unsigned long long result=Fibonacci<18>::value; CHECK( result==2584u ); }
SCENARIO( "Test with 19" ) { unsigned long long result=Fibonacci<19>::value; CHECK( result==4181u ); }
SCENARIO( "Test with 20" ) { unsigned long long result=Fibonacci<20>::value; CHECK( result==6765u ); }
SCENARIO( "Test with 21" ) { unsigned long long result=Fibonacci<21>::value; CHECK( result==10946u ); }
SCENARIO( "Test with 22" ) { unsigned long long result=Fibonacci<22>::value; CHECK( result==17711u ); }
SCENARIO( "Test with 23" ) { unsigned long long result=Fibonacci<23>::value; CHECK( result==28657u ); }
SCENARIO( "Test with 24" ) { unsigned long long result=Fibonacci<24>::value; CHECK( result==46368u ); }
SCENARIO( "Test with 25" ) { unsigned long long result=Fibonacci<25>::value; CHECK( result==75025u ); }
SCENARIO( "Test with 26" ) { unsigned long long result=Fibonacci<26>::value; CHECK( result==121393u ); }
SCENARIO( "Test with 27" ) { unsigned long long result=Fibonacci<27>::value; CHECK( result==196418u ); }
SCENARIO( "Test with 28" ) { unsigned long long result=Fibonacci<28>::value; CHECK( result==317811u ); }
SCENARIO( "Test with 29" ) { unsigned long long result=Fibonacci<29>::value; CHECK( result==514229u ); }
SCENARIO( "Test with 30" ) { unsigned long long result=Fibonacci<30>::value; CHECK( result==832040u ); }
SCENARIO( "Test with 31" ) { unsigned long long result=Fibonacci<31>::value; CHECK( result==1346269u ); }
SCENARIO( "Test with 32" ) { unsigned long long result=Fibonacci<32>::value; CHECK( result==2178309u ); }
SCENARIO( "Test with 33" ) { unsigned long long result=Fibonacci<33>::value; CHECK( result==3524578u ); }
SCENARIO( "Test with 34" ) { unsigned long long result=Fibonacci<34>::value; CHECK( result==5702887u ); }
SCENARIO( "Test with 35" ) { unsigned long long result=Fibonacci<35>::value; CHECK( result==9227465u ); }
SCENARIO( "Test with 36" ) { unsigned long long result=Fibonacci<36>::value; CHECK( result==14930352u ); }
SCENARIO( "Test with 37" ) { unsigned long long result=Fibonacci<37>::value; CHECK( result==24157817u ); }
SCENARIO( "Test with 38" ) { unsigned long long result=Fibonacci<38>::value; CHECK( result==39088169u ); }
SCENARIO( "Test with 39" ) { unsigned long long result=Fibonacci<39>::value; CHECK( result==63245986u ); }
SCENARIO( "Test with 40" ) { unsigned long long result=Fibonacci<40>::value; CHECK( result==102334155u ); }
SCENARIO( "Test with 41" ) { unsigned long long result=Fibonacci<41>::value; CHECK( result==165580141u ); }
SCENARIO( "Test with 42" ) { unsigned long long result=Fibonacci<42>::value; CHECK( result==267914296u ); }
SCENARIO( "Test with 43" ) { unsigned long long result=Fibonacci<43>::value; CHECK( result==433494437u ); }
SCENARIO( "Test with 44" ) { unsigned long long result=Fibonacci<44>::value; CHECK( result==701408733u ); }
SCENARIO( "Test with 45" ) { unsigned long long result=Fibonacci<45>::value; CHECK( result==1134903170u ); }
SCENARIO( "Test with 46" ) { unsigned long long result=Fibonacci<46>::value; CHECK( result==1836311903u ); }
SCENARIO( "Test with 47" ) { unsigned long long result=Fibonacci<47>::value; CHECK( result==2971215073u ); }
/* Only works as far as here for normal unsigned 32 bit integers (overflows) */
SCENARIO( "Test with 48" ) { unsigned long long result=Fibonacci<48>::value; CHECK( result==4807526976u ); }
SCENARIO( "Test with 49" ) { unsigned long long result=Fibonacci<49>::value; CHECK( result==7778742049u ); }
SCENARIO( "Test with 50" ) { unsigned long long result=Fibonacci<50>::value; CHECK( result==12586269025u ); }
SCENARIO( "Test with 51" ) { unsigned long long result=Fibonacci<51>::value; CHECK( result==20365011074u ); }
SCENARIO( "Test with 52" ) { unsigned long long result=Fibonacci<52>::value; CHECK( result==32951280099u ); }
SCENARIO( "Test with 53" ) { unsigned long long result=Fibonacci<53>::value; CHECK( result==53316291173u ); }
SCENARIO( "Test with 54" ) { unsigned long long result=Fibonacci<54>::value; CHECK( result==86267571272u ); }
SCENARIO( "Test with 55" ) { unsigned long long result=Fibonacci<55>::value; CHECK( result==139583862445u ); }
SCENARIO( "Test with 56" ) { unsigned long long result=Fibonacci<56>::value; CHECK( result==225851433717u ); }
SCENARIO( "Test with 57" ) { unsigned long long result=Fibonacci<57>::value; CHECK( result==365435296162u ); }
SCENARIO( "Test with 58" ) { unsigned long long result=Fibonacci<58>::value; CHECK( result==591286729879u ); }
SCENARIO( "Test with 59" ) { unsigned long long result=Fibonacci<59>::value; CHECK( result==956722026041u ); }
SCENARIO( "Test with 60" ) { unsigned long long result=Fibonacci<60>::value; CHECK( result==1548008755920u ); }
SCENARIO( "Test with 61" ) { unsigned long long result=Fibonacci<61>::value; CHECK( result==2504730781961u ); }
SCENARIO( "Test with 62" ) { unsigned long long result=Fibonacci<62>::value; CHECK( result==4052739537881u ); }
SCENARIO( "Test with 63" ) { unsigned long long result=Fibonacci<63>::value; CHECK( result==6557470319842u ); }
SCENARIO( "Test with 64" ) { unsigned long long result=Fibonacci<64>::value; CHECK( result==10610209857723u ); }
SCENARIO( "Test with 65" ) { unsigned long long result=Fibonacci<65>::value; CHECK( result==17167680177565u ); }
SCENARIO( "Test with 66" ) { unsigned long long result=Fibonacci<66>::value; CHECK( result==27777890035288u ); }
SCENARIO( "Test with 67" ) { unsigned long long result=Fibonacci<67>::value; CHECK( result==44945570212853u ); }
SCENARIO( "Test with 68" ) { unsigned long long result=Fibonacci<68>::value; CHECK( result==72723460248141u ); }
SCENARIO( "Test with 69" ) { unsigned long long result=Fibonacci<69>::value; CHECK( result==117669030460994u ); }
SCENARIO( "Test with 70" ) { unsigned long long result=Fibonacci<70>::value; CHECK( result==190392490709135u ); }
SCENARIO( "Test with 71" ) { unsigned long long result=Fibonacci<71>::value; CHECK( result==308061521170129u ); }
SCENARIO( "Test with 72" ) { unsigned long long result=Fibonacci<72>::value; CHECK( result==498454011879264u ); }
SCENARIO( "Test with 73" ) { unsigned long long result=Fibonacci<73>::value; CHECK( result==806515533049393u ); }
SCENARIO( "Test with 74" ) { unsigned long long result=Fibonacci<74>::value; CHECK( result==1304969544928657u ); }
SCENARIO( "Test with 75" ) { unsigned long long result=Fibonacci<75>::value; CHECK( result==2111485077978050u ); }
SCENARIO( "Test with 76" ) { unsigned long long result=Fibonacci<76>::value; CHECK( result==3416454622906707u ); }
SCENARIO( "Test with 77" ) { unsigned long long result=Fibonacci<77>::value; CHECK( result==5527939700884757u ); }
SCENARIO( "Test with 78" ) { unsigned long long result=Fibonacci<78>::value; CHECK( result==8944394323791464u ); }
SCENARIO( "Test with 79" ) { unsigned long long result=Fibonacci<79>::value; CHECK( result==14472334024676221u ); }
SCENARIO( "Test with 80" ) { unsigned long long result=Fibonacci<80>::value; CHECK( result==23416728348467685u ); }
SCENARIO( "Test with 81" ) { unsigned long long result=Fibonacci<81>::value; CHECK( result==37889062373143906u ); }
SCENARIO( "Test with 82" ) { unsigned long long result=Fibonacci<82>::value; CHECK( result==61305790721611591u ); }
SCENARIO( "Test with 83" ) { unsigned long long result=Fibonacci<83>::value; CHECK( result==99194853094755497u ); }
SCENARIO( "Test with 84" ) { unsigned long long result=Fibonacci<84>::value; CHECK( result==160500643816367088u ); }
SCENARIO( "Test with 85" ) { unsigned long long result=Fibonacci<85>::value; CHECK( result==259695496911122585u ); }
SCENARIO( "Test with 86" ) { unsigned long long result=Fibonacci<86>::value; CHECK( result==420196140727489673u ); }
SCENARIO( "Test with 87" ) { unsigned long long result=Fibonacci<87>::value; CHECK( result==679891637638612258u ); }
SCENARIO( "Test with 88" ) { unsigned long long result=Fibonacci<88>::value; CHECK( result==1100087778366101931u ); }
SCENARIO( "Test with 89" ) { unsigned long long result=Fibonacci<89>::value; CHECK( result==1779979416004714189u ); }
SCENARIO( "Test with 90" ) { unsigned long long result=Fibonacci<90>::value; CHECK( result==2880067194370816120u ); }
SCENARIO( "Test with 91" ) { unsigned long long result=Fibonacci<91>::value; CHECK( result==4660046610375530309u ); }
SCENARIO( "Test with 92" ) { unsigned long long result=Fibonacci<92>::value; CHECK( result==7540113804746346429u ); }
SCENARIO( "Test with 93" ) { unsigned long long result=Fibonacci<93>::value; CHECK( result==12200160415121876738u ); }
/* After this, 64 bit unsigned integers will overflow */
