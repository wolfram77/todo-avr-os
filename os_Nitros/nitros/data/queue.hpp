#ifndef _DATA_QUEUE_HPP_
#define _DATA_QUEUE_HPP_


// generic queue definition
template <typename T, uword size>
class queue
{
public:
	uword	Count;
	uword	Front;
	uword	Size;
	uword	Max;
	T		Item[size];
	
public:
	inline void Init()
	{
		Size = size;
		Max = size - 1;
		Count = Front = 0;
	}
	inline uword Rear()
	{
		return (Front + Count) & Max;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline uword Index(uword pos)
	{
		return (Front + pos) & Max;
	}
	inline uword Pos(uword indx)
	{
		return (indx - Front) & Max;
	}
	inline void Clear()
	{
		Count = Front = 0;
	}
	noInline void PushFront(T item)
	{
		Count++;
		Front = (Front - 1) & Max;
		Item[Front] = item;
	}
	noInline void PushRear(T item)
	{
		Item[Rear()] = item;
		Count++;
	}
	noInline T PopFront()
	{
		Count--;
		T item = Item[Front];
		Front = (Front + 1) & Max;
		return item;
	}
	noInline T PopRear()
	{
		Count--;
		return Item[Rear()];
	}
	noInline uword IndexOf(T item)
	{
		for(uword i=Front, n=Count; n>0; n--)
		{
			if(Item[i] == item) return i;
			i = (i + 1) & Max;
		}
		return (uword) -1;
	}
	noInline void InsertAt(uword indx, T item)
	{
		PushFront(Item[indx]);
		Item[indx] = item;
	}
	noInline void DeleteAt(uword indx)
	{
		Item[indx] = Item[Front];
		PopFront();
	}
	noInline void Remove(T item)
	{
		uword indx = IndexOf(item);
		if(indx != (uword) -1) DeleteAt(indx);
	}
};


typedef queue<uint8, 8> queue8_uint8;
typedef queue<uint16, 8> queue8_uint16;


// 8-bit queue definition
template <typename T, uword size>
class queue8
{
	public:
	uword	Count;
	uword	Front;
	uword	Size;
	uword	Max;
	T		Item[size];
	
	public:
	inline void Init()
	{
		Size = size;
		Max = size - 1;
		Count = Front = 0;
	}
	inline uword Rear()
	{
		return (Front + Count) & Max;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline uword Index(uword pos)
	{
		return (Front + pos) & Max;
	}
	inline uword Pos(uword indx)
	{
		return (indx - Front) & Max;
	}
	inline void Clear()
	{
		Count = Front = 0;
	}
	inline void PushFront(T item)
	{
		((queue8_uint8*)this)->PushFront((uint8)item);
	}
	inline void PushRear(T item)
	{
		((queue8_uint8*)this)->PushRear((uint8)item);
	}
	inline T PopFront()
	{
		return (T) ((queue8_uint8*)this)->PopFront();
	}
	inline T PopRear()
	{
		return (T) ((queue8_uint8*)this)->PopRear();
	}
	inline uword IndexOf(T item)
	{
		return ((queue8_uint8*)this)->IndexOf((uint8)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((queue8_uint8*)this)->InsertAt(indx, (uint8)item);
	}
	inline void DeleteAt(uword indx)
	{
		((queue8_uint8*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((queue8_uint8*)this)->Remove((uint8)item);
	}
};


// 16-bit queue definition
template <typename T, uword size>
class queue16
{
	public:
	uword	Count;
	uword	Front;
	uword	Size;
	uword	Max;
	T		Item[size];
	
	public:
	inline void Init()
	{
		Size = size;
		Max = size - 1;
		Count = Front = 0;
	}
	inline uword Rear()
	{
		return (Front + Count) & Max;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline uword Index(uword pos)
	{
		return (Front + pos) & Max;
	}
	inline uword Pos(uword indx)
	{
		return (indx - Front) & Max;
	}
	inline void Clear()
	{
		Count = Front = 0;
	}
	inline void PushFront(T item)
	{
		((queue8_uint16*)this)->PushFront((uint16)item);
	}
	inline void PushRear(T item)
	{
		((queue8_uint16*)this)->PushRear((uint16)item);
	}
	inline T PopFront()
	{
		return (T) ((queue8_uint16*)this)->PopFront();
	}
	inline T PopRear()
	{
		return (T) ((queue8_uint16*)this)->PopRear();
	}
	inline uword IndexOf(T item)
	{
		return ((queue8_uint16*)this)->IndexOf((uint16)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((queue8_uint16*)this)->InsertAt(indx, (uint16)item);
	}
	inline void DeleteAt(uword indx)
	{
		((queue8_uint16*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((queue8_uint16*)this)->Remove((uint16)item);
	}
};


#endif /* _DATA_QUEUE_HPP_ */