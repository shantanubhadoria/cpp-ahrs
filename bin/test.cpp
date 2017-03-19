#include "lib/LSM303DLHC_Magnetometer.h"
#include "lib/LSM303DLHC_Accelerometer.h"

int main() {
  const char* i2cDevice = "/dev/i2c-1";
  LSM303DLHC_Magnetometer mag(i2cDevice);
  LSM303DLHC_Accelerometer acc(i2cDevice);
  mag.begin();
  acc.begin();
  while(1) {
    mag.read();
    printf("%7d %7d %7d \n",
            mag.raw.x, mag.raw.y, mag.raw.z
          );
    acc.read();
    printf("%7d %7d %7d \n",
            acc.raw.x, acc.raw.y, acc.raw.z
          );
  }
  return 0;
}

