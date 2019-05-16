#pragma once
class CObjectManager {
public:
	CObjectManager();
	~CObjectManager();
	void addObject(CObjectManager*);
	CObjectManager* getObject();
};

