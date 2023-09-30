// Ex5-Unit-Test-Driver-Template.cpp : Defines the entry point for the console application.
//
//
// Explore how this example code works in your debugger and create a new version of the overloaded functions for
// the sv3_t and sm3_t with the same names as the original vector3 and matrix3 versions.
//
// This is a basic exploration of overloading functions that can be resolved by type and use of structures without use of more
// advanced object-oriented methods we'll look at later that could vastly improve the abstration of these operations.


#include "stdafx.h"

#include <iostream>
#include <cmath>

using namespace std;


// Here's some basic three space vector matrix algebra types using arrays
typedef float vector3[3];
typedef float matrix3[3][3];
typedef float scalar;


// Original function prototypes that you can overloaded with new versions, resolved by type signature
void coutv(vector3 v);
void coutm(matrix3 m);
scalar add(scalar s1, scalar s2);
vector3& add(vector3 v1, vector3 v2);
vector3& add3(vector3 v1, vector3 v2, vector3 v3);
vector3& normalize(vector3& v);
scalar magnitude(vector3 v);
vector3& scale(vector3& v, scalar s);
scalar dotprod(vector3 v1, vector3 v2);
vector3& crossprod(vector3 v1, vector3 v2);
matrix3& product(matrix3 m1, matrix3 m2);
vector3& rotate(matrix3 m, vector3 v);



// Note that we can create a derived type that encapsulates a 3D vector or
// matrix inside a structure.
typedef struct
{
	float v3[3];
} sv3_t;

typedef struct 
{
	float m3[3][3];
} sm3_t;


// function prototypes for new coutv and coutm for sv3_t and sm3_t
void coutv(sv3_t v3);
void coutm(sm3_t m3);
sv3_t& add(sv3_t v1, sv3_t v2);
sv3_t& add3(sv3_t v1, sv3_t v2, sv3_t v3);
sv3_t& normalize(sv3_t& v);
scalar magnitude(sv3_t v);
sv3_t& scale(sv3_t& v, scalar s);
scalar dotprod(sv3_t v1, sv3_t v2);
sv3_t& crossprod(sv3_t v1, sv3_t v2);
sm3_t& product(sm3_t m1, sm3_t m2);
sv3_t& rotate(sm3_t m, sv3_t v);


int main(void)
{
	scalar s1=1.0, s2=2.0;
	vector3 v1={1.0,0.0,0.0}, v2={0.0,1.0,0.0}, v3={0.0,0.0,1.0};
	vector3 vbig={10.0, 10.0, 10.0};
	vector3 vtemp={0.0,0.0,0.0};

	matrix3 m1={{1.0,2.0,3.0},{1.0,2.0,3.0},{1.0,2.0,3.0}};
	matrix3 m2={{1.0,1.0,1.0},{2.0,2.0,2.0},{3.0,3.0,3.0}};

	matrix3 rotx={{1.0,0.0,0.0},{0.0,0.0,-1.0},{0.0,1.0,0.0}};
	matrix3 roty={{0.0,0.0,1.0},{0.0,1.0,0.0},{-1.0,0.0,0.0}};
	matrix3 rotz={{0.0,-1.0,0.0},{1.0,0.0,0.0},{0.0,0.0,1.0}};

	// structure encapsulated vector and matrix declarations -- note more complex initializers
	sv3_t sv3_x={{1.0,0.0,0.0}}, sv3_y={{0.0,1.0,0.0}}, sv3_z={{0.0,0.0,1.0}};
	sm3_t sm3_rotx={{{1.0,0.0,0.0},{0.0,0.0,-1.0},{0.0,1.0,0.0}}};
	sm3_t sm3_roty={{{0.0,0.0,1.0},{0.0,1.0,0.0},{-1.0,0.0,0.0}}};
	sm3_t sm3_rotz={{{0.0,-1.0,0.0},{1.0,0.0,0.0},{0.0,0.0,1.0}}};

	sv3_t sv3_a;
	sm3_t sm3_a;

	cout << "array vector3 v3="; coutv(v3); cout << endl;

	// now, what if we use assignment with the structure encapsulated types?
	// can we in fact assign an instance of the same type that is pre-initialized to
	// an uninitialized version of that type?
	sv3_a = sv3_x;
	sv3_a = sv3_y;
	sm3_a = sm3_rotx;
	sm3_a = sm3_rotx;

	cout << "\nScalar Addition:\n";
	cout << "s1=" << s1 << ", s2=" << s2 << ": s1 + s2=" << (s1+s2) << endl;
	cout << "s1=" << s1 << ", s2=" << s2 << ": s1 + s2=" << add(s1, s2) << endl;

	cout << "\nVector Addition:\n";
	cout << "v1="; coutv(v1); cout << ", v2="; coutv(v2); cout << ", v3="; coutv(v3); cout << ": v1 + v2 + v3="; coutv(add(add(v1, v2), v3)); cout << endl;
	cout << "v1="; coutv(v1); cout << ", v2="; coutv(v2); cout << ", v3="; coutv(v3); cout << ": v1 + v2 + v3="; coutv(add3(v1, v2, v3)); cout << endl;
	cout << "v1="; coutv(v1); cout << ", v2="; coutv(v2); cout << ": v1 + v2="; coutv(add(v1, v2)); cout << endl;


	// Add unit tests for new structure vector type here - your output should match original functions


	cout << "\nVector & Matrix Operations:\n";
	cout << "v="; coutv(vbig); cout << "mag(v)=" << magnitude(vbig); cout << ", vnorm="; coutv(normalize(vbig)); cout << endl;
	cout << "v1="; coutv(v1); cout << ", v2="; coutv(v2); cout << ", and v1 dot v2=" << dotprod(v1, v2); cout << endl;
	cout << "v1="; coutv(v1); cout << ", v2="; coutv(v2); cout << ", and v1 X v2="; coutv(crossprod(v1, v2)); cout << endl;
	cout << "m1="; coutm(m1); cout << ", m2="; coutm(m2); cout << ", and m1 * m2="; coutm(product(m1, m2)); cout << endl;
	cout << "v1="; coutv(v1); cout << ", roty="; coutm(roty); cout << ", and v1 * roty="; coutv(rotate(roty, v1)); cout << "\n\n";


	// Add unit tests for new structure matrix type here - your output should match original functions


	cout << "\nDone\n";

	return 0;
}


// Original array vector matrix function implementations
//

scalar add(scalar s1, scalar s2)
{
	return (s1+s2);
}


static vector3 vsum2v;
vector3& add(vector3 v1, vector3 v2)
{
	// vector3 vsum2;

	vsum2v[0]=v1[0]+v2[0];
	vsum2v[1]=v1[1]+v2[1];
	vsum2v[2]=v1[2]+v2[2];

	return(vsum2v);
}


void add(vector3 & v1, vector3 & v2, vector3 & vsum)
{
	for(int idx=0; idx < 3; idx++)
		vsum[idx]=v1[idx]+v2[idx];
}


static vector3 vsum3v;
vector3& add3(vector3 v1, vector3 v2, vector3 v3)
{

	vsum3v[0]=v1[0]+v2[0]+v3[0];
	vsum3v[1]=v1[1]+v2[1]+v3[1];
	vsum3v[2]=v1[2]+v2[2]+v3[2];

	return(vsum3v);
}


void coutv(vector3 v)
{
	for(int idx=0; idx < 3; idx++)
		cout << v[idx] << " ";
}


void coutm(matrix3 m)
{
	for(int row=0; row < 3; row++)
	{
		for(int col=0; col < 3; col++)
			cout << m[row][col] << " ";

		cout << ";  ";
	}
}


static vector3 normv;
vector3& normalize(vector3& v)
{
	float mag=magnitude(v);

	for(int idx=0; idx < 3; idx++)
		normv[idx]=v[idx]/mag;

	return(normv);
}

scalar magnitude(vector3 v)
{
	return(sqrt((v[0]*v[0]) + (v[1]*v[1]) + (v[2]*v[2])));
}

static vector3 scalev;
vector3& scale(vector3& v, scalar s)
{
	for(int idx=0; idx < 3; idx++)
		scalev[idx]=v[idx]*s;

	return(scalev);
}

// returns zero if 2 vectors are orthogonal, 
// otherwise dotprod is magnitude(v1)*magnitude(v2)*cos(angle-between-them)
scalar dotprod(vector3 v1, vector3 v2)
{
	return ((v1[0]*v2[0]) + (v1[1]*v2[1]) + (v1[2]*v2[2]));
}


// Cross product of v1 X v2 is:
// = (v1[0]i + v1[1]j + v1[2]k) X (v2[0]i + v2[1]j + v2[2]k)
//
// This simplifies where (i X i) = 0, (j X j) = 0, (k X k) = 0
//
static vector3 v1xv2;
vector3& crossprod(vector3 v1, vector3 v2)
{
	// scalar components for v1xv2 =c1*i + c2*j + c3*k
	v1xv2[0]=v1[1]*v2[2] - v1[2]*v2[1];
	v1xv2[1]=v1[2]*v2[0] - v1[0]*v2[2];
	v1xv2[2]=v1[0]*v2[1] - v1[1]*v2[0];

	return v1xv2;
}

// Multiply each row * column and sum
// A 3x3 * 3x3 yields a 3x3
// where element(0,0) = row0 * col0 and so on ... 
static matrix3 m1xm2;
matrix3& product(matrix3 m1, matrix3 m2)
{
	int row, col;

	for(row=0; row < 3; row++)
		for(col=0; col < 3; col++)
			m1xm2[row][col]=0.0;

	for(row=0; row < 3; row++)
	{
		for(col=0; col < 3; col++)
		{
			for(int idx=0; idx < 3; idx++)
			{
				m1xm2[row][col]+=m1[row][idx]*m2[idx][col];
			}
		}
	}

	return m1xm2;
}

// Multiply each row * column and sum
// A 1x3 * 3x3 yields a rotated 1x3
// where element(0,0) = row0 * col0 and so on ... 
static vector3 rv;
vector3& rotate(matrix3 m, vector3 v)
{
	int col;

	for(col=0; col < 3; col++)
		rv[col]=0.0;

	for(col=0; col < 3; col++)
	{
		for(int idx=0; idx < 3; idx++)
		{
			rv[col]+=m[idx][col]*v[idx];
		}
	}

	return rv;
}


// Implement these and add new overloaded operations on these types as well
// as requested in Ex-5 assignment and test them in your main, comparing to original functions for the
// array type.

void coutv(sv3_t v3)
{
	cout << "Replace me with a new output method\n";
}

void coutm(sm3_t m3)
{
		cout << "Replace me with a new output method\n";
}

// Here are the remaining stubbed-out bodies for the new functions you have been asked to implement
sv3_t vsum2;
sv3_t& add(sv3_t v1, sv3_t v2)
{
	return vsum2;
}

sv3_t vsum3;
sv3_t& add3(sv3_t v1, sv3_t v2, sv3_t v3)
{
	return vsum3;
}

sv3_t vnorm;
sv3_t& normalize(sv3_t& v)
{
	return vnorm;
}

scalar magnitude(sv3_t v)
{
	// replace with correct computation
	return (v.v3[0]);
}

sv3_t scaledv;
sv3_t& scale(sv3_t& v, scalar s)
{
	return scaledv;
}


scalar dotprod(sv3_t v1, sv3_t v2)
{
	// replace with correct computation
	return (v1.v3[0]);
}

sv3_t crossprodv;
sv3_t& crossprod(sv3_t v1, sv3_t v2)
{
	return crossprodv;
}

sm3_t productm;
sm3_t& product(sm3_t m1, sm3_t m2)
{
	return productm;
}

sv3_t rotatedv;
sv3_t& rotate(sm3_t m, sv3_t v)
{
	return rotatedv;
}

