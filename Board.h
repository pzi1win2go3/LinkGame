# ifndef BOARD_H
# define BOARD_H

class Point;

class Board
{
public:
	Board(int _length, int _height, int _pictureType);
	~Board();
	void rearrange();
	void generate();
	bool isSolvable();											// ! unfinished !
	int  findPath(Point p1, Point p2, Point tp1, Point tp2);	// ! unfinished !
	bool linkable(int x1, int y1, int x2, int y2);				// ! unfinished !
	void show();												// for debug
private:
	int** matrix;												// -1 for no picture, 0..n for picture number
	int length;
	int height;
	int pictureType;
	int pointLeft;
	void rearrange(int ** ptr);
	
};

#endif