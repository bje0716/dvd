// scanf ������ ���� ����
#define _CRT_SECURE_NO_WARNINGS

// ��ũ�� ��� ����
#define ARR_SIZE 100
#define STR_LEN 20
#define TEL_LEN 20
#define ISBN_LEN 50
#define DVD_NAME_LEN 100

// ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

// ����ü ���� �κ�
typedef struct {
	char name[STR_LEN]; // �̸�
	char tel[TEL_LEN]; // ����ó
	int latePaymentCount; // ��üȽ��
} Person;

typedef struct {
	char isbn[ISBN_LEN]; // isbn
	char genre[STR_LEN]; // �帣
	int lanchYear; // �����
} DvdInfo;

typedef struct {
	char dvdName[DVD_NAME_LEN]; // dvd �̸�
	char rentalName[STR_LEN]; // �뿩��
	int rentalDate; // �뿩��¥
	int returnDate; // �ݳ���¥
	bool isLatePayment; // ��ü����
} RentalInfo;

typedef struct {
	char name[STR_LEN]; // �̸�
	int latePaymentCount; // ��üȽ��
} BlackList;

// ������ ���� �κ�
enum {
	// ���� �޴�
	PERSON_INFO = 1,
	DVD_INFO = 2,
	DVD_RENTAL = 3,
	LATE_PAYMENT_PERSON = 4,
	BLACK_LIST = 5,
	QUIT = 6,

	// ȸ������ �޴�
	PERSON_ADD = 1,
	PERSON_PRINT = 2,
	PERSON_RENEWAL = 3,
	PERSON_DELETE = 4,
	PERSON_MENU_RETURN = 5,
	PERSON_QUIT = 6,

	// DVD �������� �޴�
	DVD_ADD = 1,
	DVD_PRINT = 2,
	DVD_RENEWAL = 3,
	DVD_DELETE = 4,
	DVD_MENU_RETURN = 5,
	DVD_QUIT = 6,

	// DVD �뿩���� �޴�
	DVD_RENTAL_ADD = 1,
	DVD_RENTAL_PRINT = 2,
	DVD_RENTAL_RENEWAL = 3,
	DVD_RENTAL_DELETE = 4,
	DVD_RENTAL_MENU_RETURN = 5,
	DVD_RENTAL_QUIT = 6,

	// DVD ��ü���� �޴�
	LATE_PAYMENT_ADD = 1,
	LATE_PAYMENT_PRINT = 2,
	LATE_PAYMENT_RENEWAL = 3,
	LATE_PAYMENT_DELETE = 4,
	LATE_PAYMENT_MENU_RETURN = 5,
	LATE_PAYMENT_QUIT = 6,

	// DVD �������� �޴�
	BLACK_LIST_ADD = 1,
	BLACK_LIST_PRINT = 2,
	BLACK_LIST_RENEWAL = 3,
	BLACK_LIST_DELETE = 4,
	BLACK_LIST_MENU_RETURN = 5,
	BLACK_QUIT = 6,

	YES = 1,
	NO = 2
};

// ���� ���� �κ�
const int menuCntOut = 7;
int selectedMenu = 0;
int cnt = 0;

// ����ü ������ �迭 ���� �κ�
Person* perPtr[ARR_SIZE];
DvdInfo* dvdPtr[ARR_SIZE];
RentalInfo* rentalPtr[ARR_SIZE];
BlackList* blackListPtr[ARR_SIZE];

// �Լ� ���� �κ�
void showMainMenu();
void showPersonInfoMenu();
void showDvdInfoMenu();
void showDvdRentalInfoMenu();
void personInfoAdd();
void showPersonPrint();

void main() {
	// ���θ޴� ���
	showMainMenu();
}

void showMainMenu() {
	while (1) {
		printf("\n============================ \n");
		printf("   DVD �뿩 ���� ���α׷� \n");
		printf("============================ \n\n");

		printf(" 1. ȸ������ \n");
		printf(" 2. DVD �������� \n");
		printf(" 3. DVD �뿩���� \n");
		printf(" 4. ��ü ������Ʈ ��� \n");
		printf(" 5. ������Ʈ ���� \n");
		printf(" 6. ���� \n\n");

		printf("���� : ");

		scanf("%d", &selectedMenu);
		getchar(); // �Է� ���� ����

		if (selectedMenu == PERSON_INFO) {
			printf("ȸ������ �޴� ȣ��! \n");
			showPersonInfoMenu();
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_INFO) {
			printf("DVD �������� �޴� ȣ��! \n");
			Sleep(1000);
			showDvdInfoMenu();
			break;
		}
		else if (selectedMenu == DVD_RENTAL) {
			printf("DVD �뿩���� �޴� ȣ��! \n");
			showDvdRentalInfoMenu();
			break;
		}
		else if (selectedMenu == LATE_PAYMENT_PERSON) {
			printf("DVD ��ü���� �޴� ȣ��! \n");
			break;
		}
		else if (selectedMenu == BLACK_LIST) {
			printf("������Ʈ �����޴� ȣ��! \n");
			break;
		}
		else if (selectedMenu == QUIT) {
			printf("���α׷� �����մϴ�. \n");
			break;
		}

		if (selectedMenu > menuCntOut) {
			printf("�ùٸ��� ���� �޴��Դϴ�. �ٽ� �Է��ϼ���. \n");
		}
	}
}

void showPersonInfoMenu() {
	while (1) {
		system("cls");

		selectedMenu = 0; // selectedMenu ���� �ʱ�ȭ

		printf("\n=========================== \n");
		printf("        ȸ������ \n");
		printf("=========================== \n\n");

		printf(" 1. ȸ������ �߰� \n");
		printf(" 2. ȸ������ ��� \n");
		printf(" 3. ȸ������ ���� \n");
		printf(" 4. ȸ������ ���� \n");
		printf(" 5. �ڷΰ��� \n");
		printf(" 6. ���� \n\n");

		printf("���� : ");
		scanf("%d", &selectedMenu);
		getchar();

		if (selectedMenu == PERSON_ADD) {
			printf("ȸ���߰� ��� ȣ��! \n");
			personInfoAdd();
			break;
		}
		else if (selectedMenu == PERSON_PRINT) {
			printf("ȸ������ ��� ��� ȣ��! \n");
			showPersonPrint();
			break;
		}
		else if (selectedMenu == PERSON_RENEWAL) {
			printf("ȸ������ ��� ȣ��! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == PERSON_DELETE) {
			printf("ȸ������ ��� ȣ��! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == PERSON_MENU_RETURN) {
			printf("���θ޴� ���ư��� ȣ��! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == PERSON_QUIT) {
			printf("���α׷� �����մϴ�. \n");
			break;
		}

		if (selectedMenu > menuCntOut) {
			printf("�߸��� �޴� �����Դϴ�. �ٽ� �Է��ϼ���. \n");
			Sleep(1000);
		}
	}
}

void personInfoAdd() {
	system("cls");

	// ������ ����ü �迭 �����Ҵ�
	for (int i = 0; i < sizeof(perPtr) / sizeof(Person*); i++) {
		perPtr[i] = malloc(sizeof(perPtr));
	}

	int selectValue = 0;

	while (1) {
		// ȸ�� �̸�
		printf("%d��° ȸ�� �̸� �Է� : ", cnt + 1);
		gets(perPtr[cnt]->name);
		getchar();
		
		// ȸ�� ����ó
		printf("%d��° ȸ�� ����ó �Է� : ", cnt + 1);
		gets(perPtr[cnt]->tel);
		getchar();

		// ��üȽ�� 0���� ����
		perPtr[cnt]->latePaymentCount = 0;

		while (1) {
			printf("��� �Է��Ͻðڽ��ϱ�? (1. ��), (2. �ƴϿ�) : ");
			scanf("%d", &selectValue);
			getchar();

			if (selectValue == YES) {
				cnt++;
				break;
			}
			else if (selectValue == NO) {
				showPersonInfoMenu(); // �� �޴��� ���ư���
				break;
			}
			else {
				printf("\n�ٽ� �Է����ּ��� \n");
			}
		}

		if (selectValue == NO) break;
	}
}

void showPersonPrint() {
	system("cls");

	int value;

	for (int i = 0; i <= cnt; i++) {
		if (perPtr[i] == NULL) {
			printf("����� ȸ�������� �����ϴ�. \n");
			Sleep(1000);
			showPersonInfoMenu();
			break;
		}

		printf("\nȸ���̸� : %s\n", perPtr[i]->name);
		printf("����ó : %s\n", perPtr[i]->tel);
		printf("��üȽ�� : %d\n", perPtr[i]->latePaymentCount);
	}

	printf("�޴��� ���ư��÷��� 1�� �Է��Ͻð�, ���α׷� �����Ͻ÷��� 0�� �Է����ּ���. : ");
	scanf("%d", &value);
	getchar();

	if (value == 1) {
		showPersonInfoMenu();
	}
	else if (value == 0) {
		printf("���α׷��� �����մϴ�. \n");
		// �����޸� ����
		for (int i = 0; i < sizeof(perPtr) / sizeof(Person); i++) {
			free(perPtr[i]);
		}
		return 0;
	}
}

void showDvdInfoMenu() {
	while (1) {
		system("cls");

		selectedMenu = 0; // ���� �ʱ�ȭ

		printf("\n============================ \n");
		printf("       DVD ���� ���� \n");
		printf("============================ \n\n");

		printf(" 1. DVD ���� �߰� \n");
		printf(" 2. DVD ���� ���� \n");
		printf(" 3. DVD ���� ���� \n");
		printf(" 4. �ڷΰ��� \n");
		printf(" 5. ���� \n\n");

		printf("���� : ");
		scanf("%d", &selectedMenu);
		getchar();

		if (selectedMenu == DVD_ADD) {
			printf("DVD ���� �߰���� ȣ��! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_RENEWAL) {
			printf("DVD ���� ������� ȣ��! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_DELETE) {
			printf("DVD ���� ������� ȣ��! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_MENU_RETURN) {
			printf("���θ޴� ���ư��� ȣ��! \n");
			Sleep(1000);
			system("cls");
			showMainMenu();
			break;
		}
		else if (selectedMenu == DVD_QUIT) {
			printf("���α׷��� �����մϴ�. \n");
			break;
		}

		if (selectedMenu > menuCntOut) {
			printf("�߸��� �޴� �����Դϴ�. �ٽ� �Է��ϼ���. \n");
			Sleep(1000); // 1�� ����
		}
	}
}

void showDvdRentalInfoMenu() {
	system("cls");

	selectedMenu = 0; // ���� �ʱ�ȭ

	printf("\n============================ \n");
	printf("       DVD �뿩 ���� \n");
	printf("============================ \n\n");

	printf(" 1. DVD �뿩���� �߰� \n");
	printf(" 2. DVD �뿩���� ���� \n");
	printf(" 3. DVD �뿩���� ���� \n");
	printf(" 4. �ڷΰ��� \n");
	printf(" 5. ���� \n\n");

	printf("���� : ");
	scanf("%d", &selectedMenu);
	getchar();
}