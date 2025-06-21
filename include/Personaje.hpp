#pragma once

class Personaje {
public:
    Personaje() {
        if (!texture.loadFromFile("assets/images/gato.png")) {
            throw std::runtime_error("No se pudo cargar la textura del gato");
        }
        
        sprite.setTexture(texture);
        sprite.setPosition(100, 400);
        
        // Animación
        currentFrame = 0;
        frameTime = 0.1f;
        frameWidth = 19;
        frameHeight = 30;
        numFrames = 8;
        xOffset = 20;
        yOffset = 83;
        
        // Salto
        isJumping = false;
        groundLevel = 400;
        jumpHeight = 450.0f;
        jumpSpeed = 0.0f;
        gravity = 500.0f;
        fastFallGravity = 1500.0f;
        
        sprite.setTextureRect(sf::IntRect(xOffset, yOffset, frameWidth, frameHeight));
    }

    void reset() {
        sprite.setPosition(100, 400);
        isJumping = false;
        jumpSpeed = 0.0f;
    }

    void update(float deltaTime, bool fastFall) {
        // Animación
        animationTime += deltaTime;
        if (animationTime >= frameTime) {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * frameWidth) + xOffset, yOffset, frameWidth, frameHeight));
            animationTime = 0.0f;
        }
        
        // Salto/Caída
        if (isJumping) {
            float currentGravity = fastFall ? fastFallGravity : gravity;
            sprite.move(0, jumpSpeed * deltaTime);
            jumpSpeed += currentGravity * deltaTime;
            
            if (sprite.getPosition().y >= groundLevel) {
                sprite.setPosition(sprite.getPosition().x, groundLevel);
                isJumping = false;
            }
        }
    }

    void jump() {
        if (!isJumping) {
            isJumping = true;
            jumpSpeed = -jumpHeight;
        }
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

private:
    sf::Sprite sprite;
    sf::Texture texture;
    int currentFrame, numFrames, frameWidth, frameHeight, xOffset, yOffset;
    float frameTime, animationTime = 0.0f;
    bool isJumping;
    float groundLevel, jumpHeight, jumpSpeed, gravity, fastFallGravity;
};