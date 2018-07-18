#include "fibonacci.h"
#include <catch.hpp>

/*
 * Even though the "fibonacci()" function is constexpr, the compiler doesn't actually evaluate
 * the result at compile time. The performance is (currently) the same as niaive recursion.
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

/*
 *These are assigned to constexpr, so are forced to be evaluated at compile time
 */
// SCENARIO( "Test with 2" ) { constexpr unsigned long long value=fibonacci(2);  CHECK( value ==1u ); }
// SCENARIO( "Test with 3" ) { constexpr unsigned long long value=fibonacci(3);  CHECK( value ==2u ); }
// SCENARIO( "Test with 4" ) { constexpr unsigned long long value=fibonacci(4);  CHECK( value ==3u ); }
// SCENARIO( "Test with 5" ) { constexpr unsigned long long value=fibonacci(5);  CHECK( value ==5u ); }
// SCENARIO( "Test with 6" ) { constexpr unsigned long long value=fibonacci(6);  CHECK( value ==8u ); }
// SCENARIO( "Test with 7" ) { constexpr unsigned long long value=fibonacci(7);  CHECK( value ==13u ); }
// SCENARIO( "Test with 8" ) { constexpr unsigned long long value=fibonacci(8);  CHECK( value ==21u ); }
// SCENARIO( "Test with 9" ) { constexpr unsigned long long value=fibonacci(9);  CHECK( value ==34u ); }
// SCENARIO( "Test with 10" ){ constexpr unsigned long long value=fibonacci(10); CHECK( value ==55u ); }
// SCENARIO( "Test with 11" ){ constexpr unsigned long long value=fibonacci(11); CHECK( value ==89u ); }
// SCENARIO( "Test with 12" ){ constexpr unsigned long long value=fibonacci(12); CHECK( value ==144u ); }
// SCENARIO( "Test with 13" ){ constexpr unsigned long long value=fibonacci(13); CHECK( value ==233u ); }
// SCENARIO( "Test with 14" ){ constexpr unsigned long long value=fibonacci(14); CHECK( value ==377u ); }
// SCENARIO( "Test with 15" ){ constexpr unsigned long long value=fibonacci(15); CHECK( value ==610u ); }
// SCENARIO( "Test with 16" ){ constexpr unsigned long long value=fibonacci(16); CHECK( value ==987u ); }
// SCENARIO( "Test with 17" ){ constexpr unsigned long long value=fibonacci(17); CHECK( value ==1597u ); }
// SCENARIO( "Test with 18" ){ constexpr unsigned long long value=fibonacci(18); CHECK( value ==2584u ); }
// SCENARIO( "Test with 19" ){ constexpr unsigned long long value=fibonacci(19); CHECK( value ==4181u ); }
// SCENARIO( "Test with 20" ){ constexpr unsigned long long value=fibonacci(20); CHECK( value ==6765u ); }
// SCENARIO( "Test with 21" ){ constexpr unsigned long long value=fibonacci(21); CHECK( value ==10946u ); }
// SCENARIO( "Test with 22" ){ constexpr unsigned long long value=fibonacci(22); CHECK( value ==17711u ); }
// SCENARIO( "Test with 23" ){ constexpr unsigned long long value=fibonacci(23); CHECK( value ==28657u ); }
// SCENARIO( "Test with 24" ){ constexpr unsigned long long value=fibonacci(24); CHECK( value ==46368u ); }
// SCENARIO( "Test with 25" ){ constexpr unsigned long long value=fibonacci(25); CHECK( value ==75025u ); }
// SCENARIO( "Test with 26" ){ constexpr unsigned long long value=fibonacci(26); CHECK( value ==121393u ); }
// SCENARIO( "Test with 27" ){ constexpr unsigned long long value=fibonacci(27); CHECK( value ==196418u ); }
// SCENARIO( "Test with 28" ){ constexpr unsigned long long value=fibonacci(28); CHECK( value ==317811u ); }
// SCENARIO( "Test with 29" ){ constexpr unsigned long long value=fibonacci(29); CHECK( value ==514229u ); }
// SCENARIO( "Test with 30" ){ constexpr unsigned long long value=fibonacci(30); CHECK( value ==832040u ); }
// SCENARIO( "Test with 31" ){ constexpr unsigned long long value=fibonacci(31); CHECK( value ==1346269u ); }
// SCENARIO( "Test with 32" ){ constexpr unsigned long long value=fibonacci(32); CHECK( value ==2178309u ); }
// SCENARIO( "Test with 33" ){ constexpr unsigned long long value=fibonacci(33); CHECK( value ==3524578u ); }
// SCENARIO( "Test with 34" ){ constexpr unsigned long long value=fibonacci(34); CHECK( value ==5702887u ); }
// SCENARIO( "Test with 35" ){ constexpr unsigned long long value=fibonacci(35); CHECK( value ==9227465u ); }
// SCENARIO( "Test with 36" ){ constexpr unsigned long long value=fibonacci(36); CHECK( value ==14930352u ); }
// SCENARIO( "Test with 37" ){ constexpr unsigned long long value=fibonacci(37); CHECK( value ==24157817u ); }
// SCENARIO( "Test with 38" ){ constexpr unsigned long long value=fibonacci(38); CHECK( value ==39088169u ); }
// SCENARIO( "Test with 39" ){ constexpr unsigned long long value=fibonacci(39); CHECK( value ==63245986u ); }
// SCENARIO( "Test with 40" ){ constexpr unsigned long long value=fibonacci(40); CHECK( value ==102334155u ); }
// SCENARIO( "Test with 41" ){ constexpr unsigned long long value=fibonacci(41); CHECK( value ==165580141u ); }
// SCENARIO( "Test with 42" ){ constexpr unsigned long long value=fibonacci(42); CHECK( value ==267914296u ); }
// SCENARIO( "Test with 43" ){ constexpr unsigned long long value=fibonacci(43); CHECK( value ==433494437u ); }
// SCENARIO( "Test with 44" ){ constexpr unsigned long long value=fibonacci(44); CHECK( value ==701408733u ); }
// SCENARIO( "Test with 45" ){ constexpr unsigned long long value=fibonacci(45); CHECK( value ==1134903170u ); }
// SCENARIO( "Test with 46" ){ constexpr unsigned long long value=fibonacci(46); CHECK( value ==1836311903u ); }
// SCENARIO( "Test with 47" ){ constexpr unsigned long long value=fibonacci(47); CHECK( value ==2971215073u ); }
// SCENARIO( "Test with 48" ){ constexpr unsigned long long value=fibonacci(48); CHECK( value ==4807526976u ); }
// SCENARIO( "Test with 49" ){ constexpr unsigned long long value=fibonacci(49); CHECK( value ==7778742049u ); }
// SCENARIO( "Test with 50" ){ constexpr unsigned long long value=fibonacci(50); CHECK( value ==12586269025u ); }
// SCENARIO( "Test with 51" ){ constexpr unsigned long long value=fibonacci(51); CHECK( value ==20365011074u ); }
// SCENARIO( "Test with 52" ){ constexpr unsigned long long value=fibonacci(52); CHECK( value ==32951280099u ); }
// SCENARIO( "Test with 53" ){ constexpr unsigned long long value=fibonacci(53); CHECK( value ==53316291173u ); }
// SCENARIO( "Test with 54" ){ constexpr unsigned long long value=fibonacci(54); CHECK( value ==86267571272u ); }
// SCENARIO( "Test with 55" ){ constexpr unsigned long long value=fibonacci(55); CHECK( value ==139583862445u ); }
// SCENARIO( "Test with 56" ){ constexpr unsigned long long value=fibonacci(56); CHECK( value ==225851433717u ); }
// SCENARIO( "Test with 57" ){ constexpr unsigned long long value=fibonacci(57); CHECK( value ==365435296162u ); }
// SCENARIO( "Test with 58" ){ constexpr unsigned long long value=fibonacci(58); CHECK( value ==591286729879u ); }
// SCENARIO( "Test with 59" ){ constexpr unsigned long long value=fibonacci(59); CHECK( value ==956722026041u ); }
// SCENARIO( "Test with 60" ){ constexpr unsigned long long value=fibonacci(60); CHECK( value ==1548008755920u ); }
// SCENARIO( "Test with 61" ){ constexpr unsigned long long value=fibonacci(61); CHECK( value ==2504730781961u ); }
// SCENARIO( "Test with 62" ){ constexpr unsigned long long value=fibonacci(62); CHECK( value ==4052739537881u ); }
// SCENARIO( "Test with 63" ){ constexpr unsigned long long value=fibonacci(63); CHECK( value ==6557470319842u ); }
// SCENARIO( "Test with 64" ){ constexpr unsigned long long value=fibonacci(64); CHECK( value ==10610209857723u ); }
// SCENARIO( "Test with 65" ){ constexpr unsigned long long value=fibonacci(65); CHECK( value ==17167680177565u ); }
// SCENARIO( "Test with 66" ){ constexpr unsigned long long value=fibonacci(66); CHECK( value ==27777890035288u ); }
// SCENARIO( "Test with 67" ){ constexpr unsigned long long value=fibonacci(67); CHECK( value ==44945570212853u ); }
// SCENARIO( "Test with 68" ){ constexpr unsigned long long value=fibonacci(68); CHECK( value ==72723460248141u ); }
// SCENARIO( "Test with 69" ){ constexpr unsigned long long value=fibonacci(69); CHECK( value ==117669030460994u ); }
// SCENARIO( "Test with 70" ){ constexpr unsigned long long value=fibonacci(70); CHECK( value ==190392490709135u ); }
// SCENARIO( "Test with 71" ){ constexpr unsigned long long value=fibonacci(71); CHECK( value ==308061521170129u ); }
// SCENARIO( "Test with 72" ){ constexpr unsigned long long value=fibonacci(72); CHECK( value ==498454011879264u ); }
// SCENARIO( "Test with 73" ){ constexpr unsigned long long value=fibonacci(73); CHECK( value ==806515533049393u ); }
// SCENARIO( "Test with 74" ){ constexpr unsigned long long value=fibonacci(74); CHECK( value ==1304969544928657u ); }
// SCENARIO( "Test with 75" ){ constexpr unsigned long long value=fibonacci(75); CHECK( value ==2111485077978050u ); }
// SCENARIO( "Test with 76" ){ constexpr unsigned long long value=fibonacci(76); CHECK( value ==3416454622906707u ); }
// SCENARIO( "Test with 77" ){ constexpr unsigned long long value=fibonacci(77); CHECK( value ==5527939700884757u ); }
// SCENARIO( "Test with 78" ){ constexpr unsigned long long value=fibonacci(78); CHECK( value ==8944394323791464u ); }
// SCENARIO( "Test with 79" ){ constexpr unsigned long long value=fibonacci(79); CHECK( value ==14472334024676221u ); }
// SCENARIO( "Test with 80" ){ constexpr unsigned long long value=fibonacci(80); CHECK( value ==23416728348467685u ); }
// SCENARIO( "Test with 81" ){ constexpr unsigned long long value=fibonacci(81); CHECK( value ==37889062373143906u ); }
// SCENARIO( "Test with 82" ){ constexpr unsigned long long value=fibonacci(82); CHECK( value ==61305790721611591u ); }
// SCENARIO( "Test with 83" ){ constexpr unsigned long long value=fibonacci(83); CHECK( value ==99194853094755497u ); }
// SCENARIO( "Test with 84" ){ constexpr unsigned long long value=fibonacci(84); CHECK( value ==160500643816367088u ); }
// SCENARIO( "Test with 85" ){ constexpr unsigned long long value=fibonacci(85); CHECK( value ==259695496911122585u ); }
// SCENARIO( "Test with 86" ){ constexpr unsigned long long value=fibonacci(86); CHECK( value ==420196140727489673u ); }
// SCENARIO( "Test with 87" ){ constexpr unsigned long long value=fibonacci(87); CHECK( value ==679891637638612258u ); }
// SCENARIO( "Test with 88" ){ constexpr unsigned long long value=fibonacci(88); CHECK( value ==1100087778366101931u ); }
// SCENARIO( "Test with 89" ){ constexpr unsigned long long value=fibonacci(89); CHECK( value ==1779979416004714189u ); }
// SCENARIO( "Test with 90" ){ constexpr unsigned long long value=fibonacci(90); CHECK( value ==2880067194370816120u ); }
// SCENARIO( "Test with 91" ){ constexpr unsigned long long value=fibonacci(91); CHECK( value ==4660046610375530309u ); }
// SCENARIO( "Test with 92" ){ constexpr unsigned long long value=fibonacci(92); CHECK( value ==7540113804746346429u ); }
// SCENARIO( "Test with 93" ){ constexpr unsigned long long value=fibonacci(93); CHECK( value ==12200160415121876738u ); }
