#include "ResourceHolder.hpp"
#include "TextureIDs.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Resources");
	window.setFramerateLimit(20);

	//try and load resource using ResourceHolder
	ResourceHolder<sf::Texture, TextureIDs> textures;


	

	try {
		textures.load(TextureIDs::Landscape, "Media/Textures/Desert.png");
		textures.load(TextureIDs::Airplane, "Media/Textures/Eagle.png");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}

	sf::Sprite landscape(textures.get(TextureIDs::Landscape));
	sf::Sprite airplane(textures.get(TextureIDs::Airplane));
	airplane.setPosition(200.f, 200.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed)
			{
				return 0;
			}
		}
		window.clear();
		window.draw(landscape);
		window.draw(airplane);
		window.display();
	}
}