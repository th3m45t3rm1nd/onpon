#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

int main() {

  // Initialization
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

    // For exiting
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Position of Paddles
    sf::Vector2f pad1CurrPos = paddle1.getPosition();
    sf::Vector2f pad2CurrPos = paddle2.getPosition();

    // Movement for Left Paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
      if (pad1CurrPos.y > 0 + 10.0)
        paddle1.move({0, -5.0});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
      if (pad1CurrPos.y < 600 - 10.0 - 100)
        paddle1.move({0, 5.0});

    // Movement for Right Paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
      if (pad2CurrPos.y > 0 + 10.0)
        paddle2.move({0, -5.0});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
      if (pad2CurrPos.y < 600 - 10.0 - 100)
        paddle2.move({0, 5.0});

    // Shape Drawing
    window.clear(sf::Color::Black);
    window.draw(paddle1);
    window.draw(paddle2);
    window.draw(ball);

    window.display();
  }
}
