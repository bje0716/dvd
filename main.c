// scanf ������ ���� ����
#define _CRT_SECURE_NO_WARNINGS

// ��ũ�� ��� ����
#define ARR_SIZE 100
#define STR_LEN 20
#define TEL_LEN 15
#define ISBN_LEN 50
#define DVD_NAME_LEN 100

// ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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

const int mainMenuOut = 7;
int selectedMenu = 0;

Person person;
DvdInfo dvdInfo;
RentalInfo rentalInfo;
BlackList blackList;

// �Լ� ���� �κ�
void showMainMenu();
void showPersonInfoMenu();

void main() {
	// ������ ����ü ����
	struct Person* pArr;
	struct DvdInfo* dvdArr;
	struct RentalInfo* rentalArr;

	// ���θ޴� ���
	while (1) {
		showMainMenu();

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

void showMainMenu() {
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

void personAddInfo() {

}