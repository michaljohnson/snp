cmake_minimum_required(VERSION 3.28)
project(P02_Funktionen_Datentyp_enum C)

set(CMAKE_C_STANDARD 11)

add_executable(P02_Funktionen_Datentyp_enum
        work/tage-pro-monat/src/main.c
        work/wochentag-berechnung/src/main.c
        work/wochentag-berechnung/tests/tests.c)
