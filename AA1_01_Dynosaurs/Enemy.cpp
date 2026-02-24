#include "Enemy.h"
#include <cstdlib> // Para rand()

// Devuelve el nombre del tipo como strings
std::string getDynosaurTypeToString(DynosaurType type) {
    switch (type) {
    case DynosaurType::TYRANNOSAURUS: return "TYRANNOSAURUS";
    case DynosaurType::VELOCIRAPTOR:  return "VELOCIRAPTOR";
    case DynosaurType::BRACHIOSAURUS: return "BRACHIOSAURUS";
    case DynosaurType::DIPLODOCUS:    return "DIPLODOCUS";
    default: return "UNKNOWN";
    }
}

//La fuerza es la suma de salud + ataque
bool compareDynosaurStrength(Dynosaur d1, Dynosaur d2) {
    return (d1.health + d1.attackPower) == (d2.health + d2.attackPower);
}

//Creación aleatoria
Dynosaur createRandomDynosaur() {
    Dynosaur d;
    int randomNum = rand() % 4;
    d.type = static_cast<DynosaurType>(randomNum);

    // Asignación según el tipo
    if (d.type == DynosaurType::TYRANNOSAURUS) {
        d.name = "TYRANNOSAURUS";
        d.attackPower = 100;
    }
    else if (d.type == DynosaurType::VELOCIRAPTOR) {
        d.name = "VELOCIRAPTOR";
        d.attackPower = 80;
    }
    else if (d.type == DynosaurType::BRACHIOSAURUS) {
        d.name = "BRACHIOSAURUS";
        d.attackPower = 65;
    }
    else if (d.type == DynosaurType::DIPLODOCUS) {
        d.name = "DIPLODOCUS";
        d.attackPower = 45;
    }
    return d;
}