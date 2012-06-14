#include "qList.h"


qList::qList(void)
{
}

qList::qList(QWidget* top): QListWidget(top){
}

qList::~qList(void)
{
}

void qList::AddToList(QListWidgetItem* a){
	addItem(a);
}

void qList::DeleteFromList(QListWidgetItem* d){
	takeItem(row(d));
}
