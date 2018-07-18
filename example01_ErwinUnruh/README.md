# example1_ErwinUnruh

This is supposedly the first ever template meta program, written by Erwin Unruh in 1994.
Note that it doesn't actually compile - the prime numbers were printed as part of the error message.

I can't get this to work, but I guess it's heavily reliant on what information the compiler gives
as part of an error message which is not part of the standard.

It's supposed to print out the following error message:

    main.cpp 30: conversion from enum to D<2> requested in Prime_print
    main.cpp 30: conversion from enum to D<3> requested in Prime_print
    main.cpp 30: conversion from enum to D<5> requested in Prime_print
    main.cpp 30: conversion from enum to D<7> requested in Prime_print
    main.cpp 30: conversion from enum to D<11> requested in Prime_print
    main.cpp 30: conversion from enum to D<13> requested in Prime_print
    main.cpp 30: conversion from enum to D<17> requested in Prime_print
    main.cpp 30: conversion from enum to D<19> requested in Prime_print
