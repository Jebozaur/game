#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "funkcje.h"
using namespace std;

void kwadraty(int w, int h)
{
    //KWADRATY GRANICZNE DO DETEKCJI KOLIZJI
	sf::RectangleShape r1(sf::Vector2f(100, h));
	r1.setPosition(-100, 0);
	sf::RectangleShape r2(sf::Vector2f(100, h));
	r2.setPosition(w, 0);
	sf::RectangleShape r3(sf::Vector2f(w, 3));
	r3.setPosition(0, -3);
	sf::RectangleShape r4(sf::Vector2f(w, 3));
	r4.setPosition(0, h+3);
	//KONIEC KWADRATOW GRANICZNYCH ^

}

void klawiatura()
{
    //keyboard + slowing down the player
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
		//END OF KEYBOARD

}
