#ifndef _MAKE_ATTRIBUTE_HPP_
#define _MAKE_ATTRIBUTE_HPP_


// attribute specification
#define attrib(...)	\
__attribute__((__VA_ARGS__))


// standard attributes
#define aligned(amt)	attrib(__aligned__(amt))
#define alwaysInline	attrib(__always_inline__)
#define deprecated(msg)	attrib(__deprecated__(msg))
#define raw				attrib(__naked__)
#define noInline		attrib(__noinline__)
#define noReturn		attrib(__noreturn__)
#define optimizeSpeed	attrib(__optimize__("O3"))
#define optimizeSize	attrib(__optimize__("Os"))
#define optimize		optimizeSize
#define osMain			attrib(__OS_main__)
#define osTask			attrib(__OS_task__)
#define pure			attrib(__pure__)
#define hot				attrib(__hot__)
#define cold			attrib(__cold__)
#define section(name)	attrib(__section__(name))
#define isrSpecial		attrib(__interrupt__)
#define isr				attrib(__signal__)
#define ignore			attrib(__unused__)
#define used			attrib(__used__)
#define packed			attrib(__packed__)
#define progMem			attrib(__progmem__)
// rtosFn = attrib(section(".boot"), optimize("Os"))



#endif /* _MAKE_ATTRIBUTE_HPP_ */