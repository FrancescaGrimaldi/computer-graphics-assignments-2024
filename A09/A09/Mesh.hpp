

/**************
 Creae the meshes, as described below
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

void MakeSquare(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	float halfSize = size / 2.0f;

	vertices = {
				   {-halfSize,0.0f,-halfSize,0.0f,1.0f,0.0f},
				   {-halfSize,0.0f, halfSize,0.0f,1.0f,0.0f},
				   { halfSize,0.0f,-halfSize,0.0f,1.0f,0.0f},
				   { halfSize,0.0f, halfSize,0.0f,1.0f,0.0f}};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
/*	vertices = {
				   {-size/2.0f,0.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   {-size/2.0f,0.0f, size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f,0.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f,0.0f, size/2.0f,0.0f,1.0f,0.0f}};
	indices = {0, 1, 2,    1, 3, 2};
*/ 
	float halfSize = size / 2.0f;

    vertices = {
        // 0-3 bottom
        {-halfSize, -halfSize, -halfSize, 0.0f, -1.0f, 0.0f}, // 0
        {-halfSize, -halfSize,  halfSize, 0.0f, -1.0f, 0.0f}, // 1
        { halfSize, -halfSize, -halfSize, 0.0f, -1.0f, 0.0f}, // 2
        { halfSize, -halfSize,  halfSize, 0.0f, -1.0f, 0.0f}, // 3
        // 4-7 top
        {-halfSize,  halfSize, -halfSize, 0.0f, 1.0f, 0.0f},
        {-halfSize,  halfSize,  halfSize, 0.0f, 1.0f, 0.0f},
        { halfSize,  halfSize, -halfSize, 0.0f, 1.0f, 0.0f},
        { halfSize,  halfSize,  halfSize, 0.0f, 1.0f, 0.0f},
        // 8-11 front
        {-halfSize, -halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        { halfSize, -halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        {-halfSize,  halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        { halfSize,  halfSize,  halfSize, 0.0f, 0.0f, 1.0f},
        // 12-15 back
        {-halfSize, -halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        { halfSize, -halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        {-halfSize,  halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        { halfSize,  halfSize, -halfSize, 0.0f, 0.0f, -1.0f},
        // 16-19 left
        {-halfSize, -halfSize, -halfSize, -1.0f, 0.0f, 0.0f},
        {-halfSize, -halfSize,  halfSize, -1.0f, 0.0f, 0.0f},
        {-halfSize,  halfSize, -halfSize, -1.0f, 0.0f, 0.0f},
        {-halfSize,  halfSize,  halfSize, -1.0f, 0.0f, 0.0f},
        // 20-23 right
        { halfSize, -halfSize, -halfSize, 1.0f, 0.0f, 0.0f},
        { halfSize, -halfSize,  halfSize, 1.0f, 0.0f, 0.0f},
        { halfSize,  halfSize, -halfSize, 1.0f, 0.0f, 0.0f},
        { halfSize,  halfSize,  halfSize, 1.0f, 0.0f, 0.0f}
    };

    indices = {
        4,5,6, 5,7,6,           // top
        0,2,1, 1,2,3,           // bottom
        16,17,18, 17,19,18,     // left
        20,22,21, 21,22,23,     // right
        8,9,10, 10,9,11,        // front
        12,14,13, 13,14,15,     // back
    };

}

void MakeCylinder(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
/*  vertices = {
				   {-radius,-height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   {-radius, height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   { radius,-height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   { radius, height/2.0f,0.0f,0.0f,0.0f,1.0f}};
    indices = {0, 2, 1,    1, 2, 3};
*/
	float halfHeight = height / 2.0f;

	vertices.resize((slices + 1) * 2 * 2); // adding double the vertices to include two normals
    indices.resize(6 * 2 * slices);

    int vertexCount = 0;

    // Generate vertices for the cylinder
    for (int i = 0; i < slices; ++i) {
        float angle = 2.0f * M_PI * i / slices;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

		vertices[vertexCount] = { x, halfHeight, z, 0.0f, 1.0f, 0.0f };     // top - normal pointing upward
        vertexCount++;

		vertices[vertexCount] = { x, -halfHeight, z, 0.0f, -1.0f, 0.0f };   // bottom - normal pointing downward
        vertexCount++;

        vertices[vertexCount] = { x, halfHeight, z, x / radius, 0.0f, z / radius };    // top - side normal
        vertexCount++;

		vertices[vertexCount] = { x, -halfHeight, z, x / radius, 0.0f, z / radius };   // bottom - side normal
        vertexCount++;
    }

    int topCenterIdx = vertexCount; // index of the top center vertex
	vertices[vertexCount] = { 0.0f, halfHeight, 0.0f, 0.0f, 1.0f, 0.0f };	// top center vertex
	vertexCount++;

	int bottomCenterIdx = vertexCount;	 // index of the bottom center vertex
	vertices[vertexCount] = { 0.0f, -halfHeight, 0.0f, 0.0f, -1.0f, 0.0f };	// bottom center vertex

    // indices for top and bottom faces
    int idx = 0;
    for (int i = 0; i < slices; ++i) {
        indices[idx++] = topCenterIdx;
        indices[idx++] = ((i + 1) % slices) * 4;
        indices[idx++] = i * 4;

        indices[idx++] = bottomCenterIdx;
        indices[idx++] = i * 4 + 1;
        indices[idx++] = ((i + 1) % slices) * 4 + 1;
    }

    // indices for the side
    for (int i = 0; i < slices; ++i) {

		// 1st triangle of quadrilateral
        indices[idx++] = i * 4 + 2;
		indices[idx++] = ((i + 1) % slices) * 4 + 2;
        indices[idx++] = i * 4 + 3;

		// 2nd triangle of quadrilateral
		indices[idx++] = ((i + 1) % slices) * 4 + 2;
		indices[idx++] = ((i + 1) % slices) * 4 + 3;
        indices[idx++] = i * 4 + 3;
    }
}

void MakeCone(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
/*	vertices = {
				   {-radius,-height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   { radius,-height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   { 0.0f,   height/2.0f,0.0f,0.0f,0.0f,1.0f}};
	indices = {0, 1, 2};
*/
	float halfHeight = height / 2.0f;

	vertices.resize(slices * 2 + 2); // 2 vertices foe rach slice + 2 (apex + base center)
	indices.resize(slices * 3 * 2);  // 3 indices for each triangle

	int vertexCounter = 0;

	for (int i = 0; i < slices; ++i) {
		float ang = 2.0f * M_PI * (float)i / (float)slices;
		float x = radius * cos(ang);
		float z = radius * sin(ang);

		// normal vector in the base of the lateral surface
		glm::vec3 normalVec = normalize(glm::vec3(height * cos(ang), radius, height * sin(ang)));

		vertices[vertexCounter] = { x, -halfHeight, z, 0.0f, 0.0f, 0.0f }; // base - no normal
		vertexCounter++;

		vertices[vertexCounter] = { x, -halfHeight, z, normalVec[0], normalVec[1], normalVec[2] };	// base - side normal
		vertexCounter++;
	}

	vertices[vertexCounter] = { 0.0f, halfHeight, 0.0f, 0.0f, 0.0f, 0.0f };	// apex of the cone
	int apexIdx = vertexCounter; // index of the apex vertex

	int bottomCenterIdx = vertexCounter + 1; // index of the bottom center vertex
	vertices[vertexCounter + 1] = { 0.0f, -halfHeight, 0.0f, 0.0f, -1.0f, 0.0f };	// bottom center vertex

	int idx = 0;

	// base indices
    for (int i = 0; i < slices; ++i) {
        indices[idx++] = bottomCenterIdx;
        indices[idx++] = i * 2;
        indices[idx++] = ((i + 1) % slices) * 2;
    }

	// side indices
    for (int i = 0; i < slices; ++i) {
        indices[idx++] = apexIdx;
        indices[idx++] = ((i + 1) % slices) * 2 + 1;
        indices[idx++] = i * 2 + 1;
    }
}

void MakeSphere(float radius, int rings, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.
/*	vertices.resize(slices + 1);
	indices.resize(3*slices);
	vertices[slices] = {0.0f,0.0f,0.0f,0.0f,0.0f,1.0f};
	for(int i = 0; i < slices; i++) {
		float ang = 2*M_PI * (float)i / (float)slices;
		vertices[i] = {radius * cos(ang), radius * sin(ang), 0.0f,0.0f,0.0f,1.0f};
		indices[3*i  ] = slices;
		indices[3*i+1] = i;
		indices[3*i+2] = (i+1) % slices;
	}
*/
	vertices.resize((rings + 1) * (slices + 1));
	indices.resize(6 * rings * slices);

	for (int i = 0; i <= rings; ++i) {
		float ang2 = M_PI * (float)i / (float)rings;
		for (int j = 0; j <= slices; ++j) {
			float ang = 2.0f * M_PI * (float)j / (float)slices;
			float x = radius * sin(ang2) * cos(ang);
			float y = radius * cos(ang2);
			float z = radius * sin(ang2) * sin(ang);

			vertices[i * (slices + 1) + j] = { x, y, z, x, y, z };
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
