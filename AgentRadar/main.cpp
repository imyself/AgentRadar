#include "agentradar.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AgentRadar w;
	w.show();
	return a.exec();
}
