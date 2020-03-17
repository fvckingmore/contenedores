#ifndef LOG_FILTER_HPP
#define LOG_FILTER_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "log.hpp"

using namespace std;

class LogFilter {

	/*static void getLogs(char *filaName);
	static bool validateLog(string line);
	static string getValues(string line);
	static string parseValues(string line);*/
private:

	string date;

public:

	/* Extrae los logs del archivo .log */
	void getLogData(string fileName, Log &log) {

		string line, valuesfilte;
		ifstream file(fileName.c_str());
		//file.open();

		if(file.is_open()) {

			while(!file.eof()) {

				getline(file, line);
				log.increaseLogsCount();

				if(validateLog(line)) {

					//log.insert(getAccount(line));

					log.insertLog(getData(line, "account"),
						getData(line, "event_type"));
					log.increaseEventsCount();
					//cout<< getValues(line)<< endl;
					//cout<< getData(line, "account")<< " "<< getData(line, "event_type")<< endl;
					//cout<<getAccount(separateValues(getValues(line), "account"))<<endl;
					//separateValues(getValues(line));
				}

				line = "";
			}
		}

		file.close();

		return;
	}


	/* Valida las lineas de log que contienen la cadena "SIGNALHANDLER" */
	bool validateLog(string line) {

		return 	line.find("SIGNALHANDLER") != string::npos /*&&
				line.find(date) != string::npos*/;
	}


	/* Obtiene los valores del log */
	string getValues(string line) {

		string values;

		values = line.substr(line.find('{'));
		//values.erase(0, 1);
		//values.erase(values.size()-1, 1);
		values.erase(values.find('{'), 1);
		values.erase(values.find('}'), 1);

		return values;
	}


	string separateValues(string values, string toFind) {

		string value;
		istringstream sValues (values);

		while(getline(sValues, value, ',')){

			if(isblank(value[0])) {

				value.erase(0, 1);
			}

			if(value.find(toFind) != string::npos)
				return value;
		}
//			cout<< value<< endl;


		return "";
	}


	void parseValues(string value) {

		istringstream sValue (value);
		string data;

		while(getline(sValue, data, ':')) {

			isblank(data[0]) ? data.erase(0, 2) : data.erase(0, 1);
			data.erase(data.size()-1, 1);

			cout<<data<< " ";

			
		}

		cout<<endl;




		//return event;
	}


	string getAccount(string value) {

		istringstream sValue (separateValues(getValues(value), "account"));
		string data;

		getline(sValue, data, ':');
		getline(sValue, data, ':');


		isblank(data[0]) ? data.erase(0, 2) : data.erase(0, 1);
		data.erase(data.size()-1, 1);


		return data;
	}


	string getData(string value, string dataType) {

		istringstream sValue (separateValues(getValues(value), dataType));
		string data;

		getline(sValue, data, ':');
		getline(sValue, data, ':');


		isblank(data[0]) ? data.erase(0, 2) : data.erase(0, 1);
		data.erase(data.size()-1, 1);


		return data;
	}



};


#endif

