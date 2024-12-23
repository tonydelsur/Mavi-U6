#pragma once
#include "principal.h"
class NPC :
    public principal
    
{
private:
    int ancho, alto;
public:
    NPC();
    void colocarTextura(sf::Texture& textura);
    void actualizar(sf::RenderWindow &ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;
    bool pegar(sf::RenderWindow& ventana);
};

