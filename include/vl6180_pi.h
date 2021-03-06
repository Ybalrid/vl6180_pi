#ifndef VL6180_PI_INCLUDED
#define VL6180_PI_INCLUDED

#ifdef __cplusplus
extern "C"{
#else 
#include <stdbool.h>
#endif 

typedef int vl6180;

#define VL6180_DEFAULT_ADDR 0x29

///Initialize a vl6180 sensor on the i2c bus configured at the specified address
/// \param device The I2C bus to open. e.g. "1" for using /dev/i2c-1
/// \param i2c_addr addres of the device. If you don't know, just call the "vl6180_initialise" variant of this function.
/// \return handle to the sensor. Keep this variable to talk to the sensor via the library
vl6180 vl6180_initialise_address(int device, int i2c_addr);

///Initialise a vl6180 sensor at it's default address
/// \param device The I2C bus to open. e.g. "1" for using /dev/i2c-1
/// \return handle to the sensor. Keep this variable to talk to the sensor via the library
vl6180 vl6180_initialise(int device);
  
///Change the address of the device. Needed if you have an address conflict (for example: using two of theses sensors on the same design). The handle will also be updated
/// \param handle The handle to the sensor given by vl6180_initialise
/// \param new_addr The new address to use on the i2c bus for this device
void vl6180_change_addr(vl6180 handle, int new_addr);

//TODO some of theses functions doesn't have the vl6180 prefix. udpate them to avoid name clashing
  
///Return the current distance as readed by the sensor
/// \param handle The handle to the sensor given by vl6180_initialise
/// \return distance in milimeter as an integer
int get_distance(vl6180 handle);

///Set the scalinb mode (read datasheet to seee about the max range vs. precision deal on this sensor)
/// \param handle The handle to the sensor given by vl6180_initialise
/// \param scaling Index of the scaling mode to use
void set_scaling(vl6180 handle, int scaling);

///Start range measurement. You need to wait until vl6180_is_range_available starts returning true
///To get the value, use vl6180_read_distance_result
/// \param handle The handle to the sensor given by vl6180_initialise
void vl6180_start_range(vl6180 handle);

///Return true if measurement is available after calling vl6180_start_range
/// \param handle The handle to the sensor given by vl6180_initialise
bool vl6180_is_range_available(vl6180 handle);

///Return the measured value according to the current scalling after vl6180_start_range has been called
/// \param handle The handle to the sensor given by vl6180_initialise
int vl6180_read_distance_result(vl6180 handle);


#ifdef __cplusplus
}
#endif
#endif
