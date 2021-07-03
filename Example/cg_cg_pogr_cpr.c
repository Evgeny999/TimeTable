/*! \file		cg_cg_pogr_cpr.c
 *
    \brief		ЦГ восстановления ПО во включенной грани
    \author		Деревянкина
    \created	13.09.2019
    \modified	09.04.2020
*/


#include <config.h>
#include <bos.h>
#include <types.h>
#include <mkolist.h>
//#include <ozu_d01.h>
#include <op_per_troe.h>
//#include <sovp_ozu_bos.h>
//#include <sovp_ozu_skd.h>
#include <op_mgo.h>
#include <util.h>

extern void mgo_ShtatSendData(uint32_t Size);

extern void MGOShtatPO();


extern void reconfA();
extern void reconfB();

extern void MkoInit1();
extern void MkoInit2();
extern void MkoDispatcher2();



const __attribute__((aligned(4))) CgItem CgPoGrCpr[] =
{
//	{1550,	(uint*) Empty, KERNEL},		//1

	
	{6000,	(uint*) Empty, KERNEL},			//2
	{8000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{10000,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	{23000,	(uint*) Empty, KERNEL},			//6
	{26500,	(uint*) reconfB, KERNEL},			//7		// реконфигурация

	{30000,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация

	{60000,	(uint*) Empty, KERNEL},
//	{80000,	(uint*) MkoDispatcher2,	KERNEL},
//	{90000,	(uint*) MkoInit2,	KERNEL},
	{99000,	(uint*) Empty, KERNEL},	                //12

	{0, 0, 0}
};



#define P Modules(CgPoGrCpr)


uint32_t cgTimeArrayCgPoGrCpr[P];
uint32_t cgMaxTimeArrayCgPoGrCpr[P];
uint32_t cgTermCauseArrayCgPoGrCpr[P];
uint32_t cgTermPCArrayCgPoGrCpr[P];
uint32_t cgTermVaddrArrayCgPoGrCpr[P];
uint64_t cgShcalaCgPoGrCpr[1];
uint64_t cgErrShcalaCgPoGrCpr[1];

#undef P

const struct s_CgCore CgPoGrCprCore =
{
	Modules(CgPoGrCpr),
	(CgItem*) &CgPoGrCpr,
	cgTimeArrayCgPoGrCpr,
	cgMaxTimeArrayCgPoGrCpr,
	cgTermCauseArrayCgPoGrCpr,
	cgTermPCArrayCgPoGrCpr,
	cgTermVaddrArrayCgPoGrCpr,
	cgShcalaCgPoGrCpr,
	cgErrShcalaCgPoGrCpr
};

