#include "Enemy.h"
#include <cstdlib>
//Convierte el tipo de dinosaurio a un texto para imprimirlo
std::string getDynosaurTypeToString(DynosaurType type) {
    switch (type) {
    case DynosaurType::TYRANNOSAURUS: return "TYRANNOSAURUS";
    case DynosaurType::VELOCIRAPTOR:  return "VELOCIRAPTOR";
    case DynosaurType::BRACHIOSAURUS: return "BRACHIOSAURUS";
    case DynosaurType::DIPLODOCUS:    return "DIPLODOCUS";
    default: return "UNKNOWN";
    }
}

bool compareDynosaurStrength(Dynosaur d1, Dynosaur d2) {
    // La fuerza es la suma vida + ataque
    return (d1.health + d1.attackPower) == (d2.health + d2.attackPower);
}
//Crea un dinosaurio con datos aleatorios según su tipo
Dynosaur createRandomDynosaur() {
    Dynosaur d;
    
    int randomNum = rand() % NUM_DINO_TYPES;
    d.type = static_cast<DynosaurType>(randomNum);

    //Asigna nombre y ataque específico según el tipo elegido
    if (d.type == DynosaurType::TYRANNOSAURUS) {
        d.name = "TYRANNOSAURUS";
        d.attackPower = ATK_TYRANNOSAURUS;
    }
    else if (d.type == DynosaurType::VELOCIRAPTOR) {
        d.name = "VELOCIRAPTOR";
        d.attackPower = ATK_VELOCIRAPTOR;
    }
    else if (d.type == DynosaurType::BRACHIOSAURUS) {
        d.name = "BRACHIOSAURUS";
        d.attackPower = ATK_BRACHIOSAURUS;
    }
    else if (d.type == DynosaurType::DIPLODOCUS) {
        d.name = "DIPLODOCUS";
        d.attackPower = ATK_DIPLODOCUS;
    }
    return d;
}