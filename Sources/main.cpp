#include "../Headers/LinkGame.h"
#include "../Headers/Board.h"
# include "../Headers/Point.h"
#include "DxLib.h"
#include <stdio.h>

// 欢迎界面开始游戏按钮
int startGameLeftTopX = 200, startGameLeftTopY = 300,  startGameRightBottomX = 300,startGameRightBottomY = 350;
// 欢迎界面关于我们按钮
int aboutUsLeftTopX, aboutUsLeftTopY, aboutUsRightBottomX, aboutUsRightBottomY;
// 关于我们界面返回欢迎界面的按钮
int welcomeLeftTopX, welcomeLeftTopY, welcomeRightBottomX, welcomeRightBottomY;
// 游戏界面退出游戏按钮
int finishLeftTopX, finishLeftTopY, finishRightBottomX, finishRightBottomY;
// 游戏界面board的范围
int boardLeftTopX, boardLeftTopY, boardRightBottomX, boardRightBottomY;
// 结束界面退出游戏按钮
int exitLeftTopX, exitLeftTopY, exitRightBottomX, exitRightBottomY;
// 结束界面重新开始按钮
int restartLeftTopX, restartLeftTopY, restartRightBottomX, restartRightBottomY;


enum {InGame, InWelcome, InFinish};

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	int mouseInput = 0;
	int mouseX, mouseY;
	bool click = false;
	SetGraphMode( 640 , 480 , 16 ) ;
	DxLib_Init();
    LinkGame *engine = new LinkGame;
	SetMouseDispFlag( TRUE ) ;
	int Cr = GetColor(  0 , 0 , 255 ) ;// for debug
	Point input1, input2, rtn1, rtn2;

    while (1)
	{
		if( CheckHitKey( KEY_INPUT_ESCAPE ) == 1 )
			return 0;

		// 捕捉鼠标
		mouseInput = GetMouseInput();
		if (( mouseInput & MOUSE_INPUT_LEFT ) != 0)
		{
			GetMousePoint( &mouseX, &mouseY );
		}

        engine->draw();

        if (engine->getStatus() == InWelcome)
		{
			DrawBox(200,300,300,350,Cr,TRUE); // for debug
            // 游戏欢迎页面要响应的事件
			if (mouseInput)
			{
				if (mouseX >= startGameLeftTopX && mouseY >= startGameLeftTopY && mouseX <= startGameRightBottomX && mouseY <= startGameRightBottomY )
					engine->startGame();
				if (mouseX >= aboutUsLeftTopX && mouseY >= aboutUsLeftTopY && mouseX <= aboutUsRightBottomX && mouseY <= aboutUsRightBottomY )
					engine->aboutUs();//关于我们
			}
        }
        else if (engine->getStatus() == InAboutUs)
        {
        	// 关于我们页面要响应的事件
        	if (mouseInput)
        	{
        		if (mouseX >= welcomeLeftTopX && mouseY >= welcomeLeftTopY && mouseX <= welcomeRightBottomX && mouseY <= welcomeRightBottomY)
        			engine->init();
        	}
        }
		else if (engine->getStatus() == InGame) 
		{
			DrawBox(50,50,350,350,Cr,TRUE); // for debug
            // 游戏进行页面要响应的事件

			/*-- 关于时间--*/
			if (engine->timeIsUp())
				engine->finish();

			if (engine->getBoard()->empty())
				engine->finish();

			/*--------------------------------响应鼠标----------------------------------------------------*/
			if (mouseInput)
			{
				// 在Board内
				if (mouseX >= boardLeftTopX && mouseY >= boardLeftTopY && mouseX <= boardRightBottomX && mouseY <= boardRightBottomY)
				{
					// 若为第一次选中图片
					if (click == false)
					{
						click = true;
						/* convertX convertY needed here
						input1.x = convertX(mouseX);
						input1.y = convertY(mouseY);
						*/

						// change the selected picture
						engine->getBoard()->changeMode(input1);
					}

					// 若选中了第二张图片
					else
					{
						click = false;
						/* convertX convertY needed here
						input2.x = convertX(mouseX);
						input2.y = convertY(mouseY);
						*/

						// 对engine内board调用函数

						if (engine->getBoard()->findPath(input1,input2,rtn1,rtn2) <0 || (input1.x == input2.x&&input1.y == input2.y))
						{
							// 恢复被选中图片状态
							engine->getBoard()->resetMode(input1);
							
						}
						else
						{
							engine->getBoard()->remove(input1, input2); // 删除图片
							// 画线!
						}

					}
				}

				// Board外
				else
				{
					// 若已经选中了一张图片，将其恢复
					if (click == true)
						engine->getBoard()->resetMode(input1);

					click = false;
					if (mouseX >= finishLeftTopX && mouseY >= finishLeftTopY && mouseX <= finishRightBottomX && mouseY <= finishRightBottomY )
					{
						engine->finish();
					}
				}
			}
			/*--------------------------------响应鼠标结束----------------------------------------------------*/
        } 
		else if (engine->getStatus() == InFinish)
		{
            // 游戏结束页面要响应的事件
			if (mouseInput)
			{
				if (mouseX >= restartLeftTopX && mouseY >= restartLeftTopY && mouseX <= restartRightBottomX && mouseY <= restartRightBottomY )
				{
					engine->reset();
				}
				if (mouseX >= exitLeftTopX && mouseY >= exitLeftTopY && mouseX <= exitRightBottomX && mouseY <= exitRightBottomY )
					return 0; // maybe need to be written 
			}
        } 
		else 
		{
            printf("Something Went Wrong!\n");
            return 0;
        }
    }

    return 0;
}