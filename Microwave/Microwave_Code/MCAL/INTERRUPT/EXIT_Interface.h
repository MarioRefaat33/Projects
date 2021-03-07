#ifndef _EXIT_INTERFACE_H_
#define _EXIT_INTERFACE_H_

void EXIT_VidInit(void);


void EXIT0_Enable(void);
void EXIT0_Disable(void);

void EXIT1_Enable(void);
void EXIT1_Disable(void);

void EXIT2_Enable(void);
void EXIT2_Disable(void);


void VECT_INT0_CallBack ( void ( *Copy_INT0_PCallBack )( void )  );


#endif
