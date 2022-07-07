#include "Pin.h"

Pin::Pin()
{
	m_Status = NotAssigned;	//Default Status is LOW
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

STATUS Pin::getStatus()
{
	return m_Status;
}