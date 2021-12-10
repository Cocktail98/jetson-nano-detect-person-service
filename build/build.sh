#!/bin/sh

printf "[INFO] make clean ..."
make clean
printf "\n[INFO] make clean finished ..."

printf "\n[INFO] Generate gRPC ..."
cd ..
sh gen_grpc.sh
# shellcheck disable=SC2164
cd build
printf "\n[INFO] Generate gRPC finished ..."

cmake -DCMAKE_BUILD_TYPE=Release ..

printf "\n[INFO] Using %d cores to build ...\n\n" "$(nproc)"

cmake --build . -j"$(nproc)"
printf "\n[INFO] Build finished ...\n\n"
