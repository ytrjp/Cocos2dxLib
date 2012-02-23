
#include "CompVisual.hpp"

class CompVisualSphere : public CompVisual {
	//Component interface
public:
	virtual const comp_id_type& componentID() const { return mFamilyID; }

	// CompVisual interface
public:
	virtual void render() const {
		printf("render sphere with radius %f\n", mRadius);
	}

	// CompVisualSphere interface
public:
	CompVisualSphere(float radius) {
		setRadius(radius);
	}

	const float getRadius() const { return mRadius; }
	void setRadius(const float r) { mRadius = r; }
private:
	float mRadius;
	static comp_id_type mFamilyID;
};