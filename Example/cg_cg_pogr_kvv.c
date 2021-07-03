/*! \file		cg_cg_pogr_kvv.c
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
//#include <ozu_skd.h>
#include <op_per_troe.h>
//#include <sovp_ozu_bos.h>
//#include <sovp_ozu_skd.h>
#include <op_mgo.h>
#include <util.h>

extern void mgo_ShtatSendData(uint32_t Size);

extern void MGOShtat_Po();

extern void reconfA();
extern void reconfB();

extern void MkoInit1();
extern void MkoInit2();
extern void MkoDispatcher2();
extern void dcg0kvv();
extern void MPOCg0Kvv();



const __attribute__((aligned(4))) CgItem CgPoGrKvv[] =
{
	{15500,	(uint*) Empty, KERNEL},		//1

	
	{42900,	(uint*) Empty, KERNEL},			//2
	{44500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{46000,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

	{80000,	(uint*) Empty, KERNEL},			//6

    {84200,	(uint*) reconfB, KERNEL},			//8
	{86400,	(uint*) Empty, KERNEL},			//8
	{87700,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация
	{90000,	(uint*) Empty, KERNEL},
	{95000,	(uint*) Empty/*MkoDispatcher2*/,	KERNEL},
	{97000,	(uint*) Empty/*MkoInit2*/,	KERNEL},
	{99000,	(uint*) Empty, KERNEL},	                //12

	{0, 0, 0}
};

#define P Modules(CgPoGrKvv)

uint32_t cgTimeArrayPoGr[P];
uint32_t cgMaxTimeArrayPoGr[P];
uint32_t cgTermCauseArrayPoGr[P];
uint32_t cgTermPCArrayPoGr[P];
uint32_t cgTermVaddrArrayPoGr[P];
uint64_t cgShcalaPoGr[1];
uint64_t cgErrShcalaPoGr[1];

#undef P

const struct s_CgCore CgPoGrKvvCore =
{
	Modules(CgPoGrKvv),
	(CgItem*) &CgPoGrKvv,
	cgTimeArrayPoGr,
	cgMaxTimeArrayPoGr,
	cgTermCauseArrayPoGr,
	cgTermPCArrayPoGr,
	cgTermVaddrArrayPoGr,
	cgShcalaPoGr,
	cgErrShcalaPoGr
};


