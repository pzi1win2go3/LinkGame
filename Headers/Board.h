# ifndef BOARD_H
# define BOARD_H
# include "Point.h"
// #include "LinkGame.h"

class Board
{
public:
	Board(int _length, int _height, int _pictureType);			// construct the matrix[height][length],picture types needed
	~Board();
	void rearrange();											// rearrange puzzle when matrix is unsolvable
	void generate();											// generate the whole puzzle
	bool isSolvable();											
	int  findPath(Point p1, Point p2, Point &tp1, Point& tp2);	
	bool linkable(int x1, int y1, int x2, int y2);				
	void show();												// for debug
	bool isDirectlyLinked(int x1,int y1,int x2,int y2);
	bool isTwoEdgesLinked(int x1,int y1,int x2,int y2,Point &temp);
	bool isThreeEdgesLinked(int x1,int y1,int x2,int y2,Point &m,Point &n);
	void remove(Point p1, Point p2);
	void changeMode(Point p);
	void resetMode(Point p);
	bool empty();

	int getLength();
	int getHeight();
	int getVal(Point & p);
private:
	int** matrix;												// -1 for no picture, 0..n for picture number
	int length;													// horizontal length  2nd dimension in array
	int height;													// vertical length 1st dimension in array
	int pictureType;											// types of picture
	int pointLeft;												// remaining points in puzzle
	void rearrange(int ** ptr);									// rearrange puzzle when matrix is unsolvable


};

#endif
