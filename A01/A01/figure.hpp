

void DrawFigure(A01 *A) {
/**************
 Function A->Plot(float x1, float y1, float r, float g, float b)

 draws a single point at (x1,y1), colored with the (r,g,b) specified color.
 The point is addressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 

 Function A->Line(float x1, float y1, float x2, float y2, float r, float g, float b)

 draws a segment from point (x1,y1) to point (x2, y2), colored with the (r,g,b) specified color.
 Starting and ending points are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]),
 following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 

 Function A->Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 Vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 
 
 Using functions Plot(...), Line(...) and Triangle(...) try to draw a simple picture.
 
 First remove the ten functions below (given only as an example), and replace them with your own.
 Please note that there is an upper limit in the number of primitives that can be used (89998). This number
 xs however huge, and it should not pose any limit, not even for the most complex drawings.

 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

	// sky
	A->Triangle(-2,-2, 6,0.5, -2,0.5, 0,0.7,1);

	// house
	A->Triangle(-0.4, 0.5, 0.4, 0.5, -0.4, -0.03, 0.6,0.22,0.78);
	A->Triangle(-0.4, -0.03, 0.4, 0.5, 0.4, -0.03, 0.6,0.22,0.78);

	// house roof
	A->Triangle(0.4, -0.03, 0, -0.3, -0.4, -0.03, 0.6,0.22,0.78);

	// roof lines
	A->Line(0, -0.3, 0.4, -0.03, 0,0,0);
	A->Line(0, -0.3, -0.4, -0.03, 0,0,0);

	// windows
	A->Triangle(-0.15, 0.05, -0.15, 0.25, -0.32, 0.05, 0, 0, 1);
	A->Triangle(-0.32, 0.25, -0.15, 0.25, -0.32, 0.05, 0, 0.5, 1);

	A->Triangle(0.15, 0.05, 0.15, 0.25, 0.32, 0.05, 0, 0, 1);
	A->Triangle(0.32, 0.25, 0.15, 0.25, 0.32, 0.05, 0, 0.5, 1);


	// door
	A->Triangle(-0.08,0.5, 0.08,0.5, -0.08,0.15, 0,0,0);
	A->Triangle(-0.08,0.15, 0.08,0.5, 0.08,0.15, 0,0,0);
	A->Plot(0.06,0.35, 1,1,1); // handle

	// grass
	A->Triangle(-2,2, 6,0.5, -2,0.5, 0.2,0.6,0.2);
	A->Line(-2,0.5, 2,0.5, 0.1,0.4,0.1);
}
