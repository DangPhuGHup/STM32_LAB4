/*
 * traffic_light.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"

enum led {red, green, yellow, black};

void light_1(enum led color);
void light_2(enum led color);

#endif /* INC_TRAFFIC_LIGHT_H_ */
