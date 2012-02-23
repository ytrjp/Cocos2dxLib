
#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <string>
#include <map>

#include "Component.hpp"

typedef std::string obj_id_type;

class Object {
public:
	Object( const obj_id_type& id) {
		setID(id);
	}

	const obj_id_type& getID() const { return mOID; }
	void setID( const obj_id_type& id ) { mOID = id; }

	Component* getComponent(const comp_id_type& familyID ) {
		return mComponents[familyID];
	}
	Component* setComponent(Component *newComp) {
		comp_id_type family = newComp->familyID();
		Component *oldComp = mComponents[family];
		mComponents[family] = newComp;
		return oldComp;
	}
	void clearComponents() {
		std::map<const comp_id_type, Component*>::iterator iter;
		for(iter = mComponents.begin(); iter != mComponents.end(); iter++) {
			delete iter->second;
		}
		mComponents.clear();
	}

private:
	obj_id_type mOID;			//unique identifier for this object

	typedef std::map<const comp_id_type, Component*> component_table_type;
	component_table_type mComponents;		//map of all components;
};

#endif
