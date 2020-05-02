#ifndef _MATH_CONCAT_HPP_
#define _MATH_CONCAT_HPP_


// integer concatenation
#define math_Concat2(v1, v0, sft)	\
(((v1) << (sft)) | (v0))

#define math_Concat3(v2, v1, v0, sft)	\
math_Concat2(math_Concat2(v2, v1, sft), v0, sft)

#define math_Concat4(v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v3, v2, v1, sft), v0, sft)

#define math_Concat5(v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat4(v4, v3, v2, v1, sft), v0, sft)

#define math_Concat6(v5, v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v5, v4, v3, v2, v1, sft), v0, sft)

#define math_Concat7(v6, v5, v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v6, v5, v4, v3, v2, v1, sft), v0, sft)

#define math_Concat8(v7, v6, v5, v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v7, v6, v5, v4, v3, v2, v1, sft), v0, sft)

#define	math_Concat(...)	\
macro_Fn(macro_Fn9(__VA_ARGS__, math_Concat8, math_Concat7, math_Concat6, math_Concat5, math_Concat4, math_Concat3, math_Concat2)(__VA_ARGS__))


// value formation
#define math_MakeInt8n(v1, v0)	\
math_Concat(v1, v0, 4)

#define	math_MakeInt8b(v7, v6, v5, v4, v3, v2, v1, v0)	\
math_Concat(v7, v6, v5, v4, v3, v2, v1, v0, 1)

#define math_MakeInt8(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, math_MakeInt8b, _7, _6, _5, _4, _3, math_MakeInt8n)(__VA_ARGS__))

#define math_MakeUint8	\
math_MakeInt8

#define	math_MakeInt16(v1, v0)	\
	math_Concat(v1, v0, 8)

#define math_MakeUint16	\
math_MakeInt16

#define math_MakeInt32_4(v3, v2, v1, v0)	\
math_Concat(v3,v2, v1, v0, 8)

#define	math_MakeInt32_2(v1, v0)	\
math_Concat(v1, v0, 16)

#define math_MakeInt32(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, math_MakeInt32_4, _3, math_MakeInt32_2)(__VA_ARGS__))

#define	math_MakeUint32	\
math_MakeInt32

#define math_MakeInt64_8(v7, v6, v5, v4, v3, v2, v1, v0)	\
math_Concat(v7, v6, v5, v4, v3, v2, v1, v0, 8)

#define math_MakeInt64_4(v3, v2, v1, v0)	\
math_Concat(v3, v2, v1, v0, 16)

#define math_MakeInt64_2(v1, v0)	\
math_Concat(v1, v0, 32)

#define math_MakeInt64(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, math_MakeInt64_8, _7, _6, _5, math_MakeInt64_4, _3, math_MakeInt64_2)(__VA_ARGS__))

#define math_MakeUint64	\
math_MakeInt64


#endif /* _MATH_CONCAT_HPP_ */