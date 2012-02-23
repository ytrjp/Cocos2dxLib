
#ifndef __OBJECTTEMPLATE_HPP__
#define __OBJECTTEMPLATE_HPP__

#include <vector>

#include "ComponentTemplate.hpp"

class ObjectTemplate {
public:
	ObjectTemplate( const std::string& name) {
		mName = name;
	}
	typedef std::vector<ComponentTemplate*> compTempl_list_type;

	~ObjectTemplate() {}

	void clearComponents() {
		int i;
		for(i=0; i<mComponents.size(); i++)
			delete mComponents[i];
	}

	const std::string& name() const { return mName; }
	void setName(const std::string& name) { mName = name; }

	compTempl_list_type& components() { return mComponents; }
	
	void addCompTemplate( ComponentTemplate* compTemplate) {
		mComponents.push_back(compTemplate);
	}
	ComponentTemplate* getCompTemplate( const comp_id_type& id) const {
		int i = 0;
		while(i<mComponents.size()) {
			if(mComponents[i]->componentID() == id)
				break;
			++i;
		}
		if(i==mComponents.size())
			return NULL;
		return mComponents[i];
	}

protected:
	std::string mName;
	compTempl_list_type mComponents;
};

#endif
