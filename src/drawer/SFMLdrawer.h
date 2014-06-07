#pragma once
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
#include "drawer.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
namespace toucan
{
using namespace std;

class SFMLDrawer: public Drawer, public sf::Drawable
{
public:
    void clear()
    {
        data.clear();
    }
    void addParticle(const Particle& particle)
    {
        sf::Color color(particle.color[0], particle.color[1], particle.color[2], particle.color[3]);
        sf::Vector2f points[4];
        double s, c;
        sincos(particle.angle, &s, &c);

        points[0].x = particle.halfsize_x*c - particle.halfsize_y*s;
        points[0].y = particle.halfsize_x*s + particle.halfsize_y*c;
        points[1].x = particle.halfsize_x*c + particle.halfsize_y*s;
        points[1].y = particle.halfsize_x*s - particle.halfsize_y*c;
        points[2].x = -points[0].x;
        points[2].y = -points[0].y;
        points[3].x = -points[1].x;
        points[3].y = -points[1].y;
        for(int i=0;i<4;i++)
        {
            points[i].x += particle.position_x;
            points[i].y += particle.position_y;
        }
        data.push_back(sf::Vertex(points[0], color,\
                                  sf::Vector2f(particle.texcoord_x1, particle.texcoord_y1)));

        data.push_back(sf::Vertex(points[1], color,\
                                  sf::Vector2f(particle.texcoord_x2, particle.texcoord_y1)));

        data.push_back(sf::Vertex(points[2], color,\
                                  sf::Vector2f(particle.texcoord_x2, particle.texcoord_y2)));

        data.push_back(sf::Vertex(points[3], color,\
                                  sf::Vector2f(particle.texcoord_x1, particle.texcoord_y2)));
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const
    {
        target.draw(data.data(), data.size(), sf::PrimitiveType::Quads, states);
    }


private:
    vector<sf::Vertex> data;
};

}
