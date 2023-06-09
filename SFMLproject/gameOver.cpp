#include "gameOver.h"
#include <string>

int gameOver::draw(sf::Time time)
{
	

	sf::RenderWindow window(sf::VideoMode(400, 400), "Game Over!", sf::Style::Titlebar | sf::Style::Close);
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Astronomus.ttf"))
	{
		std::cout << "We have some trouble with finding font file!" << std::endl;
	}
	sf::Font font2;
	if (!font2.loadFromFile("../Fonts/DS-DIGIB.ttf"))
	{
		std::cout << "We have some trouble with finding font file!" << std::endl;
	}

	game_over_item[0].setFont(font);
	game_over_item[0].setFillColor(sf::Color::White);
	game_over_item[0].setString("GAME OVER");
	game_over_item[0].setCharacterSize(55);
	game_over_item[0].setPosition(sf::Vector2f(window.getSize().x * 0.0725, window.getSize().y * 0.025));

	game_over_item[1].setFont(font2);
	game_over_item[1].setFillColor(sf::Color::White);
	string a = "Time: ";
	string b = to_string(time.asSeconds());
	string c = " s";
	string timee = a + b + c;
	game_over_item[1].setString(timee);
	game_over_item[1].setCharacterSize(40);
	game_over_item[1].setPosition(sf::Vector2f(window.getSize().x * 0.2225, window.getSize().y * 0.2));

	game_over_item[2].setFont(font);
	game_over_item[2].setFillColor(sf::Color::White);
	game_over_item[2].setString("Try again");
	game_over_item[2].setCharacterSize(40);
	game_over_item[2].setPosition(sf::Vector2f(window.getSize().x * 0.2225, window.getSize().y * 0.55));

	game_over_item[3].setFont(font);
	game_over_item[3].setFillColor(sf::Color::White);
	game_over_item[3].setString("Exit");
	game_over_item[3].setCharacterSize(40);
	game_over_item[3].setPosition(sf::Vector2f(window.getSize().x * 0.4, window.getSize().y * 0.70));

	decision = renderwindow(window, game_over_item);
	window.close();
	return decision;
}

