

/**************
 Create the meshes, as described below
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

void MakeSquare(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	vertices = {
				   {-size/2.0f,0.0f,-size/2.0f},
				   {-size/2.0f,0.0f, size/2.0f},
				   { size/2.0f,0.0f,-size/2.0f},
				   { size/2.0f,0.0f, size/2.0f}};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
/*	vertices = {
				   {-size/2.0f,0.0f,-size/2.0f},
				   {-size/2.0f,0.0f, size/2.0f},
				   { size/2.0f,0.0f,-size/2.0f},
				   { size/2.0f,0.0f, size/2.0f}};
	indices = {0, 1, 2,    1, 3, 2}; */

	vertices = {
				   {-size/2.0f, -size/2.0f, -size/2.0f},
				   {-size/2.0f, -size/2.0f,  size/2.0f},
				   { size/2.0f, -size/2.0f, -size/2.0f},
				   { size/2.0f, -size/2.0f,  size/2.0f},
				   {-size/2.0f, size/2.0f, -size/2.0f},
				   {-size/2.0f, size/2.0f,  size/2.0f},
				   { size/2.0f, size/2.0f, -size/2.0f},
				   { size/2.0f, size/2.0f,  size/2.0f}
	};
	indices = {
				   4,5,6, 5,7,6,	// top
				   0,2,1, 1,2,3,	// bottom
				   0,1,4, 1,5,4,	// left
				   2,6,3, 3,6,7,	// right
				   0,4,2, 2,4,6,	// front face
				   1,3,5, 5,3,7,	// back face
	};

}

void MakeCylinder(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	/* vertices = {
				   {-radius,-height/2.0f,0.0f},
				   {-radius, height/2.0f,0.0f},
				   { radius,-height/2.0f,0.0f},
				   { radius, height/2.0f,0.0f}};
	indices = {0, 2, 1,    1, 2, 3}; */
	vertices.resize((slices + 1) * 2);
	indices.resize(6 * slices);
	
	for (int i = 0; i <= slices; ++i) {
		float ang = 2.0f * M_PI * (float)i / (float)slices;
		float x = radius * cos(ang);
		float z = radius * sin(ang);

		vertices[i] = { x, -height/2.0f, z };
		vertices[i + slices + 1] = { x, height/2.0f, z };
	}

	for (int i = 0; i < slices; ++i) {
		indices[6 * i] = i;
		indices[6 * i + 1] = i + slices + 1;
		indices[6 * i + 2] = i + 1;

		indices[6 * i + 3] = i + 1;
		indices[6 * i + 4] = i + slices + 1;
		indices[6 * i + 5] = i + slices + 2;
	}

	// TODO: review this part
	int bottomCenterIdx = vertices.size(); // Index of the bottom center vertex
	int topCenterIdx = vertices.size() + 1; // Index of the top center vertex
	vertices.push_back(glm::vec3(0.0f, -height / 2.0f, 0.0f)); // Bottom center vertex
	vertices.push_back(glm::vec3(0.0f, height / 2.0f, 0.0f)); // Top center vertex

	// Generate bottom cap indices
	for (int i = 0; i < slices; ++i) {
		indices.push_back(bottomCenterIdx);
		indices.push_back(i);
		indices.push_back((i + 1) % slices);
	}

	// Generate top cap indices
	int offset = slices + 1;
	for (int i = 0; i < slices; ++i) {
		indices.push_back(topCenterIdx);
		indices.push_back((i + 1) % slices + offset);
		indices.push_back(i + offset);
	}

}

void MakeCone(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
/*	vertices = {
				   {-radius,-height/2.0f,0.0f},
				   { radius,-height/2.0f,0.0f},
				   { 0.0f, height/2.0f,0.0f}};
	indices = {0, 1, 2}; */

	vertices.resize(slices + 2);
	indices.resize(3 * slices);

	vertices[slices] = { 0.0f, height/2.0f, 0.0f };  // Apex of the cone

	for (int i = 0; i < slices; ++i) {
		float ang = 2.0f * M_PI * (float)i / (float)slices;
		float x = radius * cos(ang);
		float z = radius * sin(ang);

		vertices[i] = { x, -height/2.0f, z };

		indices[3 * i] = i;
		indices[3 * i + 1] = slices;  // Apex index 
		indices[3 * i + 2] = (i + 1) % slices;
	}

	// TODO: review this part
	// Generate bottom cap vertices and indices
	int bottomCenterIdx = vertices.size(); // Index of the bottom center vertex
	vertices.push_back(glm::vec3(0.0f, -height / 2.0f, 0.0f)); // Bottom center vertex

	for (int i = 0; i < slices; ++i) {
		indices.push_back(bottomCenterIdx);
		indices.push_back(i);
		indices.push_back((i + 1) % slices);
	}
}

void MakeSphere(float radius, int rings, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.
/*	vertices.resize(slices + 1);
	indices.resize(3*slices);
	vertices[slices]= {0.0f,0.0f,0.0f};
	for(int i = 0; i < slices; i++) {
		float ang = 2*M_PI * (float)i / (float)slices;
		vertices[i] = glm::vec3(radius * cos(ang), radius * sin(ang), 0.0f);
		indices[3*i  ] = slices;
		indices[3*i+1] = i;
		indices[3*i+2] = (i+1) % slices;
	} */

	vertices.resize((rings + 1) * (slices + 1));
	indices.resize(6 * rings * slices);

	for (int i = 0; i <= rings; ++i) {
		float ang2 = M_PI * (float)i / (float)rings;
		for (int j = 0; j <= slices; ++j) {
			float ang = 2.0f * M_PI * (float)j / (float)slices;
			float x = radius * sin(ang2) * cos(ang);
			float y = radius * cos(ang2);
			float z = radius * sin(ang2) * sin(ang);

			vertices[i * (slices + 1) + j] = { x, y, z };
		}
	}

	for (int i = 0; i < rings; ++i) {
		for (int j = 0; j < slices; ++j) {
			int current = i * (slices + 1) + j;
			int next = current + slices + 1;

			indices[6 * (i * slices + j)] = current;
			indices[6 * (i * slices + j) + 1] = current + 1;
			indices[6 * (i * slices + j) + 2] = next;

			indices[6 * (i * slices + j) + 3] = current + 1;
			indices[6 * (i * slices + j) + 4] = next + 1;
			indices[6 * (i * slices + j) + 5] = next;
		}
	}
}
