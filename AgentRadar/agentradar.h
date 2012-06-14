#ifndef AGENTRADAR_H
#define AGENTRADAR_H

#include <QtGui/QMainWindow>
#include "ui_agentradar.h"

class AgentRadar : public QMainWindow
{
	Q_OBJECT

public:
	AgentRadar(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AgentRadar();

private:
	Ui::AgentRadarClass ui;
};

#endif // AGENTRADAR_H
