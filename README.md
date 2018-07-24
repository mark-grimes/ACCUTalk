# Bristol ACCU talk

All the code used in my [talk to the Bristol ACCU](https://www.meetup.com/ACCU-Bristol/events/250408251/)
meetup on 18/Jul/2018. It's all set up with Makefiles; I'm not a big fan of using them directly but
it was the simplest way to set up such small snippets of code.

## Docker container to build examples

There is a Dockerfile to build the docker image I used in the `docker` subdirectory. If you'd like
to use it you can build with

    docker build -t accu ./docker

and then run with

    docker run --rm -it -v $PWD:/source:ro,consistent accu

The container will start in the directory `/work`, and all the code will be in the read only
directory `/source`. So you can build everything in the `/work` directory with

    make -f /source/Makefile

Note that the "consistent" option for the volume mount is important on non-linux hosts. Without it
I was getting clock skew between the container and host that made `make` think everything was up to
date when it wasn't.

**N.B.** When I came to try some c++17 examples I found that the compiler in the container doesn't have
the c++17 features required. So **the container won't build example08**. I should probably recreate the
container with a different compiler, but that's a lot of effort to support one example.

## Building natively

At least on Mac OS X with Xcode command line tools installed you can build with

    mkdir build
    cd build
    make -f ../ACCUTalk/Makefile

This will probably also work on most Linux systems. When building natively example08 will probably
compile (it does on the lates Xcode command line tools).
