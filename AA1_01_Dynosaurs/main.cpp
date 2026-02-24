#include <iostream>
#include <ctime>
#include "Enemy.h"

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    //Define el tamaño máximo y crea el array de 15 punteros
    const short MAX_DYNOSAURS = 15;
    Dynosaur* jurassicPark[MAX_DYNOSAURS];
    //Recorre el array para llenarlo
    for (short i = 0; i < MAX_DYNOSAURS; i++) {
        if (i % 2 == 0) {
            bool valid = false;
            while (!valid) {// Comprueba que no tenga la misma fuerza que el dinosaurio de i-2
                Dynosaur temp = createRandomDynosaur();
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
            jurassicPark[i] = nullptr;
        }
    }

    //Imprime la lista completa por pantalla
    for (short i = 0; i < MAX_DYNOSAURS; i++) {
        std::cout << "Posicion " << i << ": ";
        if (jurassicPark[i] != nullptr) {
            std::cout << jurassicPark[i]->name << " (Fuerza: "
                << (jurassicPark[i]->health + jurassicPark[i]->attackPower) << ")" << std::endl;
        }
        else {
            std::cout << "No hay Dinosaurio" << std::endl;
        }
    }
    //Borra los dinosaurios creados para liberar memoria(parte de las "BEST PRACTICES")
    for (short i = 0; i < MAX_DYNOSAURS; i++) {
        delete jurassicPark[i];
    }

    return 0;
}