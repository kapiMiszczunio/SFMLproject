#include "scoreTable.h"
#include "enums.h"

void scoreTable::readTable(int difficulty)
{
	std::fstream score;
	switch (difficulty)
	{
	case 1:
		score.open("../Score/easy.txt");
		break;
	case 2:
		score.open("../Score/medium.txt");
		break;
	case 3:
		score.open("../Score/hard.txt");
		break;
	}

	if (score.is_open())
	{
		std::string line;
		int a = 0;
		while (getline(score, line))
		{
			tablescore[a] = line;
			a++;
		}
	}
	score.close();
	

	


}

void scoreTable::displayTable()
{
	sf::RenderWindow table(sf::VideoMode(400, 400), "Ranking", sf::Style::Titlebar | sf::Style::Close);
	sf::Image icon;
	icon.loadFromFile("../Images/icon.jpg");
	table.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(400, 400));
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("../Images/end_background.png");
	background.setTexture(&backgroundTexture);
	sf::Font font;
	if (!font.loadFromFile("../Fonts/DS-DIGIB.ttf"))
	{
		std::cout << "We have some trouble with finding font file!" << std::endl;
	}
	ranking[0].setFont(font);
	ranking[0].setFillColor(sf::Color::White);
	ranking[0].setString("1 - " + tablescore[0]);
	ranking[0].setCharacterSize(50);
	ranking[0].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.1));

	ranking[1].setFont(font);
	ranking[1].setFillColor(sf::Color::White);
	ranking[1].setString("2 - " + tablescore[1]);
	ranking[1].setCharacterSize(50);
	ranking[1].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.25));

	ranking[2].setFont(font);
	ranking[2].setFillColor(sf::Color::White);
	ranking[2].setString("3 - " + tablescore[2]);
	ranking[2].setCharacterSize(50);
	ranking[2].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.4));

	ranking[3].setFont(font);
	ranking[3].setFillColor(sf::Color::White);
	ranking[3].setString("4 - "+tablescore[3]);
	ranking[3].setCharacterSize(50);
	ranking[3].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.55));

	ranking[4].setFont(font);
	ranking[4].setFillColor(sf::Color::White);
	ranking[4].setString("5 - "+tablescore[4]);
	ranking[4].setCharacterSize(50);
	ranking[4].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.7));



	while (table.isOpen())
	{
		sf::Event event;
		while (table.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				table.close();
				break;
			}
		}
		table.clear();
		table.draw(background);
		for (int i = 0; i < 5; i++)
		{
			table.draw(ranking[i]);
		}
		table.display();
	}

	
}
