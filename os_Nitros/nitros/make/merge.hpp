#ifndef _MAKE_MERGE_HPP_
#define _MAKE_MERGE_HPP_


// merge tokens together
#define merge2(a, b)											a##b
#define merge3(a, b, c)											a##b##c
#define merge4(a, b, c, d)										a##b##c##d
#define merge5(a, b, c, d, e)									a##b##c##d##e
#define merge6(a, b, c, d, e, f)								a##b##c##d##e##f
#define merge7(a, b, c, d, e, f, g)								a##b##c##d##e##f##g
#define merge8(a, b, c, d, e, f, g, h)							a##b##c##d##e##f##g##h
#define merge9(a, b, c, d, e, f, g, h, i)						a##b##c##d##e##f##g##h##i
#define merge10(a, b, c, d, e, f, g, h, i, j)					a##b##c##d##e##f##g##h##i##j##k
#define merge11(a, b, c, d, e, f, g, h, i, j, k)				a##b##c##d##e##f##g##h##i##j##k##l
#define merge12(a, b, c, d, e, f, g, h, i, j, k, l)				a##b##c##d##e##f##g##h##i##j##k##l
#define merge13(a, b, c, d, e, f, g, h, i, j, k, l, m)			a##b##c##d##e##f##g##h##i##j##k##l##m
#define merge14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)		a##b##c##d##e##f##g##h##i##j##k##l##m##n
#define merge15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)	a##b##c##d##e##f##g##h##i##j##k##l##m##n##o
#define merge16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)	a##b##c##d##e##f##g##h##i##j##k##l##m##n##o##p

#define merge(...)	\
macro_Fn(macro_Fn16(__VA_ARGS__, merge16, merge15, merge14, merge13, merge12, merge11, merge10, merge9, merge8, merge7, merge6, merge5, merge4, merge3, merge2)(__VA_ARGS__))


#endif /* _MAKE_MERGE_HPP_ */