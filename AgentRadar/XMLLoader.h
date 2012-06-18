#pragma once
#include <tinyxml.h>
#include "Wedge.h"
#include "Rect.h"

class XMLLoader : public TiXmlVisitor
{
public:
	XMLLoader();
	~XMLLoader();

	std::vector<Sector*> sectors;
	Sector* current_sector;

	virtual bool VisitEnter( const TiXmlElement& element, const TiXmlAttribute* attribute);
	virtual bool VisitExit( const TiXmlElement& element);
};

