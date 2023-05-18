#include "Visualization.h"
void Visualization::button(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(30, 0, "����");//���Ϊ0��������Ӧ

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);
}

void Visualization::picture(const char* text)
{
	IMAGE img;
	loadimage(&img, text);
	putimage(0, 0, &img);
}

void Visualization::picture(int x, int y, int w, int h, const char* text)
{
	IMAGE img;
	loadimage(&img, text, w, h, 1);
	putimage(x, y, &img);
}

void Visualization::Visualize(Manage* m)
{
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (m->map[i][j] == '$')
			{
				picture(40 * j, 40 * i, 40, 40, "./food.png");
			}
			else if (m->map[i][j] == '#')
			{
				picture(40 * j, 40 * i, 40, 40, "./obstacle.jpg");
			}
			else if (m->map[i][j] == 's')
			{
				//����������
				setlinecolor(BLACK);//���α߿��ߵ���ɫ
				setfillcolor(RGB(rand() % 255, rand() % 2, rand() % 255));//�ڲ������ɫ
				fillrectangle(40 * j, 40 * i, 40 * (j + 1), 40 * (i + 1));
			}
		}
	}
}
