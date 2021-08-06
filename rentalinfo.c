struct RentalInfo {
	char dvdName[100]; // dvd 이름
	char rentalName[20]; // 대여자
	int rentalDate; // 대여날짜
	int returnDate; // 반납날짜
	bool isLatePayment; // 연체여부
};