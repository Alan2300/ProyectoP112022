#include "persona.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

void persona::menu()//imprime el menú
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PERSONAS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Personas"<<endl;
	cout<<"\t\t\t 2. Despliegue Personas"<<endl;
	cout<<"\t\t\t 3. Modifica Personas"<<endl;
	cout<<"\t\t\t 4. Busca Personas"<<endl;
	cout<<"\t\t\t 5. Borra Personas"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1://si la opcion es 1
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";//da la opción de agregar otra peronsa: "Y(si)/N(no)
    		cin>>x;//impprime x
		}while(x=='y'||x=='Y');
		break;
	case 2://en caso de que sea 2, se va al metodo display
		display();
		break;
	case 3://en caso de que sea 3, se va al metodo modiy
		modify();
		break;
	case 4://en caso de que sea 4, se va al metodo search
		search();
		break;
	case 5://en caso de que sea 5, se va al metodo delet
		delet();
		break;
	case 6://en caso de que sea 6, se va al metodo exit
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";//si no elige ninguna opcion entre 1 y 6, despliega el mensaje
	}
	getch();
    }while(choice!= 6);
}
void persona::insert()//metodo insert
{
	system("cls");//en system("cls")
	fstream file;//fstream para abrir archivo
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";
	cin>>id;//guarda el id
	cout<<"\t\t\tIngresa Nombre Persona     : ";
	cin>>name;//guarda el nombre
	cout<<"\t\t\tIngresa Telefono Persona   : ";
	cin>>phone;//guarda el telefono
	cout<<"\t\t\tIngresa Universidad Persona: ";
	cin>>college;//Guarda la universidad
	cout<<"\t\t\tIngresa Direccion Persona  : ";
	cin>>address;//guarda la dirección
	file.open("ParticipantRecord.txt", ios::app | ios::out);//guarda los participantes en el archivo .txt
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	file.close();//cierra el archivo
}
void persona::display()//metodo display
{
	system("cls");
	fstream file;//se usa fstream para abrir un archvo
	int total=0;//inicializa total en 0
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);//abre el archivo .txt
	if(!file)//si no se abre el archivo despliega el mensaje de no información
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();//ciera el archivo
	}
	else//si el archivo se abre
	{
		file >> id >> name >> phone >> college >> address;//cosas que debera incluir
		while(!file.eof())//end of line
		{
			total++;
			//imprime los datos
			cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
			cout<<"\t\t\t Nombre Persona: "<<name<<endl;
			cout<<"\t\t\t Telefono Persona: "<<phone<<endl;
			cout<<"\t\t\t Universidad Persona: "<<college<<endl;
			cout<<"\t\t\t Direccion Persona: "<<address<<endl;
			file >> id >> name >> phone >> college >> address;
		}
		if(total==0)//si no hay ningun dato, despliega el mensaje
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();//cierra el archivo
}
void persona::modify()//metodo modify
{
	system("cls");
	fstream file,file1;
	string participant_id;//variable para buscar el id
	int found=0;//found inicializado en 0
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);//abre el archivo
	if(!file)//despliega mensaje si no hay información
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();//cierra archivo
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;//id de la persona que hay que modificar
		file1.open("Record.txt",ios::app | ios::out);//abre los datos de la persona
		file >> id >> name >> phone >> college >> address;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
			    //opción para modificar todos los datos
				cout<<"\t\t\tIngrese Id Persona: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Persona: ";
				cin>>name;
				cout<<"\t\t\tIngrese Telefono Persona: ";
				cin>>phone;
				cout<<"\t\t\tIngrese Universidad Persona: ";
				cin>>college;
				cout<<"\t\t\tIngrese Direccion Persona: ";
				cin>>address;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
				found++;
			}
			file >> id >> name >> phone >> college >> address;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
void persona::search()//metodo search
{
	system("cls");
	fstream file;//fstream para abrir archivo
	int found=0;//foun inicializada en 0
	file.open("ParticipantRecord.txt",ios::in);//abre el archivo
	if(!file)//si no hay información despliega mensaje
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;//variable para buscar id de la persona
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;//ingreso de id
		file >> id >> name >> phone >> college >> address;//abre los datos
		while(!file.eof())
		{
			if(participant_id==id)
			{
			    //muestra los datos
				cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
				cout<<"\t\t\t Nombre Persona: "<<name<<endl;
				cout<<"\t\t\t Telefono Persona: "<<phone<<endl;
				cout<<"\t\t\t Universidad Persona: "<<college<<endl;
				cout<<"\t\t\t Direccion Persona: "<<address<<endl;
				found++;
			}
			file >> id >> name >> phone >> college >> address;
		}
		if(found==0)//si no se encuentra el id
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();//cierra archivo
	}
}
void persona::delet()//metodo delete
{
	system("cls");
	fstream file,file1;
	string participant_id;//variable para id de la persona a borrar
	int found=0;//found en 0
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);//abre el archivo
	if(!file)//si no hay información despliega mensaje
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();//cierra archivo
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;//ingreso id de la persona a borrar
		file1.open("Record.txt",ios::app | ios::out);//abre el archivo
		file >> id >> name >> phone >> college >> address;//abre datos
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
			}
			else//borra los datos
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> phone >> college >> address;
		}
		if(found==0)//si no encuentra el id, despliega el mensaje
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		//cierre de archivos
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
persona::persona()
{
    //ctor
}

persona::~persona()
{
    //dtor
}
