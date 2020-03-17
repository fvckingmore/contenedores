#ifndef UI_HPP
#define UI_HPP


#include <iostream>
#include <vector>
#include "log.hpp" 
#include "logFilter.hpp"


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

	/* Ciclo principal del programa */
	void menu() {

		while(options()){}
	}


	/* Muestra opciones principales */
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


	/* Opciones principales */
	bool options() {

		bool b = true;
		int op;
		LogFilter lf;	// Objeto LogFilter
		string date;

		scr();
		showOptions();

		cout<< "\tOpcion -> ";
		cin>>op;
		cout<<endl;

		switch(op) {

			case 1:	// Ingreso de fecha
				date = getDate();
				
				if(isDateEntry) lf.getLogData("signals.log", log, date);
				readKey();
				scr();
				break;

			case 2:	//Muestra Logs totales
				if(isDateEntry) cout<<"Logs totales: "<<log.getLogsCount()<<"\n\n";
				else cout<< "Debe ingresar una fecha\n\n"; 
				readKey();
				scr();
				break;

			case 3:	//Muestra total de eventos recibidos
				if(isDateEntry) 
					cout<<"Eventos recibidos: "<<log.getEventsCount()<<"\n\n";
				else cout<< "Debe ingresar una fecha\n\n";
				readKey();
				scr();
				break;

			case 4:	// Muestra total de cuentas
				if(isDateEntry) 
					cout<<"Cuentas totales: "<<log.getAccountCount()<<"\n\n";
				else cout<< "Debe ingresar una fecha\n\n";
				readKey();
				scr();
				break;

			case 5:	// Muestra cuentas con cantdad de eventos
				if(isDateEntry) log.getAccountWithMoreEvents();
				else cout<< "Debe ingresar una fecha\n\n";
				readKey();
				scr();
				break;

			case 6:	// Muestra lista de eventos
				if(isDateEntry) log.getEvents();
				else cout<< "Debe ingresar una fecha\n\n";
				readKey();
				scr();
				break;

			case 7:	// Exporta a archivo csv
				if(isDateEntry) log.exportToCSV();
				else cout<< "Debe ingresar una fecha\n\n";
				readKey();
				scr();
				break;

			case 0:	// Salida
				b = false;
				scr();
				break;

			default:	// Error
				cout<< "Error\n\n";
				readKey();
				scr();
				break;
		}

		return b;
	}


	/* Obtiene fecha para validar */
	string getDate() {

		string date;
		cout<<"Ingrese la fecha a buscar en formato (AAAA-MM-DD): ";
		//cin.ignore(numeric_limits<int>::max(),'\n');	// Limpia buffer
		//getline(cin, date, '\n');
		cin>>date;
		cout<<endl;
		if(date.find('-') != string::npos && date.size() == 10) {

			this->isDateEntry = true;
			return date;
		}
		cout<<"Fecha incorrecta\n\n";

		return "";
	} 


	/* Limpia pantalla */
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