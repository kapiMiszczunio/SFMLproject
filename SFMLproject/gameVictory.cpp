#include "gameVictory.h"


int gameVictory::draw(sf::Time time)
{
	cout << time.asSeconds();
	sf::RenderWindow window(sf::VideoMode(400, 400), "VICTORY!", sf::Style::Titlebar | sf::Style::Close);
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
	
	victory_item[0].setFont(font);
	victory_item[0].setFillColor(sf::Color::White);
	victory_item[0].setString("VICTORY");
	victory_item[0].setCharacterSize(70);
	victory_item[0].setPosition(sf::Vector2f(window.getSize().x * 0.1, window.getSize().y * 0.025));

	victory_item[1].setFont(font2);
	victory_item[1].setFillColor(sf::Color::White);
	victory_item[1].setString("Time: 00:00:00");
	victory_item[1].setCharacterSize(40);
	victory_item[1].setPosition(sf::Vector2f(window.getSize().x * 0.175, window.getSize().y * 0.25));

	victory_item[2].setFont(font);
	victory_item[2].setFillColor(sf::Color::White);
	victory_item[2].setString("Try again");
	victory_item[2].setCharacterSize(40);
	victory_item[2].setPosition(sf::Vector2f(window.getSize().x * 0.2225, window.getSize().y * 0.55));

	victory_item[3].setFont(font);
	victory_item[3].setFillColor(sf::Color::White);
	victory_item[3].setString("Exit");
	victory_item[3].setCharacterSize(40);
	victory_item[3].setPosition(sf::Vector2f(window.getSize().x * 0.4, window.getSize().y * 0.70));

	decision = renderwindow(window, victory_item);
	window.close();
	return decision;
}
