// MyMeanOfTransport.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <vector>

using namespace std;
class Person
{
private:
    string _name;
    string _surname;
    const int _id = 1;

public:
    Person() {};
    Person(const string& Name, const string& Surname) : _name(Name), _surname(Surname) {};

    string GetName() {
        return _name;
    }
    string GetSurname() {
        return _surname;
    }
    int GetId() {
        return _id;
    }

    void SetName(const string& Name) {
        _name = Name != "" ? Name : throw exception("Error");
    }
    void SetSurame(const string& Surname) {
        _surname = Surname != "" ? Surname : throw exception("Error");
    }

};

class Cargo
{
private:
    string _type;
    double _weight;
    const int _id = 2;

public:
    Cargo() {};
    Cargo(const string& Type, const double& Weight) : _type(Type), _weight(Weight) {};

    string GetType() {
        return _type;
    }
    double GetWeight() {
        return _weight;
    }
    int GetId() {
        return _id;
    }

    void SeType(const string& Type) {
        _type = Type != "" ? Type : throw exception("Error");
    }
    void SetWeight(const double& Weight) {
        _weight = Weight != NULL || Weight != 0 ? Weight : throw exception("Error");
    }
};
class MyTransport
{
protected:
    vector<Person> _persons;
    vector<Cargo> _cargos;
    double _distanceKM;
    double _timeHours;
    double _speedKMH;
public:
    virtual double TimeCalculate() = 0;
    virtual double CostCalculateCargo() = 0;
    virtual double CostCalculatePerson() = 0;
    virtual void PrintInfo() = 0;
};

class MyAutomobile : public MyTransport
{
private:
    const double _costPerson = 1000;
    const double _costCargo = 500;
    const double _maxWeightKG = 100;
    const int _maxPersonNumber = 3;

public:

    MyAutomobile() {};
    MyAutomobile(const Person PersonN, const double& DistanceKM) 
    {
        _persons.push_back(PersonN);
        _distanceKM = DistanceKM;
        _speedKMH = 60;
        _timeHours = _distanceKM / _speedKMH;
    };
    MyAutomobile(const Cargo CargoN, const double& DistanceKM)
    {
        _cargos.push_back(CargoN);
        _distanceKM = DistanceKM;
        _speedKMH = 60;
        _timeHours = _distanceKM / _speedKMH;
    };

    double CostCalculatePerson() {
        double temp = 0, tempPerson = 0;
        if (_persons.size() == 0) return temp;

        for (int i = 0; i < _persons.size(); i++)
        {
            temp += _costPerson;
            tempPerson++;
            if (tempPerson >= _maxPersonNumber) break;
        }
        return temp;
    }

    double CostCalculateCargo() {
        double temp = 0, tempWeight = 0;

        if (_cargos.size() == 0) return temp;

        for (int i = 0; i < _cargos.size(); i++)
        {
            temp += _costCargo;
            tempWeight += _cargos[i].GetWeight();
            if (tempWeight >= _maxWeightKG) break;
        }
        return temp;
    }

    double GetTotalCost() {
        return CostCalculatePerson() + CostCalculateCargo();
    }

    double TimeCalculate() {
        return _timeHours != NAN ? _timeHours : throw exception("Error");
    }

    void PrintInfo() {
        cout << "Количество пассажиров -" << _persons.size() << endl
            << "Цена за каждого пассажира - " << _costPerson << endl
            << "Цена всех пассажиров - " << CostCalculatePerson() << endl
            << "Количество всех грузов - " << _cargos.size() << endl
            << "Цена за каждый груз - " << _costCargo << endl
            << "Цена всего груза - " << CostCalculateCargo() << endl
            << "Цена всей перевозки - " << GetTotalCost() << endl;
    }
};

class MyBicycle : public MyTransport
{
private:
    const double _costPerson = 100;
    const double _costCargo = 10;
    const double _maxWeightKG = 15;
    const int _maxPersonNumber = 2;

public:

    MyBicycle() {};
    MyBicycle(const Person PersonN, const double& DistanceKM)
    {
        _persons.push_back(PersonN);
        _distanceKM = DistanceKM;
        _speedKMH = 20;
        _timeHours = _distanceKM / _speedKMH;
    };
    MyBicycle(const Cargo CargoN, const double& DistanceKM)
    {
        _cargos.push_back(CargoN);
        _distanceKM = DistanceKM;
        _speedKMH = 20;
        _timeHours = _distanceKM / _speedKMH;
    };

    double CostCalculatePerson() {
        double temp = 0, tempPerson = 0;
        if (_persons.size() == 0) return temp;

        for (int i = 0; i < _persons.size(); i++)
        {
            temp += _costPerson;
            tempPerson++;
            if (tempPerson >= _maxPersonNumber) break;
        }
        return temp;
    }

    double CostCalculateCargo() {
        double temp = 0, tempWeight = 0;

        if (_cargos.size() == 0) return temp;

        for (int i = 0; i < _cargos.size(); i++)
        {
            temp += _costCargo;
            tempWeight += _cargos[i].GetWeight();
            if (tempWeight >= _maxWeightKG) break;
        }
        return temp;
    }

    double GetTotalCost() {
        return CostCalculatePerson() + CostCalculateCargo();
    }

    double TimeCalculate() {
        return _timeHours != NAN ? _timeHours : throw exception("Error");
    }

    void PrintInfo() {
        cout << "Количество пассажиров -" << _persons.size() << endl
            << "Цена за каждого пассажира - " << _costPerson << endl
            << "Цена всех пассажиров - " << CostCalculatePerson() << endl
            << "Количество всех грузов - " << _cargos.size() << endl
            << "Цена за каждый груз - " << _costCargo << endl
            << "Цена всего груза - " << CostCalculateCargo() << endl
            << "Цена всей перевозки - " << GetTotalCost() << endl;
    }
};

class MyCart : public MyTransport
{
private:
    const double _costPerson = 500;
    const double _costCargo = 200;
    const double _maxWeightKG = 70;
    const int _maxPersonNumber = 10;

public:

    MyCart() {};
    MyCart(const Person PersonN, const double& DistanceKM)
    {
        _persons.push_back(PersonN);
        _distanceKM = DistanceKM;
        _speedKMH = 40;
        _timeHours = _distanceKM / _speedKMH;
    };
    MyCart(const Cargo CargoN, const double& DistanceKM)
    {
        _cargos.push_back(CargoN);
        _distanceKM = DistanceKM;
        _speedKMH = 60;
        _timeHours = _distanceKM / _speedKMH;
    };

    double CostCalculatePerson() {
        double temp = 0, tempPerson = 0;
        if (_persons.size() == 0) return temp;

        for (int i = 0; i < _persons.size(); i++)
        {
            temp += _costPerson;
            tempPerson++;
            if (tempPerson >= _maxPersonNumber) break;
        }
        return temp;
    }

    double CostCalculateCargo() {
        double temp = 0, tempWeight = 0;

        if (_cargos.size() == 0) return temp;

        for (int i = 0; i < _cargos.size(); i++)
        {
            temp += _costCargo;
            tempWeight += _cargos[i].GetWeight();
            if (tempWeight >= _maxWeightKG) break;
        }
        return temp;
    }

    double GetTotalCost() {
        return CostCalculatePerson() + CostCalculateCargo();
    }

    double TimeCalculate() {
        return _timeHours != NAN ? _timeHours : throw exception("Error");
    }

    void PrintInfo() {
        cout << "Количество пассажиров -" << _persons.size() << endl
            << "Цена за каждого пассажира - " << _costPerson << endl
            << "Цена всех пассажиров - " << CostCalculatePerson() << endl
            << "Количество всех грузов - " << _cargos.size() << endl
            << "Цена за каждый груз - " << _costCargo << endl
            << "Цена всего груза - " << CostCalculateCargo() << endl
            << "Цена всей перевозки - " << GetTotalCost() << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");
}
