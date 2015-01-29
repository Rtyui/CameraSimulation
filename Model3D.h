#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_opengl.h>
using namespace std;

class Model3D{

private:
	vector<float*> vertices;
	vector<float*> normals;
	vector<float*> textures;
	vector<unsigned int*> vindices;
	vector<unsigned int*> nindices;
	vector<unsigned int*> tindices;
	ALLEGRO_BITMAP *texture;
	unsigned int texID;


public:
	Model3D(const char *name){

		ifstream file;

		file.open(name);

		string line;

		while(!file.eof()){

			getline(file, line);
			if(line[0] == 'v'){
				if(line[1] == ' '){
					istringstream ss(line);
					string token;
					getline(ss, token, ' ');
					getline(ss, token, ' ');
					float x = atof(token.c_str());
					getline(ss, token, ' ');
					float y = atof(token.c_str());
					getline(ss, token, ' ');
					float z = atof(token.c_str());
					float *elem = new float[3];
					elem[0] = x; elem[1] = y; elem[2] = z;
					vertices.push_back(elem);

				}

				if(line[1] == 'n'){
					istringstream ss(line);
					string token;
					getline(ss, token, ' ');
					getline(ss, token, ' ');
					float x = atof(token.c_str());
					getline(ss, token, ' ');
					float y = atof(token.c_str());
					getline(ss, token, ' ');
					float z = atof(token.c_str());
					float *elem = new float[3];
					elem[0] = x; elem[1] = y; elem[2] = z;
					normals.push_back(elem);
				}

				if(line[1] == 't'){
					istringstream ss(line);
					string token;
					getline(ss, token, ' ');
					getline(ss, token, ' ');
					float x = atof(token.c_str());
					getline(ss, token, ' ');
					float y = atof(token.c_str());
					float *elem = new float[2];
					elem[0] = x; elem[1] = y;
					textures.push_back(elem);
				}
			}
			else if(line[0] == 'u'){
				istringstream ss(line);
				string token;
				getline(ss, token, ' ');
				getline(ss, token, ' ');
				texture = al_load_bitmap(token.c_str());
				texID = al_get_opengl_texture(texture);
			}
			else if(line[0] == 'f'){
				istringstream ss(line);
				string token;
				getline(ss, token, ' ');
				getline(ss, token, ' ');
				istringstream subss(token);
				string subtoken;
				getline(subss, subtoken, '/');
				unsigned int x = atoi(subtoken.c_str());
				getline(subss, subtoken, '/');
				unsigned int tx = atoi(subtoken.c_str());
				getline(subss, subtoken, '/');
				unsigned int nx = atoi(subtoken.c_str());


				getline(ss, token, ' ');
				istringstream subss2(token);
				getline(subss2, subtoken, '/');
				unsigned int y = atoi(subtoken.c_str());
				getline(subss2, subtoken, '/');
				unsigned int ty = atoi(subtoken.c_str());
				getline(subss2, subtoken, '/');
				unsigned int ny = atoi(subtoken.c_str());

				getline(ss, token, ' ');
				istringstream subss3(token);
				getline(subss3, subtoken, '/');
				unsigned int z = atoi(subtoken.c_str());
				getline(subss3, subtoken, '/');
				unsigned int tz = atoi(subtoken.c_str());
				getline(subss3, subtoken, '/');
				unsigned int nz = atoi(subtoken.c_str());

				unsigned int *elem = new unsigned int[3];
				elem[0] = x; elem[1] = y; elem[2] = z;
				vindices.push_back(elem);

				unsigned int *telem = new unsigned int[3];
				telem[0] = tx; telem[1] = ty; telem[2] = tz;
				tindices.push_back(telem);

				unsigned int *nelem = new unsigned int[3];
				nelem[0] = nx; nelem[1] = ny; nelem[2] = nz;
				nindices.push_back(nelem);
			}
		}
		file.close();

	}

	void draw(){

		glBindTexture(GL_TEXTURE_2D, texID);

		glBegin(GL_TRIANGLES);
		for(int i = 0; i < vindices.size(); ++i){
			
			glTexCoord2fv(textures[tindices[i][0] - 1]);
			glNormal3fv(normals[nindices[i][0] - 1]); 
			glVertex3fv(vertices[vindices[i][0] - 1]);

			glTexCoord2fv(textures[tindices[i][1] - 1]);
			glNormal3fv(normals[nindices[i][1] - 1]); 
			glVertex3fv(vertices[vindices[i][1] - 1]);

			glTexCoord2fv(textures[tindices[i][2] - 1]);
			glNormal3fv(normals[nindices[i][2] - 1]); 
			glVertex3fv(vertices[vindices[i][2] - 1]);
		}

		glEnd();
	}
};