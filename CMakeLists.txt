cmake_minimum_required(VERSION 3.6)
project(RestauranteFuturistico)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main/main.cpp Controller/Cardapio.h Model/Item.h Controller/HostessConect.h Controller/Cozinha.h Controller/Pedido.h)
add_executable(RestauranteFuturistico ${SOURCE_FILES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")


