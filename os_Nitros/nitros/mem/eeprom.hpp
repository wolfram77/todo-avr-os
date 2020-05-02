#ifndef _MEM_EEPROM_HPP_
#define _MEM_EEPROM_HPP_


namespace mem
{
using namespace data;

class eeprom
{
	struct task
	{
		void*	Dest;
		void*	Src;
		uint	Size;
	};
	
	private:
	queue<task, 16> Tasks;
	
	private:
	void _Isr()
	{
		_Handler();
	}
	
	void _Handler()
	{
		
	}
	
	public:
	void Read(void* dest, void* src, uint size)
	{
		// Check if queue is already full or not, if yes, block
		task tsk = {dest, src, size};
		Tasks.PushRear(tsk);
	}
	
	void Write(void* dest, void* src, uint size)
	{
		task tsk = {dest, src, size};
	}
};

} // end (namespace) mem


#endif /* _MEM_EEPROM_HPP_ */