#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <Personaje.hpp>

#include <Obstaculo.hpp>

#include <Juego.hpp>

int main() {
    try {
        Juego juego;
        juego.run();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}