#include <iostream>
#include "./logFilter.hpp"

using namespace std;

int main() {

	//vector<string> vec;

	LogFilter log;

	log.getLogs("../signals.log");


	/*cout<< getValues("2019-12-02 03:15:24.661001Z: 1 PID 129702 SIGNALHANDLER {'event_type': 'SUP', 'user': '', 'zone': '0E602', 'code_text': 'Prueba Panel', 'account': '9260-7620', 'datetime': '2019-12-02 03:15:20.470', 'priority': '115', 'code': '20', 'tipo': 'ABC-EVENT', 'zone_text': 'None'}")<< endl;*/


		

	return 0;
}