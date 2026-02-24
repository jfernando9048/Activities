#pragma once
#include <string>

//Definición de los tipos de dinosaurios
enum class DynosaurType {
    TYRANNOSAURUS,
    VELOCIRAPTOR,
    BRACHIOSAURUS,
    DIPLODOCUS
};

//Estructura de datos para el Dinosaurio X
struct Dynosaur {
    DynosaurType type;           // Tipo de dinosaurio [cite: 157]
    std::string name;            // Nombre del dinosaurio 
    int health = 100;            // Vida inicializada a 100 por defecto 
    int attackPower;             // Poder de ataque 
};

//Creación de funciones

//Convierte el tipo de dinosaurio a texto
std::string getDynosaurTypeToString(DynosaurType type);

//Compara si dos dinosaurios tienen la misma fuerza
bool compareDynosaurStrength(Dynosaur d1, Dynosaur d2);

//Crea un dinosaurio con valores aleatorios
Dynosaur createRandomDynosaur();