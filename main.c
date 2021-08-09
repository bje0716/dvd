// scanf 컴파일 에러 무시
#define _CRT_SECURE_NO_WARNINGS

// 매크로 상수 선언
#define ARR_SIZE 100
#define STR_LEN 20
#define TEL_LEN 20
#define ISBN_LEN 50
#define DVD_NAME_LEN 100

// 헤더 파일
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

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

// 열거형 선언 부분
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
	PERSON_PRINT = 2,
	PERSON_RENEWAL = 3,
	PERSON_DELETE = 4,
	PERSON_MENU_RETURN = 5,
	PERSON_QUIT = 6,

	// DVD 정보관리 메뉴
	DVD_ADD = 1,
	DVD_PRINT = 2,
	DVD_RENEWAL = 3,
	DVD_DELETE = 4,
	DVD_MENU_RETURN = 5,
	DVD_QUIT = 6,

	// DVD 대여관리 메뉴
	DVD_RENTAL_ADD = 1,
	DVD_RENTAL_PRINT = 2,
	DVD_RENTAL_RENEWAL = 3,
	DVD_RENTAL_DELETE = 4,
	DVD_RENTAL_MENU_RETURN = 5,
	DVD_RENTAL_QUIT = 6,

	// DVD 연체관리 메뉴
	LATE_PAYMENT_ADD = 1,
	LATE_PAYMENT_PRINT = 2,
	LATE_PAYMENT_RENEWAL = 3,
	LATE_PAYMENT_DELETE = 4,
	LATE_PAYMENT_MENU_RETURN = 5,
	LATE_PAYMENT_QUIT = 6,

	// DVD 정보관리 메뉴
	BLACK_LIST_ADD = 1,
	BLACK_LIST_PRINT = 2,
	BLACK_LIST_RENEWAL = 3,
	BLACK_LIST_DELETE = 4,
	BLACK_LIST_MENU_RETURN = 5,
	BLACK_QUIT = 6,

	YES = 1,
	NO = 2
};

// 변수 선언 부분
const int menuCntOut = 7;
int selectedMenu = 0;
int cnt = 0;

// 구조체 포인터 배열 선언 부분
Person* perPtr[ARR_SIZE];
DvdInfo* dvdPtr[ARR_SIZE];
RentalInfo* rentalPtr[ARR_SIZE];
BlackList* blackListPtr[ARR_SIZE];

// 함수 선언 부분
void showMainMenu();
void showPersonInfoMenu();
void showDvdInfoMenu();
void showDvdRentalInfoMenu();
void personInfoAdd();
void showPersonPrint();

void main() {
	// 메인메뉴 출력
	showMainMenu();
}

void showMainMenu() {
	while (1) {
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

		scanf("%d", &selectedMenu);
		getchar(); // 입력 버퍼 제거

		if (selectedMenu == PERSON_INFO) {
			printf("회원관리 메뉴 호출! \n");
			showPersonInfoMenu();
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_INFO) {
			printf("DVD 정보관리 메뉴 호출! \n");
			Sleep(1000);
			showDvdInfoMenu();
			break;
		}
		else if (selectedMenu == DVD_RENTAL) {
			printf("DVD 대여관리 메뉴 호출! \n");
			showDvdRentalInfoMenu();
			break;
		}
		else if (selectedMenu == LATE_PAYMENT_PERSON) {
			printf("DVD 연체관리 메뉴 호출! \n");
			break;
		}
		else if (selectedMenu == BLACK_LIST) {
			printf("블랙리스트 관리메뉴 호출! \n");
			break;
		}
		else if (selectedMenu == QUIT) {
			printf("프로그램 종료합니다. \n");
			break;
		}

		if (selectedMenu > menuCntOut) {
			printf("올바르지 않은 메뉴입니다. 다시 입력하세요. \n");
		}
	}
}

void showPersonInfoMenu() {
	while (1) {
		system("cls");

		selectedMenu = 0; // selectedMenu 변수 초기화

		printf("\n=========================== \n");
		printf("        회원관리 \n");
		printf("=========================== \n\n");

		printf(" 1. 회원정보 추가 \n");
		printf(" 2. 회원정보 출력 \n");
		printf(" 3. 회원정보 수정 \n");
		printf(" 4. 회원정보 삭제 \n");
		printf(" 5. 뒤로가기 \n");
		printf(" 6. 종료 \n\n");

		printf("선택 : ");
		scanf("%d", &selectedMenu);
		getchar();

		if (selectedMenu == PERSON_ADD) {
			printf("회원추가 기능 호출! \n");
			personInfoAdd();
			break;
		}
		else if (selectedMenu == PERSON_PRINT) {
			printf("회원정보 출력 기능 호출! \n");
			showPersonPrint();
			break;
		}
		else if (selectedMenu == PERSON_RENEWAL) {
			printf("회원수정 기능 호출! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == PERSON_DELETE) {
			printf("회원삭제 기능 호출! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == PERSON_MENU_RETURN) {
			printf("메인메뉴 돌아가기 호출! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == PERSON_QUIT) {
			printf("프로그램 종료합니다. \n");
			break;
		}

		if (selectedMenu > menuCntOut) {
			printf("잘못된 메뉴 선택입니다. 다시 입력하세요. \n");
			Sleep(1000);
		}
	}
}

void personInfoAdd() {
	system("cls");

	// 포인터 구조체 배열 동적할당
	for (int i = 0; i < sizeof(perPtr) / sizeof(Person*); i++) {
		perPtr[i] = malloc(sizeof(perPtr));
	}

	int selectValue = 0;

	while (1) {
		// 회원 이름
		printf("%d번째 회원 이름 입력 : ", cnt + 1);
		gets(perPtr[cnt]->name);
		getchar();
		
		// 회원 연락처
		printf("%d번째 회원 연락처 입력 : ", cnt + 1);
		gets(perPtr[cnt]->tel);
		getchar();

		// 연체횟수 0부터 시작
		perPtr[cnt]->latePaymentCount = 0;

		while (1) {
			printf("계속 입력하시겠습니까? (1. 예), (2. 아니요) : ");
			scanf("%d", &selectValue);
			getchar();

			if (selectValue == YES) {
				cnt++;
				break;
			}
			else if (selectValue == NO) {
				showPersonInfoMenu(); // 전 메뉴로 돌아가기
				break;
			}
			else {
				printf("\n다시 입력해주세요 \n");
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
			printf("출력할 회원정보가 없습니다. \n");
			Sleep(1000);
			showPersonInfoMenu();
			break;
		}

		printf("\n회원이름 : %s\n", perPtr[i]->name);
		printf("연락처 : %s\n", perPtr[i]->tel);
		printf("연체횟수 : %d\n", perPtr[i]->latePaymentCount);
	}

	printf("메뉴로 돌아가시려면 1을 입력하시고, 프로그램 종료하시려면 0을 입력해주세요. : ");
	scanf("%d", &value);
	getchar();

	if (value == 1) {
		showPersonInfoMenu();
	}
	else if (value == 0) {
		printf("프로그램을 종료합니다. \n");
		// 동적메모리 해제
		for (int i = 0; i < sizeof(perPtr) / sizeof(Person); i++) {
			free(perPtr[i]);
		}
		return 0;
	}
}

void showDvdInfoMenu() {
	while (1) {
		system("cls");

		selectedMenu = 0; // 변수 초기화

		printf("\n============================ \n");
		printf("       DVD 정보 관리 \n");
		printf("============================ \n\n");

		printf(" 1. DVD 정보 추가 \n");
		printf(" 2. DVD 정보 수정 \n");
		printf(" 3. DVD 정보 삭제 \n");
		printf(" 4. 뒤로가기 \n");
		printf(" 5. 종료 \n\n");

		printf("선택 : ");
		scanf("%d", &selectedMenu);
		getchar();

		if (selectedMenu == DVD_ADD) {
			printf("DVD 정보 추가기능 호출! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_RENEWAL) {
			printf("DVD 정보 수정기능 호출! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_DELETE) {
			printf("DVD 정보 삭제기능 호출! \n");
			Sleep(1000);
			break;
		}
		else if (selectedMenu == DVD_MENU_RETURN) {
			printf("메인메뉴 돌아가기 호출! \n");
			Sleep(1000);
			system("cls");
			showMainMenu();
			break;
		}
		else if (selectedMenu == DVD_QUIT) {
			printf("프로그램을 종료합니다. \n");
			break;
		}

		if (selectedMenu > menuCntOut) {
			printf("잘못된 메뉴 선택입니다. 다시 입력하세요. \n");
			Sleep(1000); // 1초 지연
		}
	}
}

void showDvdRentalInfoMenu() {
	system("cls");

	selectedMenu = 0; // 변수 초기화

	printf("\n============================ \n");
	printf("       DVD 대여 관리 \n");
	printf("============================ \n\n");

	printf(" 1. DVD 대여정보 추가 \n");
	printf(" 2. DVD 대여정보 수정 \n");
	printf(" 3. DVD 대여정보 삭제 \n");
	printf(" 4. 뒤로가기 \n");
	printf(" 5. 종료 \n\n");

	printf("선택 : ");
	scanf("%d", &selectedMenu);
	getchar();
}