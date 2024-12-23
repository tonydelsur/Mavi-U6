#include<SFML/graphics.hpp>
#include<SFML/system.hpp>
#include<SFML/window.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "principal.h"
#include "fondo.h"
#include "NPC.h"
#include "Mira.h"

using namespace sf;
using namespace std;

int main() {
	sf::Texture Tback;
	Tback.loadFromFile("./assets/FONDO.png");
	sf::Texture TnpcB;
	TnpcB.loadFromFile("./assets/rcircle.png");
	sf::Texture Tmira;
	Tmira.loadFromFile("./assets/MIRA.png");
	// VARIABLES DE JUEGO
	int estado = 2; //0- Intro 1- menu, 2- jugar, 3- game over
	int vidas = 0;
	float posX = 0;
	int posNPC = 0;
	bool jugando = false;
	int bajasMalos = 0;
	int bajasBuenos = 0;
	int puntos = 0;
	float tiempoEspera = 1500; // mili-segundos
	clock_t tiempoInicial = clock();

	sf::Sprite Menu;
	sf::Texture MenuT;

	fondo back;
	back.colocarTextura(Tback);
	NPC personaje;
	// personaje.colocarTextura(Tnpc);
	// personaje.setPosition(80, 150);
	Mira jugador;
	jugador.colocarTextura(Tmira);
	jugador.setPosition(400, 300);
	
	// Definir la posición y velocidad inicial del objeto
	sf::Vector2f position(100.0f, 100.0f);
	sf::Vector2f velocity(0.50f, 200.0f); // Velocidad inicial en el eje x (MRU) y en el eje y(MRUV)
	// Constante de aceleración para el MRUV
	const float acceleration = 20;

	
	//Creamos la ventana
	sf::RenderWindow Ventana(sf::VideoMode(800, 600, 32),"3-2-1 Dispara");
	Ventana.setFramerateLimit(60);
	// Loop principal
	puntos = 0;
	while (Ventana.isOpen()) {
		
				bool colision = false;
				if (!jugando){
					posX = (rand() % 10 + 1) * 60 + 100;
					tiempoInicial = clock();
					jugando = true;
					position.x = posX;
					position.y = 50;
					velocity.x = 1.5;
					velocity.y = 0.5;
					personaje.colocarTextura(TnpcB);
					std::cout << "Inicializa correctamente - - " << posX << std::endl;
				}
			
			
			
				sf::Event evento;
				while (Ventana.pollEvent(evento)) {
					if (evento.type == sf::Event::Closed) {
						Ventana.close();
					}
					if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
						if (personaje.pegar(Ventana)) {
							puntos++;
							jugando = false;
							std::cout << "Puntos: " << puntos << endl;
						}
					}

				}
				// Actualizar la velocidad del objeto en función de la aceleración y el tiempo transcurrido
				float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se está ejecutando a 60 FPS
				velocity.y += acceleration;
				// Actualizar la posición del objeto en función de la velocidad y el tiempo transcurrido
				position.y += velocity.y * deltaTime;
				position.x += velocity.x;

				// Comprobar si el objeto ha llegado al suelo (límite inferior de la ventana)
				if (position.y > 450) {
					// Si el objeto ha llegado al suelo, hacer que rebote invirtiendo su velocidad en y
					position.y = 450.0f;
					velocity.y = -velocity.y;
				}
				if (position.x > 700) {
					// Si el objeto ha llegado al suelo, hacer que rebote invirtiendo su velocidad en y
					position.x = 700.0f;
					velocity.x = -velocity.x;
				}
				if (position.x < 0) {
					// Si el objeto ha llegado al suelo, hacer que rebote invirtiendo su velocidad en y
					position.x = 0.0f;
					velocity.x = -velocity.x;
				}
				personaje.setPosition(position.x, position.y);

				jugador.actualizar(Ventana);

				// Limpiamos la ventana
				Ventana.clear();
				back.dibujar(Ventana);
				personaje.dibujar(Ventana);
				jugador.dibujar(Ventana);
				Ventana.display();
			

			
	}
	return 0;
}

