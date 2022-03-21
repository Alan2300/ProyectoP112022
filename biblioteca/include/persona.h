#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#ifndef PERSONA_H
#define PERSONA_H
using namespace std;

class persona
{
    public:
        persona();
        virtual ~persona();
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();

    protected:

    private:
        string id,name,phone,college,address;
};

#endif // PERSONA_H
