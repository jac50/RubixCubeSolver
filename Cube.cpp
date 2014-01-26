#include <iostream>
#include <vector>
enum FaceColours {White, Red, Blue, Orange, Green, Yellow};
enum Direction {ClockWise,CounterClockWise};
enum RelativeDirection {Up, Down, Left, Right};
class Cube {

	public: 

	enum FaceColours cube[3][3][6];
	
	Cube(bool Solved = true, int randomiseSteps = 0,int size = 3) {
		 for (int i = 0;i < size;i++){
			for (int j=0;j < size;j++){
				cube[i][j][White] = White;
				cube[i][j][Red] = Red;
				cube[i][j][Blue] = Blue;				
				cube[i][j][Orange] = Orange;
				cube[i][j][Green] = Green;
				cube[i][j][Yellow] = Yellow;
			}
		}
	//Check if the Puzzle needs to be randomised.
	if (randomiseSteps!=0){
		for (int i=0;i < randomiseSteps; i++){
	
		//Implement rotations, then add in 
		}


	}
	cube[0][1][Red] = Blue;
	cube[0][0][Red] = Blue;
	cube[0][2][Red] = Blue;
}


int rotateFace(enum FaceColours Face,enum Direction direction){
	enum FaceColours Edge[3][3];
	enum FaceColours NewFace[3][3];
	enum FaceColours NewEdge[3][4];
	//Write Face to temporary Variable
	
	if (direction == ClockWise){
		NewFace[0][0] = cube[2][0][Face];
		NewFace[0][1] = cube[1][0][Face];
		NewFace[0][2] = cube[0][0][Face];
		NewFace[1][0] = cube[2][1][Face];
		NewFace[2][0] = cube[2][2][Face];
		NewFace[1][2] = cube[0][1][Face];
		NewFace[2][1] = cube[1][2][Face];
		NewFace[2][2] = cube[0][2][Face];

		
	//Edge Updating
		for (int i = 0 ; i < 3 ; i++){
		
			NewEdge[i][0] = Edge[i][3];
			NewEdge[i][1] = Edge[i][0];
			NewEdge[i][2] = Edge[i][1];
			NewEdge[i][3] = Edge[i][2];
		}
	}
	else if(direction==CounterClockWise){
		NewFace[2][0] = cube[0][0][Face];
		NewFace[1][0] = cube[0][1][Face];
		NewFace[0][0] = cube[0][2][Face];
		NewFace[0][1] = cube[1][2][Face];
		NewFace[2][2] = cube[2][0][Face];
		NewFace[2][1] = cube[1][0][Face];
		NewFace[1][2] = cube[2][1][Face];
		NewFace[0][2] = cube[2][2][Face];
	
	//Update Edges
		for (int i = 0; i < 3; i++){
		
			NewEdge[i][0] = Edge[i][1];
			NewEdge[i][1] = Edge[i][2];
			NewEdge[i][2] = Edge[i][3];
			NewEdge[i][3] = Edge[i][0];
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0;j < 3; j++){
			if (i == 1 && j == 1) continue;
			cube[i][j][Face] = NewFace[i][j];
		}
	}
}
enum FaceColours relativeFace(enum FaceColours Face, enum RelativeDirection direction){
	switch (Face){
		case Red:
			switch (direction){

				case Up: return ;
				case Down: return ;
				case Left: return ;
				case Right: return ;
			}
			
		case Blue:
			switch (direction){
				case Up: return ;
				case Down: return ;
				case Left: return ;
				case Right: return ;
			}
		case White:
			switch (direction){
				case Up: return ;
				case Down: return ;
				case Left: return ;
				case Right: return ;
			}
		case Orange:
			switch (direction}
				case Up: return ;
				case Down: return ;
				case Left: return ;
				case Right: return; 
			break;
		case Green:
			break;
		case Yellow:
			break;
	}		
}
};

int main(){

std::cout << "Hello World" << std::endl;
Cube cube = new Cube(true);
for (int i = 0; i < 3; i++) std::cout << cube.cube[i][0][Red] << " " << cube.cube[i][1][Red] << " " << cube.cube[i][2][Red] << std::endl;
cube.rotateFace(Red,CounterClockWise);
cube.rotateFace(Red,CounterClockWise);
cube.rotateFace(Red,CounterClockWise);
cube.rotateFace(Red,CounterClockWise);

for (int i = 0; i < 3; i++){
	std::cout << cube.cube[i][0][Red] << " " << cube.cube[i][1][Red] << " " << cube.cube[i][2][Red] << std::endl;
}

return 0;

}
