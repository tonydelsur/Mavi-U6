#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
int main()
{
	// Crear una ventana SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Unidad 6 Fast & Furious");
	window.setFramerateLimit(60);
	// Definir la posición y velocidad inicial del objeto
	sf::Vector2f position(0.0f, 100.0f);
	sf::Vector2f velocity(3.0f, 0.0f); // Velocidad inicial en el eje x (MRU) 
	sf::Vector2f velocityFinal(15.0f, 0.0f); // Velocidad final x 
	// Constante de aceleración 
	const float acceleration = 0.5;
	// Bucle principal del juego
	while (window.isOpen() && velocity.x < velocityFinal.x)
	{
		// Dibujar el objeto en su posición actual
		sf::RectangleShape object(sf::Vector2f(50.0f, 50.0f));
		//Bucle de pantalla
		while (position.x<800)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			//Tiempo
			float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS
			// Actualizar la posición del objeto en función de la velocidad
			position += velocity;
					
			// Limpiar la ventana
			window.clear();
			object.setPosition(position);
			object.setFillColor(sf::Color::Red);
			window.draw(object);
			// Mostrar todo en la ventana
			window.display();
		}
		// resetear la posicion en x
		position.x = 0;
		// aumentar la velocidad en funcion de la aceleracion
		velocity.x += acceleration;
		//mostrar en consola la velocidad en x
		std::cout << velocity.x << std::endl;
	}
	return 0;
}
