#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(const string& name) : name(name) {}
};

class Pet {
public:
    virtual void Feed(int foodAmount, int randomNumber) = 0;
};

class Dog : public Animal, public Pet {
public:
    Dog(const string& name) : Animal(name) {}
    void Feed(int foodAmount, int randomNumber) override {
        cout << "Покормите Собаку: " << name << endl;
        if (randomNumber >= foodAmount - 10 && randomNumber <= foodAmount + 10) {
            cout << "Собака жива." << endl;
        } else {
            cout << "Собака умерла." << endl;
        }
    }
};

class Cat : public Animal, public Pet {
public:
    Cat(const string& name) : Animal(name) {}
    void Feed(int foodAmount, int randomNumber) override {
        cout << "Покормите котика: " << name << endl;
        if (randomNumber >= foodAmount - 10 && randomNumber <= foodAmount + 10) {
            cout << "Котик жив." << endl;
        } else {
            cout << "Котик умер." << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int foodAmount;
    string dogName, catName;

    cout << "Введите количество нямок: ";
    cin >> foodAmount;

    while (foodAmount < 1 || foodAmount > 100) {
        cout << "Ошибка: Введите число от 1 до 100: ";
        cin >> foodAmount;
    }

    cout << "Введите имя пёсика: ";
    cin >> dogName;
    cout << "Введите имя котика: ";
    cin >> catName;

    int dogRandom = rand() % 101;
    int catRandom = rand() % 101;

    Dog dog(dogName);
    Cat cat(catName);

    dog.Feed(foodAmount, dogRandom);
    cat.Feed(foodAmount, catRandom);

    return 0;
}