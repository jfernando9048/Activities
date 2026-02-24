#pragma once
#include <string>

#pragma once //Evita que el archivo se cargue más de una vez
#include <string>

//Valores fijos para evitar los "magic numbers " en el código
const short DEFAULT_HEALTH = 100;
const short ATK_TYRANNOSAURUS = 100;
const short ATK_VELOCIRAPTOR = 80;
const short ATK_BRACHIOSAURUS = 65;
const short ATK_DIPLODOCUS = 45;
const short NUM_DINO_TYPES = 4;

enum class DynosaurType { //Define los 4 tipos de dinosaurios
    TYRANNOSAURUS, VELOCIRAPTOR, BRACHIOSAURUS, DIPLODOCUS
};
//Estructura que agrupa los datos de un "Dynosaur"
struct Dynosaur {
    DynosaurType type;
    std::string name;
    short health = DEFAULT_HEALTH;
    short attackPower;
};
//Declaración de funciones que se implementarán en el .cpp
std::string getDynosaurTypeToString(DynosaurType type);
bool compareDynosaurStrength(Dynosaur d1, Dynosaur d2);
Dynosaur createRandomDynosaur();