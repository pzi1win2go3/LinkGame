#include "../Headers/Board.h"
#include "../Headers/Point.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory.h>

bool Board::isDirectlyLinked(int x1,int y1,int x2,int y2)
{
    int i;
    int x=x1>x2?x2:x1;      //x is the smaller number between x1 and x2
    int y=y1>y2?y2:y1;      //y is the smaller number between y1 and y2
    if(x1!=x2&&y1!=y2)
        return false;


    else if(x1==x2)
    {
        for(i=y+1;i<=(y1+y2-y-1);i++)
        {
            if(matrix[x1][i]!=-1)
                return false;


        }
    }
    else if(y1==y2)
    {
        for(i=x+1;i<=(x1+x2-x)-1;i++)
        {
            if(matrix[i][y1]!=-1)
                return false;


        }
    }
    return true;

}


bool Board::isTwoEdgesLinked(int x1,int y1,int x2,int y2,Point &temp)
{
    if(x1==x2||y1==y2)
        return false;
    if(isDirectlyLinked(x1,y1,x1,y2)&&isDirectlyLinked(x1,y2,x2,y2)&&matrix[x1][y2]==-1)
    {
        temp.x=x1;
        temp.y=y2;
        return true;
    }

    if(isDirectlyLinked(x1,y1,x2,y1)&&isDirectlyLinked(x2,y1,x2,y2)&&matrix[x2][y1]==-1)
    {
        temp.x=x2;
        temp.y=y1;
        return true;
    }


    return false;
}


bool Board::isThreeEdgesLinked(int x1,int y1,int x2,int y2,Point &m,Point &n)
{
    int i;
    if(x1!=x2) //if this two cells are not in the same line
    {
        for(i=y1+1;i<=length+1;i++)
        {
            if(matrix[x1][i]!=-1)
                break;
            if(i==y2)
                continue;
            if(isTwoEdgesLinked(x1,i,x2,y2,n))
            {
                m.x=x1;
                m.y=i;
                return true;
            }



        }
        for(i=y1-1;i>=0;i--)
        {
            if(matrix[x1][i]!=-1)
                break;
            if(i==y2)
                continue;
            if(isTwoEdgesLinked(x1,i,x2,y2,n))
            {
                m.x=x1;
                m.y=i;
                return true;

            }

        }

    }
    if(y1!=y2) //if this two cells are not in the same line
    {
        for(i=x1+1;i<=height+1;i++)
        {
            if(matrix[i][y1]!=-1)
                break;
            if(i==x2)
                continue;
            if(isTwoEdgesLinked(i,y1,x2,y2,n))
            {
                m.x=i;
                m.y=y1;
                return true;
            }

        }

        for(i=x1-1;i>=0;i--)
        {
            if(matrix[i][y1]!=-1)
                break;
            if(i==x2)
                continue;
            if(isTwoEdgesLinked(i,y1,x2,y2,n))
            {
                m.x=i;
                m.y=y1;
                return true;
            }

        }
    }
    return false;

}


/* generate matrix[height][length]*/
Board::Board(int _length, int _height, int _pictureType)
{
    int i;
    length = _length;
    height = _height;
    pictureType = _pictureType;
    pointLeft = length*height;
    matrix = new int* [height+2];
    for (i = 0; i < height+2; i++)
        matrix[i] = new int[length+2];
    generate();
}

Board::~Board()
{
    int i;
    for (i = 0; i <= height+1; i++)
        delete []matrix[i];
    delete []matrix;
}


/* need to be written */
bool Board::isSolvable()  //return true if nothing can be linked
{

    int i,j,x,y;
    for(i=1;i<=height;i++)
    {
        for(j=1;j<=length;j++)
        {
            for(x=i;x<=height;x++)
            {
                for(y=j+1;y<=length;y++)
                {
                    if(linkable(i,j,x,y))
                        return false;
                }

            }
        }
    }
    return true;
}



int Board::findPath(Point p1, Point p2, Point &tp1, Point& tp2)
{
    int x1=p1.x;
    int y1=p1.y;
    int x2=p2.x;
    int y2=p2.y;
    if(isDirectlyLinked(x1,y1,x2,y2))
    {

        tp1.x=tp2.x=tp1.y=tp2.y=-1;
        return 0;

    }
    if(isTwoEdgesLinked(x1,y1,x2,y2,tp1))
    {
        tp2.x=tp2.y=-1;
        return 1;
    }
    if(isThreeEdgesLinked(x1,y1,x2,y2,tp1,tp2))
    {
        return 2;
    }
    return -1;
}



void Board::rearrange()
{
    rearrange(matrix);
}

void Board::rearrange(int ** ptr)
{
    std::vector<int> number;
    int i,j;
    for (i = 1; i <= height; i++)
        for (j = 1; j <= length; j++)
        {
            if (ptr[i][j] >= 0)
                number.push_back(ptr[i][j]);
        }
    std::random_shuffle(number.begin(),number.end());
    std::vector<int>::iterator iter = number.begin();
    for (i = 1; i <= height; i++)
        for (j = 1; j <= length; j++)
        {
            if (ptr[i][j] >= 0)
            {
                ptr[i][j] = *iter;
                ++iter;
            }
        }
}

void Board::generate()
{
    int i,j,k,l;
    int num;
    int tLeft = length*height;
    int x, y;
    int **temp = new int *[height+2];
    for (i = 0; i <= height+1; i++)
        temp[i] = new int[length+2];
    for (i = 0; i <= height+1; i++)
        for (j = 0; j <= length+1; j++)
            matrix[i][j] = temp[i][j] = -1;

    srand((unsigned int)time(NULL));
    for (i = 0; i < (height*length)/2; i++)
    { 
        num = rand() % pictureType;
        for (j = 0; j < 2; j++)
        {
            x = rand()%height+1;
            y = rand() % length+1;
            while (matrix[x][y] != -1)
            {
                y++;
                if ( y == length+1)
                {
                    y = 1;
                    x += 1;
                }
                if (x == height+1)
                    x = 1;
            }
            matrix[x][y] = num;
        }
    }

    while (tLeft > 0)
    {
        for (i = 1; i <= height; i++)
            for(j = 1; j <= length; j++)
                for (k = 1; k <= height; k++)
                    for (l = 1; l <= length; l++)
                    {
                        if (i == k && j == l)
                            continue;
                        if (matrix[i][j] != -1 && matrix[k][l] != -1)
                        {
                            //std::cout << i << ' ' << j << ':' << matrix[i][j] << '\n';
                            if (linkable(i,j,k,l))
                            {
                                temp[i][j] = matrix[i][j];
                                temp[k][l] = matrix[k][l];
                                matrix[i][j] = matrix[k][l] = -1;
                                tLeft -= 2;
                            }
                        }
                    }

        rearrange(matrix);
        //show();
    }

    for (i = 0; i < height; i++)
        delete []matrix[i];
    delete []matrix;
    matrix = temp;
    
}

/* need to be rewritten
 * judge linkability
 */
bool Board::linkable(int x1, int y1, int x2, int y2)
{
    if(matrix[x1][y1]!=matrix[x2][y2])
        return false;
    if (matrix[x1][y1] == -1 ||matrix[x2][y2] == -1 )
        return false;
    Point tmp1,tmp2;
    if(isDirectlyLinked(x1,y1,x2,y2))
    {
        return true;
    }
    if(isTwoEdgesLinked(x1,y1,x2,y2,tmp1))
    {
        return true;
    }
    if(isThreeEdgesLinked(x1,y1,x2,y2,tmp1,tmp2))
    {
        return true;
    }
    return false;
}

/* for debug */
void Board::show()
{
    int i,j;
    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= length; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void Board::remove(Point p1, Point p2)
{
	matrix[p1.x][p1.y] = matrix[p2.x][p2.y] = -1;
	pointLeft -= 2;
	return;
}

void Board::changeMode(Point p)
{
	matrix[p.x][p.y] += 1000;
}

void Board::resetMode(Point p)
{
	matrix[p.x][p.y] -= 1000;
}

bool Board::empty()
{
	return pointLeft == 0;
}
