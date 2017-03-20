#include "lib/LSM303DLHC_Magnetometer.h"
#include "lib/LSM303DLHC_Accelerometer.h"
#include "lib/L3GD20H_Gyroscope.h"
#include <unistd.h>

int main() {
  const char* i2cDevice = "/dev/i2c-1";
  LSM303DLHC_Magnetometer mag(i2cDevice);
  lsm303DLHCMagData minMag;
  lsm303DLHCMagData maxMag;
  LSM303DLHC_Accelerometer acc(i2cDevice);
  L3GD20H_Gyroscope gyr(i2cDevice);

  gyr.begin();
  mag.begin();
  acc.begin();

  mag.read();
  minMag.x = maxMag.x = mag.raw.x;
  minMag.y = maxMag.y = mag.raw.y;
  minMag.z = maxMag.z = mag.raw.z;

  printf("| min(x)  | max(x)  | min(y)  | max(y)  | min(z)  | max(z)  ||");
  printf("         |         |         ||");
  printf("         |         |         |\n");
  while(1) {
    mag.read();
    if (mag.raw.x < minMag.x) {
      minMag.x = mag.raw.x;
    }
    if (mag.raw.x > maxMag.x) {
      maxMag.x = mag.raw.x;
    }
    if (mag.raw.y < minMag.y) {
      minMag.y = mag.raw.y;
    }
    if (mag.raw.y > maxMag.y) {
      maxMag.y = mag.raw.y;
    }
    if (mag.raw.z < minMag.z) {
      minMag.z = mag.raw.z;
    }
    if (mag.raw.z > maxMag.z) {
      maxMag.z = mag.raw.z;
    }
    acc.read();
    gyr.read();
    printf(
            "\r| %7d | %7d | %7d | %7d | %7d | %7d || %7d | %7d | %7d || %7d | %7d | %7d |",
            minMag.x, maxMag.x,
            minMag.y, maxMag.y,
            minMag.z, maxMag.z,
            acc.raw.x, acc.raw.y, acc.raw.z,
            gyr.raw.x, gyr.raw.y, gyr.raw.z
          );
    fflush(stdout);
    
    usleep(20*1000);
  }
  return 0;
}

