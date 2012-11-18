#include "LinkGame.h"
#include "Board.h"
#include "Point.h"
#include "DxLib.h"
#include <stdio.h>

// ��ӭ���濪ʼ��Ϸ��ť
int startGameLeftTopX = 335, startGameLeftTopY = 218,  startGameRightBottomX = 335 + 255,startGameRightBottomY = 218+130;
// ��ӭ����������ǰ�ť
int aboutUsLeftTopX = 405, aboutUsLeftTopY = 408, aboutUsRightBottomX =405+121, aboutUsRightBottomY=408+44;
// �������ǽ��淵�ػ�ӭ����İ�ť
int welcomeLeftTopX = 633, welcomeLeftTopY = 477, welcomeRightBottomX = 633 + 83, welcomeRightBottomY = 477 + 94;
// ��Ϸ�����˳���Ϸ��ť
int finishLeftTopX = 703, finishLeftTopY = 457, finishRightBottomX = 703 + 49, finishRightBottomY = 457 + 80;
// ��Ϸ����board�ķ�Χ
int boardLeftTopX = 26, boardLeftTopY = 107, boardRightBottomX = 26 + 600, boardRightBottomY = 107 + 464;
// ���������˳���Ϸ��ť
int exitLeftTopX = 418, exitLeftTopY = 457, exitRightBottomX = 418 + 121, exitRightBottomY = 457 + 45;
// �����������¿�ʼ��ť
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

		// ��׽���
		mouseInput = GetMouseInput();
		if (( mouseInput & MOUSE_INPUT_LEFT ) != 0)
		{
			GetMousePoint( &mouseX, &mouseY );
		}

        if (engine->getStatus() == InWelcome)
		{
			
            // ��Ϸ��ӭҳ��Ҫ��Ӧ���¼�
			if (mouseInput)
			{
				if (mouseX >= startGameLeftTopX && mouseY >= startGameLeftTopY && mouseX <= startGameRightBottomX && mouseY <= startGameRightBottomY )
					engine->startGame();
				if (mouseX >= aboutUsLeftTopX && mouseY >= aboutUsLeftTopY && mouseX <= aboutUsRightBottomX && mouseY <= aboutUsRightBottomY )
					engine->aboutUs();//��������
				if (mouseX >= exitLeftTopX && mouseX <= exitRightBottomX && mouseY >= exitLeftTopY && mouseY <= exitRightBottomY) {
					engine->quit();
					return 0;
				}
			}
        }
        else if (engine->getStatus() == InAboutUs)
        {
        	// ��������ҳ��Ҫ��Ӧ���¼�
        	if (mouseInput)
        	{
        		if (mouseX >= welcomeLeftTopX && mouseY >= welcomeLeftTopY && mouseX <= welcomeRightBottomX && mouseY <= welcomeRightBottomY)
        			engine->menu();
        	}
        }
		else if (engine->getStatus() == InGame) 
		{
			
            // ��Ϸ����ҳ��Ҫ��Ӧ���¼�

			/*-- ����ʱ��--*/
			if (engine->timeIsUp())
				engine->finish();

			if (engine->getBoard()->empty())
				engine->finish();

			/*--------------------------------��Ӧ���----------------------------------------------------*/
			if (mouseInput)
			{
				// ��Board��
				if (mouseX >= boardLeftTopX && mouseY >= boardLeftTopY && mouseX <= boardRightBottomX && mouseY <= boardRightBottomY)
				{
					// ��Ϊ��һ��ѡ��ͼƬ
					if (click == false)
					{
						click = true;
						input1.x = convertX(mouseX);
						input1.y = convertY(mouseY);

						// change the selected picture
						engine->getBoard()->changeMode(input1);
					}

					// ��ѡ���˵ڶ���ͼƬ
					else
					{
						click = false;
						input2.x = convertX(mouseX);
						input2.y = convertY(mouseY);

						// ��engine��board���ú���

						if (engine->getBoard()->findPath(input1,input2,rtn1,rtn2) <0 || (input1.x == input2.x&&input1.y == input2.y))
						{
							// �ָ���ѡ��ͼƬ״̬
							engine->getBoard()->resetMode(input1);
							
						}
						else
						{
							engine->getBoard()->remove(input1, input2); // ɾ��ͼƬ
							// ����!
						}

					}
				}

				// Board��
				else
				{
					// ���Ѿ�ѡ����һ��ͼƬ������ָ�
					if (click == true)
						engine->getBoard()->resetMode(input1);

					click = false;
					if (mouseX >= finishLeftTopX && mouseY >= finishLeftTopY && mouseX <= finishRightBottomX && mouseY <= finishRightBottomY )
					{
						engine->finish();
					}
				}
			}
			/*--------------------------------��Ӧ������----------------------------------------------------*/
        } 
		else if (engine->getStatus() == InFinish)
		{
            // ��Ϸ����ҳ��Ҫ��Ӧ���¼�
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