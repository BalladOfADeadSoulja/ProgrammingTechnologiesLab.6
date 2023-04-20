#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Car { //главный класс автомобиль
private:
    string brand;
    string model;
    string horsepower;
    string mileage;
    string color;
    string body;
public:
    Car(string brand, string model, string horsepower, string mileage) {
        this->brand = brand;
        this->model = model;
        this->horsepower = horsepower;
        this->mileage = mileage;
    }

    string getColor(string color) {
        cout << "Color body: White";
        return color;
    }

   virtual void setColor() {
        this->color = color;
    }

    string getBody(string body) {
        cout << "Car body size: middle size";
        return body;
    }

    virtual void setBody() {
        this->body = body;
    }

    virtual ~Car() {}

    string getBrand() {
        cout << "Enter brand: ";
        cin >> brand;
        return brand;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    string getModel() {
        cout << "Enter model: ";
        cin >> model;
        return model;
    }

    void setModel(string model) {
        this->model = model;
    }

    string getAge() {
        cout << "Enter mileage: ";
        cin >> mileage;
        return mileage;
    }

    void setAge() {
        this->mileage = mileage;
    }

    string getPower() {
        cout << "Enter horse power: ";
        cin >> horsepower;
        return horsepower;
    }

    void setPower() {
        this->horsepower = horsepower;
    }

};//должны быть 2 перекрытые в каждом классе

class PassengerCar : public Car { //класс легковой автомобиль
private:
    int passengers;//пассажиры
    int ProductionYear;//Год производства
public:
    PassengerCar(string brand, string model, string horsepower, string mileage, int passengers, int ProductionYear, string color, string body) : Car(brand, model, horsepower, mileage) {
        this->passengers = passengers;
        this->ProductionYear = ProductionYear;
        setColor(color);
        setBody(body);
    }

    string getColor() {
        char str[25] = { "Color body: Red" };
        return str;
    }

    virtual void setColor(string color) {
        color = color; //color = "red";
    }

    string getBody() {
        char str2[25] = { "Car body size: small" };
        return str2;
    }

    virtual void setBody(string body) {
        body = body; //body = "small";
    }

    int getPassengers() {
        cout << "Enter passengers: ";
        cin >> passengers;
        return passengers;
    }

    void setPassengers(int passengers) {
        this->passengers = passengers;
    }

    int getProductionYear() {//получить объем багажника
        cout << "Enter ProductionYear: ";
        cin >> ProductionYear;
        return ProductionYear;
    }

    void setProductionYear(int ProductionYear) {
        this->ProductionYear = ProductionYear;
    }
};

class Truck : public Car { //класс грузовик
private:
    int payloadCapacity;
    int bodyLength;
public:
    Truck(string brand, string model, string horsepower, string mileage, int payloadCapacity, int bodyLength, string color, string body) : Car(brand, model, horsepower, mileage) {
        this->payloadCapacity = payloadCapacity;//Грузоподъемность
        this->bodyLength = bodyLength;//Длина грузовика
    }

    string getColor() {
        char str[25] = { "Color body: green" };
        return str;
    }

    virtual void setColor(string color) {
        color = color;//color = "green";
    }

    string getBody() {
        char str2[25] = { "Car body size: Large" };
        return str2;
    }

    virtual void setBody(string body) {
        body = body;//body = "Large";
    }

    int getPayloadCapacity() {
        cout << "Enter payloadCapacity: ";
        cin >> payloadCapacity;
        return payloadCapacity;
    }

    void setPayloadCapacity(int payloadCapacity) {
        this->payloadCapacity = payloadCapacity;
    }

    int getBodyLength() {
        cout << "Enter bodyLength: ";
        cin >> bodyLength;
        return bodyLength;
    }

    void setBodyLength(int bodyLength) {
        this->bodyLength = bodyLength;
    }
};

int main() {

    cout << "Enter a number of car: ";
    int count; cin >> count;
    cout << endl;
    int* mas = new int[count];
    char x;
    for (int i = 0; i < count; i++)
    {
    start:
        cout << "Enter truck or not? (T or L): ";
        cin >> x; cout << endl;
        if (x == 'l' || x == 'L')
        {
            Car* car1 = new PassengerCar(" ", " ", " ", " ", NULL, NULL, " ", " ");
            cout << "Car 1: " << car1->getBrand() << " " << car1->getModel() << endl;
            cout << dynamic_cast<PassengerCar*>(car1)->getPassengers() << endl;
            cout << dynamic_cast<PassengerCar*>(car1)->getProductionYear() << endl;
            cout << dynamic_cast<PassengerCar*>(car1)->getAge() << endl;
            cout << dynamic_cast<PassengerCar*>(car1)->getPower() << endl;
            cout << dynamic_cast<PassengerCar*>(car1)->getColor() << endl;
            cout << dynamic_cast<PassengerCar*>(car1)->getBody() << endl;
            cout << endl;
            delete car1;
        }
        else if (x == 't' || x == 'T')
        {
            Car* car2 = new Truck(" ", " ", " ", " ", NULL, NULL, " ", " ");
            cout << "Car 2: " << car2->getBrand() << " " << car2->getModel() << endl;
            cout << dynamic_cast<Truck*>(car2)->getBodyLength() << endl;
            cout << dynamic_cast<Truck*>(car2)->getPayloadCapacity() << endl;
            cout << dynamic_cast<Truck*>(car2)->getAge() << endl;
            cout << dynamic_cast<Truck*>(car2)->getPower() << endl;
            cout << dynamic_cast<Truck*>(car2)->getColor() << endl;
            cout << dynamic_cast<Truck*>(car2)->getBody() << endl;
            cout << endl;
            delete car2;
        }
    }
    system("pause");

    return 0;
}

//Иерархия классов :
//- Родительский класс "Автомобиль" (Car)
//- Члены данных : марка(brand), модель(model)
//- Функции : конструктор(Car), деструктор(~Car), геттеры и сеттеры для марки и модели
//
//- Дочерний класс "Легковой автомобиль" (PassengerCar), наследуется от класса "Автомобиль"
//- Дополнительные члены данных : количество пассажиров(passengers), год выпуска(ProductionYear)
//- Перекрытые функции : геттеры и сеттеры для количества пассажиров и года выпуска
//
//- Дочерний класс "Грузовой автомобиль" (Truck), наследуется от класса "Автомобиль"
//- Дополнительные члены данных : грузоподъемность(payloadCapacity), длина кузова(bodyLength)
//- Перекрытые функции : геттеры и сеттеры для грузоподъемности и длины кузова
// 
//  Для доступа к дополнительным членам данных и функциям дочерних классов используется приведение типов (dynamic_cast).
