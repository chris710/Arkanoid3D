#include "Block.h"
//plik Ÿród³a klasy bloczka
Block::Block(float x, float y) {
		this->X = x;
		this->Y = y;
		this->health = 1;
		this->destroyed = false;
		Loader newLoader;
		newLoader.load("res/bloczek2.obj",this->vertices,this->uvs,this->normals);
}

void Block::drawBlock() {
	//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glEnableClientState( GL_VERTEX_ARRAY );
	//glLoadIdentity();
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); 
	glVertexPointer( 3, GL_FLOAT, 0, &(this->vertices.at(0)));
	glColor3d(0.4f,0.4f,0.4f);
	glDrawArrays( GL_QUADS, 0, this->vertices.size());
	glDisableClientState( GL_VERTEX_ARRAY );
}