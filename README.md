# cpp-ahrs
Pluggable Altitude and Heading Reference System.

## Compiling

    g++ -I. bin/test.cpp lib/LSM303DLHC_Magnetometer.cpp lib/LSM303DLHC_Accelerometer.cpp lib/I2CBus.cpp --std=c++0x
