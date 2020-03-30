#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "ml6.h"

int main(){
	FILE* f = fopen("rawData","r");
	FILE* obj = fopen("pList","w");

	char line[128];
	double vertices[256][3];
	char* faces;
	char* b;
	int p;
	int waste1,waste2; //God this is dirty
	int vList[4];

	for(int x = 0; x < 256; x++){
		fgets(line,sizeof(line),f);

		line[strlen(line)-1] = '\0';

		sscanf(line, "v %lf %lf %lf", vertices[x], vertices[x]+1, vertices[x]+2);
		printf("%lf %lf %lf\n", vertices[x][0], vertices[x][1], vertices[x][2]);
	}

	for(int x = 0; x < 263; x++){

		b = malloc(128);
		p = 0;

		fgets(line,sizeof(line),f);

		line[strlen(line)-1] = '\0';
		strcpy(b,line);
		//printf("%s\n", b);

		while( (faces = strsep(&b," ")) != NULL){
			if(strcmp(faces,"f") != 0){
				sscanf(faces,"%d/%d/%d",vList+p,&waste1,&waste2);
				p++;
			}
		}

		for(int n = 0; n < p; n++){
			printf("%d\n", vList[n]);
		} printf("\n");

		if(p == 3){
			fprintf(obj,"polygon\n%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", 
				vertices[vList[0]-1][0],vertices[vList[0]-1][1],vertices[vList[0]-1][2],
				vertices[vList[1]-1][0],vertices[vList[1]-1][1],vertices[vList[1]-1][2],
				vertices[vList[2]-1][0],vertices[vList[2]-1][1],vertices[vList[2]-1][2]);
		} else {
			fprintf(obj,"polygon\n%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", 
				vertices[vList[0]-1][0],vertices[vList[0]][1],vertices[vList[0]-1][2],
				vertices[vList[1]-1][0],vertices[vList[1]][1],vertices[vList[1]-1][2],
				vertices[vList[2]-1][0],vertices[vList[2]][1],vertices[vList[2]-1][2]);
			fprintf(obj,"polygon\n%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", 
				vertices[vList[0]-1][0],vertices[vList[0]-1][1],vertices[vList[0]-1][2],
				vertices[vList[2]-1][0],vertices[vList[2]-1][1],vertices[vList[2]-1][2],
				vertices[vList[3]-1][0],vertices[vList[3]-1][1],vertices[vList[3]-1][2]);
		}
		free(b);

	}

	fclose(f);
	fclose(obj);
}