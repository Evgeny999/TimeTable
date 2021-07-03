/*! \file		cg_cg_OzuGr_kvv.c
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

void MGOShtat_Po() {

	 mpo_qntt_out = MasIn[n_gr][0];
	 if((mpo_qntt_out < 1)||(mpo_qntt_out > 256)) {sch_mgo1++; mas_fail[sch_mgo1] = gTc;}
	MgoInit();
	mgo_ShtatSendData(mpo_qntt_out);
};

extern void reconfA();
extern void reconfB();

extern void MkoInit1();
extern void MkoInit2();
extern void MkoDispatcher2();
extern void dcg0kvv();
extern void MPOCg0Kvv();



const __attribute__((aligned(4))) CgItem CgOzuGrKvv[] =
{
	{7500,	(uint*) Empty, KERNEL},		//1



	{11500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{14500,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

    {19000,	(uint*) reconfB, KERNEL},			//8
	{22000,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация



	{26000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{29000,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

    {33500,	(uint*) reconfB, KERNEL},			//8

	{36500,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация

	{37500,	(uint*) Empty,	KERNEL},

	{40500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{43500,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

    {48000,	(uint*) reconfB, KERNEL},			//8

	{52000,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация

	{53000,	(uint*) Empty,	KERNEL},

	{56000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{59000,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

    {63500,	(uint*) reconfB, KERNEL},			//8

	{66500,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация

	{67500,	(uint*) Empty,	KERNEL},

	{70500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{73500,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

    {78000,	(uint*) reconfB, KERNEL},			//8

	{81000,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация

	{82000,	(uint*) Empty,	KERNEL},

	{85000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
	{88000,	(uint*) MGOShtat_Po, KERNEL},			//4		//реконфигурация

    {92500,	(uint*) reconfB, KERNEL},			//8

	{95500,	(uint*) MGOShtat_Po, KERNEL},			//10		//реконфигурация

	{96500,	(uint*) Empty,	KERNEL},

	{97000,	(uint*) Empty,	KERNEL},
	{99000,	(uint*) Empty, KERNEL},	                //12

	{0, 0, 0}
};

#define P Modules(CgOzuGrKvv)

uint32_t cgTimeArrayOzuGr[P];
uint32_t cgMaxTimeArrayOzuGr[P];
uint32_t cgTermCauseArrayOzuGr[P];
uint32_t cgTermPCArrayOzuGr[P];
uint32_t cgTermVaddrArrayOzuGr[P];
uint64_t cgShcalaOzuGr[1];
uint64_t cgErrShcalaOzuGr[1];

#undef P

const struct s_CgCore CgOzuGrKvvCore =
{
	Modules(CgOzuGrKvv),
	(CgItem*) &CgOzuGrKvv,
	cgTimeArrayOzuGr,
	cgMaxTimeArrayOzuGr,
	cgTermCauseArrayOzuGr,
	cgTermPCArrayOzuGr,
	cgTermVaddrArrayOzuGr,
	cgShcalaOzuGr,
	cgErrShcalaOzuGr
};


