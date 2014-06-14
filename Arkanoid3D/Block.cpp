#include "Block.h"
//plik Ÿród³a klasy bloczka


Block::Block(float x, float y) {
	this->X = x;
	this->Y = y;
	this->health = 1;
	this->destroyed = false;
	Loader newLoader;
	newLoader.load("res/bloczek.obj",this->vertices,this->uvs,this->normals);
			
}

void Block::drawBlock(int i, int j) {
GLuint tex;				//Globalnie do tekstury				//Obojêtnie czy globalnie, czy lokalnie do tektury ////    ŒWIAT£O
	GLenum id = GL_LIGHT0;		
    GLfloat position[ 4 ] = { 0.0f, 10.0f, 10.0f, 1.0f };
    GLfloat ambient[ 4 ] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat diffuse[ 4 ] ={ 0.8f, 0.8f, 0.8f, 1.0f }; 
    GLfloat specular[ 4 ] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
    glEnable( id );
    glLightfv( id, GL_AMBIENT, ambient );
    glLightfv( id, GL_DIFFUSE, diffuse );
    glLightfv( id, GL_SPECULAR, specular );
    glLightfv( id, GL_POSITION, position );
		

// PRZESUNIÊCIE
	mat4 V = lookAt(										//wspó³rzêdne kamery	//kamera jest sta³a!
	vec3(0.0f,0.0f,30.0f),									//gdzie
	vec3(0.0f,-5.0f,0.0f),									//kierunek
	vec3(0.0f,1.0f,0.0f));	
	this->Macierz = mat4(1.0f);
	float k = (-11.0f) + 2.02*(float)i;
	float l = ( 5.0f ) - 0.802*(float)j;
	this->Macierz = glm::translate(this->Macierz, glm::vec3(k, l, 0.0f));
	mat4 P=perspective(50.0f, 1.0f, 1.0f, 50.0f);

// ³adowanie macierzy do modelu
	glMatrixMode(GL_PROJECTION);	//macierz rzutowania
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);		//macierz modelu
	glLoadMatrixf(value_ptr(V*(this->Macierz)));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState( GL_NORMAL_ARRAY );   
	glEnableClientState( GL_VERTEX_ARRAY );

	GLfloat ambient_col[ 4 ] =  { 0.0f, 0.0f, 0.0f, 1.0f };	//materia³
	GLfloat diffuse_col[ 4 ] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specular_col[ 4 ] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat shiness = 0.9f;
	glMaterialfv( GL_FRONT, GL_AMBIENT, ambient_col );
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse_col );
	glMaterialfv( GL_FRONT, GL_SPECULAR, specular_col );
	glMaterialf( GL_FRONT, GL_SHININESS, shiness );
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); //wyœwietla siatkê
	glPolygonMode( GL_FRONT, GL_FILL );    //wyœwietla œciany

	glVertexPointer( 3, GL_FLOAT, 0, &(this->vertices.at(0)));
	glNormalPointer( GL_FLOAT, 0, &(this->normals.at(0)));
	glTexCoordPointer( 2, GL_FLOAT, 0, &(this->uvs.at(0)));
	glDrawArrays( GL_TRIANGLES, 0, this->vertices.size());
	
	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_NORMAL_ARRAY );
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}