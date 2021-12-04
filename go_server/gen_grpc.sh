#!/bin/bash

# 生成 Detect 的代码
protoc --go_out=. --go_opt=paths=source_relative \
--go-grpc_out=. --go-grpc_opt=paths=source_relative \
--grpc-gateway_out=. --grpc-gateway_opt=paths=source_relative \
api/detect/v1/detect.proto

printf "-- Generate 'detect.proto' finished\n"
