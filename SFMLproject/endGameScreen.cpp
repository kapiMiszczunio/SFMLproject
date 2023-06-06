#include "endGameScreen.h"
#include <stdlib.h>

int endGameScreen::renderwindow(sf::RenderWindow& window, sf::Text *items)
{
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(400, 400));
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("../Images/end_background.png");
	background.setTexture(&backgroundTexture);
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Astronomus.ttf"))
	{
		cout << "We have some trouble with finding font file!" << endl;
	}
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
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (sf::Mouse::getPosition(window).x > 80 && sf::Mouse::getPosition(window).x < 320 && sf::Mouse::getPosition(window).y > 225 && sf::Mouse::getPosition(window).y < 260)
					{
						window.close();
						return 1;
					}
					if (sf::Mouse::getPosition(window).x > 150 && sf::Mouse::getPosition(window).x < 250 && sf::Mouse::getPosition(window).y > 290 && sf::Mouse::getPosition(window).y < 320)
					{
						window.close();
						return 2;
					}
				}
			}

			window.clear();
			window.draw(background);
			for (int i = 0; i < 4; i++)
			{
				window.draw(items[i]);
			}
			window.display();
		}
	}
}

int endGameScreen::draw(sf::Time time)
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Tanks for playing!", sf::Style::Titlebar | sf::Style::Close);
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Astronomus.ttf"))
	{
		cout << "We have some trouble with finding font file!" << endl;
	}
	sf::Font font2;
	if (!font2.loadFromFile("../Fonts/DS-DIGIB.ttf"))
	{
		cout << "We have some trouble with finding font file!" << endl;
	}

	window_item[0].setFont(font);
	window_item[0].setFillColor(sf::Color::White);
	window_item[0].setString("THANKS FOR PLAYING");
	window_item[0].setCharacterSize(30);
	window_item[0].setPosition(sf::Vector2f(window.getSize().x * 0.055, window.getSize().y * 0.1));
	
	window_item[1].setFont(font);
	window_item[1].setFillColor(sf::Color::White);
	window_item[1].setString("Game made by");
	window_item[1].setCharacterSize(35);
	window_item[1].setPosition(sf::Vector2f(window.getSize().x * 0.15, window.getSize().y * 0.2));

	window_item[2].setFont(font);
	window_item[2].setFillColor(sf::Color::White);
	window_item[2].setString("Wojciech Lewko");
	window_item[2].setCharacterSize(35);
	window_item[2].setPosition(sf::Vector2f(window.getSize().x * 0.0725, window.getSize().y * 0.5));

	window_item[3].setFont(font);
	window_item[3].setFillColor(sf::Color::White);
	window_item[3].setString("Kacper Perkowski");
	window_item[3].setCharacterSize(35);
	window_item[3].setPosition(sf::Vector2f(window.getSize().x * 0.0225, window.getSize().y * 0.6));

	renderwindow(window, window_item);
	window.close();
	return decision;
}
