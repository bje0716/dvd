// scanf 컴파일 에러 무시
#define _CRT_SECURE_NO_WARNINGS

// 매크로 상수 선언
#define ARR_SIZE 100
#define STR_LEN 20
#define TEL_LEN 15
#define ISBN_LEN 50
#define DVD_NAME_LEN 100

// 헤더 파일
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// 구조체 선언 부분
typedef struct {
	char name[STR_LEN]; // 이름
	char tel[TEL_LEN]; // 연락처
	int latePaymentCount; // 연체횟수
} Person;

typedef struct {
	char isbn[ISBN_LEN]; // isbn
	char genre[STR_LEN]; // 장르
	int lanchYear; // 출시일
} DvdInfo;

typedef struct {
	char dvdName[DVD_NAME_LEN]; // dvd 이름
	char rentalName[STR_LEN]; // 대여자
	int rentalDate; // 대여날짜
	int returnDate; // 반납날짜
	bool isLatePayment; // 연체여부
} RentalInfo;

typedef struct {
	char name[STR_LEN]; // 이름
	int latePaymentCount; // 연체횟수
} BlackList;

enum {
	// 메인 메뉴
	PERSON_INFO = 1,
	DVD_INFO = 2,
	DVD_RENTAL = 3,
	LATE_PAYMENT_PERSON = 4,
	BLACK_LIST = 5,
	QUIT = 6,

	// 회원관리 메뉴
	PERSON_ADD = 1,
	PERSON_RENEWAL = 2,
	PERSON_DELETE = 3,
	PERSON_MENU_RETURN = 4,
	PERSON_QUIT = 5,

	// DVD 정보관리 메뉴
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

// 함수 선언 부분
void showMainMenu();
void showPersonInfoMenu();

void main() {
	// 포인터 구조체 선언
	struct Person* pArr;
	struct DvdInfo* dvdArr;
	struct RentalInfo* rentalArr;

	// 메인메뉴 출력
	while (1) {
		showMainMenu();

		scanf("%d", &selectedMenu);
		getchar();

		if (selectedMenu == PERSON_INFO) {
			printf("회원관리 기능 호출!\n");
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
			printf("프로그램을 종료합니다.\n");
			break;
		}

		if (selectedMenu > mainMenuOut) {
			printf("올바르지 않은 메뉴입니다. 다시 입력하세요. \n");
		}
	}
}

void showMainMenu() {
	printf("\n============================ \n");
	printf("   DVD 대여 정보 프로그램 \n");
	printf("============================ \n\n");

	printf(" 1. 회원관리 \n");
	printf(" 2. DVD 정보관리 \n");
	printf(" 3. DVD 대여관리 \n");
	printf(" 4. 연체 고객리스트 출력 \n");
	printf(" 5. 블랙리스트 관리 \n");
	printf(" 6. 종료 \n\n");

	printf("선택 : ");
}

void showPersonInfoMenu() {
	system("cls");

	selectedMenu = 0; // selectedMenu 변수 초기화

	printf("\n=========================== \n");
	printf("        회원관리 \n");
	printf("=========================== \n\n");

	printf(" 1. 회원정보 추가 \n");
	printf(" 2. 회원정보 수정 \n");
	printf(" 3. 회원정보 삭제 \n");
	printf(" 4. 뒤로가기 \n");
	printf(" 5. 종료 \n\n");

	printf("선택 : ");
}

void personAddInfo() {

}