
#include "CompHealth.hpp"
#include "CompHealthTemplate.hpp"

/*static*/ comp_id_type CompHealth::mComponentID = "CompHealth";
/*static*/ comp_id_type CompHealth::mFamilyID = "CompHealth";

CompHealth::CompHealth(CompHealthTemplate *templ) {
	// Construct
	int i;
	for(i=0; i<cNumBodyParts; i++) {
		mInitialHPs[i] = templ->getInitialHealthAt(static_cast<CompHealthTemplate::bodyPart_e>(i));
	}
}
