#ifndef _CORE_EVENT_HPP_
#define _CORE_EVENT_HPP_


// Define event handler
#define event	\
noInline


// Set event handler
#define event_Set(obj, evnt, fn)	\
(*((void**) mem(obj, evnt)) = (void*)(fn))

#define event_On	\
event_Set


// Clear event handler
#define event_Clear(obj, evnt)	\
event_Set(obj, evnt, null)

#define event_Reset	\
event_Clear


#endif /* _CORE_EVENT_HPP_ */