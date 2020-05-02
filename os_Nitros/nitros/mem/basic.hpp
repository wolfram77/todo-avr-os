#ifndef _MEM_BASIC_HPP_
#define _MEM_BASIC_HPP_


#define address(base, off)	\
(((char*)(base)) + (off))


// swap variables
#define	mem_Swap3(a, b, temp)	\
macro_Begin		\
temp = a;	\
a = b;		\
b = temp;	\
macro_End

#define	mem_Swap2(a, b)	\
macro_Begin	\
a ^= b;	\
b ^= a;	\
a ^= b;	\
macro_End

#define	mem_Swap(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, mem_Swap3, mem_Swap2)(__VA_ARGS__))


// write variables to memory
#define	mem_Write1(dst, var1)	\
(*((typeOf(var1)*)(dst)) = var1)

#define	mem_Write2(dst, var1, var2)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
macro_End

#define	mem_Write3(dst, var1, var2, var3)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeOf(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
macro_End

#define	mem_Write4(dst, var1, var2, var3, var4)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeOf(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeOf(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
macro_End

#define	mem_Write5(dst, var1, var2, var3, var4, var5)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeOf(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeOf(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeOf(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
macro_End

#define	mem_Write6(dst, var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeOf(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeOf(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeOf(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeOf(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
macro_End

#define	mem_Write7(dst, var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeOf(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeOf(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeOf(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeOf(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((typeOf(var7)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
macro_End

#define	mem_Write8(dst, var1, var2, var3, var4, var5, var6, var7, var8)	\
macro_Begin	\
*((typeOf(var1)*)(dst)) = var1;	\
*((typeOf(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeOf(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeOf(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeOf(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeOf(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((typeOf(var7)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
*((typeOf(var8)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6) + sizeof(var7))) = var8;	\
macro_End

#define	mem_Write(...)	\
macro_Fn(macro_Fn10(_0, __VA_ARGS__, mem_Write8, mem_Write7, mem_Write6, mem_Write5, mem_Write4, mem_Write3, mem_Write2, mem_Write1, macro_FnE, macro_FnE)(__VA_ARGS__))

#define mem_Save	mem_Write


// read variables from memory
#define	mem_Read1(src, var1)	\
(var1 = *((typeOf(var1)*)(src)))

#define	mem_Read2(src, var1, var2)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)(src) + sizeof(var1)));	\
macro_End

#define	mem_Read3(src, var1, var2, var3)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeOf(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
macro_End

#define	mem_Read4(src, var1, var2, var3, var4)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)src) + sizeof(var1)));	\
var3 = *((typeOf(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeOf(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
macro_End

#define	mem_Read5(src, var1, var2, var3, var4, var5)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeOf(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeOf(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeOf(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
macro_End

#define	mem_Read6(src, var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeOf(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeOf(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeOf(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeOf(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
macro_End

#define	mem_Read7(src, var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeOf(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeOf(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeOf(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeOf(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((typeOf(var7)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
macro_End

#define	mem_Read8(src, var1, var2, var3, var4, var5, var6, var7, var8)	\
macro_Begin	\
var1 = *((typeOf(var1)*)(src));	\
var2 = *((typeOf(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeOf(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeOf(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeOf(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeOf(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((typeOf(var7)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
var8 = *((typeOf(var8)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6) + sizeof(var7)));	\
macro_End

#define	mem_Read(...)	\
macro_Fn(macro_Fn10(_0, __VA_ARGS__, mem_Read8, mem_Read7, mem_Read6, mem_Read5, mem_Read4, mem_Read3, mem_Read2, mem_Read1, macro_FnE, macro_FnE)(__VA_ARGS__))


#endif /* _MEM_BASIC_HPP_ */