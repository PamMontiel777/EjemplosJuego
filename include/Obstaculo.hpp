#pragma once

class Obstaculo {
public:
    enum Tipo { METEORO, PIEDRA };
    
    Obstaculo(Tipo tipo, float velocidad) : tipo(tipo), velocidad(velocidad) {
        std::string file = (tipo == METEORO) ? "assets/images/meteoro.png" : "assets/images/piedra.png";
        float scale = (tipo == METEORO) ? 0.2f : 0.2f;
        
        if (!texture.loadFromFile(file)) {
            throw std::runtime_error("No se pudo cargar la textura del obstáculo");
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setScale(scale, scale);
        
        float yPos = (tipo == METEORO) ? 350 : 400 - sprite.getGlobalBounds().height;
        sprite.setPosition(800, yPos);
    }

    void update(float deltaTime) { sprite.move(-velocidad * deltaTime, 0); }
    void draw(sf::RenderWindow& window) const { window.draw(sprite); }
    bool isOutOfScreen() const { return sprite.getPosition().x + sprite.getGlobalBounds().width < 0; }
    sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }

private:
    sf::Sprite sprite;
    sf::Texture texture;
    Tipo tipo;
    float velocidad;
};