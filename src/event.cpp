/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : event.cpp
 * Authors    : zhwang@taurus
 * Create Time: 2019-07-17:08:52:13
 * Description:
 * 
 */

#include "event.h"

void event::test_event()
{
	event::Subject* sub = new event::ChinaSubject("ChinaSubject");
	event::Observer* aob = new event::AObserver("aob",sub);
	event::Observer* bob = new event::BObserver("bob",sub);

	sub->attach(aob);
	sub->attach(bob);

	sub->notify();

	sub->name = "I am a ChinaSubject";

	sub->detach(bob);

	sub->notify();

	sub->detach(aob);
	delete sub;
	sub = nullptr;
	
	delete aob;
	aob = nullptr;
	
	delete bob;
	bob = nullptr;
} 
