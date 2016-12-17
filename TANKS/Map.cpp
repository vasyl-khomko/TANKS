#include "Map.h"


Map::Map(void) {
	block.width = 8;
	block.height = 8;
	size.width = 40;
	size.height = 40;
	blockTextures[0].FromFile(L"Textures\\Blocs\\1.bmp");
	blockTextures[1].FromFile(L"Textures\\Blocs\\2.bmp");
	blockTextures[2].FromFile(L"Textures\\Blocs\\3.bmp");
	baseTexture.FromFile(L"Textures\\Blocs\\Base.bmp");

}

Map::Map(string nameFile) {
	block.width = 8;
	block.height = 8;
	size.width = 40;
	size.height = 40;

	blockTextures[0].FromFile(L"Textures\\Blocs\\1.bmp");
	blockTextures[1].FromFile(L"Textures\\Blocs\\2.bmp");
	blockTextures[2].FromFile(L"Textures\\Blocs\\3.bmp");
	baseTexture.FromFile(L"Textures\\Blocs\\Base.bmp");

	FromFile(nameFile);
}

Map::~Map(void) {

}

int Map::GetElement(unsigned int x, unsigned int y) {
	if(x >= size.width || y >= size.height){
		//printf("*** Get wychid za mezi pola !!! \n ");
		return -1;
	}
	return matrix[x][y];
}

Texture& Map::BlockTexture(int index) {
	return blockTextures[index];
}

Texture& Map::BaseTexture(void) {
	return baseTexture;
}


void Map::SetElement(int element, unsigned int x, unsigned int y) {
	if(x >= size.width || y >= size.height){
		cout<<"*** Get wychid za mezi pola !!!"<<endl;;
		return;
	}
	matrix[x][y] = element;
}

void Map::SetMatrix(int matrix[40][40]) {
	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 40; j++) {
			this->matrix[i][j] = matrix[39-j][i];
		}
	}
}

void Map::FromFile(string nameFile) {
	cout<<" Map::FromFile(string nameFile) \""<<nameFile<<"\""<<endl;
	fstream file(nameFile);
	if(!file) {
		cout<<" Eror: Imput file \""<<nameFile<<"\""<<endl;
		return;
	}
	int _matrix[40][40];
	int element = 0;
	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 40; j++) {
			file>>_matrix[i][j];
		}
	}
	SetMatrix(_matrix);
	cout<<" END Map::FromFile(string nameFile) "<<endl;
}

void Map::Displey(void) {
	glEnable(GL_TEXTURE_2D);
	glColor3d(1,1,1);
	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 40; j++) {	
			if((i == 20 - 1 || i == 20) && (j == 0 || j == 1)) continue;
			if(matrix[i][j] != 0) {
				glBindTexture(GL_TEXTURE_2D, blockTextures[matrix[i][j]-1].Get()) ;	
				glPushMatrix();
					glTranslated(i*block.width, j*block.height, 0);	
					glBegin(GL_QUADS);
						glTexCoord2d(0,0); glVertex3d( 0,			0,				0);
						glTexCoord2d(0,1); glVertex3d( 0,			block.height,	0);
						glTexCoord2d(1,1); glVertex3d( block.width,	block.height,	0);
						glTexCoord2d(1,0); glVertex3d( block.width,	0,				0);
						glEnd();
					glPopMatrix();
			}
		}
	}
	glBindTexture(GL_TEXTURE_2D, baseTexture.Get()) ;	
	glPushMatrix();
		glTranslated(19*block.width, 0, 0);	
		glBegin(GL_QUADS);
			glTexCoord2d(0,0); glVertex3d( 0,				0,				0);
			glTexCoord2d(0,1); glVertex3d( 0,				2*block.height,	0);
			glTexCoord2d(1,1); glVertex3d( 2*block.width,	2*block.height,	0);
			glTexCoord2d(1,0); glVertex3d( 2*block.width,	0,				0);
		glEnd();
	glPopMatrix();
}