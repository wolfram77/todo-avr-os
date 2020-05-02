#ifndef _MEM_BLOCK_HPP_
#define _MEM_BLOCK_HPP_


// functions
#define mem_Set			memset
#define mem_Compare		memcmp
#define mem_Copy		memcpy
#define mem_Move		memmove
#define mem_IndexOf		memchr
#define mem_Find		memchr


// check equality (true if equal)
#define	mem_Equals(mem1, mem2, size)	\
(!mem_Compare(mem1, mem2, size))


// initialize memory to 0
#define	mem_Init(dst, size)	\
mem_Set(dst, size, 0)


#endif /* _MEM_BLOCK_HPP_ */