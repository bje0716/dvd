// scanf ������ ���� ����
#define _CRT_SECURE_NO_WARNINGS

// ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ����ü ���� �κ�
struct Person {
	char name[20]; // �̸�
	int tel; // ����ó
};

struct DvdInfo {
	char isbn[50]; // isbn
	char genre[20]; // �帣
	int lanchYear; // �����
};

struct RentalInfo {
	char dvdName[100]; // dvd �̸�
	char rentalName[20]; // �뿩��
	int rentalDate; // �뿩��¥
	int returnDate; // �ݳ���¥
	bool isLatePayment; // ��ü����
};

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
	PERSON_RENEWAL = 2,
	PERSON_DELETE = 3,
	PERSON_MENU_RETURN = 4,
	PERSON_QUIT = 5,

	// DVD �������� �޴�
	DVD_ADD = 1,
	DVD_RENEWAL = 2,
	DVD_DELETE = 3,
	DVD_MENU_RETURN = 4,
	DVD_QUIT = 5
};

const int arrSize = 100; // �迭 ũ�� ����
const int mainMenuOut = 7;
int selectedMenu = 0;

// �Լ� ���� �κ�
void showMenu();
void showPersonInfoMenu();

void main() {
	// ������ ����ü ����
	struct Person* pArr;
	struct DvdInfo* dvdArr;
	struct RentalInfo* rentalArr;

	// ������ ����ü �����迭 ����
	pArr = (struct Person*)malloc(sizeof(struct Person) * arrSize);
	dvdArr = (struct DvdInfo*)malloc(sizeof(struct DvdInfo) * arrSize);
	rentalArr = (struct RentalInfo*)malloc(sizeof(struct RentalInfo) * arrSize);

	// ���θ޴� ���
	while (1) {
		showMenu();

		scanf("%d", &selectedMenu);
		getchar();

		if (selectedMenu == PERSON_INFO) {
			printf("ȸ������ ��� ȣ��!\n");
			getchar();
			showPersonInfoMenu();
			break;
		}
		else if (selectedMenu == DVD_INFO) {
			break;
		}
		else if (selectedMenu == DVD_RENTAL) {
			break;
		}
		else if (selectedMenu == LATE_PAYMENT_PERSON) {
			break;
		}
		else if (selectedMenu == BLACK_LIST) {
			break;
		}
		else if (selectedMenu == QUIT) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		if (selectedMenu > mainMenuOut) {
			printf("�ùٸ��� ���� �޴��Դϴ�. �ٽ� �Է��ϼ���. \n");
		}
	}
}

void showMenu() {
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
}

void showPersonInfoMenu() {
	system("cls");

	selectedMenu = 0; // selectedMenu ���� �ʱ�ȭ

	printf("\n=========================== \n");
	printf("        ȸ������ \n");
	printf("=========================== \n\n");

	printf(" 1. ȸ������ �߰� \n");
	printf(" 2. ȸ������ ���� \n");
	printf(" 3. ȸ������ ���� \n");
	printf(" 4. �ڷΰ��� \n");
	printf(" 5. ���� \n\n");

	printf("���� : ");
}