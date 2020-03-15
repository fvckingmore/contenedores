#ifndef LOG_FILTER_HPP
#define LOG_FILTER_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


struct EVENT {

	string type;
	string user;
	string codeText;
	string account;
	string date;
	string priority;
	string code;
	string zone;

};


class LogFilter {

	/*static void getLogs(char *filaName);
	static bool validateLog(string line);
	static string getValues(string line);
	static string parseValues(string line);*/

public:

	/* Extrae los logs del archivo .log */
	void getLogs(string fileName) {

		string line, values;
		ifstream file(fileName.c_str());
		//file.open();

		if(file.is_open()) {

			while(!file.eof()) {

				getline(file, line);

				if(validateLog(line)) {

					
					//cout<< getValues(line)<< endl;
					separateValues(getValues(line));
				}

				line = "";
			}
		}

		file.close();

		return;
	}


	/* Valida las lineas de log que conitienen la cadena "SIGNALHANDLER" */
	bool validateLog(string line) {

		return line.find("SIGNALHANDLER") != string::npos;
	}


	/* Obtiene los valores del log */
	string getValues(string line) {

		string values;

		values = line.substr(line.find('{'));
		values.erase(0, 1);
		values.erase(values.size()-1, 1);

		return values;
	}


	void separateValues(string line) {

		string value;
		istringstream sLine (line);

		while(getline(sLine, value, ',')){

			if(isblank(value[0])) {

				value.erase(0, 1);
			}

			cout<< value<< endl;
		}


		return ;
	}


	EVENT parseValues(string value) {

		EVENT event;
		istringstream sValue (value);
		string data;

		while(getline(sValue, data, ':')) {

			isblank(data[0]) ? data.erase(0, 2) : data.erase(0, 1);
			data.erase(data.size()-1, 1);

			switch(data) {

				case "event_type":

					break;
			}
		}




		return event;
	}
};


#endif

