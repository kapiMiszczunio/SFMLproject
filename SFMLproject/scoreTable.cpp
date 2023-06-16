#include "scoreTable.h"

void scoreTable::readTable(difficulty difficulty)
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

	scoreTable_item[0].setFont(font);
	scoreTable_item[0].setFillColor(sf::Color::White);
	scoreTable_item[0].setString("1 - " + tablescore[0]);
	scoreTable_item[0].setCharacterSize(50);
	scoreTable_item[0].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.1));

	scoreTable_item[1].setFont(font);
	scoreTable_item[1].setFillColor(sf::Color::White);
	scoreTable_item[1].setString("2 - " + tablescore[1]);
	scoreTable_item[1].setCharacterSize(50);
	scoreTable_item[1].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.25));

	scoreTable_item[2].setFont(font);
	scoreTable_item[2].setFillColor(sf::Color::White);
	scoreTable_item[2].setString("3 - " + tablescore[2]);
	scoreTable_item[2].setCharacterSize(50);
	scoreTable_item[2].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.4));

	scoreTable_item[3].setFont(font);
	scoreTable_item[3].setFillColor(sf::Color::White);
	scoreTable_item[3].setString("4 - "+tablescore[3]);
	scoreTable_item[3].setCharacterSize(50);
	scoreTable_item[3].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.55));

	scoreTable_item[4].setFont(font);
	scoreTable_item[4].setFillColor(sf::Color::White);
	scoreTable_item[4].setString("5 - "+tablescore[4]);
	scoreTable_item[4].setCharacterSize(50);
	scoreTable_item[4].setPosition(sf::Vector2f(table.getSize().x * 0.15, table.getSize().y * 0.7));

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
			table.draw(scoreTable_item[i]);
		}
		
		table.display();
	}
}
