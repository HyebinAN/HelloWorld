#pragma once

#include "Employee.h"
#include "DataBase.h"
#include <list>

using namespace std;

enum class Column {
	EMPLOYEE_NUM,
	NAME,
	FIRST_NAME,
	LAST_NAME,
	CL,
	PHONE,
	PHONE_MID,
	PHONE_LAST,
	BIRTHDAY,
	BIRTHDAY_YEAR,
	BIRTHDAY_MONTH,
	BIRTHDAY_DAY,
	CERTI
};

class IDbms {
public:
	virtual list<Employee*> add(Employee data) = 0;
	virtual list<Employee*> del(Column type, string data) = 0;
	virtual list<Employee*> sch(Column type, string data) = 0;
	virtual list<Employee*> mod(Column typeFrom, string dataFrom, Column typeTo, string dataTo) = 0;
};

class Dbms : public IDbms {
private:
	IDataBase* _db;
public:
	Dbms(IDataBase* db);
	virtual list<Employee*> add(Employee data) override;
	virtual list<Employee*> del(Column type, string data) override;
	virtual list<Employee*> sch(Column type, string data) override;
	virtual list<Employee*> mod(Column typeFrom, string dataFrom, Column typeTo, string dataTo) override;
};
