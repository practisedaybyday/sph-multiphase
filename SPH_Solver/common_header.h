
#pragma once


#include "geometry.h"


/*#define TEX_SIZE		2048	
#define LIGHT_NEAR		0.5
#define LIGHT_FAR		300.0
#define DEGtoRAD		(3.141592/180.0)*/

#ifndef EMIT_BUF_RATIO
#define EMIT_BUF_RATIO 2
#endif

#define MAX_FLUIDNUM 3

#define FLUID 0
#define BOUNDARY 1

typedef unsigned int			uint;
typedef unsigned short int		ushort;






struct ParamCarrier {

	//environment
	float intstiff;
	float extstiff;
	float extdamp;
	float acclimit;
	float vlimit;
	cfloat3 gravity;
	cfloat3 volmin;
	cfloat3 volmax;
	cfloat3 softminx;
	cfloat3 softmaxx;

	//case
	int num;
	float dt;
	float simscale;

	//fluid
	float viscosity;
	float restdensity;
	float mass;
	float radius;
	float smoothradius;
	float scalep;
	float massArr[3];
	float densArr[3];
	float viscArr[3];


	//boundary particle
	float bmass;
	float bRestdensity;


	//grid parameter
	float cellsize;
	int searchnum;
	int neighbornum;
	cfloat3 gridmin, gridmax;
	cfloat3 gridsize;
	cfloat3 gridIdfac;
	cint3 gridres;
	int gridtotal;

	//tensile instability
	float w_deltax;
	float fijn;
	float a_phi;
	float a_psi;
	float k_c;

	float SFlipControl;
	float LFlipControl;
	int   mpmSplitNum;
	float collisionStiff;
	float surfaceTensionK;
	float surfaceTensionFluidC;
	float fBlending;
};




struct displayPack {
	cfloat3 pos;
	cfloat4 color;
	int type;
};
struct calculationPack {
	cfloat3 vel;
	cfloat3 veleval;
	float pressure;
	float dens;
	float restdens;
	float mass;
	float visc;
	int bornid;
	cfloat3 accel;
	//bool isbound;
};
//remain unsorted
struct IntermediatePack {

};

struct bufList {
	//Particle properties

	

	displayPack* displayBuffer;
	calculationPack* calcBuffer;
	IntermediatePack* intmBuffer;

	//For sorting
	char*			msortbuf;
	int*			mgridcnt;
	int*			mgridoff;
	uint*			mgcell;
	uint*			mgndx;
	int*			MFidTable;
	uint*			midsort;
	//End sorting

	//Mpm Grid
	//Split Grid For Phases!
	float*          mpmMass;
	cfloat3*         mpmVel;
	cfloat3*         mpmForce;
	float*          mpmTensor;

	float*          mpmAlpha;

	uint*           mpmGid;    //mpmSize
	uint*           mpmIdSort; //mpmSize
	int*            mpmGridVList; //mpmSize
	int*            mpmGridCnt;//gridSize
	int*            mpmGridOff; //gridSize

	cfloat3*         mpmPos;

};// End particle&grid buffers
