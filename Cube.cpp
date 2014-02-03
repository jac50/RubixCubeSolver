#include <iostream> // For Print Statements
#include <ctime> // For rand
#include <cstdlib> //for rand
enum FaceColours {White, Red, Blue, Orange, Green, Yellow};
enum Direction {ClockWise,CounterClockWise};
enum RelativeDirection {Up, Down, Left, Right};
enum RowCol{TopRow, BotRow, LeftCol, RightCol};
class Cube {

	public: 

	enum FaceColours cube[3][3][6];
	
	Cube( ) {
		 for (int i = 0;i < 3;i++){
			for (int j=0;j < 3;j++){
				cube[i][j][White] = White;
				cube[i][j][Red] = Red;
				cube[i][j][Blue] = Blue;				
				cube[i][j][Orange] = Orange;
				cube[i][j][Green] = Green;
				cube[i][j][Yellow] = Yellow;
			}
		}
	//Check if the Puzzle needs to be randomised.
				
	
	}
	int randomise(void){
		int randomiseSteps = 50;
		if (randomiseSteps!=0 && randomiseSteps <= 50){
			for (int i=0;i < randomiseSteps; i++){
				rotateFace((enum FaceColours) (rand() % 6),ClockWise);
			}
		}
		return 0;
	}
int rotateFace(enum FaceColours Face,enum Direction direction){
	enum FaceColours Edge[3][4];
	enum FaceColours NewFace[3][3];
	enum FaceColours NewEdge[3][4];
	//Define Edge

	enum FaceColours LeftEdge = relativeFace(Face,Left);
	enum FaceColours RightEdge = relativeFace(Face,Right);
	enum FaceColours TopEdge = relativeFace(Face, Up);
	enum FaceColours BottomEdge = relativeFace(Face,Down);
	enum RowCol rowcol;
	//Logic to calculate which edges of the top and bottom faces will be used.
	switch (Face){
		case Red:
			
			for (int i=0; i < 3; i++){
				Edge[i][Left] = cube[i][2][LeftEdge];
				Edge[i][Right] = cube[i][0][RightEdge];
				Edge[i][Up] = cube[2][i][TopEdge];
				Edge[i][Down] = cube[2][2-i][BottomEdge];
			}
			break;
		case Blue:
			for (int i=0; i < 3; i++){
				Edge[i][Left] = cube[i][2][LeftEdge];
				Edge[i][Right] = cube[i][0][RightEdge];
				Edge[i][Up] = cube[0][i][TopEdge];
				Edge[i][Down] = cube[2][i][BottomEdge];
			}
			break;
		case Orange:
			
			for (int i=0; i < 3; i++){
				Edge[i][Left] = cube[i][2][LeftEdge];
				Edge[i][Right] = cube[i][0][RightEdge];
				Edge[i][Up] = cube[0][i][TopEdge];
				Edge[i][Down] = cube[0][2 - i][BottomEdge];
			}
			break;
		case Green:
			
			for (int i=0; i < 3; i++){
				Edge[i][Left] = cube[i][2][LeftEdge];
				Edge[i][Right] = cube[i][0][RightEdge];
				Edge[i][Up] = cube[i][2][TopEdge];
				Edge[i][Down] = cube[i][0][BottomEdge];
			}
			break;
	}
	
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
		
			NewEdge[i][Up] = Edge[i][Left];
			NewEdge[i][Right] = Edge[i][Up];
			NewEdge[i][Down] = Edge[i][Right];
			NewEdge[i][Left] = Edge[i][Down];
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
		
			NewEdge[i][Up] = Edge[i][Right];
			NewEdge[i][Right] = Edge[i][Down];
			NewEdge[i][Down] = Edge[i][Left];
			NewEdge[i][Left] = Edge[i][Up];
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0;j < 3; j++){
			if (i == 1 && j == 1) continue;
			cube[i][j][Face] = NewFace[i][j];
			
		}
	}
	for (int i = 0; i < 3; i++){
		cube[i][2][LeftEdge] = NewEdge[i][Left]; //The two edges that are independant to what colour is where.
		cube[i][0][RightEdge] = NewEdge[i][Right];
	}
	switch (Face){
		case Red:
			
			for (int i=0; i < 3;i++){
				cube[2][i][TopEdge] = NewEdge[i][Up];
				cube[2][2-i][BottomEdge] = NewEdge[i][Down];
			}
			break;
		case Blue:
					
			for (int i=0; i < 3; i++){
				cube[0][i][TopEdge] = NewEdge[i][Up];
				cube[2][i][BottomEdge] = NewEdge[i][Down];
			}
			break;
		case Orange:
			
			for (int i=0; i < 3; i++){
				cube[0][i][TopEdge] = NewEdge[i][Up];
				cube[0][2-i][BottomEdge] = NewEdge[i][Down];
			}
			break;
		case Green:
			
			for (int i=0; i < 3; i++){
				cube[i][2][TopEdge] = NewEdge[i][Up];
				cube[i][0][BottomEdge] = NewEdge[i][Down];
			}
			break;
	}
	return 0;
}
enum FaceColours relativeFace(enum FaceColours Face, enum RelativeDirection direction){
	switch (Face){
		case Red:
			switch (direction){

				case Up: return Yellow ;
				case Down: return White;
				case Left: return Blue;
				case Right: return Green;
			}
			
		case Blue:
			switch (direction){
				case Up: return Blue;
				case Down: return White;
				case Left: return Orange;
				case Right: return Red;
			}
		case White:
			switch (direction){
				case Up: return Red;
				case Down: return Orange;
				case Left: return Blue;
				case Right: return Green;
			}
		case Orange:
			switch (direction){
				case Up: return Yellow;
				case Down: return White;
				case Left: return Green;
				case Right: return Blue;
			}
		case Green:
			switch (direction){
				case Up: return Yellow;
				case Down: return White;
				case Left: return Red;
				case Right: return Orange;
			}
				
		case Yellow:
			switch (direction){
				case Up: return Red;
				case Down: return White;
				case Left: return Green;
				case Right: return Blue;
			}
	}		
}

enum FaceColours getColour(enum FaceColours OriginalFace, enum RelativeDirection direction, int i){
	if (i < 0 || i > 2) {
		std::cout << "Error: Index in error. Exiting with return 6" << std::endl;
		return Red;
	}
	enum FaceColours relFace = relativeFace(OriginalFace,direction);
	switch (direction){
		case Up:
			switch (relFace){
				case Blue:
				case Red:
				case Orange:
				case Green:
					return cube[2][i][relFace];
				case Yellow:
					switch (OriginalFace){
						case Blue:
							return cube[i][0][relFace];
						case Red:
							return cube[2][i][relFace];
						case Green:
							return cube[i][2][relFace];
						case Orange:
							return cube[0][i][relFace];
					}

				case White:
					return cube[2][i][relFace];
			}
		case Left:
			switch (relFace){
				case Blue:
				case Red:
				case Orange:
				case Green:
					return cube[i][2][relFace];
			}		
							
		case Right:
			switch (relFace){
				case Blue:
				case Red:
				case Orange:
				case Green:
					return cube[0][i][relFace];
			}		
		case Down:
			switch (relFace){
				case Blue:
				case Red:
				case Orange:
				case Green:
					return cube[0][i][relFace];
				case White:
					switch (OriginalFace){
						case Red:
							return cube[2][2-i][relFace];
						case Blue:
							return cube[i][2][relFace];
						case Orange:
							return cube[0][2-i][relFace];
						case Green:
							return cube[2-i][0][relFace];
					}
			}
	}
}

};
class Solver {
	Cube cube;
	public:
	Solver(Cube cube):cube(cube){}	
	int solve(){
		enum FaceColours startingFace = pickBestFace();			
		std::cout << "Starting Face: " << startingFace << std::endl;	
		Cross(startingFace);	


	}
	enum FaceColours pickBestFace(){	
		int current = 0, best = 0;
		enum FaceColours bestColour;
		for (int i = 0 ; i < 6; i++){
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 3; k++){

					if (cube.cube[j][k][i] == i) current++;
				}
			}
			
			if (current > best){
				best = current;
				current = 0;
				bestColour = (enum FaceColours) i;
			}
		}
		return (enum FaceColours) bestColour;
		
	}
	
	int Cross(enum FaceColours startingFace){
		enum FaceColours OtherColour = Red;
		bool Run = true;
		if (cube.cube[0][1][Face] == Face)
			 OtherColour = getColour(startingFace, Up,1);
		else if (cube.cube[1][0][Face] == Face)
			OtherColour = getColour(startingFace,Left,1);
		else if (cube.cube[1][2][Face] == Face)
			OtherColour = getColour(startingFace,Right,1);
		else Run = false;
		while (relativeFace(startingFace,Up) != OtherColour && Run){ // Part of Cross is wrong. rotate until it's correct
			rotateFace(startingFace, ClockWise);
			}
		while (!CheckCross(startingFace)){
			//Rest of CheckCross Algo here		
	}
		
	bool CheckCross(enum FaceColours Face){
		//Check Top Part of Cross
		if (cube.cube[0][1][Face] == Face && cube.cube[1][0][Face] == Face && cube.cube[1][2][Face] == Face && cube.cube[2][1][Face] == Face) return true;
		else return false;
 
			
		}	
	}



};
int main(){

Cube cube = Cube();
cube.randomise();

Solver solver(cube);
solver.solve();
std::cout << "Hello World" << std::endl;

//for (int i = 0; i < 3; i++) std::cout << cube.cube[i][0][Yellow] << " " << cube.cube[i][1][Yellow] << " " << cube.cube[i][2][Yellow] << std::endl;


std::cout << std::endl;
//for (int i = 0; i < 3; i++) std::cout << cube.cube[i][0][Yellow] << " " << cube.cube[i][1][Yellow] << " " << cube.cube[i][2][Yellow] << std::endl;
std::cout << std::endl;

//cube.rotateFace(Red,CounterClockWise);
//for (int i = 0; i < 3; i++) std::cout << cube.cube[i][0][Yellow] << " " << cube.cube[i][1][Yellow] << " " << cube.cube[i][2][Yellow] << std::endl;
std::cout << std::endl;

//for (int i = 0; i < 3; i++) std::cout << cube.cube[i][0][Yellow] << " " << cube.cube[i][1][Yellow] << " " << cube.cube[i][2][Yellow] << std::endl;

std::cout << std::endl;
//for (int i = 0; i < 3; i++) std::cout << cube.cube[i][0][Yellow] << " " << cube.cube[i][1][Yellow] << " " << cube.cube[i][2][Yellow] << std::endl;
std::cout << std::endl;

return 0;
}
