
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
#define FLUID_NUM 3

#define TYPE_FLUID 0
#define TYPE_BOUNDARY 1
#define TYPE_ELASTIC 2
#define TYPE_GRANULAR 3

typedef unsigned int			uint;
typedef unsigned short int		ushort;

struct ParamCarrier {

	//environment
	float acclimit;
	float vlimit;
	cfloat3 gravity;
	cfloat3 volmin;
	cfloat3 volmax;
	cfloat3 softminx;
	cfloat3 softmaxx;

	//case
	int num;
	int maxNum;
	float dt;
	float simscale;

	//fluid
	float viscosity;
	float restdensity;
	float mass;
	float radius;
	float smoothradius;
	float scalep;
	float massArr[FLUID_NUM];
	float densArr[FLUID_NUM];
	float viscArr[FLUID_NUM];
	float boundstiff;

	//sph kernel
	float kpoly6;
	float kspiky;
	float kspikydiff;
	float klaplacian;
	float kspline;

	//boundary particle
	float bmass;
	float bRestdensity;
	float bvisc;


	//index sort grid
	float cellsize;
	int searchnum;
	int neighbornum;
	int neighborid[27];
	cfloat3 gridmin, gridmax;
	cfloat3 gridsize;
	cfloat3 gridIdfac;
	cint3 gridres;
	int gridtotal;


	//flip/mpm grid
	float mpmcellsize;
	cfloat3 mpmXmin, mpmXmax;
	cint3 mpmRes;
	int mpmNodeNum;

	//solid
	float solidK;//bulk modulus
	float solidG;//shear modulus

	//Drucker-Prager
	float a_phi;
	float a_psi;
	float k_c;

	//tensile instability
	float w_deltax;
	float fijn;
	

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
	cmat3 deformGrad;
	cmat3 stress;//sigma
	cmat3 B;//apic
	float solidG;
	float solidK;
	
	cfloat3 X; //reference position
	cmat3 invA;
	
};
