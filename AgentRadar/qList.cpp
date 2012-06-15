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

void qList::RemoveFromList(){
	takeItem(currentRow());
}

void qList::ClearList(){
	while(count()>0){
		takeItem(0);
	}
}
void qList::AccessValue(QListWidgetItem* q){
	emit SendValue(dynamic_cast<SnappingPoint*>(q)->position);
}

void qList::ArcValueChanged(QString qs){
	dynamic_cast<SnappingPoint*>(currentItem())->setText(qs);
	dynamic_cast<SnappingPoint*>(currentItem())->position = qs.toInt();
}


