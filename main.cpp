#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "funkcje.h"

using namespace std;
int main()
{
	float x_rect;
	const int width = 1280;
	const int height = 720;

	sf::RenderWindow window(sf::VideoMode(width, height), "Gra");
	window.setFramerateLimit(60);

	 //player
	sf::Texture player;
	player.loadFromFile("statek.png");
	sf::Sprite sprite1;
	sprite1.setTexture(player);
	sprite1.setTextureRect(sf::IntRect(0, 0, 108, 126));
	//end of player

	//background
	sf::Texture texture;
	texture.loadFromFile("tlo.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
    //end of background

    //BORDER SQUARES FOR COLLISION DETECTION
	sf::RectangleShape r1(sf::Vector2f(100, height));
	r1.setPosition(-100, 0);
	sf::RectangleShape r2(sf::Vector2f(100, height));
	r2.setPosition(width, 0);
	sf::RectangleShape r3(sf::Vector2f(width, 3));
	r3.setPosition(0, -3);
	sf::RectangleShape r4(sf::Vector2f(width, 3));
	r4.setPosition(0, height+3);
	//END OF BORDER SQUARES

	//muzyka
	/*
	sf::Music music;
	if (!music.openFromFile("muzyka.ogg"))
		cout << "ERROR, nie mozna zaladowac muzyki.";
	music.play();
	*/


	//SPEED OF PLAYER MOVEMENT
	float moveSpeed = 800.0f;
    //END OF PLAYER MOVEMENT SPEED

	sf::Clock clock;


    //------MAIN GAME LOOP-------------
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			}
		}


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                   sprite1.move(moveSpeed * clock.getElapsedTime().asSeconds(), 0);
                    if (sprite1.getGlobalBounds().intersects(r2.getGlobalBounds()))
                        sprite1.move(-20.0, 0.0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    sprite1.move(-moveSpeed * clock.getElapsedTime().asSeconds(), 0);
                    if (sprite1.getGlobalBounds().intersects(r1.getGlobalBounds()))
                        sprite1.move(20.0, 0.0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sprite1.move(0 * clock.getElapsedTime().asSeconds(), -10);
                    if (sprite1.getGlobalBounds().intersects(r3.getGlobalBounds()))
                        sprite1.move(0.0, 20.0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sprite1.move(0 * clock.getElapsedTime().asSeconds(), 10);
                    if (sprite1.getGlobalBounds().intersects(r4.getGlobalBounds()))
                        sprite1.move(0.0, -20.0);
                }

		sf::Time time = clock.getElapsedTime();
		cout << 1.0f / time.asSeconds() << endl;
		clock.restart().asSeconds();


		// Draw it
		window.draw(r1);
		window.draw(sprite);
		window.draw(sprite1);
		window.display();
		window.clear();
	}
	return 0;
}


