#include "fibonacci.h"
#include <catch.hpp>

/*
 * All of these are coded up as separate scenarios, so that I can get the timing
 * with the "--durations yes" command line option.
 */
SCENARIO( "Test with 0" ) { CHECK( fibonacci(0) ==0u ); }
SCENARIO( "Test with 1" ) { CHECK( fibonacci(1) ==1u ); }
SCENARIO( "Test with 2" ) { CHECK( fibonacci(2) ==1u ); }
SCENARIO( "Test with 3" ) { CHECK( fibonacci(3) ==2u ); }
SCENARIO( "Test with 4" ) { CHECK( fibonacci(4) ==3u ); }
SCENARIO( "Test with 5" ) { CHECK( fibonacci(5) ==5u ); }
SCENARIO( "Test with 6" ) { CHECK( fibonacci(6) ==8u ); }
SCENARIO( "Test with 7" ) { CHECK( fibonacci(7) ==13u ); }
SCENARIO( "Test with 8" ) { CHECK( fibonacci(8) ==21u ); }
SCENARIO( "Test with 9" ) { CHECK( fibonacci(9) ==34u ); }
SCENARIO( "Test with 10" ){ CHECK( fibonacci(10)==55u ); }
SCENARIO( "Test with 11" ){ CHECK( fibonacci(11)==89u ); }
SCENARIO( "Test with 12" ){ CHECK( fibonacci(12)==144u ); }
SCENARIO( "Test with 13" ){ CHECK( fibonacci(13)==233u ); }
SCENARIO( "Test with 14" ){ CHECK( fibonacci(14)==377u ); }
SCENARIO( "Test with 15" ){ CHECK( fibonacci(15)==610u ); }
SCENARIO( "Test with 16" ){ CHECK( fibonacci(16)==987u ); }
SCENARIO( "Test with 17" ){ CHECK( fibonacci(17)==1597u ); }
SCENARIO( "Test with 18" ){ CHECK( fibonacci(18)==2584u ); }
SCENARIO( "Test with 19" ){ CHECK( fibonacci(19)==4181u ); }
SCENARIO( "Test with 20" ){ CHECK( fibonacci(20)==6765u ); }
SCENARIO( "Test with 21" ){ CHECK( fibonacci(21)==10946u ); }
SCENARIO( "Test with 22" ){ CHECK( fibonacci(22)==17711u ); }
SCENARIO( "Test with 23" ){ CHECK( fibonacci(23)==28657u ); }
SCENARIO( "Test with 24" ){ CHECK( fibonacci(24)==46368u ); }
SCENARIO( "Test with 25" ){ CHECK( fibonacci(25)==75025u ); }
SCENARIO( "Test with 26" ){ CHECK( fibonacci(26)==121393u ); }
SCENARIO( "Test with 27" ){ CHECK( fibonacci(27)==196418u ); }
SCENARIO( "Test with 28" ){ CHECK( fibonacci(28)==317811u ); }
SCENARIO( "Test with 29" ){ CHECK( fibonacci(29)==514229u ); }
SCENARIO( "Test with 30" ){ CHECK( fibonacci(30)==832040u ); }
SCENARIO( "Test with 31" ){ CHECK( fibonacci(31)==1346269u ); }
SCENARIO( "Test with 32" ){ CHECK( fibonacci(32)==2178309u ); }
SCENARIO( "Test with 33" ){ CHECK( fibonacci(33)==3524578u ); }
SCENARIO( "Test with 34" ){ CHECK( fibonacci(34)==5702887u ); }
SCENARIO( "Test with 35" ){ CHECK( fibonacci(35)==9227465u ); }
SCENARIO( "Test with 36" ){ CHECK( fibonacci(36)==14930352u ); }
SCENARIO( "Test with 37" ){ CHECK( fibonacci(37)==24157817u ); }
SCENARIO( "Test with 38" ){ CHECK( fibonacci(38)==39088169u ); }
SCENARIO( "Test with 39" ){ CHECK( fibonacci(39)==63245986u ); }
SCENARIO( "Test with 40" ){ CHECK( fibonacci(40)==102334155u ); }
SCENARIO( "Test with 41" ){ CHECK( fibonacci(41)==165580141u ); }
SCENARIO( "Test with 42" ){ CHECK( fibonacci(42)==267914296u ); }
SCENARIO( "Test with 43" ){ CHECK( fibonacci(43)==433494437u ); }
SCENARIO( "Test with 44" ){ CHECK( fibonacci(44)==701408733u ); }
SCENARIO( "Test with 45" ){ CHECK( fibonacci(45)==1134903170u ); }
SCENARIO( "Test with 46" ){ CHECK( fibonacci(46)==1836311903u ); }
SCENARIO( "Test with 47" ){ CHECK( fibonacci(47)==2971215073u ); }
SCENARIO( "Test with 48" ){ CHECK( fibonacci(48)==4807526976u ); }
SCENARIO( "Test with 49" ){ CHECK( fibonacci(49)==7778742049u ); }
SCENARIO( "Test with 50" ){ CHECK( fibonacci(50)==12586269025u ); }
SCENARIO( "Test with 51" ){ CHECK( fibonacci(51)==20365011074u ); }
SCENARIO( "Test with 52" ){ CHECK( fibonacci(52)==32951280099u ); }
SCENARIO( "Test with 53" ){ CHECK( fibonacci(53)==53316291173u ); }
SCENARIO( "Test with 54" ){ CHECK( fibonacci(54)==86267571272u ); }
SCENARIO( "Test with 55" ){ CHECK( fibonacci(55)==139583862445u ); }
SCENARIO( "Test with 56" ){ CHECK( fibonacci(56)==225851433717u ); }
SCENARIO( "Test with 57" ){ CHECK( fibonacci(57)==365435296162u ); }
SCENARIO( "Test with 58" ){ CHECK( fibonacci(58)==591286729879u ); }
SCENARIO( "Test with 59" ){ CHECK( fibonacci(59)==956722026041u ); }
SCENARIO( "Test with 60" ){ CHECK( fibonacci(60)==1548008755920u ); }
SCENARIO( "Test with 61" ){ CHECK( fibonacci(61)==2504730781961u ); }
SCENARIO( "Test with 62" ){ CHECK( fibonacci(62)==4052739537881u ); }
SCENARIO( "Test with 63" ){ CHECK( fibonacci(63)==6557470319842u ); }
SCENARIO( "Test with 64" ){ CHECK( fibonacci(64)==10610209857723u ); }
SCENARIO( "Test with 65" ){ CHECK( fibonacci(65)==17167680177565u ); }
SCENARIO( "Test with 66" ){ CHECK( fibonacci(66)==27777890035288u ); }
SCENARIO( "Test with 67" ){ CHECK( fibonacci(67)==44945570212853u ); }
SCENARIO( "Test with 68" ){ CHECK( fibonacci(68)==72723460248141u ); }
SCENARIO( "Test with 69" ){ CHECK( fibonacci(69)==117669030460994u ); }
SCENARIO( "Test with 70" ){ CHECK( fibonacci(70)==190392490709135u ); }
SCENARIO( "Test with 71" ){ CHECK( fibonacci(71)==308061521170129u ); }
SCENARIO( "Test with 72" ){ CHECK( fibonacci(72)==498454011879264u ); }
SCENARIO( "Test with 73" ){ CHECK( fibonacci(73)==806515533049393u ); }
SCENARIO( "Test with 74" ){ CHECK( fibonacci(74)==1304969544928657u ); }
SCENARIO( "Test with 75" ){ CHECK( fibonacci(75)==2111485077978050u ); }
SCENARIO( "Test with 76" ){ CHECK( fibonacci(76)==3416454622906707u ); }
SCENARIO( "Test with 77" ){ CHECK( fibonacci(77)==5527939700884757u ); }
SCENARIO( "Test with 78" ){ CHECK( fibonacci(78)==8944394323791464u ); }
SCENARIO( "Test with 79" ){ CHECK( fibonacci(79)==14472334024676221u ); }
SCENARIO( "Test with 80" ){ CHECK( fibonacci(80)==23416728348467685u ); }
SCENARIO( "Test with 81" ){ CHECK( fibonacci(81)==37889062373143906u ); }
SCENARIO( "Test with 82" ){ CHECK( fibonacci(82)==61305790721611591u ); }
SCENARIO( "Test with 83" ){ CHECK( fibonacci(83)==99194853094755497u ); }
SCENARIO( "Test with 84" ){ CHECK( fibonacci(84)==160500643816367088u ); }
SCENARIO( "Test with 85" ){ CHECK( fibonacci(85)==259695496911122585u ); }
SCENARIO( "Test with 86" ){ CHECK( fibonacci(86)==420196140727489673u ); }
SCENARIO( "Test with 87" ){ CHECK( fibonacci(87)==679891637638612258u ); }
SCENARIO( "Test with 88" ){ CHECK( fibonacci(88)==1100087778366101931u ); }
SCENARIO( "Test with 89" ){ CHECK( fibonacci(89)==1779979416004714189u ); }
SCENARIO( "Test with 90" ){ CHECK( fibonacci(90)==2880067194370816120u ); }
SCENARIO( "Test with 91" ){ CHECK( fibonacci(91)==4660046610375530309u ); }
SCENARIO( "Test with 92" ){ CHECK( fibonacci(92)==7540113804746346429u ); }
SCENARIO( "Test with 93" ){ CHECK( fibonacci(93)==12200160415121876738u ); }
