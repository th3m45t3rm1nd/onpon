#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>
#include <ctime>

int main() {

  // Initialization
  sf::RenderWindow window(sf::VideoMode({800, 600}), "OnPon");
  sf::RectangleShape paddle1;
  sf::RectangleShape paddle2;
  sf::CircleShape ball;
  sf::RectangleShape wall1;
  sf::RectangleShape wall2;
  sf::Clock clock;

  window.setFramerateLimit(60);

  paddle1.setSize(sf::Vector2f(40, 100));
  paddle1.setPosition({10, 230});
  paddle1.setFillColor(sf::Color(211, 211, 211));
  paddle2.setSize(sf::Vector2f(40, 100));
  paddle2.setPosition({750, 230});
  paddle2.setFillColor(sf::Color(211, 211, 211));

  const double PI = 3.141592653589793;
  ball.setRadius(10);
  ball.setPosition({400, 300});
  float angle = PI / 3;
  float ballSpeed = 270;
  float scaleX = cos(angle);
  float scaleY = sin(angle);
  float velX = scaleX * ballSpeed;
  float velY = scaleY * ballSpeed;

  wall1.setSize(sf::Vector2f(800, 10));
  wall1.setPosition({0, 0});
  wall1.setFillColor(sf::Color(211, 211, 211));
  wall2.setSize(sf::Vector2f(800, 10));
  wall2.setPosition({0, 590});
  wall2.setFillColor(sf::Color(211, 211, 211));

  while (window.isOpen()) {
    sf::Event event;

    // For exiting
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    float dt = clock.restart().asSeconds();
    float ballX = ball.getPosition().x;
    float ballY = ball.getPosition().y;

    if (ballY - 10 <= 0 || ballY + 30 >= 600)
      velY = -velY;

    ball.setPosition(ballX + (velX * dt), ballY + (velY * dt));

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
    window.draw(ball);
    window.draw(paddle1);
    window.draw(paddle2);
    window.draw(wall1);
    window.draw(wall2);

    window.display();
  }
}
