#include "lib/LSM303DLHC_Magnetometer.h"
#include "lib/LSM303DLHC_Accelerometer.h"
#include "lib/L3GD20H_Gyroscope.h"
#include <unistd.h>

int main() {
  const char* i2cDevice = "/dev/i2c-1";
  LSM303DLHC_Magnetometer mag(i2cDevice);
  LSM303DLHC_Accelerometer acc(i2cDevice);
  L3GD20H_Gyroscope gyr(i2cDevice);

  gyr.begin();
  mag.begin();
  acc.begin();
  while(1) {
    mag.read();
    acc.read();
    gyr.read();
    printf(
            "compass: %7d %7d %7d\tacc: %7d %7d %7d\tgyr: %7d %7d %7d\n",
            mag.raw.x, mag.raw.y, mag.raw.z,
            acc.raw.x, acc.raw.y, acc.raw.z,
            gyr.raw.x, gyr.raw.y, gyr.raw.z
          );
    
    usleep(20*1000);
  }
  return 0;
}

