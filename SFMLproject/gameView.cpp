#include "gameView.h"
#include "gameModel.h"
#include "gameController.h"
#include "scoreTable.h"

gameView::~gameView()
{
}

difficulty gameView::launch(float width, float height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SAPER", sf::Style::Titlebar | sf::Style::Close);
	setIcon(window);
	sf::Font font;
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture mainTexture;
	mainTexture.loadFromFile("../Images/menuBackground.png");
	background.setTexture(&mainTexture);
	if (!font.loadFromFile("../Fonts/arial.ttf"))
	{
		std::cout << "We have some trouble with finding font file!" << std::endl;
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
						return difficulty(easy);
					}
					if (sf::Mouse::getPosition(window).x > 230 && sf::Mouse::getPosition(window).x < 410 && sf::Mouse::getPosition(window).y > 330 && sf::Mouse::getPosition(window).y < 380)
					{
						window.close();
						return difficulty(medium);
					}
					if (sf::Mouse::getPosition(window).x > 230 && sf::Mouse::getPosition(window).x < 360 && sf::Mouse::getPosition(window).y > 420 && sf::Mouse::getPosition(window).y < 470)
					{
						window.close();
						return difficulty(hard);
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

void gameView::draw_menu(sf::RenderWindow& window, sf::Font font)
{
	menu_item[0].setFont(font);
	menu_item[0].setFillColor(sf::Color::White);
	menu_item[0].setString("SAPER");
	menu_item[0].setCharacterSize(70);
	menu_item[0].setPosition(sf::Vector2f(window.getSize().x * 0.30, window.getSize().y * 0.05));

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

continuation gameView::play(float width, float height, gameModel& model)
{
	sf::RenderWindow play(sf::VideoMode(width, height), "Saper", sf::Style::Titlebar | sf::Style::Close);
	setIcon(play);
	sf::Texture field;
	field.loadFromFile("../Images/tiles.jpg");
	sf::Sprite spriteField(field);

	int fieldSize = 32;
	std::vector<std::vector<int>> grid = model.getGrid();
	std::vector<std::vector<int>> board = model.getBoard();
	int boardSize = model.getBoardSize();

	//ropoczêcie odliczania czasu
	sf::Clock timer;
	start_timer = 1;


	while (play.isOpen()) {
		sf::Vector2i pos = sf::Mouse::getPosition(play);
		int x = pos.x / (fieldSize * (width / (boardSize + 2)) / fieldSize);
		int y = pos.y / (fieldSize * (width / (boardSize + 2)) / fieldSize);
		int xF = x - 1;
		int yF = y - 1;
		sf::Event playEvent;


		while (play.pollEvent(playEvent)) 
		{

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
					if (start_timer == 1)
					{
						timer.restart();
						start_timer = 0;
					}
					if (xF >= 0 and xF < boardSize and yF >= 0 and yF < boardSize) {
						if (grid[xF][yF] == 10)
						{
							grid[xF][yF] = board[yF][xF];
							fieldLeft -= 1;
							
						}
					}
				}
				else if (playEvent.key.code == sf::Mouse::Right) {
					if (xF >= 0 and xF < boardSize and yF >= 0 and yF < boardSize) {
						if (grid[xF][yF] == 11) {
							grid[xF][yF] = 10;
							fieldLeft += 1;
						}
						else {
							if (grid[xF][yF] == 10)
							{
								grid[xF][yF] = 11;
								fieldLeft -= 1;
							}
						}
					}
				}
			}
		}
		
		if (fieldLeft == 0)
		{
			curr_time = timer.getElapsedTime();
			model.updateRanking(std::to_string(curr_time.asSeconds()));
			play.close();
			endGameScreen *screen = new gameVictory;
			continuation after_screen = screen->draw(curr_time, model.getGameDifficulty());
			delete(screen);
			return after_screen;
		}
		play.clear(sf::Color::White);

		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (xF >= 0 and xF < boardSize and yF >= 0 and yF < boardSize)
				{
					if (grid[xF][yF] == 9) {
						grid[i][j] = board[j][i]; 
						play.close();

						endGameScreen  *screen = new gameOver;
						curr_time = timer.getElapsedTime();
						continuation after_screen = screen->draw(curr_time, model.getGameDifficulty());
						delete(screen);
						return after_screen;
					}
				}
				spriteField.setTextureRect(sf::IntRect(grid[i][j] * fieldSize, 0, fieldSize, fieldSize));
				spriteField.setScale((width / (boardSize + 2)) / fieldSize, (width / (boardSize + 2)) / fieldSize);
				spriteField.setPosition((i + 1) * width / (boardSize + 2), (j + 1) * width / (boardSize + 2));
				play.draw(spriteField);
			}
		}
		play.display();
	}
}

void gameView::setIcon(sf::RenderWindow& window)
{
	sf::Image icon;
	icon.loadFromFile("../Images/icon.jpg");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}






