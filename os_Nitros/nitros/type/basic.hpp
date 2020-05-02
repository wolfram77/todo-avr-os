#ifndef	_TYPE_BASIC_HPP_
#define	_TYPE_BASIC_HPP_


// size-specified integers
typedef	signed char			int8;
typedef	unsigned char		uint8;
typedef	short				int16;
typedef	unsigned short		uint16;
typedef	long				int32;
typedef	unsigned long		uint32;
typedef	long long			int64;
typedef	unsigned long long	uint64;


// word size integer
#ifndef word
#if cpu_WORD_SIZE == 8
typedef	int8	word;
#elif cpu_WORD_SIZE == 16
typedef	int16	word;
#endif
#endif
#ifndef uword
#if cpu_WORD_SIZE == 8
typedef	uint8	uword;
#elif cpu_WORD_SIZE == 16
typedef	uint16	uword;
#endif
#endif


// named types
#ifndef byte
typedef	unsigned char	byte;
#endif
typedef	unsigned char	ubyte;
typedef signed char		sbyte;
typedef unsigned short	ushort;
typedef unsigned int	uint;
typedef unsigned long	ulong;


#endif /* _TYPE_BASIC_HPP_ */