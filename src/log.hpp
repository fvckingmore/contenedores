#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;
typedef map<string, int> eventTypeMap;

/* Utilidad para ordenas Logs */
bool sortByVal(const pair<string, int> &a, const pair<string, int> &b) { 
		return (a.second > b.second);
}


/* Clase Log */
class Log {

private:

	eventTypeMap eventMap;
	int logsCount;
	int eventsCount;
	map<string, eventTypeMap> logMap;
	vector<pair<string, int>> accounts;
	vector<pair<string, int>> events;

public:

	/* Constructor */
	Log() {
		logsCount = 0;
		eventsCount = 0;
	}

	/* Aumenta el contador de logs */
	void increaseLogsCount() {
		logsCount += 1;
	}

	/* Devuelve el contador de logs */
	int getLogsCount() {
		return logsCount;
	}

	/* Aumenta el contador de eventos */
	void increaseEventsCount() {
		eventsCount += 1;
	}

	/* Devuelve el contador de eventos */
	int getEventsCount() {
		return eventsCount;
	}

	/* Constructor de mapa de eventos vacio */
	eventTypeMap createEventTypeMap() {

		eventTypeMap newEventTypeMap;
		return newEventTypeMap;
	}

	/* Devuelve numero de cuentas */
	int getAccountCount() {
		return logMap.size();
	}

	/* Verifica si una cuenta existe */
	bool checkAccount(string accountToCheck) {

		if(logMap.find(accountToCheck) != logMap.end())
			return true;

		return false;
	}


	/* Verifica si un evento existe */
	bool checkEventType(string accountToCheck, string eventToCheck) {

		if(logMap.find(accountToCheck)->second.find(eventToCheck) !=
		logMap.find(accountToCheck)->second.end())
			return true;

		return false;
	}

	
	/* Agrega un log */
	void insertLog(string account, string eventType) {

		if(checkAccount(account)) {

			if(checkEventType(account, eventType)) {

				logMap.find(account)->second.find(eventType)->second += 1;

			} else {

				logMap.find(account)->second.insert({eventType, 1});
			}

		} else {

			logMap.insert({account, createEventTypeMap()});
		}
	}


	/* Verifica un evento repetido */
	bool checkEvent(string eventToCheck) {
		if(eventMap.find(eventToCheck) != eventMap.end())
			return true;
		return false;
	}


	/* Agrega un evento al mapa de eventos */
	void insertEvent(string eventType) {

		if(checkEvent(eventType)) {

			eventMap.find(eventType)->second += 1;

		} else {

			eventMap.insert({eventType, 1});
		}
	}


	/* Muestra lista de eventos con la cantidad de llamadas */
	void getEvents() {

		map<string, int>::iterator it = eventMap.begin();

		for(; it != eventMap.end(); it++) {
			events.push_back({it->first, it->second});
		}

		sort(events.begin(), events.end(), sortByVal);

		cout<< "\tEventos\t:\tCantidad\n\n";
		for(int i = 0; i < events.size(); i++) {
			cout<<"\t"<<events[i].first<< "\t:\t"<<events[i].second<< endl;
		}
		cout<<endl;
		return ;
	}


	/* Muestra las cuentas con mas eventos enviados */
	void getAccountWithMoreEvents() {

		if(accounts.size() == 0){ 
			//vector<pair<string, int>> accounts;
			map<string, eventTypeMap>::iterator it = logMap.begin();

			for(; it != logMap.end(); it++) {

				map<string, int>::iterator it2 = it->second.begin();
				int count = 0;
				for(; it2 != it->second.end(); it2++) {
					count += it2->second;
				}
				/*accounts.push_back({it->first, it->second.size()});*/
				accounts.push_back({it->first, count});
			}

			sort(accounts.begin(), accounts.end(), sortByVal);
		}

		cout<< "\tCuenta\t\t:\tEventos\n\n";

		for(int i = 0; i < 10; i++) {
			cout<<"\t"<<accounts[i].first<< "\t:\t"<< accounts[i].second<< endl;
		}
		cout<<endl;
		return ;
	}


	/* Exporta lista de cuentas a un archivo CSV */
	void exportToCSV() {

		ofstream csvFile("accountLog.csv");

		csvFile<< "Cuenta,Eventos\n\n";
		if(csvFile.is_open()) {

			for(int i = 0; i < accounts.size(); i++){

				csvFile<<accounts[i].first<<","<<accounts[i].second<< endl;
			}

			cout<<"Archivo creado correctamente\n\n";
			return;
		}
		csvFile.close();
		cout<<"Error al crear el archivo";
		return;
	}
};





#endif

