#include "Item.h"



Item::Item()
{
}

void Item::Set_Data(string Name, string Kind, int Price, int Damege)
{
	m_strName = Name;
	m_strKind = Kind;
	m_iPrice = Price;
	m_iDamege = Damege;
}


Item::~Item()
{
}
