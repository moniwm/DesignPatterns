/**
 * Example of the IObserver dessign pattern
 * @author Monica Waterhouse
 *
*/

#include <iostream>
#include <list>
#include <string>

class IObserver{
public:
    virtual ~IObserver(){};
    virtual void update(const std::string &message) = 0;
};

class ISubject{
public:
    virtual ~ISubject(){};
    virtual void attach(IObserver *observer)  = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify()  = 0;
};

class Subject : ISubject{

    std::list<IObserver *> listObservers;
    std::string message;

public:
    virtual ~Subject(){
        std::cout << "Closing observer \n";
    }

    void attach(IObserver *observer) override{
        listObservers.push_back(observer);
    }

    void detach(IObserver *observer) override{
        listObservers.remove(observer);
    }

    void notify() override{
        std::list<IObserver *>::iterator iterator = listObservers.begin();
        while(iterator != listObservers.end()){
            (*iterator)->update(message);
            ++iterator;
        }
    }

    void createMessage(std::string message){
        this->message = message;
        notify();
    }

};

class Observer : public IObserver{

    std::string message;
    Subject &subject;
    static int staticNumber;
    int number;

public:
    Observer(Subject &subject) : subject(subject){
        this->subject.attach(this);
        std::cout << "User number " << ++Observer::staticNumber << "\n";
        this->number = Observer::staticNumber;
    }

    void update(const std::string &message) override{
        this->message = message;
        std::cout << "Message received: " << this->message <<"\n";
    }

    ~Observer(){
        std::cout <<"Bye user: " << this->number << "\n";
    }

    void removeMeFromTheList() {
        subject.detach(this);
        std::cout << "IObserver: " << number<< " has been removed from the list.\n";
    }

};

int Observer::staticNumber = 0;

void client(){
    Subject *appleHQ = new Subject();
    Observer *user1 = new Observer(*appleHQ);
    Observer *user2 = new Observer(*appleHQ);
    Observer *user3 = new Observer(*appleHQ);

    appleHQ->createMessage("New software update! \n");
    user2->removeMeFromTheList();

    appleHQ->createMessage("Tips about iOS 14! \n");
    Observer *user4 = new Observer(*appleHQ);

    appleHQ->createMessage("Coming to the app store! \n");

    delete user1;
    delete user2;
    delete user3;
    delete user4;
}

int main(){
    client();
    return 0;
}
