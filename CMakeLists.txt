cmake_minimum_required(VERSION 3.17)
project(DualShock4)

set(CMAKE_CXX_STANDARD 20)

add_executable(DualShock4 main.cpp DualShock4.cpp DualShock4.h DataPacket/DataPacket.h DataPacket/ZeroType.h DataPacket/Definitions.h DataPacket/FingerType.h DataPacket/FingerPairType.h)