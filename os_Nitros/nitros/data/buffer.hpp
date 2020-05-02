#ifndef _DATA_BUFFER_HPP_
#define _DATA_BUFFER_HPP_


// basic buffer definition
template <uint size>
union buffer
{
	int8	Int8[1];
	uint8	Uint8[1];
	int16	Int16[1];
	uint16	Uint16[1];
	int32	Int32[1];
	uint32	Uint32[1];
	int64	Int64[1];
	uint64	Uint64[1];
	int		Int[1];
	uint	Uint[1];
	word	Word[1];
	uword	Uword[1];
	byte	Byte[size];
	ubyte	UByte[1];
	sbyte	Sbyte[1];
	char	Char[1];
	short	Short[1];
	ushort	Ushort[1];
	long	Long[1];
	ulong	Ulong[1];
	float	Float[1];
	double	Double[1];
};


#endif /* _DATA_BUFFER_HPP_ */