
#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include <string>

class Object;
typedef std::string comp_id_type;

class Component {
public:
	
	Component() : mOwnerObj(0) {}
	virtual ~Component() {}

	virtual const comp_id_type& componentID() const = 0;
	virtual const comp_id_type& familyID() const = 0;

	virtual void update() {}

	void setOwnerObject( Object* obj) { mOwnerObj = obj; }
	Object* getOwnerObject() const { return mOwnerObj; }

private:
	Object *mOwnerObj;
};

#endif
