#include"DCList.h"

void main()
{
	List mylist;
	InitDCList(&mylist);

	ElemType Item;
	Node *p = NULL;
	int select = 1;
	while(select)
	{
		printf("**************************************\n");
		printf("* [1] push_back      [2] push_front  *\n");
		printf("* [3] show_list      [4] pop_back    *\n");
		printf("* [5] pop_front      [6] insert_val  *\n");
		printf("* [7] find           [8] length      *\n");
		printf("* [9] delete_val     [10] sort       *\n");
		printf("* [11] resver        [12] clear      *\n");
		printf("* [13*] destroy      [0] quit_system *\n");
		printf("**************************************\n");
		printf("��ѡ��:>");
		scanf("%d",&select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("������Ҫ���������(-1����):>");
			while(scanf("%d",&Item),Item != -1)
			{
				push_back(&mylist,Item);
			}
			break;
		case 2:
			printf("������Ҫ���������(-1����):>");
			while(scanf("%d",&Item),Item != -1)
			{
				push_front(&mylist,Item);
			}
			break;
		case 3:
			show_list(&mylist);
			break;
		case 4:
			pop_back(&mylist);
			break;
		case 5:
			pop_front(&mylist);
			break;
		case 6:
			printf("������Ҫ���������:>");
			scanf("%d",&Item);
			insert_val(&mylist,Item);
			break;
		case 7:
			printf("������Ҫ���ҵ�����:>");
			scanf("%d",&Item);
			p = find(&mylist,Item);
			if(p == NULL)
			{
				printf("Ҫ���ҵ������������в�����.\n");
			}
			break;
		case 8:
			printf("˫��ѭ������ĳ���Ϊ:> %d \n",length(&mylist));
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d",&Item);
			delete_val(&mylist,Item);
			break;
		case 10:
			sort(&mylist);
			break;
		case 11:
			resver(&mylist);
			break;
		case 12:
			clear(&mylist);
			break;
		//case 13:
		//	destroy(&mylist);
		//	break;
		default:
			printf("������������,����������.\n");
			break;
		}
	}
	destroy(&mylist);
}