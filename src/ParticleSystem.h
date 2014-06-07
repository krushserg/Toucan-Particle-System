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
#include "area.h"
#include "particle.h"

#include "randomizer.h"
#include "randomizer/uniformRandomizer.h"

#include "emitter.h"
#include "emitter/pointEmitter.h"
#include "emitter/lineEmitter.h"
#include "emitter/circleEmitter.h"

#include "affector.h"
#include "affector/baseAffector.h"
#include "affector/accelerationAffector.h"
#include "affector/angularAccelerationAffector.h"
#include "affector/velocityAffector.h"
#include "affector/deathAffector.h"
#include "affector/randomVelocityAffector.h"
#include "affector/randomAngularVelocityAffector.h"
#include "affector/randomSizeAffector.h"
#include "affector/randomAngleAffector.h"
#include "affector/randomTextureAffector.h"
#include "affector/randomColorAffector.h"
#include "affector/randomMaskAffector.h"
#include "affector/gravityAffector.h"
#include "affector/angleOnDirectionAffector.h"
#include "affector/colorFaderAffector.h"
