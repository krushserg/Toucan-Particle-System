/*
  Copyright (C) Sergey Rakhmanov

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#pragma once
#include "emitter.h"
#include <iostream>
namespace toucan
{
using namespace std;
class PointEmitter : public Emitter
{
public:
    PointEmitter()
        :PointEmitter(0, 0)
    {
    }

    PointEmitter(double _x, double _y)
    {
        setPosition(_x, _y);
    }
    void setPosition(double _x, double _y)
    {
        x= _x;
        y= _y;
    }

    Particle operator ()()
    {
        Particle p;
        p.position_x = x;
        p.position_y = y;
        return p;
    }

private:
    double x = 0;
    double y = 0;
};
}
