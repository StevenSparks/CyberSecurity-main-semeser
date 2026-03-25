/*
* Made by Steven Sparks
* finished on 1/12/2025
* with the help of https://sternumiot.com/iot-blog/memory-corruption-examples-impact-and-4-ways-to-prevent-it/
* purpose of code is to showcase two exploits, and understand them how they happen and why.
*/

using namespace std;
#include <iostream>
#include <cstring>

void printHeader()
{
    cout << endl << "Demo PRP memory corruption" << endl;
    cout << "---------------------------" << endl;
}

void printMenu()
{
    cout << "1: Quit program" << endl;
    cout << "2: Buffer Overflow  demo" << endl;
    cout << "3: Use-After-Free demo" << endl;
}

int getUserinputNumber()
{
    int choice = 0;

    cin >> choice;

    //if input is anything but INT specified
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        choice = -1;
    }

    return choice;
}

void showcaseBufferOverflow()
{   
    cout << "Buffer Overflow exploit" << endl  << "---------------------------" << endl;
    char buffer[10];
    char largeInput[] = "TooLongInputDataExceedingBuffer";

    cout << "largeInput originally: "  << largeInput << endl;

    strcpy(buffer, largeInput);

    cout << "largeInput after using strcpy : " << largeInput << endl;
    cout << "---------------------------" << endl;
    
    cout.clear();
}

void UAFprint()
{
    cout << "u have been pwned" << endl;
}

class UAFResource
{
    public:
    int Data;
    void (*Ptr)();
};

void showcaseUseAfterFree()
{
    cout << "Use After Free exploit" << endl  << "---------------------------" << endl;
    cout << "create Resource with function pointer" << endl;
    UAFResource *res = (UAFResource*)malloc(sizeof(UAFResource));
    res->Data = 12;
    res->Ptr = NULL;

    cout << "free resource, improper deconstructor didnt free function pointer" << endl;
    free(res);
    
    cout << "set pointer of freed resource to own controlled function, and execute" << endl; 
    res->Ptr = UAFprint;
    res->Ptr();
}

int main()
{
    printHeader();
    bool run = true;
    
    while (run == true)
    {
        printMenu();

        int choice = getUserinputNumber();

        switch (choice)
        {
        case 1:
            run = false;
            break;
        
        case 2:
            showcaseBufferOverflow();
            break;   

        case 3:
            showcaseUseAfterFree();
            break;

        default:
            cout << "Not a number / Invalid Option: " << endl;
            break;
        }
    }
        
    cout << "exiting program." << endl;
}