#include "qList.h"

SnappingPoint::SnappingPoint(int pos){
	position = pos;
	std::string s;
	std::stringstream ss;
	ss<<pos;
	s = ss.str();
	this->setText(s.c_str());
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

void qList::ClearList(){
	while(count()>0){
		takeItem(0);
	}
}


