#ifndef _DATA_LIST_HPP_
#define _DATA_LIST_HPP_


// generic list definition
template <typename T, uword size>
class list
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	public:
	inline uword Size()
	{
		return size;
	}
	inline void Init()
	{
		Count = 0;
		Size = size;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return size - Count;
	}
	inline void Clear()
	{
		Count = 0;
	}
	noInline void Add(T item)
	{
		Item[Count++] = item;
	}
	noInline uword IndexOf(T item)
	{
		for(uword i=0, n=Count; n>0; i++, n--)
			if(Item[i] == item) return i;
		return (uword) -1;
	}
	noInline void InsertAt(uword indx, T item)
	{
		Item[Count++] = Item[indx];
		Item[indx] = item;
	}
	noInline void DeleteAt(uword indx)
	{
		Item[indx] = Item[--Count];
	}
	noInline void Remove(T item)
	{
		uword indx = IndexOf(item);
		if(indx != (uword) -1) DeleteAt(indx);
	}
};

typedef list<uint8, 8> list8_uint8;
typedef list<uint16, 8> list8_uint16;


// 8-bit list definition
template <typename T, uword size>
class list8
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	public:
	inline void Init()
	{
		Count = 0;
		Size = size;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return size - Count;
	}
	inline void Clear()
	{
		Count = 0;
	}
	inline void Add(T item)
	{
		((list8_uint8*)this)->Add((uint8)item);
	}
	inline uword IndexOf(T item)
	{
		return ((list8_uint8*)this)->IndexOf((uint8)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((list8_uint8*)this)->InsertAt(indx, (uint8)item);
	}
	inline void DeleteAt(uword indx)
	{
		((list8_uint8*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((list8_uint8*)this)->Remove((uint8)item);
	}
};


// 16-bit list definition
template <typename T, uword size>
class list16
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	public:
	inline void Init()
	{
		Count = 0;
		Size = size;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return size - Count;
	}
	inline void Clear()
	{
		Count = 0;
	}
	inline void Add(T item)
	{
		((list8_uint16*)this)->Add((uint16)item);
	}
	inline uword IndexOf(T item)
	{
		return ((list8_uint16*)this)->IndexOf((uint16)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((list8_uint16*)this)->InsertAt(indx, (uint16)item);
	}
	inline void DeleteAt(uword indx)
	{
		((list8_uint16*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((list8_uint16*)this)->Remove((uint16)item);
	}
};


#endif /* _DATA_LIST_HPP_ */