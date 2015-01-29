#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class Model3D3{

private:
	vector<float> vertices;
	vector<float*> normals;
	vector<unsigned int> vindices;
	vector<unsigned int*> nindices;

	unsigned int vertvbo;
	unsigned int indvbo;

public:
	Model3D3(const char *name){

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

					vertices.push_back(x);
					vertices.push_back(y);
					vertices.push_back(z);

				}
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


				getline(ss, token, ' ');
				istringstream subss2(token);
				getline(subss2, subtoken, '/');
				unsigned int y = atoi(subtoken.c_str());

				getline(ss, token, ' ');
				istringstream subss3(token);
				getline(subss3, subtoken, '/');
				unsigned int z = atoi(subtoken.c_str());

				vindices.push_back(x);
				vindices.push_back(y);
				vindices.push_back(z);
			}
		}
		file.close();

		float vertices2[vertices.size()];
		float vindices2[vindices.size()];
		for(int i = 0; i < vertices.size(); i++){
			vertices2[i] = vertices[i];
		}
		for(int i = 0; i < vindices.size(); i++){
			vindices2[i] = vindices[i];
		}

		glGenBuffers(1, &vertvbo);
 		glBindBuffer(GL_ARRAY_BUFFER, vertvbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

        glGenBuffers(1, &indvbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indvbo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vindices2), vindices2, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        glBindBuffer(GL_ARRAY_BUFFER,0);


	}

	void draw(){
		

		
		  glBindBuffer(GL_ARRAY_BUFFER, vertvbo);
		  glEnableVertexAttribArray(0);
		  glVertexAttribPointer(0, 3,GL_FLOAT,GL_FALSE,0,0);

		  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indvbo);
		  glDrawElements(GL_TRIANGLES, vindices.size() * 3, GL_UNSIGNED_INT, 0);

	}
};