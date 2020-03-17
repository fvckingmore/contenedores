#ifndef UI_HPP
#define UI_HPP


#include <iostream>
#include <vector>
#include "../logManip/log.hpp" 
#include "../logManip/logFilter.hpp"


using namespace std;

class UI {

private:

	Log log;
	bool isDateEntry;

public:

	UI(Log &log) {

		this->log = log;
		this->isDateEntry = false;
	}

	void menu() {

		while(options()){}
	}


	void showOptions() {

		cout<< "BIENVENIDO"<<endl;
		cout<< "\t[1] Ingresar fecha\n";
		cout<< "\t[2] Total de Logs\n";
		cout<< "\t[3] Total de Eventos\n";
		cout<< "\t[4] Total de Cuentas\n";
		cout<< "\t[5] Cuentas con mas Eventos\n";
		cout<< "\t[6] Eventos enviados\n";
		cout<< "\t[7] Exportar a archivo\n";
		cout<< "\t[0] Salir\n\n";
	}


	bool options() {

		bool b = true;
		int op;

		scr();
		showOptions();

		cout<< "\tOpcion -> ";
		cin>>op;
		cout<<endl;

		switch(op) {

			case 1:
				cout<<"Ingresar fecha"<<endl;
				readKey();
				scr();
				break;

			case 2:
				cout<<"Total de logs"<<endl;
				readKey();
				scr();
				break;

			case 3:
				cout<<"total de eventos"<<endl;
				readKey();
				scr();
				break;

			case 4:
				cout<<"total de cuentas"<<endl;
				readKey();
				scr();
				break;

			case 5:
				cout<<"cuentas con mas eventos"<<endl;
				readKey();
				scr();
				break;

			case 6:
				cout<<"eventos enviados"<<endl;
				readKey();
				scr();
				break;

			case 7:
				cout<<"exportar archivo"<<endl;
				readKey();
				scr();
				break;

			case 0:
				b = false;
				scr();
				break;

			default:
				cout<< "Error";
				readKey();
				scr();
				break;

		}


		return b;
	}


	void getDate() {

		
	} 


	void scr() { 

	#ifdef __linux__
		system("clear");
	#elif _WIN32
		system("cls");
	#endif
}


/* Presione una tecla para continuar... */

void readKey() {

	buf();

	cout<< "Presione enter para continuar...";
	#ifdef __linux__
		getchar();
	#elif _WIN32
		getch();
	#endif
}


/* Limpia buffer */

void buf() { 

	#ifdef __linux__
		int c; while ( (c = fgetc(stdin)) != EOF && c != '\n' ) {}
	#elif _WIN32
		fflush(stdin);
	#endif
}



};

#endif