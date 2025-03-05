/*
 * AccGyroSensor.h
 *
 *  Created on: 05.02.2024
 *      Author: lescher
 */

#ifndef SRC_ACCGYROSENSOR_H_
#define SRC_ACCGYROSENSOR_H_

#include "IKS01A3Motion.h"

class AccGyroSensor {
private:
	const uint32_t INSTANCE = 0;
	const uint32_t FUNCTION_INIT_ACC_GYRO = MOTION_ACCELERO | MOTION_GYRO;
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;
	const uint32_t FUNCTION_GYRO = MOTION_GYRO;


public:
	AccGyroSensor();
	virtual ~AccGyroSensor();

	void initSensor(void);
	void updateValues(void);
	void setZero(void);

	IKS01A3_Motion Gyro;
	IKS01A3_Motion Accelero;
};

#endif /* SRC_ACCGYROSENSOR_H_ */
