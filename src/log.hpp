#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef map<string, int> eventTypeMap;

/* Utilidad para ordenas Logs */
bool sortByVal(const pair<string, int> &a, const pair<string, int> &b) { 
		return (a.second > b.second);
}


/* Clase Log */
class Log {

private:

	map<string, eventTypeMap> logMap;
	int logsCount;
	int eventsCount;

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

	/* Devuelve el contador de cuetas */
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


	/* Crea un mapa de eventos vacio */
	eventTypeMap createEventTypeMap() {

		eventTypeMap newEventTypeMap;
		return newEventTypeMap;
	}

	/* Devuelve numero de cuentas */
	int getAccountCount() {

		return logMap.size();
	}


	/* Muestra las cuentas con mas eventos enviados */
	void accountWithMoreEvents() {

		vector<pair<string, int>> accounts;
		map<string, eventTypeMap>::iterator it = logMap.begin();

		for(; it != logMap.end(); it++) {
			accounts.push_back({it->first, it->second.size()});
		}

		sort(accounts.begin(), accounts.end(), sortByVal);

		for(int i = 0; i < 10; i++) {
			cout<<accounts[i].first<< ": "<< accounts[i].second<< endl;
		}
	}
};





#endif

