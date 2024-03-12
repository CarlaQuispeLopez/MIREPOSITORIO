#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Jugador {
private:
    int opcion;
    int puntaje;

public:
    Jugador() : opcion(0), puntaje(0) {}

    void setOpcion(int opcion) {
        this->opcion = opcion;
    }

    int getOpcion() const {
        return opcion;
    }

    void aumentarPuntaje() {
        puntaje++;
    }

    int getPuntaje() const {
        return puntaje;
    }
};

class Juego {
public:
    static void mostrarReglas() {
        std::cout << "REGLAS:\n";
        std::cout << "-Piedra=1\n";
        std::cout << "-Papel=2\n";
        std::cout << "-Tijera=3\n";
        std::cout << "-Escriba EXIT para finalizar el juego\n";
    }

    static int generarOpcionAleatoria() {
        return rand() % 3 + 1; // Genera un número aleatorio entre 1 y 3
    }

    static void determinarGanador(const Jugador& jugador1, const Jugador& jugador2) {
        if (jugador1.getOpcion() == jugador2.getOpcion()) {
            std::cout << "Empate!\n";
        } else if ((jugador1.getOpcion() == 1 && jugador2.getOpcion() == 3) ||
                   (jugador1.getOpcion() == 2 && jugador2.getOpcion() == 1) ||
                   (jugador1.getOpcion() == 3 && jugador2.getOpcion() == 2)) {
            std::cout << "Jugador 1 gana esta ronda!\n";
            const_cast<Jugador&>(jugador1).aumentarPuntaje();
        } else {
            std::cout << "Jugador 2 gana esta ronda!\n";
            const_cast<Jugador&>(jugador2).aumentarPuntaje();
        }
    }

    static void finalizarJuego(const Jugador& jugador1, const Jugador& jugador2) {
        std::cout << "Puntaje:\n";
        std::cout << "Jugador_1: " << jugador1.getPuntaje() << std::endl;
        std::cout << "Jugador_2: " << jugador2.getPuntaje() << std::endl;

        if (jugador1.getPuntaje() > jugador2.getPuntaje()) {
            std::cout << "El ganador es: Jugador 1\n";
        } else if (jugador1.getPuntaje() < jugador2.getPuntaje()) {
            std::cout << "El ganador es: Jugador 2\n";
        } else {
            std::cout << "¡Ha sido un empate!\n";
        }
    }
};

int main() {
    srand(time(nullptr)); // Semilla para generar números aleatorios

    Jugador jugador1, jugador2;
    Juego::mostrarReglas();

    while (true) {
        std::string entrada;
        std::cout << "Ingrese Jugador_1: ";
        std::cin >> entrada;

        if (entrada == "EXIT") {
            Juego::finalizarJuego(jugador1, jugador2);
            return 0; // Finalizar el programa si se ingresa "EXIT"
        }

        int opcionJugador1 = std::stoi(entrada);

        if (opcionJugador1 < 1 || opcionJugador1 > 3) {
            std::cout << "Opción inválida. Inténtelo de nuevo.\n";
            continue;
        }

        jugador1.setOpcion(opcionJugador1);
        int opcionJugador2 = Juego::generarOpcionAleatoria();
        jugador2.setOpcion(opcionJugador2);

        std::cout << "Jugador_2: " << opcionJugador2 << std::endl;

        Juego::determinarGanador(jugador1, jugador2);
    }

    return 0;
}
