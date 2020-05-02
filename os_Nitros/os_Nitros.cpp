#include "nitros/nitros.hpp"

queue16<uint, 8> ListU;
queue16<int, 8> ListI;

int main(void)
{
	ListI.Init();
	ListU.Init();
	ListI.PushRear(3);
	ListI.PushRear(3);
	ListI.PushRear(3);
	ListU.PushRear(3);
	ListU.PushRear(3);
	ListU.PushRear(3);
/*
	list_AddF(list_Ptr(ListI), 3);
	list_AddF(list_Ptr(ListI), 3);
	list_AddF(list_Ptr(ListI), 3);
	list_AddF(&ListU, 3);
	list_AddF(&ListU, 3);
	list_AddF(&ListU, 3);
*/
}
