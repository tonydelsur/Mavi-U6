#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	// Crear una ventana SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo de Tiro Vertical");
	window.setFramerateLimit(60);
	// Definir la posici�n y velocidad inicial del objeto
	sf::Vector2f position(400.0f, 50.0f);
	sf::Vector2f velocity(0.0f, 100.0f); // Velocidad inicial en el eje y (MRUV hacia arriba)
	// Constante de aceleraci�n para el MRUV (gravedad)
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
		// Actualizar la velocidad del objeto en funci�n de la aceleraci�n y el tiempo transcurrido
		float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se est� ejecutando a 60 FPS
		velocity.y += acceleration; //* deltaTime;
		// Actualizar la posici�n del objeto en funci�n de la velocidad y el tiempo transcurrido
		position += velocity * deltaTime;
		// Comprobar si el objeto ha alcanzado su altura m�xima (velocidad invertida)
		if (velocity.y > 0.0f && position.y > 560.0f)
		{
			// Invertir la direcci�n de la velocidad para simular la ca�da
			velocity.y = -velocity.y;
		}
		// Limpiar la ventana
		window.clear();
		// Dibujar el objeto en su posici�n actual
		sf::CircleShape object(20.0f);
		object.setPosition(position);
		object.setFillColor(sf::Color::Red);
		window.draw(object);
		// Mostrar todo en la ventana
		window.display();
	}
	return 0;
}

