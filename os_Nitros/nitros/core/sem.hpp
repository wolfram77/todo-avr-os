#ifndef _CORE_SEM_HPP_
#define _CORE_SEM_HPP_


// Define
typedef word sempahore;


// Wait
void sem_WaitF(sempahore* sem)
{
	task_Now->Block = sem;
	task_Blk.Add((uint) task_Now);
}

#define sem_Wait(sem, ...)	\
macro_Begin	\
(sem)--;	\
if((sem) < 0)	\
{	\
	sem_WaitF(&sem);	\
	task_Save(__VA_ARGS__);	\
	task_Block();	\
}	\
macro_End

#define sem_Take	sem_Wait


// Signal
void sem_SignalF(sempahore* sem)
{
	for(uword i=0; i<task_Blk.Count; i++)
	{
		task* tsk = (task*) task_Blk.Item[i];
		if(tsk->Block == sem)
		{
			task_RdyH.PushRear(tsk);
			task_Blk.DeleteAt(i);
			tsk->Block = null;
			return;
		}
	}
}

#define sem_Signal(sem, ...)	\
macro_Begin	\
(sem)++;	\
if((sem) <= 0)	\
{	\
	sem_SignalF(&(sem));	\
	task_Yield();	\
}	\
macro_End

#define sem_Release		sem_Signal


// Check if free to use
#define sem_IsFree(sem)	\
((semp) > 0)


#endif /* _CORE_SEM_HPP_ */