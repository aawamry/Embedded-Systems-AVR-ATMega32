/*
 * BIT_MATH.h
 *
 * Created:			12/14/2023 10:38:23 AM
 * Author:			Ahmad Lotfy
 * Description:		Basic Bit Math Operations
 
 */ 



#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define		SET_BIT(REG, BIT_NUM)		REG|=(1<<BIT_NUM)
#define		CLR_BIT(REG, BIT_NUM)		REG&~(1<<BIT_NUM)
#define		TOG_BIT(REG, BIT_NUM)		REG^=(1<<BIT_NUM)
#define		GET_BIT(REG, BIT_NUM)		((REG>>BIT_NUM)&1)	 

#endif /* BIT_MATH_H_ */