#ifndef _CORE_KERNEL_HPP_
#define _CORE_KERNEL_HPP_


// critical section
#define critSec_Begin()		cli()
#define critSec_End()		sei()


// task lists
queue16<task*, 16> task_RdyL;
queue16<task*, 16> task_RdyM;
queue16<task*, 8> task_RdyH;
list16<task*, 16> task_Blk;
task* task_Now;


// add a task
noInline void task_Add(task* tsk)
{
	switch(tsk->Priority)
	{
		case task_HIGH_PRIORITY:
		task_RdyH.PushRear(tsk);
		break;
		case task_MED_PRIORITY:
		task_RdyM.PushFront(tsk);
		break;
		case task_LOW_PRIORITY:
		task_RdyL.PushRear(tsk);
		break;
	}
}


// remove a task
noInline void task_Remove(task* tsk)
{
	switch(tsk->Priority)
	{
		case task_HIGH_PRIORITY:
		task_RdyH.Remove(tsk);
		break;
		case task_MED_PRIORITY:
		break;
	}
}


void kernel_Scheduler(void)
{
	while(true)
	{
		if(task_RdyH.Avail()) task_Now = task_RdyH.PopFront();
		else if(task_RdyM.Avail()) task_Now = task_RdyM.PopFront();
		else if(task_RdyL.Avail()) task_Now = task_RdyL.PopFront();
		((taskFnPtr)(task_Now->Addr))(task_Now);
	}
}


#endif /* _CORE_KERNEL_HPP_ */