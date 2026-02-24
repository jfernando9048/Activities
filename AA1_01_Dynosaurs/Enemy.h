#pragma once
#include <string>

//Nombres de los  diferentes tipos de dinosaurios
enum class DynosaurType {
    TYRANNOSAURUS,
    VELOCIRAPTOR,
    BRACHIOSAURUS,
    DIPLODOCUS
};

//Estructura de datos del "Dynosaur"
struct Dynosaur {
    DynosaurType type;
    std::string name;
    int health = 100;
    int attackPower;
};

//LosPrototipos de funciones
std::string getDynosaurTypeToString(DynosaurType type);
bool compareDynosaurStrength(Dynosaur d1, Dynosaur d2);
Dynosaur createRandomDynosaur();