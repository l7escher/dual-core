/*
 * IKS01A3Motion.h
 *
 *  Created on: 05.02.2024
 *      Author: lescher
 */

#ifndef SRC_IKS01A3MOTION_H_
#define SRC_IKS01A3MOTION_H_

#include "iks01a3_motion_sensors.h"
#include "util_ring_allocator.h"
#include <vector>
#include <numeric>




class IKS01A3_Motion {
private:
	IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
	IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;
	std::vector<int32_t, util::ring_allocator<int32_t>> RingBufferAxisX;
	std::vector<int32_t, util::ring_allocator<int32_t>> RingBufferAxisY;
	std::vector<int32_t, util::ring_allocator<int32_t>> RingBufferAxisZ;

	void getValue(uint32_t Instance, int32_t Function, int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis);


public:
	IKS01A3_Motion();
	virtual ~IKS01A3_Motion();

	void init(int32_t Instance, int32_t Function);
	void enable(int32_t Instance, int32_t Function);
	void setZero(void);
	void updateValues(int32_t Instance, int32_t Function);
	void getAVGValues(int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis);
};

#endif /* SRC_IKS01A3MOTION_H_ */
