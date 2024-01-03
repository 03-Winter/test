#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
//int main()
//{
//	int i, j, k, h, X, Y, n, z, s, m;
//	scanf("%d", &n);
//
//	i = 1 << n - 1;
//	j = 1 << n - 1;
//	X = 3 * i;
//	Y = 5 * j + (j - 1);
//	char a[3][5] = { {'*',' ','*',' ','*'},{' ','*',' ','*',' '},{' ',' ','*',' ',' ',} };
//	char b[X][Y];//= {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};//{{0},{0},{0},{0},{0},{0}};
//
//	for (i = 0; i < X; i++)
//	{
//		for (j = 0; j < Y; j++)
//		{
//			//printf("%d ",b[i][j]);
//			b[i][j] = ' ';
//			//printf("%c ",b[i][j]);
//
//		}
//		//putchar('\n');
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//
//			b[i][j] = a[i][j];
//			//printf("%c",b[i][j]);
//
//		}
//		//putchar('\n');
//	}
//
//
//
//	//for(k=0;k<n;k++)
//	{
//		for (h = 0, z = 0, k = 0, s = 0; s < n + n - 1; h++, z++, s++, k = 0)
//		{
//
//			if (z > 1)
//			{
//				z = 0;
//				h--;
//				k = h;
//				m = k;
//				//m++;
//			}
//			//printf("h = %d ",h);
//			//printf("k = %d ",k);
//			//printf("m = %d ",m);
//			//printf("s = %d ",s);
//			//printf("z = %d ",z);
//			//putchar('\n');
//
//
//			for (i = (k > 0) * 3 * (1 << k - 1); i < 3 * (1 << m); i++)//(k>0)*3*(1<<k-1)
//			{
//
//				for (j = (h > 0) * (5 * (1 << (h - 1)) + (1 << (h - 1))) - ((k > 0) << k - 1) * (3); j < 5 * (1 << h) + (1 << h) - 1 - ((k > 0) << k - 1) * (3); j++)
//				{
//					//printf("%d  ",j-(h>0)*(5*(1<<h-1)+(1<<h-1)-(k>0)*(n+1)));
//					//printf("%c",b[i][j]);
//					b[i][j] = b[i - (k > 0) * 3 * (1 << k - 1)][j - (h > 0) * (5 * (1 << h - 1) + (1 << h - 1) - ((k > 0) << k - 1) * (3))];
//				}
//
//			}
//			//putchar('\n');
//		}
//	}
//
//
//	for (i = X - 1; i >= 0; i--)
//	{
//		for (j = Y - 1; j >= 0; j--)
//		{
//			printf("%c", b[i][j]);
//
//		}
//		putchar('\n');
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < Y; j++)
//		{
//			printf("%c", b[X - 1][j]);
//		}
//		putchar('\n');
//	}
//
//	//printf("%d\n",count);
//	return 0;
//}
//

int main() {
    int n;
    scanf("%d", &n);
    int row = 3;
    int col = 5;
    char arr[400][800] = { "  *  ", " * * ", "* * *" };
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                arr[j + row][k] = arr[j][k];
                arr[j + row][k + col + 1] = arr[j][k];
            }
        }

        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                arr[j][k] = ' ';
            }
        }

        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                arr[j][k + row] = arr[j + row][k];
            }
        }

        row = row * 2;
        col = col * 2 + 1;
    }

    for (int j = 0; j < row; j++) {
        for (int k = 0; k < col; k++) {
            if (arr[j][k] == '*')
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    while (n) { //Ê÷¸ù
        for (int i = 0; i < row - 1; i++)
            printf(" ");
        printf("*\n");
        n--;
    }
    return 0;
}
