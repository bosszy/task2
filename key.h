#ifndef __KEY_H
#define __KEY_H

#include "sys.h"
#define WAUP PAin(0)
#define KEY0 PEin(4)
#define KEY1 PEin(3)

void KEY_Init(void);
u8 KEY_Scan(u8);

#endif



