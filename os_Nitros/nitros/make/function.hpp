#ifndef _MAKE_FUNCTION_HPP_
#define _MAKE_FUNCTION_HPP_


// macros: typeOf
#if compiler_NAME != compiler_GCC
	#define typeOf(expr)	\
	decltype(expr)
#else
	#define typeOf(expr)	\
	typeof(expr)
#endif


// convert a token to string
#define toString(a)	\
#a


// mark unused variables
#define notUsed(var)	\
(void)(var)


// apply memory barrier (prevents reordering)
#ifndef barrier
	#define barrier()	\
	asm volatile("" ::: "memory")
#endif


// assembly coding
#define assembly	\
__asm__ __volatile__

#define line(text)	\
text "\n\t"


#endif /* _MAKE_FUNCTION_HPP_ */