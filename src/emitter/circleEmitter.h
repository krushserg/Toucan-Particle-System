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
#include "randomizer/uniformRandomizer.h"
#include <iostream>
namespace toucan
{
using namespace std;
class CircleEmitter : public Emitter
{
public:
    CircleEmitter()
        :CircleEmitter(0,0,1)
    {
    }

    CircleEmitter(double _x, double _y, double _radius, double _depth=0,\
                  double _min_angle = 0, double _max_angle = 2.*M_PI,\
                  shared_ptr<Randomizer> circle_randomizer = make_shared<UniformRandomizer>())
    {
        setPosition(_x, _y, _radius, _depth, _min_angle, _max_angle);
        _circle_randomizer = circle_randomizer;
    }
    void setPosition(double _x, double _y, double _radius, double _depth=0,\
                     double _min_angle = 0, double _max_angle = 2.*M_PI)
    {
        x= _x;
        y= _y;
        depth = _depth;
        radius=_radius;
        min_angle=_min_angle;
        max_angle=_max_angle;
    }

    Particle operator ()()
    {
        double angle = _circle_randomizer->get(min_angle, max_angle);
        double dep = _circle_randomizer->get(0, depth);
        Particle p;
        p.position_x = cos(angle)*(radius+dep) + x;
        p.position_y = sin(angle)*(radius+dep) + y;
        return p;
    }

private:
    double x = 0;
    double y = 0;
    double radius = 1;
    double depth = 0;
    double min_angle = 0;
    double max_angle = 2.*M_PI;
    shared_ptr<Randomizer> _circle_randomizer;
};
}
