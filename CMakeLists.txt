cmake_minimum_required(VERSION 3.27)
project(P6)

set(CMAKE_CXX_STANDARD 23)

add_executable(P6 main.cpp
        Reisebuero.cpp
        Reisebuero.h
        Buchung.cpp
        Buchung.h
        HotelBuchung.cpp
        HotelBuchung.h
        FlugBuchung.cpp
        FlugBuchung.h
        Date.h
        Date.cpp
        Date.h)
