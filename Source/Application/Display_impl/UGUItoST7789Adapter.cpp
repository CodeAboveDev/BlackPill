/*****************************************************************
 * Copyright (c) 2021 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Clause
 ****************************************************************/
#include "UGUItoST7789Adapter.h"

ST7789* UGUItoST7789Adapter::pST7789 = nullptr;
DisplayBuffer<240,240> UGUItoST7789Adapter::db;
