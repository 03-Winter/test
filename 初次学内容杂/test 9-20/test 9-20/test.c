#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

//int main()
//{
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("pf");
//		return 1;
//	}
//
//
//	int ch = fgetc(pf);
//	printf("%c", ch);
//
//	//根据当前位置来指定偏移量
//	fseek(pf, 3, SEEK_CUR);
//
//	ch = fgetc(pf);
//
//	//ftell是返回相对于起始位置的偏移量 
//	int ret = ftell(pf);
//	printf("%d", ret);
//
//	//rewind是让指针回到初始位置
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//
//int main()
//{
//	FILE* fread = fopen("test.dat", "r");
//	if (fread == NULL)
//	{
//		perror("fread");
//		return 1;
//	}
//	FILE* fwrite = fopen("test2.dat", "w");
//	if (fwrite == NULL)
//	{
//		fclose(fread);
//		perror("fwrite");
//		return 2;
//	}
//
//	int ch = 0;
//	while (ch = fgetc(fread) != EOF)
//	{
//		fputc(ch, fwrite);
//	}
//
//
//	fclose(fread);
//	fread = NULL;
//	fclose(fwrite);
//	fwrite = NULL;
//
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test2.dat", "w");
//	if (pf == NULL)
//	{
//		perror("pf");
//		return 1;
//
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%s %s %s %s %d",__DATA__)
//	}
//		return 0;
//}



#include<stdio.h>


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, n, arr[200][200] = { 0 }, brr[150] = { 0 }, rr[150] = { 0 };
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d ", &arr[m][n]);
                //printf("%d ",arr[m][n]);

            }
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &brr[i]);
            //printf("%d ",brr[i]);

        }
        while (n--)
        {
            int count = 0, c = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("%d%d", arr[i][j], brr[i]);
                    if (arr[i][j] == brr[i])
                    {
                        count++;
                        break;
                    }
                }

            }
            printf("%d ", count);

            //             rr[c]=count;
            //             c++;
        }
        //         for(int j=0;j<n;j++)
        //         {
        //             printf("%d ",rr[j]);
        //         }
        printf("\n");
    }
    return 0;
}
