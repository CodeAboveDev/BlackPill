/*****************************************************************
 * Copyright (c) 2020 CodeAbove.
 * All rights reserved.
 *
 * This software component is licensed by CodeAbove under
 * BSD 3-Clause license, the 'License'. You may not use
 * this file except in compliance with the License. You
 * may obtain a copy of the License at:
 *                  opensource.org/licenses/BSD-3-Claus
 ****************************************************************/
#ifndef Systick_H
#define Systick_H

#include <stdint.h>
#include <type_traits>

class Systick
{
public:


private:
    

};

static_assert(std::is_standard_layout<Systick>::value, "Systick class is NOT standard layout");

#endif // Systick_H