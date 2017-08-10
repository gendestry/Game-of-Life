#include <SFML\Graphics.hpp>

#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * NUM_COLS, CELL_SIZE * NUM_ROWS), "Conway's game of Life");
	sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	rect.setFillColor(sf::Color(84, 221, 162, 255));

	Board board;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		board.update();
		// draw
		for (int x = 0; x < NUM_COLS; x++) {
			for (int y = 0; y < NUM_ROWS; y++) {
				if (board.getState(x, y)) {
					rect.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
					window.draw(rect);
				}
			}
		}

		window.display();
	}

	return 0;
}