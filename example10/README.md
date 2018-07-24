# example10

Practical example of some compile time calculations. The main class is a "binner" that can be used
for grouping items together, e.g. as the basis for a histogram class. It can work in N-dimensions
(hence NDimensionalBinner).

The main purpose of this example (which I completely forgot while giving the talk) was to show how
slow it is to compile even simple code on constrained devices when using template libraries. I was
supposed to show how long it takes to compile this on a Raspberry Pi Zero, then show it on a laptop
with decent memory.
