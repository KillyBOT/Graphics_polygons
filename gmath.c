#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
	double mag;
	mag = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);

	vector[0] /= mag;
	vector[1] /= mag;
	vector[2] /= mag;
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {
  double aX, bX, aY, bY, aZ, bZ;
  double* normal = calloc(3,sizeof(double));

  aX = polygons->m[0][i+1] - polygons->m[0][i];
  bX = polygons->m[0][i+2] - polygons->m[0][i];

  aY = polygons->m[1][i+1] - polygons->m[1][i];
  bY = polygons->m[1][i+2] - polygons->m[1][i];

  aZ = polygons->m[2][i+1] - polygons->m[2][i];
  bZ = polygons->m[2][i+2] - polygons->m[2][i];

  normal[0] = aY * bZ - aZ * bY;
  normal[1] = aZ * bX - aX * bZ;
  normal[2] = aX * bY - aY * bX;

  return normal;
}
