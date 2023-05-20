#include "gameView.h"

void gameView::launch(double width, double height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SAPER");
	
	sf::Font font;
	if (!font.loadFromFile("../Fonts/arial.ttf"))
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
			}
		}

		window.clear();
		draw_menu(window, font);
		window.display();
	}

}

void gameView::draw_menu(sf::RenderWindow &window, sf::Font font)
{
	menu_item[0].setFont(font);
	menu_item[0].setFillColor(sf::Color::White);
	menu_item[0].setString("SAPER");
	menu_item[0].setCharacterSize(70);
	menu_item[0].setPosition(sf::Vector2f(window.getSize().x*0.30, window.getSize().y*0.1));

	menu_item[1].setFont(font);
	menu_item[1].setFillColor(sf::Color::White);
	menu_item[1].setString("EASY");
	menu_item[1].setCharacterSize(40);
	menu_item[1].setPosition(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.4));

	menu_item[2].setFont(font);
	menu_item[2].setFillColor(sf::Color::White);
	menu_item[2].setString("MEDIUM");
	menu_item[2].setCharacterSize(40);
	menu_item[2].setPosition(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.5));

	menu_item[3].setFont(font);
	menu_item[3].setFillColor(sf::Color::White);
	menu_item[3].setString("HARD");
	menu_item[3].setCharacterSize(40);
	menu_item[3].setPosition(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.6));

	for (int i = 0; i < 4; i++)
	{
		window.draw(menu_item[i]);
	}
}


