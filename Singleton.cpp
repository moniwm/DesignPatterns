/**
 * @brief Singleton pattern example
 * @author Monica Waterhouse Montoya
 *
*/

#include <iostream>

class Country{

    static Country *instance;
    std::string name;

    Country(std::string name){
        this->name = name;
    }

public:

    std::string getCountryName(){
        return this->name;
    }

    static Country *getInstance(const std::string &name);
};

Country *Country::instance= nullptr;

Country *Country::getInstance(const std::string &name) {
    if(instance == nullptr){
        instance = new Country(name);
    }
    else{
        std::cout << "Sorry, " << name << " has already been instantiated. \n";
    }
    return instance;
}

int main(){
    std::cout << "Create Costa Rica instance...\n";
    Country *costaRica = Country::getInstance("Costa Rica");
    std::cout << "Country name: " << costaRica->getCountryName();

    std::cout << "---------------------------------\n";
    std::cout << "Trying to duplicate Costa Rica instance...\n";
    Country *country = Country::getInstance("Costa Rica");

    delete costaRica;
    delete  country;

    return 0;
}