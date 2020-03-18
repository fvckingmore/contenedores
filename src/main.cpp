#include <iostream>
#include "logFilter.hpp"
#include "log.hpp"
#include "ui.hpp"

using namespace std;

int main() {

	LogFilter lf;
	Log log;
	UI ui(log);

	ui.menu();

	return 0;
}