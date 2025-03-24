#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "OnPon");
  sf::RectangleShape paddle1;
  sf::RectangleShape paddle2;
  sf::CircleShape ball;

  paddle1.setSize(sf::Vector2f(40, 100));
  paddle1.setPosition({10, 230});
  paddle2.setSize(sf::Vector2f(40, 100));
  paddle2.setPosition({750, 230});

  ball.setRadius(10);
  ball.setPosition({400, 300});

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);
    window.draw(paddle1);
    window.draw(paddle2);
    window.draw(ball);

    window.display();
  }
}
