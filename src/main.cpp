#include <iostream>
#include "logFilter.hpp"
#include "log.hpp"

using namespace std;

int main() {

	//vector<string> vec;

	LogFilter lf;
	Log log;

	lf.getLogData("../signals.log", log);
	cout<< "Eventos: "<< log.getEventsCount()<<endl;
	cout<< "Numero de cuentas"<< log.getAccountCount()<<endl;
	cout<< "Hay "<< log.getLogsCount()<< " logs"<<endl;
	log.accountWithEvents();

		

	return 0;
}