#!/bin/bash

#printf "make clean ..."
#make clean
#printf "\n make clean finished ..."

printf "\n Generate gRPC ..."
cd ..
sh gen_grpc.sh
# shellcheck disable=SC2164
cd build
printf "\n Generate gRPC finished ..."

cmake -DCMAKE_BUILD_TYPE=Release ..

printf "\nUsing %d cores to build ...\n\n" "$(nproc)"

cmake --build . -j"$(nproc)"
printf "\nBuild finished ...\n\n"