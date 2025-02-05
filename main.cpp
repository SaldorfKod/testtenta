#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef enum ComputerTypes  {Desktop, Laptop, Mainframe, Supercomputer};

const std::vector<std::string> ComputerManufactures = {
    "Apple", "Dell",    "HP",      "Lenovo", "Acer",      "Asus", "Microsoft", "Samsung", "Toshiba",   "Sony",
    "MSI",   "Gateway", "Fujitsu", "HCL",    "Panasonic", "LG",   "IBM",       "Compaq",  "Alienware", "Razer"};

// todo - it is possible to link the models to brands in the future.
const std::vector<std::string> ComputerModels = {
    "MacBook Air", "MacBook Pro",   "iMac",         "Mac mini",  "Inspiron",       "XPS",         "Alienware",
    "Latitude",    "Precision",     "Spectre",      "Envy",      "Pavilion",       "EliteBook",   "ThinkPad",
    "Yoga",        "Legion",        "IdeaPad",      "Aspire",    "Predator",       "TravelMate",  "Swift",
    "ZenBook",     "ROG",           "VivoBook",     "TUF",       "Surface Laptop", "Surface Pro", "Surface Book",
    "Galaxy Book", "Notebook",      "Odyssey",      "Satellite", "VAIO",           "GS Series",   "GE Series",
    "GL Series",   "ThinkCentre",   "ThinkStation", "Presario",  "Area-51",        "m15",         "Aurora",
    "Blade",       "Blade Stealth", "NUC"};

const std::vector<std::string> ComputerCPUManufactures = {"Intel", "AMD", "ARM", "IBM", "Apple"};

const std::vector<std::string> ComputerCPUTypes = {
    "Dual-Core", "Quad-Core", "Hexa-Core", "Octa-Core", "Deca-Core", "Heterogeneous System Architecture",
    "ARM",       "x86",       "64-bit",    "32-bit",    "RISC",      "CISC"};

const std::vector<std::string> ComputerCPUModels = {
    "Core i9-11900K", "Core i7-11700K", "Core i5-11600K", "Core i3-10100",  "Xeon E-2278G", "Pentium Gold G6400",
    "Ryzen 9 5950X",  "Ryzen 7 5800X",  "Ryzen 5 5600X",  "Ryzen 3 3300X",  "EPYC 7763",    "Athlon 3000G",
    "Apple M1",       "Apple M1 Max",   "Apple M1 Ultra", "Apple M2",       "Apple M2 Pro", "Apple M2 Max",
    "Apple M3 Ultra", "Apple M3 Pro",   "Apple M3 Max",   "Apple M3 Ultra", "IBM POWER9",   "ARM Cortex-A78",
    "ARM Cortex-A76", "ARM Cortex-A55"};

const std::vector<std::string> ComputerGPUManufactures = {
    "NVIDIA", "AMD", "Intel", "ARM", "Qualcomm",
};

const std::vector<std::string> ComputerGPUTypes = {"Integrated", "Discrete"};

const std::vector<std::string> ComputerGPUModels = {"NVIDIA GeForce RTX 3090",
                                                    "NVIDIA GeForce RTX 3080",
                                                    "NVIDIA GeForce RTX 3070",
                                                    "NVIDIA GeForce GTX 1660 Ti",
                                                    "NVIDIA GeForce GTX 1660 Super",
                                                    "NVIDIA GeForce GTX 1660",
                                                    "NVIDIA GeForce GTX 1650 Super",
                                                    "NVIDIA GeForce GTX 1650",
                                                    "AMD Radeon RX 6900 XT",
                                                    "AMD Radeon RX 6800 XT",
                                                    "AMD Radeon RX 6700 XT",
                                                    "Intel Xe Graphics",
                                                    "ARM Mali-G78 MP14",
                                                    "Qualcomm Adreno 660",
                                                    "Imagination PowerVR GT7600",
                                                    "VIA S3 Graphics Chrome 520",
                                                    "Matrox Millennium G200",
                                                    "SiS 315",
                                                    "3dfx Voodoo3",
                                                    "S3 Graphics Savage4",
                                                    "XGI Volari V8",
                                                    "Trident Blade3D",
                                                    "ATI Radeon 9800 Pro"};

// todo - add more component names


class Computer
{
private:
    ComputerTypes type;
    std::string manufacturer;
    std::string model;
    std::string cpu;
    int price;
public:
    Computer(){
        type = ComputerTypes(rand() % (sizeof(ComputerTypes)));

        manufacturer = ComputerManufactures[(rand() % ComputerManufactures.size())];

        model = ComputerModels[rand() % ComputerModels.size()];
        cpu = ComputerCPUModels[(rand() % ComputerCPUModels.size())];
        price = 100 * ((rand() % 300 ) + 100);
    }
    ComputerTypes getType(){
        return type;
    }
    std::string getManufacturer()
    {
        return manufacturer;
    }

    std::string getModel()
    {
        return model;
    }

    std::string getCpu()
    {
        return cpu;
    }

    int getPrice() {
        return price;
    }

};

int main(){
    srand(time(0));
    Computer a;
    std::vector<Computer> computers;
    for(int i = 0; i < 1000;i++){
        computers.push_back(Computer());
    }


    // SKRIV KOD (obs! använd <ALGORITHM> och EFFEKTIVA sådana ) SOM...

    //1. Hur många Dell finns det?
    int antalDell = std::count_if(std::begin(computers), std::end(computers), [](Computer &c){
        return c.getManufacturer() == "Dell";
    });
    std::cout << "Det finns " << antalDell << " stycken Dell-datorer." << std::endl; 

    //2. Sortera alla i prisordning (billigast först)
    //   skriv ut de 10 första
    std::sort(std::begin(computers), std::end(computers), [](Computer c2, Computer c3)
              { return c2.getPrice() < c3.getPrice(); });
    //std::cout << computers[0].getPrice() << std::endl;
    //std::cout << computers[0].getModel() << std::endl;
    //int j = 10;
    std::cout << "De 10 billigaste datorerna: " << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << computers[i].getManufacturer() << " " << computers[i].getModel() << " för" << computers[i].getPrice() << "kr." << std::endl;
    }

    // 3. Finns det nån som skapar kostar mer än 41500 kr?
    //std::cout << "Dessa datorer kostar mer än 39000kr: " << std::endl;
    int counter = 0;
    for (Computer c : computers){
        if (c.getPrice() >= 39500)
        {
            counter ++;
        }
    }
    if (counter > 0){
        std::cout << "Det finns " << counter << " datorer som kostar minst 39500." << std::endl;
    }
    if (counter = 0) {
        std::cout << "Det finns inga datorer som kostar 41500 eller mer." << std::endl;
    }
    
        
        
    

    // 4. Räkna många Desktop-datorer med Core i9-11900K det finns
    int cpu = 0;
    for (Computer c : computers)
    {
        if (c.getCpu() == "Core i9-11900K")
        {
            cpu++;
        }
    }
    std::cout << "Det finns " << cpu << "datorer med Core i9-11900K." << std::endl;
    // /5.  Sortera så att det är i descending  LÄNGD-ordning för  ComputerCPUModels
    //                  dvs först alla Pentium Gold G6400, sist alla Apple M1 och Apple M2
    //                  de som har samma sorterar du på ComputerManufactures ascending

    return 0;
    }
