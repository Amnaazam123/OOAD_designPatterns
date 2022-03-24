//This pattern is used to hide complexity of your program

#include<iostream>
using namespace std;
class loadBIOS {
public:
    string Operation1() const {
        return "BIOS getting Ready........\n";
    }
    string Operation2() const {
        return "BIOS is Loaded.\n\n";
    }
};
class loadPOST {
public:
    string Operation1() const {
        return "POST getting Ready........\n";
    }
    string Operation2() const {
        return "POST is Loaded.\n\n";
    }
};
class loadOS{
public:
    string Operation1() const {
        return "OS getting Ready........\n";
    }
    string Operation2() const {
        return "OS is Loaded.\n\n";
    }
};
class configureSystem {
public:
    string Operation1() const {
        return "System configuration getting Ready........\n";
    }
    string Operation2() const {
        return "System Configuration completed.\n\n";
    }
};
class systemUtilities {
public:
    string Operation1() const {
        return "System Utilities getting Ready........\n";
    }
    string Operation2() const {
        return "System Utilities loaded.\n\n";
    }
};
class Authentication {
public:
    string Operation1() const {
        return "verifying Authentication ........\n";
    }
    string Operation2() const {
        return "Proofed authenticated.\n\n";
    }
};
class BootingAsFacade {
protected:
    loadBIOS* bios;
    loadPOST* post;
    loadOS* os;
    configureSystem* configSys;
    systemUtilities* utilities;
    Authentication* auth;
public:
    BootingAsFacade(loadBIOS* bios = nullptr, loadPOST* post = nullptr,loadOS* os=nullptr,configureSystem* configSys=nullptr,systemUtilities* ut=nullptr, Authentication* auth = nullptr)
    {
        this->bios = bios ? nullptr : new loadBIOS();
        this->post = post ? nullptr : new loadPOST();
        this->os = os ? nullptr : new loadOS();
        this->configSys = configSys ? nullptr : new configureSystem();
        this->utilities = ut ? nullptr : new systemUtilities();
        this->auth = auth ? nullptr : new Authentication();
    }
    string pressPowerButton() {
        string result = "Facade initializes booting process of computer \n-----After ONE CLICK by user:\n\n";
        result += this->bios->Operation1();
        result += this->bios->Operation2();
        result += this->post->Operation1();
        result += this->post->Operation2();
        result += this->os->Operation1();
        result += this->os->Operation2();
        result += this->configSys->Operation1();
        result += this->configSys->Operation2();
        result += this->utilities->Operation1();
        result += this->utilities->Operation2();
        result += this->auth->Operation1();
        result += this->auth->Operation2();
        result += "\n\n--------------Ended boot process----------------\n";
        return result;
    }

    ~BootingAsFacade() {
        delete bios;
        delete post;
        delete os;
        delete configSys;
        delete utilities;
        delete auth;
    }
};
void ClientInterface(BootingAsFacade* client) {

    cout << client->pressPowerButton();
}

int main() {

    BootingAsFacade* BootComputer = new BootingAsFacade();
    ClientInterface(BootComputer);
    delete BootComputer;
    return 0;
}
