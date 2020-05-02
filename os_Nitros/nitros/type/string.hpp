#ifndef _TYPE_STRING_HPP_
#define _TYPE_STRING_HPP_


// definition
typedef char*	string;


// functions
#define	string_Length		strlen
#define	string_Compare		strcmp
#define	string_ToLower		strlwr
#define	string_ToUpper		strupr
#define string_Copy			strcpy
#define string_Reverse		strrev
#define string_Concat		strcat
#define string_Reverse		strrev
#define string_IndexOfChar	strchr
#define string_FindChar		strchr
#define string_LastIndexOf	strrchr
#define string_IndexOfChars	strpbrk 
#define string_FindChars	strpbrk 
#define string_IndexOf		strstr
#define string_Find			strstr


// string equality (true if equals)
#define	string_Equals(str1, str2)	\
	(!string_Compare(str1, str2))


// find substring of a string
#define string_Substring3(dst, str, start)	\
string_Copy(dst, (str)+(start))

#define string_Substring4(dst, str, start, stop)	\
mem_Copy(dst, (str)+(start), (stop)-(start))

#define string_Substring(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, string_Substring4, string_Substring3)(__VA_ARGS__))


// remove part of a string
#define string_Remove2(str, start)	\
(*(((char*)(str))+(start)) = '\0')

#define string_Remove3(str, start, stop)	\
string_Copy((str)+(start), (str)+(stop))

#define string_Remove(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, string_Remove3, string_Remove2)(__VA_ARGS__))


#endif /* _TYPE_STRING_HPP_ */