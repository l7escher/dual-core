/*
 * IKS01A3Motion.cpp
 *
 *  Created on: 05.02.2024
 *      Author: muaha
 */

#include "IKS01A3Motion.h"

IKS01A3_Motion::IKS01A3_Motion() {
	// TODO Auto-generated constructor stub
	AxisValues.x = 0;
	AxisValues.y = 0;
	AxisValues.z = 0;

	AxisOffsets.x = 0;
	AxisOffsets.y = 0;
	AxisOffsets.z = 0;

}

void IKS01A3_Motion::getValue(uint32_t Instance, int32_t Function,
		int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis) {
	IKS01A3_MOTION_SENSOR_GetAxes(Instance, Function, &AxisValues);
	*XAxis = AxisValues.x;
	*YAxis = AxisValues.y;
	*ZAxis = AxisValues.z;
}

IKS01A3_Motion::~IKS01A3_Motion() {
	// TODO Auto-generated destructor stub

}

void IKS01A3_Motion::init(int32_t Instance, int32_t Function) {
	IKS01A3_MOTION_SENSOR_Init(Instance, Function);
}

void IKS01A3_Motion::enable(int32_t Instance, int32_t Function) {
	IKS01A3_MOTION_SENSOR_Enable(Instance, Function);
}

void IKS01A3_Motion::setZero(void) {
	AxisOffsets.x = AxisOffsets.x - AxisValues.x;
	AxisOffsets.y = AxisOffsets.y - AxisValues.y;
	AxisOffsets.z = AxisOffsets.z - AxisValues.z;
}

void IKS01A3_Motion::updateValues(int32_t Instance, int32_t Function) {
	IKS01A3_MOTION_SENSOR_Axes_t CurrentAxis;

	IKS01A3_MOTION_SENSOR_GetAxes(Instance, Function, &CurrentAxis);
	if(RingBufferAxisX.size()>5){
		RingBufferAxisX.erase(RingBufferAxisX.begin());
	}

	if(RingBufferAxisY.size()>5){
		RingBufferAxisY.erase(RingBufferAxisY.begin());
	}

	if(RingBufferAxisZ.size()>5){
		RingBufferAxisZ.erase(RingBufferAxisZ.begin());
	}

	RingBufferAxisX.push_back(CurrentAxis.x);
	RingBufferAxisY.push_back(CurrentAxis.y);
	RingBufferAxisZ.push_back(CurrentAxis.z);

}

void IKS01A3_Motion::getAVGValues(int32_t *XAxis, int32_t *YAxis,
		int32_t *ZAxis) {
	//calculating AVG using Iterator
	int32_t sum = 0;
	for(auto iterator = RingBufferAxisX.cbegin(); iterator<RingBufferAxisX.cend(); iterator++){
		sum = sum + *iterator;
	}

	*XAxis = sum / RingBufferAxisX.size();
	//calculating AVG using std::accumulate
	*YAxis = std::accumulate(RingBufferAxisY.cbegin(), RingBufferAxisY.cend(), 0) / RingBufferAxisY.size();
	*ZAxis = std::accumulate(RingBufferAxisZ.cbegin(), RingBufferAxisZ.cend(), 0) / RingBufferAxisZ.size();


	*XAxis = *XAxis + AxisOffsets.x;
	*YAxis = *YAxis + AxisOffsets.y;
	*ZAxis = *ZAxis + AxisOffsets.z;

}
