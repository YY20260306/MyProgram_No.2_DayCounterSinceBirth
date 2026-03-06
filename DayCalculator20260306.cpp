#include <iostream>
#include <ctime>

int main(){
int birth_year;
int birth_month = 0;
int days_since_birth = 0;
int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
time_t t = time(nullptr);
tm now;
localtime_s(&now, &t);
int elapsed_day_this_month = now.tm_mday;
int this_month = now.tm_mon + 1;
int this_year = now.tm_year + 1900;
std::cout << "西暦で誕生年を入力してください。";
std::cin >> birth_year;
while (birth_month < 1 || birth_month > 12) {
	std::cout << "誕生月を入力してください。";
	std::cin >> birth_month;
	if (birth_month < 1 || birth_month > 12) {
		std::cout << "入力が正しくありません。1～12の間で入力してください。" << std::endl;
  }
}
if ((birth_year % 4 == 0 && birth_year % 100 != 0) || (birth_year % 400 == 0)) {
	month_days[2] = 29;
}
int age = this_year - birth_year;
int days_before_birthday = 0;
int elapsed_days_till_last_month = 0;

for (int i = 1; i < birth_month; i++) {
	days_before_birthday += month_days[i];
}
for (int i = 1; i < this_month; i++) {
	elapsed_days_till_last_month += month_days[i];
}
int leap_days = 0;
for (int y = birth_year; y < this_year; y++) {
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		leap_days++;
	}
}
 days_since_birth = age * 365 + + elapsed_days_till_last_month - days_before_birthday + elapsed_day_this_month + leap_days;

std::cout << "生まれてから約" << days_since_birth << "日が経ちました。" << std::endl;

return 0;
}