#include "NPC.h"

NPC::NPC() : principal() {
	alto = 0;
	ancho = 0;
}

void NPC::colocarTextura(sf::Texture& textura) {
	sprite.setTexture(textura);
	ancho = textura.getSize().x;
	alto = textura.getSize().y;
}
void NPC::actualizar(sf::RenderWindow& ventana) {

}
void NPC::dibujar(sf::RenderWindow& ventana) {
	ventana.draw(sprite);
}
bool NPC::pegar(sf::RenderWindow& ventana) {
	int posX = sf::Mouse::getPosition(ventana).x;
	int posY = sf::Mouse::getPosition(ventana).y;
	if (posX > x && posX< (x + ancho) && posY> y && posY < (y + alto)) {
		return true;
	}
	else {
		return false;
	}
}

