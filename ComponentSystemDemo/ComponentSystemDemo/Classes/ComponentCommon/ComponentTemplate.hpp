
#ifndef __COMPONENTTEMPLATE_HPP__
#define __COMPONENTTEMPLATE_HPP__

#include "Component.hpp"

class Object;

class ComponentTemplate {
public:
	ComponentTemplate() {}
	virtual ~ComponentTemplate() {}

	// returns the ComponentID that, by default, we should
	// register created Component as
	virtual const comp_id_type& componentID() const = 0;
	virtual const comp_id_type& familyID() const = 0;

	virtual Component* makeComponent() = 0;
};

#endif
