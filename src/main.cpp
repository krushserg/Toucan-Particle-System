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
#include <iostream>

#include "ParticleSystem.h"
#include "drawer/SFMLdrawer.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
using namespace std;
using namespace toucan;

int main()
{

    Area area;
    //area affectors
    area.addAffector(make_shared<BaseAffector>(0, 500));
   // area.addAffector(make_shared<AngleOnDirectionAffector>());
/*
    shared_ptr<ColorFaderAffector> cf = make_shared<ColorFaderAffector>();
    cf->setMask(1);
    area.addAffector(cf);

    shared_ptr<RandomVelocityAffector> rv = make_shared<RandomVelocityAffector>(90, 150);

    shared_ptr<PointEmitter> pemmouse2 = make_shared<PointEmitter>();
    pemmouse2->particlesLifetime(1.3, 1.5);
    pemmouse2->particlesPerSecond(2000);

    pemmouse2->addAffector(rv);
    shared_ptr<RandomTextureAffector> randtext2 = make_shared<RandomTextureAffector>();
    randtext2->addCoords(32,32,32,32);
    pemmouse2->addAffector(randtext2);
    pemmouse2->addAffector(make_shared<RandomSizeAffector>(80, 120));
    shared_ptr<RandomColorAffector> randcolor2 = make_shared<RandomColorAffector>();
    randcolor2->addColor(35,5,0,255);
    //randcolor2->addColor(0,0,10,255);
    pemmouse2->addAffector(randcolor2);

    area.addEmitter(pemmouse2);


*/

    //shared_ptr<CircleEmitter> pemmouse = make_shared<CircleEmitter>();
    shared_ptr<PointEmitter> pemmouse = make_shared<PointEmitter>();
    pemmouse->particlesLifetime(0.1, 1);
    pemmouse->particlesPerSecond(10000);

    pemmouse->addAffector(make_shared<RandomVelocityAffector>(190, 350));
    pemmouse->addAffector(make_shared<RandomSizeAffector>(4, 20));
    pemmouse->addAffector(make_shared<RandomAngleAffector>());
    pemmouse->addAffector(make_shared<RandomAngularVelocityAffector>(-10,10));
    shared_ptr<RandomTextureAffector> randtext = make_shared<RandomTextureAffector>();
    randtext->addCoords(0,0,32,32);
    pemmouse->addAffector(randtext);
    shared_ptr<RandomColorAffector> randcolor = make_shared<RandomColorAffector>();
    randcolor->addColor(255,255,45,255);
    pemmouse->addAffector(randcolor);

    area.addEmitter(pemmouse);



    sf::RenderWindow window(sf::VideoMode(1000, 800), "particles test");
    sf::Texture texture;
    texture.loadFromFile("particle.png");

    shared_ptr<SFMLDrawer> particle_drawer = make_shared<SFMLDrawer>();
    area.setDrawer(particle_drawer);

   // window.setFramerateLimit(9);
    sf::Clock clock;
    double dt = 0;
    while (window.isOpen())
    {
        clock.restart();


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
            {
               // pemmouse->particlesPerSecond(10100);
                 pemmouse->setPosition(event.mouseMove.x, event.mouseMove.y);
                 //pemmouse2->setPosition(event.mouseMove.x, event.mouseMove.y);
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left);
                    window.capture().saveToFile("screen.png");

            }


        }
        area.step(dt);

        window.clear();


        sf::RenderStates rs;
        rs.blendMode = sf::BlendAdd;
        rs.texture  = &texture;
        particle_drawer->draw(window,rs);
        window.display();

        dt = clock.getElapsedTime().asSeconds();
    }
    return 0;
}

