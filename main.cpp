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
	// Create a sprite
	sf::Sprite sprite1;
	sprite1.setTexture(player);
	sprite1.setTextureRect(sf::IntRect(0, 0, 108, 126));
	//end of player


	//muzyka
	/*
	sf::Music music;
	if (!music.openFromFile("muzyka.ogg"))
		cout << "ERROR, nie mozna zaladowac muzyki.";
	music.play();
	*/

	////////////////////

	// Declare and load a texture
	sf::Texture texture;
	texture.loadFromFile("tlo.png");
	// Create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	kwadraty(width,height);

	sf::RectangleShape rect(sf::Vector2f(20, 20));
	rect.setFillColor(sf::Color::Red);
	float moveSpeed = 800.0f;


	sf::Clock clock;

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

		klawiatura();

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

