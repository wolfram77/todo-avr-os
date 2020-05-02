#ifndef _TYPE_CHAR_HPP_
#define _TYPE_CHAR_HPP_


#define	char_IsLower(ch)	\
(((ch) >= 'a') && ((ch) <= 'z'))

#define	char_IsUpper(ch)	\
(((ch) >= 'A') && ((ch) <= 'Z'))

#define	char_IsAlphabet(ch)		\
(char_IsUpper(ch) || char_IsLower(ch))

#define	char_IsDigit(ch)	\
(((ch) >= '0') && ((ch) <= '9'))

#define	char_IsAlphabetOrDigit(ch)	\
(char_IsAlphabet(ch) || char_IsDigit(ch))

#define	char_IsBlank(ch)	\
(((ch) == '\t') || ((ch) == ' '))

#define	char_IsSpace	char_IsBlank

#define	char_IsControl(ch)	\
((byte)(ch) <= (byte)31)

#define	char_IsGraphical(ch)	\
((byte)(ch) >= (byte)128)

#define	char_ToLower(ch)	\
((char_IsUpper(ch))? (ch - 'A' + 'a') : (ch))

#define	char_ToUpper(ch)	\
((char_IsLower(ch))? (ch - 'a' + 'A') : (ch))


#endif /* _TYPE_CHAR_HPP_ */