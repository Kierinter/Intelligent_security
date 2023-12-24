cmake_minimum_required(VERSION 3.25)
project(Intelligent_security C)
CC = arm-linux-gcc
AR = arm-linux-ar

main : main.o lcd.o
$(CC) -o main main.o lcd.o -lpthread -lm -L./lib -ljpeg -lfont -I./inc





set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(inc)

add_executable(Intelligent_security
inc/lcd.h)
