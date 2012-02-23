
#ifndef __COMPTEMPLATEMGR_HPP__
#define __COMPTEMPLATEMGR_HPP__

#include <map>
#include "ComponentTemplate.hpp"

class CompTemplateMgr {
protected:
	typedef std::map<const comp_id_type, ComponentTemplate*> comp_table_t;

	CompTemplateMgr() {}
public:
	~CompTemplateMgr() {}
	
	static CompTemplateMgr *getInstance() {
		if(mInstance == NULL)
			mInstance = new CompTemplateMgr();
		return mInstance;
	}

	void clearComponents() {
		comp_table_t::iterator iter;
		for(iter = mTemplates.begin(); iter != mTemplates.end(); iter++) {
			delete iter->second;
		}
		mTemplates.clear();
	}

	void registerTemplate(ComponentTemplate *templ) {
		mTemplates[templ->componentID()] = templ;
	}

	Component *createComp(comp_id_type& comp) {
		return mTemplates[comp]->makeComponent();
	}

protected:
	comp_table_t mTemplates;

	static CompTemplateMgr *mInstance;
};

#endif

