#ifndef _CORE_TASK_HPP_
#define _CORE_TASK_HPP_


// task status
#define	task_DONE		0x00
#define	task_WAIT		0x10
#define	task_YIELD		0x20
#define task_BLOCK		0x30
#define task_RELEASE	0x40


// task priority
#define task_LOW_PRIORITY	0
#define task_MED_PRIORITY	1
#define task_HIGH_PRIORITY	2


// task definition
class task
{
	public:
	void*	Fn;
	void*	Addr;
	void*	Data;
	void*	Block;
	uword	Status;
	uword	Priority;
	
	public:
	inline void Init(void* fn, void* data, uword priority)
	{
		Fn = fn;
		Addr = null;
		Data = data;
		Block = null;
		Status = task_YIELD;
		Priority = priority;
	}
};


// task function pointer
typedef uword (*taskFnPtr)(task*);


// define task function
#define	task_Fn(name)	\
void name(task* task_Obj)


// task prologue
#define task_Begin(...)	\
macro_Begin	\
__FUNCTION__##load:	\
	mem_Read(__VA_ARGS__);	\
	if(task_Obj->Addr) goto task_Obj->Addr;	\
	else goto __FUNCTION__##start;	\
__FUNCTION__##save:	\
	mem_Write(__VA_ARGS__);	\
	return;	\
__FUNCTION__##start:	\
macro_End


// task epilogue
#define task_End()	\
macro_Begin	\
	task_Obj->Addr = null;	\
	task_Obj->Status = task_DONE;	\
	return;	\
macro_End
#define	task_Done	task_End
#define task_Exit	task_Done


// yield control
#define	task_Yield()	\
macro_Begin	\
	task_Obj->Addr = &&__FUNCTION__##__LINE__;	\
	task_Obj->Status = task_YIELD;	\
	goto __FUNCTION__##save;	\
__FUNCTION__##__LINE__:	\
macro_End


// wait while (active wait)
#define	task_WaitWhile(cond)	\
macro_Begin	\
	if(!(cond)) goto __FUNCTION__##__LINE__;	\
	task_Obj->Addr = &&__FUNCTION__##__LINE__;	\
	task_Obj->Status = task_WAIT;	\
	goto __FUNCTION__##save;	\
__FUNCTION__##__LINE__:	\
	if(cond) goto __FUNCTION__##save;	\
macro_End


// wait until (active wait)
#define	task_WaitUntil(cond)	\
task_WaitWhile(!(cond))


// wait if blocked
#define task_WaitBlocked()	\
macro_Begin	\
	if(!(task_Obj->Block)) goto __FUNCTION__##__LINE__;	\
	task_Obj->Addr = &&__FUNCTION__##__LINE__;	\
	task_Obj->Status = task_BLOCK;	\
	goto __FUNCTION__##save;	\
__FUNCTION__##__LINE__:	\
macro_End


#endif /* _CORE_TASK_HPP_ */