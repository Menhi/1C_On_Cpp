#include <Includes.h>
#include <Counterparty.h>

void addCounterparty (std::vector <Counterparty> &allCounterparties){
    system("cls");
    std::cout<<"Enter name of Counterparty: ";
    std::string tempName;
    std::cin >> tempName;
    std::cin.ignore();
    allCounterparties.emplace_back(allCounterparties.back().getCode()+1, tempName, 0);
    system("cls");
    std::cout<<"Counterparty saved.\n\n";
}

void showCounterparties (std::vector <Counterparty> allCounterparties){
    system("cls");
    std::cout<<"Code Name    Discount persentage\n";
    for (auto counterparty : allCounterparties){
        if (counterparty.getCode() != 0)
            counterparty.show();
    }
    std::cout<<"\n\n";
}





void saveCounterpartiesToFile(std::vector<Counterparty>& counterparties) {
    std::ofstream outputFile("Сounterparties.txt");
    if (outputFile.is_open()) {
        for (auto& counterparty : counterparties)
            outputFile <<counterparty.getCode()<<" "
                      <<counterparty.getName()<<" "
                     <<counterparty.getDiscount()<<"\n";
        outputFile.close();
        std::cout << "Counterparties have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Сounterparties." << std::endl;
    }
}

int loadCounterpartiesFromFile(std::vector<Counterparty>& counterparties)
{
    std::ifstream inputFile("Сounterparties.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Сounterparties.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 9" << std::endl;
            return 9;
        }
        outputFile << "0 0 0 0\n";
        outputFile.close();

        inputFile.open("Сounterparties.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 10" << std::endl;
            return 10;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int Code;
        std::string Name;
        int Discount;

        if (iss >> Code >> Name >> Discount) {
            counterparties.emplace_back(Code, Name, Discount);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}



