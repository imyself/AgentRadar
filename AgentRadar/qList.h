#pragma once
#include<QListWidget>
#include<sstream>

class SnappingPoint:public QListWidgetItem
{
public:
	SnappingPoint(int);
	int position;
};

class qList:public QListWidget
{
	Q_OBJECT
public:
	qList(void);
	qList(QWidget* top);
	~qList(void);

public slots:
	void AddToList(QListWidgetItem* a);
	void RemoveFromList();
	void ClearList();
	void AccessValue(QListWidgetItem*);
	void ArcValueChanged(QString);
signals:
	void SendValue(int);
};

