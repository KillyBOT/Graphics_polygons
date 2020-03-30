#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"

int main(){
	FILE* sF = fopen("exalt.stl","r");
	FILE* f = fopen("pList.txt", "w");

	char buffer[512];
	int vCount = 0;
	double vertices[3];

	while(fgets(buffer,sizeof(buffer),sF) != NULL){
		buffer[strlen(buffer)-1] = '\0';

		if(buffer[0] == 'v'){

			if(vCount == 0){
				fprintf(f,"polygon\n");
			}

			//strsep(&buffer," ");
			//printf("%s\n", buffer);

			vCount++;
			sscanf(buffer," vertex %lf %lf %lf", vertices, vertices+1, vertices+2);

			printf("%lf %lf %lf\n", vertices[0], vertices[1], vertices[2]);
			fprintf(f,"%lf %lf %lf ", vertices[0], vertices[1], vertices[2]);

			if(vCount >= 3){
				fprintf(f,"\n");
				vCount = 0;
			}
		}
	}

	//free(buffer);
	fclose(sF);
	fclose(f);
}