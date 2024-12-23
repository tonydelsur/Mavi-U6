#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	// Crear una ventana SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo de Tiro Vertical");
	window.setFramerateLimit(60);
	// Definir la posición y velocidad inicial del objeto
	sf::Vector2f position(400.0f, 50.0f);
	sf::Vector2f velocity(0.0f, 100.0f); // Velocidad inicial en el eje y (MRUV hacia arriba)
	// Constante de aceleración para el MRUV (gravedad)
	const float acceleration = 98;
	// Bucle principal del juego
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Actualizar la velocidad del objeto en función de la aceleración y el tiempo transcurrido
		float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS
		velocity.y += acceleration; //* deltaTime;
		// Actualizar la posición del objeto en función de la velocidad y el tiempo transcurrido
		position += velocity * deltaTime;
		// Comprobar si el objeto ha alcanzado su altura máxima (velocidad invertida)
		if (velocity.y > 0.0f && position.y > 560.0f)
		{
			// Invertir la dirección de la velocidad para simular la caída
			velocity.y = -velocity.y;
		}
		// Limpiar la ventana
		window.clear();
		// Dibujar el objeto en su posición actual
		sf::CircleShape object(20.0f);
		object.setPosition(position);
		object.setFillColor(sf::Color::Red);
		window.draw(object);
		// Mostrar todo en la ventana
		window.display();
	}
	return 0;
}

