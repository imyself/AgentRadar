#pragma once
#include<QListWidget>

class qList:public QListWidget
{
	Q_OBJECT
public:
	qList(void);
	qList(QWidget* top);
	~qList(void);

public slots:
	void AddToList(QListWidgetItem* a);
	void DeleteFromList(QListWidgetItem* d);
};

