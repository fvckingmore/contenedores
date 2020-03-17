#include <iostream>
#include "logManip/logFilter.hpp"
#include "logManip/log.hpp"
#include "ui/ui.hpp"

using namespace std;

int main() {

	//LogFilter lf;
	Log log;
	UI ui(log);

	ui.menu();





	/*lf.getLogData("../rsrc/signals.log", log);
	cout<< "Eventos: "<< log.getEventsCount()<<endl;
	cout<< "Numero de cuentas"<< log.getAccountCount()<<endl;
	cout<< "Hay "<< log.getLogsCount()<< " logs"<<endl;
	log.getAccountWithMoreEvents();
	log.getEvents();*/

		

	return 0;
}