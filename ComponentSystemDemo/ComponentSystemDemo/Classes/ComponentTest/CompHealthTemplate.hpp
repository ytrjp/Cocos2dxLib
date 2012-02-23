
#ifndef __COMPHEALTHTEMPLATE_HPP__
#define __COMPHEALTHTEMPLATE_HPP__

#include "ComponentTemplate.hpp"
#include "CompHealth.hpp"

class CompHealthTemplate : public ComponentTemplate {

	// ComponentTemplate interface
public:
	//returns the Component ID that this template can create
	virtual const comp_id_type& componentID() const {
		return mComponentID;
	}
	virtual const comp_id_type& familyID() const {
		return mFamilyID;
	}

	virtual Component *makeComponent() {
		CompHealth *comp = new CompHealth(this);
		comp->reset();
		return comp;
	}

	// CompHealth interface
public:
	typedef int healt_value_t;
	enum bodyPart_e {
		head = 0, torso, leftArm, rightArm, leftLeg, rightLeg, cNumBodyParts 
	};
	healt_value_t getInitialHealthAt(const bodyPart_e part) const {
		return mInitialHPs[part];
	}
	void setInitialHealthAt(const bodyPart_e part, const healt_value_t hp) {
		mInitialHPs[part] = hp;
	}
	
private:
	healt_value_t mInitialHPs[cNumBodyParts];

	static comp_id_type mComponentID;
	static comp_id_type mFamilyID;
};

#endif
