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

void drawBlock() {
	//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}