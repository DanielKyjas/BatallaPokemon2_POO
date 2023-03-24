// BatallaPokemon2_POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<windows.h> 
#include<string>
using namespace std;

class Pokemon
{
    protected:
    //Atributos
    string nombre;
    string tipo;
    string color;
    int ataque;
    int vida;
    int vida2;
    int critico;
public:
    Pokemon()
    {
        nombre = "";
        tipo = "";
        color = "";
        ataque = 20;
        vida = 100;
        vida2 = vida;
        critico = 0;
    }
    Pokemon(string name, string type, string Color, int attack, int healthpoints)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
        critico = 0;
    }
    ~Pokemon()
    {
        cout << "El pokemon " << nombre << " ha sido derrotado\n";
    }

    virtual void mostrar()
    {
        cout << "Su nombre es " << nombre << endl;
        cout << "Es tipo " << tipo << endl;
        cout << "De color " << color << endl;
        cout << "Con un ataque de " << ataque << " de danio" << endl;
        cout << "Y tiene " << vida << " puntos de vida" << endl;
        cout << "Seguro de tu eleccion? (1 para si y 0 para no)" << endl;
    }
    virtual void atacar()
    {
        cout << "El pokemon ha atacado";
    }
    string getnombre() { return nombre; }
    void setnombre(string name) { nombre = name; }
    string gettipo() { return tipo; }
    void settipo(string type) { tipo = type; }
    string getcolor() { return color; }
    void setcolor(string Color) { color = Color; }
    int getataque() { return ataque; }
    void setataque(int attack) { ataque = attack; }
    int getvida() { return vida; }
    void setvida(int healthpoints) { vida = healthpoints; }
    int getvida2() { return vida2; }
    void setvida2(int statichealth) { vida2 = statichealth; }
    int getcritico() { return critico; }
    int setcritico(int critic) { critico = critic;  }
};
class PokemonAgua : public Pokemon
{
public:
    PokemonAgua() :Pokemon()
    {
        nombre = "hola";
        tipo = "agua";
        color = "azul";
        ataque = 15;
        vida = 90;
        vida2 = vida;
        critico = 0;
    }
    PokemonAgua(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
        critico = 0;
    }
    ~PokemonAgua()
    {
        cout << "El pokemon " << nombre << " ha sido derrotado\n";
    }
    void atacar() override
    {
        cout << "El pokemon ha usado torrente" << endl;
    }
};
class PokemonFuego : public Pokemon
{
public:
    PokemonFuego() :Pokemon()
    {
        nombre = "";
        tipo = "fuego";
        color = "naranja";
        ataque = 25;
        vida = 70;
        vida2 = vida;
        critico = 0;
    }
    PokemonFuego(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
        critico = 0;
    }
    ~PokemonFuego()
    {
        cout << "El pokemon " << nombre << " ha sido derrotado\n";
    }
    void atacar() override
    {
        cout << "El pokemon ha usado lanzallamas" << endl;
    }
};
class PokemonPlanta : public Pokemon
{
public:
    PokemonPlanta() :Pokemon()
    {
        nombre = "";
        tipo = "planta";
        color = "verde";
        ataque = 18;
        vida = 80;
        vida2 = vida;
        critico = 0;
    }
    PokemonPlanta(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
        critico = 0;
    }
    ~PokemonPlanta()
    {
        cout << "El pokemon " << nombre << " ha sido derrotado\n";
    }
    void atacar() override
    {
        cout << "El pokemon ha usado hoja afilada" << endl;
    }
};
class PokemonElectrico : public Pokemon
{
public:
    PokemonElectrico() :Pokemon()
    {
        nombre = "";
        tipo = "eletrico";
        color = "amarillo";
        ataque = 22;
        vida = 78;
        vida2 = vida;
        critico = 0;
    }
    PokemonElectrico(string name, string type, string Color, int attack, int healthpoints) : Pokemon(nombre, tipo, color, ataque, vida)
    {
        nombre = name;
        tipo = type;
        color = Color;
        ataque = attack;
        vida = healthpoints;
        vida2 = vida;
        critico = 0;
    }
    ~PokemonElectrico()
    {
        cout << "El pokemon " << nombre << " ha sido derrotado\n";
    }
    void atacar() override
    {
        cout << "el pokemon ha usado trueno" << endl;
    }
};

void AtaquePorTurnos(Pokemon* pokemon1, Pokemon* pokemon2)
{
        pokemon1->atacar();
        pokemon2->setvida(pokemon2->getvida() - pokemon1->getataque());
}

 void sanar(Pokemon* pokemon1)
{
     int vida = pokemon1->getvida();

    pokemon1->setvida(vida += 50);
    if (pokemon1->getvida() > pokemon1->getvida2())
    {
        pokemon1->setvida(pokemon1->getvida());
    }
    cout << "El pokemon " << pokemon1->getnombre() << " se ha curado y ahora su vida es de " <<  pokemon1->getvida() << "\n";
}

 void destruir(Pokemon* pokemon1)
 {
     delete pokemon1;
 }

 void victoria(Pokemon* pokemon1)
 {
     cout << "El pokemon " << pokemon1->getnombre() << " ha resultado victorioso" << endl;
 }

int main()
{
    bool eleccion = false;
    int numeropokemon = 4;
    int numeroeleccion = 4;
    int victoria = 0;
    srand(time(NULL));
    Pokemon* combatiente = new Pokemon[2];

    PokemonAgua* greninja = new PokemonAgua();
    greninja->setnombre("greninja");

    PokemonFuego* charizard = new PokemonFuego();
    charizard->setnombre("charizard");

    PokemonPlanta* bulbasaur = new PokemonPlanta();
    bulbasaur->setnombre("bulbasaur");

    PokemonElectrico* pikachu = new PokemonElectrico();
    pikachu->setnombre("pikachu");

    
    do {
        std::cout << "---------------------------------\n";
        std::cout << "|      Escoge a un pokemon      |\n";
        std::cout << "|       1.- para Greninja       |\n";
        std::cout << "|       2.- para Bulbasaur      |\n";
        std::cout << "|       3.- para Charizard      |\n";
        std::cout << "|       3.- para Pikachu        |\n";
        std::cout << "---------------------------------\n";
        cin >> numeropokemon;
        switch (numeropokemon) {
        case 1:
            greninja->mostrar();
            cin >> eleccion;
            system("CLS");
            combatiente[0] = *greninja;
            break;
        case 2:
            bulbasaur->mostrar();
            cin >> eleccion;
            system("CLS");
            combatiente[0] = *bulbasaur;
            break;
        case 3:
            charizard->mostrar();
            cin >> eleccion;
            system("CLS");
            combatiente[0] = *charizard;
            break;
        case 4:
            pikachu->mostrar();
            cin >> eleccion;
            system("CLS");
            combatiente[0] = *pikachu;
            break;
        default:
            eleccion = 0;
            system("CLS");
            break;
        }
    } while (eleccion != true);
    int tupokemon = numeropokemon;
    do {
        numeropokemon = rand() % (4 - 1);
    }while(numeropokemon == tupokemon);
    switch (numeropokemon) {
    case 1:
        combatiente[1] = *greninja;
        break;
    case 2:
        combatiente[1] = *bulbasaur;
        break;
    case 3:
        combatiente[1] = *charizard;
        break;
    case 4:
        combatiente[1] = *pikachu;
        break;
    default:
        combatiente[1] = *pikachu;
        break;
    }
    combatiente[0].mostrar();
    combatiente[1].mostrar();
    combatiente[1].atacar();
    do {
        std::cout << "-----------------------------\n";
        std::cout << "|    Escoge a una accion    |\n";
        std::cout << "|       1.- Atacar          |\n";
        std::cout << "|       2.- Curar           |\n";
        std::cout << "-----------------------------\n";
        switch (numeroeleccion) {
            
        }
    } while (victoria != 1);
}

