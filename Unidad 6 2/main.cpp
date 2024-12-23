#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
int main()
{
	// Crear una ventana SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Unidad 6 Space");
	window.setFramerateLimit(60);
	// Definir la posición y velocidad inicial del objeto
	sf::Vector2f position(0.0f, 100.0f);
	sf::Vector2f velocity(10.0f, 0.0f); // Velocidad inicial en el eje x (MRU) 
	sf::Vector2f velocityFinal(15.0f, 0.0f); // Velocidad final x 
	// Constante de aceleración 
	float acceleration = 10;
	bool derecha = true;
	// Bucle principal del juego
	while (window.isOpen())
	{
		// Dibujar el objeto en su posición actual
		sf::RectangleShape object(sf::Vector2f(50.0f, 50.0f));
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Right) {
					acceleration+= 3;
				}
				if (event.key.code == sf::Keyboard::Left) {
					acceleration-= 3;
				}
			}
			
		}
		

		//Tiempo
		float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS
		// Actualizar la posición del objeto en función de la velocidad
		velocity.x += acceleration*deltaTime;
		position.x += velocity.x * deltaTime;
					
		// Limpiar la ventana
		window.clear();
		object.setPosition(position);
		object.setFillColor(sf::Color::Red);
		window.draw(object);
		// Mostrar todo en la ventana
		window.display();
		
		std::cout << velocity.x << std::endl;
		std::cout << acceleration << std::endl;

	}
	return 0;
}
