
#ifndef __COMPHEALTH_HPP__
#define __COMPHEALTH_HPP__

#include "Component.hpp"

class CompHealthTemplate;

class CompHealth : public Component {
	//Component interface
public:
	virtual const comp_id_type& componentID() const { return mComponentID; }
	virtual const comp_id_type& familyID() const { return mFamilyID; }

	//Health interface
public:
	typedef int healt_value_t;
	enum bodyPart_e {
		head = 0, torso, leftArm, rightArm, leftLeg, rightLeg, cNumBodyParts 
	};
	
	CompHealth() {};

	//special constructor for component-template
	CompHealth(CompHealthTemplate *templ);

	healt_value_t getInitialHealthAt(const bodyPart_e part) const {
		return mInitialHPs[part];
	}
	void setInitialHealthAt(const bodyPart_e part, const healt_value_t hp) {
		mInitialHPs[part] = hp;
	}

	healt_value_t getHealthAt(const bodyPart_e part) const {
		return mCurrentHPs[part];
	}
	void setHealthAt(const bodyPart_e part, const healt_value_t hp) {
		mCurrentHPs[part] = hp;
	}

	bool isWounded() const {
		bool wounded = false;
		int i;
		for(i=0; i<cNumBodyParts; i++) {
			if(mCurrentHPs[i] != mInitialHPs[i])
				wounded = true;
		}
		return wounded;
	}

	void reset() {
		int i;
		for(i=0; i<cNumBodyParts; i++) {
			mCurrentHPs[i] = mInitialHPs[i];
		}
	}

private:
	healt_value_t mCurrentHPs[cNumBodyParts];
	healt_value_t mInitialHPs[cNumBodyParts];

	static comp_id_type mComponentID;
	static comp_id_type mFamilyID;
};

#endif
