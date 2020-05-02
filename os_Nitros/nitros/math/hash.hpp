#ifndef _MATH_HASH_HPP_
#define _MATH_HASH_HPP_


// 8-bit XOR-ROR hashing
noInline uint8 math_Hash8F(uint8* data, uint size);
uint8 math_Hash8F(uint8* data, uint size)
{
	// opt: uword size
	uint8 hash = 0;
	for(; size > 0; data++, size--)
	{
		hash ^= *data;
		assembly(
		line("bst %0, 0")
		line("lsr %0")
		line("bld %0, 7")
		: "=r"(hash)
		: "r"(hash)
		:
		);
	}
	return hash;
}

#define math_Hash8(data, size)	\
math_Hash8F((uint8*)(data), (uint)(size))


#endif /* _MATH_HASH_HPP_ */