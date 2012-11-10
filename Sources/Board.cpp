#include "../Headers/Board.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream> 
#include <memory.h>

/* generate matrix[height][length]*/
Board::Board(int _length, int _height, int _pictureType)
{
    int i, j, k;
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
bool Board::isSolvable()
{
    return true;
}


/* need to be rewritten
 * get two points and return path
int Board::findPath(Point p1, Point p2, Point tp1, Point tp2)
{
    
}
*/


void Board::rearrange()
{
    rearrange(matrix);
}

void Board::rearrange(int ** ptr)
{
    std::vector<int> number;
    int i,j,k;
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

    srand(time(NULL));
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
                        if (linkable(i,j,k,l))
                        {
                            temp[i][j] = matrix[i][j];
                            temp[k][l] = matrix[k][l];
                            matrix[i][j] = matrix[k][l] = -1;
                            tLeft -= 2;
                        }
                    }

        rearrange(matrix);
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
    if (matrix[x1][y1] == -1 || matrix[x2][y2] == -1)
        return false;
    return true;
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
