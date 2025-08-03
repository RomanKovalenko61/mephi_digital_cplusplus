cmake_minimum_required(VERSION 3.31)
project(mephi_digital_cplusplus)

set(CMAKE_CXX_STANDARD 20)

add_executable(mephi_digital_cplusplus main.cpp
        include/SkiPass.h
        include/HavingCell.h
        include/IChangeable.h
        include/IReplenishable.h
        include/Timed.h
        src/Timed.cpp
        include/Unlimited.h
        src/Unlimited.cpp
        include/Limited.h
        src/Limited.cpp
        include/Service.h
        src/Service.cpp
        src/SkiPass.cpp
        include/Settings.h
        include/IRepo.h
        src/InMemoryRepo.cpp
        include/InMemoryRepo.h)
