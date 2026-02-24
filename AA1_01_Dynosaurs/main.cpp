#include <iostream>
#include <ctime>
#include "Enemy.h"

int main() {
    //Semilla para que los números cambien cada vez
    srand(static_cast<unsigned int>(time(NULL)));

    //Constante y array de 15 punteros
    const int MAX_DYNOSAURS = 15;
    Dynosaur* jurassicPark[MAX_DYNOSAURS];

    //Inicialización de las arrays
    for (int i = 0; i < MAX_DYNOSAURS; i++) {
        if (i % 2 == 0) { // Solo en las posiciones que son pares
            bool valid = false;
            while (!valid) {
                Dynosaur temp = createRandomDynosaur();
                // Comparar con el dinosaurio de i-2
                if (i >= 2 && jurassicPark[i - 2] != nullptr) {
                    if (!compareDynosaurStrength(temp, *jurassicPark[i - 2])) {
                        jurassicPark[i] = new Dynosaur(temp);
                        valid = true;
                    }
                }
                else {
                    jurassicPark[i] = new Dynosaur(temp);
                    valid = true;
                }
            }
        }
        else {
            jurassicPark[i] = nullptr; // Las posiciones impares vacías
        }
    }

    // Imprimir resultados 
    for (int i = 0; i < MAX_DYNOSAURS; i++) {
        std::cout << "Posicion " << i << ": ";
        if (jurassicPark[i] != nullptr) {
            std::cout << jurassicPark[i]->name << " (Fuerza: "
                << (jurassicPark[i]->health + jurassicPark[i]->attackPower) << ")" << std::endl;
        }
        else {
            std::cout << "No hay Dinosaurio" << std::endl;
        }
    }

    // Limpieza de memoria (por lo de las "Best Practice")
    for (int i = 0; i < MAX_DYNOSAURS; i++) {
        delete jurassicPark[i];
    }

    return 0;
}