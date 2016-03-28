#ifndef _mail_H_
#define _mail_H_
#include "core.h"

#define mail_size 10
typedef struct _mail mail;

//function
void Put_mail(u_int_8 p_prior,float value);
float Get_mail(u_int_8 p_prior);
void clearAll_mail(void);
void clear_mail(u_int_8);

#endif
