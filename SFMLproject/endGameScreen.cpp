#include "endGameScreen.h"

int endGameScreen::gameover()
{
		sf::RenderWindow window(sf::VideoMode(400, 400), "Game Over!", sf::Style::Titlebar | sf::Style::Close);
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
			}
			window.clear();
			window.draw(background);
			draw_game_over(window, font);
			window.display();
		}
}

int endGameScreen::victory()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Victory!", sf::Style::Titlebar | sf::Style::Close);
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
						cout << "again";
						return 1;
					}
					if (sf::Mouse::getPosition(window).x > 150 && sf::Mouse::getPosition(window).x < 250 && sf::Mouse::getPosition(window).y > 290 && sf::Mouse::getPosition(window).y < 320)
					{
						window.close();
						cout << "exit";
						return 2;
					}
				}
			}
		}
		window.clear();
		window.draw(background);
		draw_victory(window, font);
		window.display();
	}
	return 1;
}
