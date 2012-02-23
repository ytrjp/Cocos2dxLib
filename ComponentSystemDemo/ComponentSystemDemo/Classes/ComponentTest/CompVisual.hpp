
#include "Component.hpp"

class CompVisual : public Component {
	//Component interface
public:
	virtual const comp_id_type& familyID() const { return mFamilyID; }

	//CompVisual interface
	virtual void render() const = 0;
private:
	static comp_id_type mFamilyID;
};