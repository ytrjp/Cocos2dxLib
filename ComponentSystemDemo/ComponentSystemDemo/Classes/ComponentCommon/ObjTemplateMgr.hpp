
#ifndef __OBJTEMPLATEMGR_HPP__
#define __OBJTEMPLATEMGR_HPP__

#include <vector>
#include <string>

#include "Object.hpp"
#include "ObjectTemplate.hpp"

class ObjTemplateMgr {
protected:
	typedef std::vector<ObjectTemplate*> object_list_t;

	ObjTemplateMgr() {}
public:
	~ObjTemplateMgr() {}

	static ObjTemplateMgr *getInstance() {
		if(mInstance == NULL)
			mInstance = new ObjTemplateMgr();
		return mInstance;
	}

	void registerTemplate(ObjectTemplate *templ) {
		mObjectTemplates.push_back(templ);
	}

	void clearTemplates() {
		for(int i=0; i<mObjectTemplates.size(); i++) {
			mObjectTemplates[i]->clearComponents();
			delete mObjectTemplates[i];
		}
	}


	Object *createObject(std::string templateName, obj_id_type &objectID) {
		int i = 0;
		while(i<mObjectTemplates.size()) {
			if(mObjectTemplates[i]->name() == templateName)
				break;
			++i;
		}
		if(i==mObjectTemplates.size())
			return NULL;
		
		Object *newObj = new Object(objectID);
		ObjectTemplate::compTempl_list_type components = mObjectTemplates[i]->components();
		for(int j=0; j<components.size(); j++) {
			newObj->setComponent( components[j]->makeComponent() );
		}
		return newObj;
	}

protected:
	object_list_t mObjectTemplates;

	static ObjTemplateMgr *mInstance;
};

#endif
