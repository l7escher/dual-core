/*
 * AccGyroSensor.cpp
 *
 *  Created on: 05.02.2024
 *      Author: muaha
 */

#include <AccGyroSensor.h>

AccGyroSensor::AccGyroSensor() {
	// TODO Auto-generated constructor stub

}

AccGyroSensor::~AccGyroSensor() {
	// TODO Auto-generated destructor stub
}

void AccGyroSensor::initSensor(void) {
	AccGyroSensor::Gyro.init(INSTANCE, FUNCTION_INIT_ACC_GYRO);
}

void AccGyroSensor::updateValues(void) {
	AccGyroSensor::Gyro.updateValues(INSTANCE, FUNCTION_GYRO);
	AccGyroSensor::Accelero.updateValues(INSTANCE, FUNCTION_ACC);
}

void AccGyroSensor::setZero(void) {
	AccGyroSensor::Gyro.setZero();
	AccGyroSensor::Accelero.setZero();
}
