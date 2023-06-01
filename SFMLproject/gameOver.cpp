#include "gameOver.h"

void gameOver::draw_game_over(sf::RenderWindow& window, sf::Font font)
{
	game_over_item[0].setFont(font);
	game_over_item[0].setFillColor(sf::Color::White);
	game_over_item[0].setString("GAME OVER");
	game_over_item[0].setCharacterSize(55);
	game_over_item[0].setPosition(sf::Vector2f(window.getSize().x * 0.0725, window.getSize().y * 0.025));

	sf::Font font2;
	if (!font2.loadFromFile("../Fonts/DS-DIGIB.ttf"))
	{
		cout << "We have some trouble with finding font file!" << endl;
	}
	game_over_item[1].setFont(font2);
	game_over_item[1].setFillColor(sf::Color::White);
	game_over_item[1].setString("Time: 00:00:00");
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

	for (int i = 0; i < 4; i++)
	{
		window.draw(game_over_item[i]);
	}
}
