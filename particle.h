#pragma once
namespace toucan
{
using namespace std;
struct Particle
{
    double position_x = 0;
    double position_y = 0;
    double velocity_x = 0;
    double velocity_y = 0;

    double angle = 0;
    double velocity_angular = 0;
};
}
