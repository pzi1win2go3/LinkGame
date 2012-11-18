#include "LinkGame.h"
#include "Board.h"
#include "Point.h"
#include "DxLib.h"
#include <stdio.h>

// 欢迎界面开始游戏按钮
int startGameLeftTopX = 335, startGameLeftTopY = 218,  startGameRightBottomX = 335 + 255,startGameRightBottomY = 218+130;
// 欢迎界面关于我们按钮
int aboutUsLeftTopX = 405, aboutUsLeftTopY = 408, aboutUsRightBottomX =405+121, aboutUsRightBottomY=408+44;
// 关于我们界面返回欢迎界面的按钮
int welcomeLeftTopX = 633, welcomeLeftTopY = 477, welcomeRightBottomX = 633 + 83, welcomeRightBottomY = 477 + 94;
// 游戏界面退出游戏按钮
int finishLeftTopX = 703, finishLeftTopY = 457, finishRightBottomX = 703 + 49, finishRightBottomY = 457 + 80;
// 游戏界面board的范围
int boardLeftTopX = 26, boardLeftTopY = 107, boardRightBottomX = 26 + 600, boardRightBottomY = 107 + 464;
// 结束界面退出游戏按钮
int exitLeftTopX = 418, exitLeftTopY = 457, exitRightBottomX = 418 + 121, exitRightBottomY = 457 + 45;
// 结束界面重新开始按钮
int restartLeftTopX, restartLeftTopY, restartRightBottomX, restartRightBottomY;

int picW = 59, picH = 65;

int scoreX = 640, scoreY = 68;

enum {InGame, InWelcome, InFinish, InAboutUs};
LinkGame *engine;

int convertX(int x) {
	return (x - boardLeftTopX) / picW + 1;
}

int convertY(int y) {
	return (y - boardLeftTopY) / picH + 1;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	int mouseInput = 0, mouseX, mouseY;
	int white = GetColor(255, 255, 255);
	bool click = false;

	SetGraphMode( 800 , 601 , 32 ) ;
	DxLib_Init();
    
	engine = new LinkGame;
	SetMouseDispFlag( TRUE ) ;
	SetDrawScreen(DX_SCREEN_BACK);
	
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

        if (engine->getStatus() == InWelcome)
		{
			
            // 游戏欢迎页面要响应的事件
			if (mouseInput)
			{
				if (mouseX >= startGameLeftTopX && mouseY >= startGameLeftTopY && mouseX <= startGameRightBottomX && mouseY <= startGameRightBottomY )
					engine->startGame();
				if (mouseX >= aboutUsLeftTopX && mouseY >= aboutUsLeftTopY && mouseX <= aboutUsRightBottomX && mouseY <= aboutUsRightBottomY )
					engine->aboutUs();//关于我们
				if (mouseX >= exitLeftTopX && mouseX <= exitRightBottomX && mouseY >= exitLeftTopY && mouseY <= exitRightBottomY) {
					engine->quit();
					return 0;
				}
			}
        }
        else if (engine->getStatus() == InAboutUs)
        {
        	// 关于我们页面要响应的事件
        	if (mouseInput)
        	{
        		if (mouseX >= welcomeLeftTopX && mouseY >= welcomeLeftTopY && mouseX <= welcomeRightBottomX && mouseY <= welcomeRightBottomY)
        			engine->menu();
        	}
        }
		else if (engine->getStatus() == InGame) 
		{
			
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
						input1.x = convertX(mouseX);
						input1.y = convertY(mouseY);

						// change the selected picture
						engine->getBoard()->changeMode(input1);
					}

					// 若选中了第二张图片
					else
					{
						click = false;
						input2.x = convertX(mouseX);
						input2.y = convertY(mouseY);

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

		engine->draw();
    }

    return 0;
}