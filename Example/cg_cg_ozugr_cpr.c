/*! \file		cg_cg_OzuGr_cpr.c
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

void MGOShtatPO() {

	 mpo_qntt_out = MasIn[n_gr][0];
	MgoInit();
	mgo_ShtatSendData(mpo_qntt_out);
};


extern void reconfA();
extern void reconfB();

extern void MkoInit1();
extern void MkoInit2();
extern void MkoDispatcher2();



const __attribute__((aligned(4))) CgItem CgOzuGrCpr[] =
{

		{7500,	(uint*) Empty, KERNEL},		//1



		{11500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
		{14500,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	    {19000,	(uint*) reconfB, KERNEL},			//8
		{22000,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация



		{26000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
		{29000,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	    {33500,	(uint*) reconfB, KERNEL},			//8

		{36500,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация

		{37500,	(uint*) Empty,	KERNEL},

		{40500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
		{43500,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	    {48000,	(uint*) reconfB, KERNEL},			//8

		{52000,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация

		{53000,	(uint*) Empty,	KERNEL},

		{56000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
		{59000,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	    {63500,	(uint*) reconfB, KERNEL},			//8

		{66500,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация

		{67500,	(uint*) Empty,	KERNEL},

		{70500,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
		{73500,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	    {78000,	(uint*) reconfB, KERNEL},			//8

		{81000,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация

		{82000,	(uint*) Empty,	KERNEL},

		{85000,	(uint*) reconfA, KERNEL},			//3		//   реконфигурация
		{88000,	(uint*) MGOShtatPO, KERNEL},			//4		//реконфигурация

	    {92500,	(uint*) reconfB, KERNEL},			//8

		{95500,	(uint*) MGOShtatPO, KERNEL},			//10		//реконфигурация

		{96500,	(uint*) Empty,	KERNEL},

		{97000,	(uint*) Empty,	KERNEL},
		{99000,	(uint*) Empty, KERNEL},	                //12




	{0, 0, 0}
};



#define P Modules(CgOzuGrCpr)


uint32_t cgTimeArrayCgOzuGrCpr[P];
uint32_t cgMaxTimeArrayCgOzuGrCpr[P];
uint32_t cgTermCauseArrayCgOzuGrCpr[P];
uint32_t cgTermPCArrayCgOzuGrCpr[P];
uint32_t cgTermVaddrArrayCgOzuGrCpr[P];
uint64_t cgShcalaCgOzuGrCpr[1];
uint64_t cgErrShcalaCgOzuGrCpr[1];

#undef P

const struct s_CgCore CgOzuGrCprCore =
{
	Modules(CgOzuGrCpr),
	(CgItem*) &CgOzuGrCpr,
	cgTimeArrayCgOzuGrCpr,
	cgMaxTimeArrayCgOzuGrCpr,
	cgTermCauseArrayCgOzuGrCpr,
	cgTermPCArrayCgOzuGrCpr,
	cgTermVaddrArrayCgOzuGrCpr,
	cgShcalaCgOzuGrCpr,
	cgErrShcalaCgOzuGrCpr
};

