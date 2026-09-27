#include <iostream>
using namespace std;

class Vehicle {
public:
    void SetSpeed(int speedToSet) {
        speed = speedToSet;
    }

    void PrintSpeed() {
        cout << speed;
    }

private:
    int speed;
};

class Carriage {
public:
    void SetSeats(int seatsToSet) {
        seats = seatsToSet;
    }

    void PrintSeats() {
        cout << seats << " seats in cart";
    }

private:
    int seats;
};

class AnimalDrawnCarriage : public Vehicle, public Carriage {
public:
    void SetAnimal(string animalToSet) {
        animal = animalToSet;
    }

    void PrintAnimalSpeed() {
        cout << animal << " speed: ";
        PrintSpeed();
    }

private:
    string animal;
};

int main() {
    AnimalDrawnCarriage cart;

    cart.SetSpeed(7);
    cart.SetSeats(3);
    cart.SetAnimal("Donkey");

    cart.PrintAnimalSpeed();
    cout << endl;
    cart.PrintSeats();

    return 0;
}