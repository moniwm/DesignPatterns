/**
 *
 * @brief Code example for an Abstract Factory design pattern
 * @author Mónica Waterhouse
 *
*/

#include <iostream>

class VirtualAssistant{
public:
    virtual ~VirtualAssistant()= default;;
    virtual std::string sayHello() const = 0;
};

class Siri : public VirtualAssistant{
public:
    std::string sayHello() const override{
        return "Hello! I'm Siri! \n";
    }
};

class Google : public VirtualAssistant{
public:
    std::string sayHello() const override{
        return "Hello! I'm Google! \n";
    }
};

class Phone{
public:
    virtual ~Phone()= default;;
    virtual std::string makePhoneCalls() const = 0;
};

class iPhone : public Phone{
public:
    std::string makePhoneCalls() const override{
        return "Making phone call with an iPhone! \n";
    }
};

class Huawei: public Phone{
public:
    std::string makePhoneCalls() const override{
        return "Making phone call with a Huawei! \n";
    }
};

class AbstractFactory{
public:
    virtual VirtualAssistant *createVirtualAssistant() const = 0;
    virtual Phone *createPhone() const = 0;

};

class Factory1 : public AbstractFactory{
public:
     VirtualAssistant *createVirtualAssistant() const override{
         return new Siri();
     }
     Phone *createPhone() const override{
         return new iPhone();
     }
};

class Factory2 : public AbstractFactory{
public:
    VirtualAssistant *createVirtualAssistant() const override{
        return new Google();
    }
    Phone *createPhone() const override{
        return new Huawei();
    }
};

void productRequest(const AbstractFactory &factory){
    const VirtualAssistant *assistant = factory.createVirtualAssistant();
    const Phone *phone = factory.createPhone();

    std::cout << "Creating product! \n";
    std::cout << assistant->sayHello() << "\n";
    std::cout << phone->makePhoneCalls() << "\n";

    delete assistant;
    delete phone;

}


int main(){

    std::cout << "Creating first product... \n";
    Factory1 *iphoneProduct = new Factory1();
    productRequest(*iphoneProduct);
    delete iphoneProduct;

    std::cout << "--------------------- \n";
    std::cout << "Creating second product... \n";
    Factory2 *huaweiProduct = new Factory2();
    productRequest(*huaweiProduct);
    delete huaweiProduct;
    return 0;

}