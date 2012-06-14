#include "qList.h"

SnappingPoint::SnappingPoint(int pos){
	position = pos;
}
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


