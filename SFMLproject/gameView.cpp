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
	setIcon(play);
	sf::Texture field;
	field.loadFromFile("../Images/tiles.jpg");
	sf::Sprite spriteField(field);

	int fieldSize = 32;

	vector<vector<int>> grid = model.generateGrid();
	vector<vector<int>> board = model.getBoard();
	int boardSize = model.getBoardSize();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = 10;
		}
	}

	while (play.isOpen()) {
		sf::Vector2i pos = sf::Mouse::getPosition(play);
		int x = pos.x / (fieldSize* (width / (boardSize + 2)) / fieldSize);
		int y = pos.y / (fieldSize * (width / (boardSize + 2)) / fieldSize);

		int xF = x - 1;
		int yF = y - 1;

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
			if (playEvent.type == sf::Event::MouseButtonPressed) {
				if (playEvent.key.code == sf::Mouse::Left) {
					if (xF >= 0 and xF < boardSize and yF >= 0 and yF < boardSize) {
						if (grid[xF][yF] != 11) {
							grid[xF][yF] = board[yF][xF];
						}
					}
				}
				else if (playEvent.key.code == sf::Mouse::Right) {
					if (grid[xF][yF] == 11) {
						grid[xF][yF] = 10;
					}
					else {
						grid[xF][yF] = 11;
					}
				}
			}
		}

		int textureSize = 64;
		float scale = 0.5;

		play.clear(sf::Color::White);

		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (grid[xF][yF] == 9) {
					grid[i][j] = board[j][i]; //!!!!!
					cout << "Koniec gry";;
					play.close();
				}
				spriteField.setTextureRect(sf::IntRect(grid[i][j]*fieldSize, 0, fieldSize, fieldSize));
				spriteField.setScale((width/ (boardSize+2))/fieldSize, (width/ (boardSize + 2))/fieldSize);
				spriteField.setPosition((i+1)* width / (boardSize + 2), (j + 1) * width / (boardSize + 2));
				play.draw(spriteField);
			}
		}
		play.display();
	}
}







