///************************************************************************************
// *                                                                                  *
// *      .o@@@@@@@@@@@@@@@@@@@@@@@@@@)                                               *
// *      @@@@@'                .o@@@'                                                *
// *      '@@@.              .o@@@(                                                   *
// *       '@@@.             o@@@@o                                                   *
// *        '@@@.              _____    __________  _________     __________          *
// *          '@@@.     .-----|    ¬\__/    _____/_/   __   ¬\___\\       ¬/          *
// *           '@@@.   /   :. |      \______   . /  .: ______/      ..:   /           *
// *             '@@@. \   .: |      /     . ..: \  :.       \ \  ..:.:  /            *
// *              '@@@. \___________/\___________/\__________/\_________/mcl          *
// *               '@@@.                                                              *
// *              @@@@@@@@ [ f ] · [ u ] · [ s ] · [ e ] · [ d ] · [ .de ]            *
// *                '@@@'                                                             *
// *                 @@'                                                              *
// *                                                                                  *
// *  coded by Questor / Fused (Kai Jourdan)                         questor@fused.de *
// *                                                                                  *
// ************************************************************************************
//
//   Example program for the "Game Object Component System" from Chris Stoy in
//   Game Programming Gems 6, Page 393.
//
//*/
//
//#pragma warning (disable : 4786)
//
//#include <vector>
//
//#include "Object.hpp"
//#include "ObjectTemplate.hpp"
//#include "CompVisualSphere.hpp"
//#include "CompHealth.hpp"
//#include "CompHealthTemplate.hpp"
//
//#include "CompTemplateMgr.hpp"
//#include "ObjTemplateMgr.hpp"
//
//std::vector<Object*> objects;
//
//void main() {
//
////PART1: Visualize Tests
//	//init object
//	Object *obj;
//	Component *compVis;
//
//	obj = new Object(obj_id_type("test obj 0"));
//	compVis = new CompVisualSphere(5.0f);
//	obj->setComponent(compVis);
//	objects.push_back(obj);
//
//	obj = new Object(obj_id_type("test obj 1"));
//	compVis = new CompVisualSphere(8.0f);
//	obj->setComponent(compVis);
//	objects.push_back(obj);
//
//	obj = new Object(obj_id_type("test obj 2"));
//	compVis = new CompVisualSphere(12.0f);
//	obj->setComponent(compVis);
//	objects.push_back(obj);
//
//	//render
//	int i;
//	for(i=0; i<objects.size(); i++) {
//		Component *comp = objects[i]->getComponent( comp_id_type("CompVisual") );
//		CompVisual *compVis = static_cast<CompVisual*>(comp);
//		if(compVis) {
//			compVis->render();
//		}
//	}
//
//	//cleanup
//	for(i=0; i<objects.size(); i++) {
//		objects[i]->clearComponents();
//	}
//
////PART2: Health normal initialisation
//	obj = new Object( obj_id_type( "Human" ) );
//	compVis = new CompVisualSphere(100.0f);     //should be CompVisualHuman :-)
//	obj->setComponent(compVis);
//
//	CompHealth *compHealth = new CompHealth();
//	compHealth->setInitialHealthAt( CompHealth::head, 7 );
//	compHealth->setInitialHealthAt( CompHealth::torso, 50 );
//	compHealth->setInitialHealthAt( CompHealth::leftArm, 20 );
//	compHealth->setInitialHealthAt( CompHealth::rightArm, 20 );
//	compHealth->setInitialHealthAt( CompHealth::leftLeg, 30 );
//	compHealth->setInitialHealthAt( CompHealth::rightLeg, 30 );
//	compHealth->reset();
//	obj->setComponent( compHealth );
//	//....
//	obj->clearComponents();
//
////PART3: Health Template initialisation
//	CompHealthTemplate *compHealthTemplate = new CompHealthTemplate();
//	compHealthTemplate->setInitialHealthAt( CompHealthTemplate::head, 7 );
//	compHealthTemplate->setInitialHealthAt( CompHealthTemplate::torso, 50 );
//	compHealthTemplate->setInitialHealthAt( CompHealthTemplate::leftArm, 20 );
//	compHealthTemplate->setInitialHealthAt( CompHealthTemplate::rightArm, 20 );
//	compHealthTemplate->setInitialHealthAt( CompHealthTemplate::leftLeg, 30 );
//	compHealthTemplate->setInitialHealthAt( CompHealthTemplate::rightLeg, 30 );
//	CompTemplateMgr::getInstance()->registerTemplate( compHealthTemplate );
//
//	//create CompHealth via component-template-manager
//	Component *comp = CompTemplateMgr::getInstance()->createComp(comp_id_type("CompHealth") );
//	obj->setComponent( comp );
//	//....
//	obj->clearComponents();
//
////PART4: Objecttemplates
//	ObjectTemplate *objTemplate = new ObjectTemplate( "HumanTemplate" );
//	CompHealthTemplate *compHealthTemplate2 = new CompHealthTemplate();
//	compHealthTemplate2->setInitialHealthAt( CompHealthTemplate::head, 7 );
//	compHealthTemplate2->setInitialHealthAt( CompHealthTemplate::torso, 50 );
//	compHealthTemplate2->setInitialHealthAt( CompHealthTemplate::leftArm, 20 );
//	compHealthTemplate2->setInitialHealthAt( CompHealthTemplate::rightArm, 20 );
//	compHealthTemplate2->setInitialHealthAt( CompHealthTemplate::leftLeg, 30 );
//	compHealthTemplate2->setInitialHealthAt( CompHealthTemplate::rightLeg, 30 );
//	objTemplate->addCompTemplate(compHealthTemplate2);
//	ObjTemplateMgr::getInstance()->registerTemplate( objTemplate );
//
//	obj = ObjTemplateMgr::getInstance()->createObject( "HumanTemplate", 
//											obj_id_type("Human"));
//	//....
//	obj->clearComponents();
//
//	ObjTemplateMgr::getInstance()->clearTemplates();
//	CompTemplateMgr::getInstance()->clearComponents();
//}
