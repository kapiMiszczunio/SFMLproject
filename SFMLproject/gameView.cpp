#include "gameView.h"
#include "gameModel.h"

int gameView::launch(float width, float height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SAPER", sf::Style::Titlebar | sf::Style::Close);
	sf::Font font;
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture mainTexture;
	mainTexture.loadFromFile("../Images/menuBackground.png");
	background.setTexture(&mainTexture);
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
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (sf::Mouse::getPosition(window).x > 230 && sf::Mouse::getPosition(window).x < 360 && sf::Mouse::getPosition(window).y > 240 && sf::Mouse::getPosition(window).y < 290)
					{
						window.close();
						return 1;
					}
					if (sf::Mouse::getPosition(window).x > 230 && sf::Mouse::getPosition(window).x < 410 && sf::Mouse::getPosition(window).y > 330 && sf::Mouse::getPosition(window).y < 380)
					{
						window.close();
						return 2;
					}
					if (sf::Mouse::getPosition(window).x > 230 && sf::Mouse::getPosition(window).x < 360 && sf::Mouse::getPosition(window).y > 420 && sf::Mouse::getPosition(window).y < 470)
					{
						window.close();
						return 3;
					}
				}
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				break;
			}

		}

		window.clear();
		window.draw(background);
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
	menu_item[0].setPosition(sf::Vector2f(window.getSize().x*0.30, window.getSize().y*0.05));

	menu_item[1].setFont(font);
	menu_item[1].setFillColor(sf::Color::White);
	menu_item[1].setString("EASY");
	menu_item[1].setCharacterSize(40);
	menu_item[1].setPosition(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.4));

	menu_item[2].setFont(font);
	menu_item[2].setFillColor(sf::Color::White);
	menu_item[2].setString("MEDIUM");
	menu_item[2].setCharacterSize(40);
	menu_item[2].setPosition(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.55));

	menu_item[3].setFont(font);
	menu_item[3].setFillColor(sf::Color::White);
	menu_item[3].setString("HARD");
	menu_item[3].setCharacterSize(40);
	menu_item[3].setPosition(sf::Vector2f(window.getSize().x * 0.40, window.getSize().y * 0.7));

	for (int i = 0; i < 4; i++)
	{
		window.draw(menu_item[i]);
	}
}

void gameView::play(float width, float height)
{
	sf::RenderWindow play(sf::VideoMode(width, height), "Saper");
	sf::Texture blankField;
	blankField.loadFromFile("../Images/blank.gif");
	sf::Sprite spriteField(blankField);
	//gameModel model;
	//vector<vector<int>> grid = model.generateGrid();

	int grid[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = 10;
		}
	}

	while (play.isOpen()) {
		sf::Event playEvent;
		while (play.pollEvent(playEvent)) {
			if (playEvent.type == sf::Event::Closed) {
				play.close();
			}
			if (playEvent.type == sf::Event::KeyPressed) {
				if (playEvent.key.code == sf::Keyboard::Escape) {
					play.close();
				}
			}
		}
		play.clear(sf::Color::White);
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				spriteField.setTextureRect(sf::IntRect(0, 0, 64,64));
				spriteField.setScale(0.5, 0.5);
				spriteField.setPosition(i * 64*0.5, j * 64*0.5);
				play.draw(spriteField);
			}
		}
		play.display();
	}
}







