#ifndef TOOL_H
#define TOOL_H

class Tool
{
protected:
	int strength;
	char type;
public:
	// making the child classed friend classes allows their methods to access protected properties of this class
	// normally, methods can only access their instance's protected members
	friend class Paper;
	friend class Rock;
	friend class Scissors;
	void setStrength(int s);
	// You actuall can't use an absract class as an argument type
	// without it being a pointer or reference
	// since an absract class isn't really a type, it's only a pointer or reference type
	// and so cannot be passed by value since it doesn't really have a value
	virtual bool fight(Tool& tool) = 0;
};

#endif
