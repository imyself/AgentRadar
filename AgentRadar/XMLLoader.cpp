#include "XMLLoader.h"


XMLLoader::XMLLoader()
{
	current_sector = 0;
}


XMLLoader::~XMLLoader()
{
}

bool XMLLoader::VisitEnter( const TiXmlElement& element, const TiXmlAttribute* attribute){
	if(element.ValueStr() == "sectors"){
		if(element.Parent() != element.GetDocument()) return false;
		return true;
	}
	else if(element.ValueStr() == "wedge"){
		if(element.Parent()->ValueStr() != "sectors") return false;
		if(current_sector != 0) return false;

		current_sector = new Wedge();
		Wedge* w = dynamic_cast<Wedge*>(current_sector);
			
		element.Attribute("left", &(w->left_bound));
		element.Attribute("right", &(w->right_bound));
		element.Attribute("near", &(w->near_bound));
		element.Attribute("far", &(w->far_bound));
		return true;
	}
	else if(element.ValueStr() == "snaparc"){
		if(element.Parent()->ValueStr() != "wedge") return false;
		if(current_sector == 0) return false;

		Wedge* w = dynamic_cast<Wedge*>(current_sector);
		SnappingPoint* s = new SnappingPoint(1);
		element.Attribute("pos", &(s->position));
		std::string name = element.Attribute("pos");
		s->setText(QString(name.c_str()));
		w->snapping_points.push_back(s);
		return true;
	}
	else if(element.ValueStr() == "rect"){
		if(element.Parent()->ValueStr() != "sectors") return false;
		if(current_sector != 0) return false;

		current_sector = new Rect();
		Rect* w = dynamic_cast<Rect*>(current_sector);
			
		element.Attribute("left", &(w->left_edge));
		element.Attribute("right", &(w->right_edge));
		element.Attribute("up", &(w->top_edge));
		element.Attribute("down", &(w->bottom_edge));
		return true;
	}
	else if(element.ValueStr() == "agents"){
		if(element.Parent()->ValueStr() != "wedge" && element.Parent()->ValueStr() != "rect") return false;
		if(current_sector == 0) return false;

		int b = 1;

		element.Attribute("bool", &(b));
		current_sector->agents = b;//Int to bool cast, safe?
		return true;
	}
	else if(element.ValueStr() == "obstacles"){
		if(element.Parent()->ValueStr() != "wedge" && element.Parent()->ValueStr() != "rect") return false;
		if(current_sector == 0) return false;

		int b = 1;

		element.Attribute("bool", &(b));
		current_sector->obstacles = b;//Int to bool cast, safe?
		return true;
	}
	else if(element.ValueStr() == "inspection"){
		if(element.Parent()->ValueStr() != "wedge" && element.Parent()->ValueStr() != "rect") return false;
		if(current_sector == 0) return false;

		int b = 1;

		element.Attribute("bool", &(b));
		current_sector->inspection = b;//Int to bool cast, safe?
		return true;
	}
	else if(element.ValueStr() == "netflow"){
		if(element.Parent()->ValueStr() != "wedge" && element.Parent()->ValueStr() != "rect") return false;
		if(current_sector == 0) return false;

		int b = 1;

		element.Attribute("bool", &(b));
		current_sector->net_flow = b;//Int to bool cast, safe?
		return true;
	}
	else if(element.ValueStr() == "density"){
		if(element.Parent()->ValueStr() != "wedge" && element.Parent()->ValueStr() != "rect") return false;
		if(current_sector == 0) return false;

		int b = 1;

		element.Attribute("bool", &(b));
		current_sector->density = b;//Int to bool cast, safe?
		return true;
	}
	else if(element.ValueStr() == "cardinality"){
		if(element.Parent()->ValueStr() != "wedge" && element.Parent()->ValueStr() != "rect") return false;
		if(current_sector == 0) return false;

		int b = 1;

		element.Attribute("num", &(b));
		current_sector->cardinality = b;
		return true;
	}
	return false;
}

bool XMLLoader::VisitExit( const TiXmlElement& element){
	if(element.ValueStr() == "sectors") return true;
	else if(element.ValueStr() == "snaparc") return true;
	else if(element.ValueStr() == "agents") return true;
	else if(element.ValueStr() == "obstacles") return true;
	else if(element.ValueStr() == "inspection") return true;
	else if(element.ValueStr() == "netflow") return true;
	else if(element.ValueStr() == "density") return true;
	else if(element.ValueStr() == "cardinality") return true;
	else if(element.ValueStr() == "wedge" || element.ValueStr() == "rect"){
		if(current_sector->GetType() == 1)
			((Wedge*)current_sector)->sweep = ((Wedge*)current_sector)->ComputeSweep(((Wedge*)current_sector)->left_bound, ((Wedge*)current_sector)->right_bound);
		sectors.push_back(current_sector);
		current_sector = 0;
		return true;
	}
	return false;
}