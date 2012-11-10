# ifndef BOARD_H
# define BOARD_H

class Point;

class Board
{
public:
	Board(int _length, int _height, int _pictureType);			// construct the matrix[height][length],picture types needed
	~Board();
	void rearrange();											// rearrange puzzle when matrix is unsolvable
	void generate();											// generate the whole puzzle
	bool isSolvable();											// ! unfinished !	check whether solvable
	int  findPath(Point p1, Point p2, Point &tp1, Point& tp2);	// ! unfinished !	given two points, find the path
	bool linkable(int x1, int y1, int x2, int y2);				// ! unfinished !	judge whether two points are linkable
	void show();												// for debug
private:
	int** matrix;												// -1 for no picture, 0..n for picture number
	int length;													// horizontal length  2nd dimension in array
	int height;													// vertical length 1st dimension in array
	int pictureType;											// types of picture
	int pointLeft;												// remaining points in puzzle
	void rearrange(int ** ptr);									// rearrange puzzle when matrix is unsolvable
	
};

#endif