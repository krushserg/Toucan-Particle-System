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
#include <cmath>
#include <iostream>
namespace toucan
{
using namespace std;
class LineEmitter : public Emitter
{
public:
    LineEmitter()
        :LineEmitter(0, 0, 1, 1)
    {
    }

    LineEmitter(double _px1, double _py1, double _px2, double _py2, \
                 shared_ptr<Randomizer> line_randomizer = make_shared<UniformRandomizer>())
    {
        setPosition(_px1, _py1, _px2, _py2);
        _line_randomizer = line_randomizer;
    }
    void setPosition(double _px1, double _py1, double _px2, double _py2)
    {
        x1 = _px1;
        y1 = _py1;
        x2 = _px2;
        y2 = _py2;
        distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        double angle = atan2(y1-y2, x1-x2);
        xkof = cos(angle);
        ykof = sin(angle);
    }

    Particle operator ()()
    {

        double pos = _line_randomizer->get(0, distance);

        Particle p;
        p.position_x =  x1 - pos*xkof;
        p.position_y =  y1 - pos*ykof;
        return p;
    }

private:
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    double distance = 0;
    double xkof = 0;
    double ykof = 0;
    shared_ptr<Randomizer> _line_randomizer;
};
}
