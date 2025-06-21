#pragma once

class Juego {
public:
    Juego() : window(sf::VideoMode(800, 600), "Gato Runner") {
        // Cargar recursos
        if (!fondoTexture.loadFromFile("assets/images/noche.jpg")) {
            throw std::runtime_error("No se pudo cargar el fondo");
        }
        fondoSprite.setTexture(fondoTexture);
        fondoSprite.setScale(800.0f / fondoTexture.getSize().x, 600.0f / fondoTexture.getSize().y);
        
        if (!font.loadFromFile("assets/fonts/ring.ttf")) { 
            throw std::runtime_error("No se pudo cargar la fuente");
        }

        // Cargar música
        if (!music.openFromFile("assets/music/musica.ogg")) {
            throw std::runtime_error("No se pudo cargar la música");
        }
        music.setLoop(true);
        music.play();

        std::srand(std::time(nullptr));
        resetGame();
    }

    void run() {
        sf::Clock clock;
        while (window.isOpen()) {
            float deltaTime = clock.restart().asSeconds();
            
            if (!gameOver) {
                scoreTime += deltaTime;
                score = static_cast<int>(scoreTime * 10); // Puntaje basado en tiempo
            }
            
            procesarEventos();
            
            if (!gameOver) {
                actualizar(deltaTime);
            }
            renderizar();
        }
    }

private:
    void resetGame() {
        personaje.reset();
        obstaculos.clear();
        velocidadJuego = 300.0f;
        tiempoSiguienteObstaculo = 2.0f;
        gameOver = false;
        scoreTime = 0.0f;
        score = 0;
    }

    void procesarEventos() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up && !gameOver) {
                    personaje.jump();
                }
                if (event.key.code == sf::Keyboard::Enter && gameOver) {
                    resetGame();
                }
            }
        }
    }

    void actualizar(float deltaTime) {
        bool fastFall = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        personaje.update(deltaTime, fastFall);
        
        // Generar obstáculos
        tiempoSiguienteObstaculo -= deltaTime;
        if (tiempoSiguienteObstaculo <= 0) {
            Obstaculo::Tipo tipo = (std::rand() % 2 == 0) ? Obstaculo::METEORO : Obstaculo::PIEDRA;
            obstaculos.emplace_back(tipo, velocidadJuego);
            tiempoSiguienteObstaculo = 1.5f + (std::rand() % 100) / 100.0f;
        }
        
        // Actualizar obstáculos
        for (auto& obstaculo : obstaculos) obstaculo.update(deltaTime);
        obstaculos.erase(
            std::remove_if(obstaculos.begin(), obstaculos.end(),
                [](const Obstaculo& o) { return o.isOutOfScreen(); }),
            obstaculos.end()
        );
        
        // Colisiones
        for (const auto& obstaculo : obstaculos) {
            if (personaje.getBounds().intersects(obstaculo.getBounds())) {
                gameOver = true;
            }
        }
        
        velocidadJuego += deltaTime * 5.0f;
    }

    void renderizar() {
        window.clear();
        window.draw(fondoSprite);
        personaje.draw(window);
        
        for (const auto& obstaculo : obstaculos) {
            obstaculo.draw(window);
        }

        // Mostrar puntaje
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString("Puntaje: " + std::to_string(score));
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(650, 20);
        window.draw(scoreText);

        // Mostrar Game Over
        if (gameOver) {
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("GAME OVER\nPresiona Enter para reiniciar");
            gameOverText.setCharacterSize(50);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setStyle(sf::Text::Bold);
            
            // Centrar texto
            sf::FloatRect textRect = gameOverText.getLocalBounds();
            gameOverText.setOrigin(textRect.left + textRect.width/2.0f,
                                 textRect.top + textRect.height/2.0f);
            gameOverText.setPosition(window.getSize().x/2.0f, window.getSize().y/2.0f);
            
            window.draw(gameOverText);
        }
        
        window.display();
    }

private:
    sf::RenderWindow window;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
    sf::Font font;
    sf::Music music;
    Personaje personaje;
    std::vector<Obstaculo> obstaculos;
    float velocidadJuego;
    float tiempoSiguienteObstaculo;
    bool gameOver;
    float scoreTime;
    int score;
};