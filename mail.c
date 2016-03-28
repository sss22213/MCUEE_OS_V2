#include "mail.h"
typedef struct _mail
{
	u_int_8 prior;
	float value;
}mail;

//mail box table
mail box1[mail_size];

void Put_mail(u_int_8 p_prior,float p_value)
{
	box1[p_prior].value=p_value;
	box1[p_prior].prior=p_prior;
}

float Get_mail(u_int_8 p_prior)
{
	return box1[p_prior].value;
}

void clearAll_mail()
{
	for(int i=0;i<mail_size;i++)
	{
		box1[i].prior=0;
	}
}

void clear_mail(u_int_8 prior)
{
                box1[prior].prior=0;
}

