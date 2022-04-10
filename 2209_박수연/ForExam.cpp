#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;


enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET, 
	YELLOW,
	WHITE,
};
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void finish_with_error(MYSQL* conn) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	mysql_close(conn);
	exit(1);
}


int main(int argc, char* argv[]) {
	system("mode con cols=130 lines=40 | title ForExam");
	char* id_name[50] = { 0, };
	int YesOrNo = 1;
	MYSQL mysql;
	MYSQL_RES* myresult, myresult2;
	MYSQL_ROW row, row2;
	MYSQL* con = mysql_init(NULL);

	int sel = 0;
	char ID[30] = { 0, }, Password[30] = { 0, }, Number[10] = { 0, }, Name[20] = { 0, }, buffer[400];
	char show[100];
	char* x = { 0 };
	int y = 10;

	int Subject = 0;

	char Subject_name[30] = { 0, };
	int first = 0, last = 0, middle = 0, first_score = 0, last_score = 0, middle_score = 0, total = 0;


	MYSQL* conn = mysql_init(NULL);

	if (conn == NULL)
	{
		fprintf(stderr, " % s\n", mysql_error(conn));
		exit(1);
	}
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");

	if (!mysql_real_connect(&mysql, "localhost", "root", "mirim", "forexam_db", 0, NULL, 0)) {
		fprintf(stderr, "% s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
	else
	{
		mysql_query(&mysql, "set names euckr");
		fputs("mysql connect success!\n", stdout);

	}
	char c = NULL;

	setColor(YELLOW);
	cout<<endl<<endl<<endl << "                                                    ☆                                                              " << endl;
	cout << "    ☆                                                                              ☆ " << endl;
	cout << "                       ☆                                                                                                             " << endl;
	cout << "                                                                                                                          ☆ " << endl;
	cout << "                                                                 ☆            " << endl;
	cout << "             ☆                                                                                               ☆ " << endl;
	setColor(VIOLET);
	cout << "                   ■■■■■                           ■■■■■                         " << endl;
	cout << "                   ■                                   ■                                                          " << endl;
	cout << "                   ■          ■■                     ■           ■      ■     " << endl;
	cout << "                   ■■■■   ■  ■     ■ ■■        ■■■■       ■  ■      ■■          ■■  ■■               " << endl;
	cout << "                   ■        ■    ■    ■■           ■               ■       ■  ■■      ■   ■   ■                    " << endl;
	cout << "                   ■         ■  ■     ■             ■             ■  ■     ■  ■ ■     ■   ■   ■                  " << endl;
	cout << "                   ■          ■■      ■             ■■■■■   ■      ■    ■■   ■    ■   ■   ■           " << endl;
	setColor(YELLOW);
	cout << "         ☆                                                                                                            ☆            " << endl;
	cout << "                                    ☆                                                                                                                        " << endl;
	cout << "                     ☆                                                           ☆            " << endl;
	cout << "                                                ☆                                                    ☆        " << endl << endl << endl << endl;
	//Sleep(3000);
	//system("cls");

	setColor(WHITE);

	do {
		
		cout << "                                                 1. 로그인 하기  " << endl;
		cout << "                                                 2. 회원가입 하기  " << endl;
		cout << "                                                 => ";
		cin >> sel;

		Sleep(100);
		system("cls");


		switch (sel) {
		case 2:

			do
			{
				cout << endl << endl << endl << "                                                 ------------- 회원가입 ------------- " << endl << endl << endl;
				cout << "                                                      아이디를 입력해주세요                                    " << endl;
				cout << "                                                      아이디 =>";
				cin >> ID;

				cout << "                                                                                                 " << endl;
				cout << "                                                                                                 " << endl;
				//ID[strlen(ID) - 1] = '\0';

				sprintf(buffer, "select ID from nana where ID= \'%s\'", ID);
				mysql_query(&mysql, buffer);
				myresult = mysql_store_result(&mysql);
				row = mysql_fetch_row(myresult);

				if (row != NULL) {
					cout << "                                                    이미 생성된 아이디 입니다.\n";
					Sleep(2000);
					system("cls");
					Sleep(10);
				}
			} while (row != NULL);

			do {
				cout << endl << endl << "                                                      비밀번호를 입력해주세요                                    " << endl;
				cout << "                                                      비밀번호 =>";
				cin >> Password;

				cout << "                                                                                                 " << endl;
				cout << "                                                                                                 " << endl;
				//Password[strlen(Password) - 1] = '\0';

				if (Password[0] == '\n' || strlen(Password) > 15) {
					cout << "                                                    다시 입력하세요\n";
					Sleep(2000);
					system("cls");
					Sleep(10);
				}
			} while (Password[0] == '\n' || strlen(Password) > 15);

			do {
				cout << endl << endl << "                                                      이름을 입력해주세요                                    " << endl;
				cout << "                                                      이름 =>";
				cin >> Name;

				cout << "                                                                                                 " << endl;
				cout << "                                                                                                 " << endl;

			} while (Name[0] == '\n');

			do {
				cout << endl << endl << "                                                      학번을 입력해주세요                                    " << endl;
				cout << "                                                      학번 =>";
				cin >> Number;

				cout << "                                                                                                 " << endl;
				cout << "                                                                                                 " << endl;
				Number[strlen(Number)] = '\0';

				if (Number[0] == '\n') {
					cout << "                                                   다시 입력하세요\n";
					Sleep(10);
					system("cls");
					Sleep(10);
				}
			} while (Number[0] == '\n');

			do {
				cout << endl << endl << "                                                      과목 수를 입력해주세요                                    " << endl;
				cout << "                                                      과목 수 =>";
				cin >> Subject;

				cout << "                                                                                                 " << endl;
				cout << "                                                                                                 " << endl;

				if (Subject == 0) {
					cout << "                                                    다시 입력하세요\n";
					Sleep(10);
					system("cls");
					Sleep(10);
				}
			} while (Subject == 0);
			Sleep(10);
			system("cls");
			Sleep(10);
			sprintf(buffer, "insert into nana(ID, Password, Name, Number, Subject)values(\'%s\', \'%s\', \'%s\', \'%s\', %d)", ID, Password, Name, Number, Subject);

			if (mysql_query(&mysql, buffer) == 0) {
				cout << endl << endl << "                                                                                                아무 키나 눌러주세요";
				c = _getch(); //입력값 input
				if (c != NULL) {
					Sleep(10);
					system("cls");
					Sleep(10);
					c = NULL;
				}

			}
			else {
				cout << setw(10) << "회원가입 실패\n"; break;
			}


		case 1:

			do {
				cout << endl << endl << endl << endl << endl << endl;
				setColor(GRAY);
				cout << "                                                 ------------- 로그인 ------------- " << endl;
				setColor(WHITE);
				cout << "                                                                                               " << endl;
				cout << "                                                                                               " << endl;

				cout << "                                                      아이디를 입력해주세요                                    " << endl;
				cout << "                                                      아이디 =>";
				cin >> ID;

				cout << "                                                                                                 " << endl;
				cout << "                                                                                                 " << endl;

				//ID[strlen(ID) - 1] = '\0'; 
				cout << "                                                      비밀번호를 입력해주세요                                    " << endl;
				cout << "                                                      비밀번호 =>";
				cin >> Password;

				//Password[strlen(Password) - 1] = '\0';

				sprintf(buffer, "select Password from nana where ID = \'%s\'and Password = \'%s\'", ID, Password);
				mysql_query(&mysql, buffer);
				myresult = mysql_store_result(&mysql);
				row = mysql_fetch_row(myresult);

				if (row == NULL) {
					cout << "                                     -------------------- 잘못 입력하셨습니다 --------------------\n\n\n";
					Sleep(10);
					system("cls");
					Sleep(10);
				}
			} while (row == NULL);

			cout << endl << endl;
			mysql_free_result(myresult);
			cout << "                                                 ----------- 로그인 완료 ----------- \n";
			break;
		}
	} while (sel != 2 && sel != 1);
	c = _getch();
	if (c != NULL) {
		Sleep(10);
		system("cls");
		Sleep(10);
		c = NULL;
	}

	MYSQL_RES* res;

	int fields = 0;
	int i = 0;
	int a = 0;
	char jumsu[2] = { 0, };
	int xo = 0;

	sprintf(buffer, "select name from nana where ID= \'%s\'", ID);
	mysql_query(&mysql, buffer);
	myresult = mysql_store_result(&mysql);
	row = mysql_fetch_row(myresult);
	 
	cout << endl << endl << endl << endl << "                                                        안녕하세요 " << row[i] << "님 " << endl;
	mysql_free_result(myresult);
	*id_name = ID;
	strcat(*id_name, "_subject");

	int xoxo = 1;
	int repeat = 0;
	int choice = 1000;
	int nanan = 0;
	char real_jumsu[5] = { 0, };
	char oo[15] = { 0, };
	char xx[15] = { 0, };
	//int total = 0;
	while (choice != 5) {

		cout << endl << endl << "		                                               MENU" << endl << endl;
		cout  << "		                 ----------------------------------------------------------------" << endl;
		cout << endl << "         					   0. 고사 점수 및 총 점수 확인 						" << endl << endl;
		cout << "         					   1. 평가 비율 기록및 확인" << endl << endl;
		cout << "         					   2. 중간 고사 점수 기록" << endl << endl;
		cout << "         					   3. 기말 고사 점수 기록" << endl << endl;
		cout << "         					   4. 수행평가 점수 기록" << endl << endl;
		cout << "         					   5. 프로그램 종료 하기"<< endl<<endl;
		
		cout << "		                 ----------------------------------------------------------------"<<endl<<endl;
		cout << "                                                    답변 => ";

		cin >> choice;


		c = _getch(); //입력값 input

		if (c != NULL) {
			Sleep(10);
			system("cls");
			Sleep(10);
			c = NULL;
		}
		int x1 = 0;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		switch (choice)
		{
		case 0:

			//sprintf(buffer, "UPDATE %s SET last_score = %d WHERE Subject_name = '%s'", *id_name, xoxo, oo);

			//if (mysql_query(&mysql, buffer) == 0)
			cout << endl << endl << "                                           ------------- 총 점수 확인 ------------- " << endl << endl << endl;
			cout << "                       |                |                 |                 |                |                 " << endl;
			cout << "              과목     |    중간고사    |     기말고사    |     수행평가    |      총점      |     등급      " << endl;
			cout << "                       |                |                 |                 |                |                 " << endl;

			sprintf(buffer, "select Subject_name, first_score, last_score, middle_score, first, last from %s", *id_name);
			mysql_query(&mysql, buffer);
			myresult = mysql_store_result(&mysql);

			while (row = mysql_fetch_row(myresult)) {
				x1 = atoi(row[1]);
				x2 = atoi(row[2]);
				x3 = atoi(row[3]);
				x4 = atoi(row[4]);
				x5 = atoi(row[5]);
				total = x3 + (x1 * x4 / 100) + (x2 * x5 / 100);
				
				if (total >= 90)
					jumsu[0] = 'A';
				else if (total >= 80)
					jumsu[0] = 'B';
				else if (total >= 70)
					jumsu[0] = 'C';
				else if (total >= 60)
					jumsu[0] = 'D';
				else
					jumsu[0] = 'E';

				cout << "           --------------------------------------------------------------------------------------------------   " << endl;
				cout << "                       |                |                 |                 |                |" << endl;
				cout << "              " << row[0] << "     |       " << row[1] << "       |        " << row[2] << "       |       " << row[3] << "        |       " << total << "       |       " << jumsu[0] << endl;
				cout << "                       |                |                 |                 |                |" << endl;
			}mysql_free_result(myresult);

			cout << endl << endl<<endl<<endl<<endl << "                                                                                                아무 키나 눌러주세요";
			
			c = _getch(); //입력값 input
			
			if (c != NULL) {
				Sleep(10);
				system("cls");
				Sleep(10);
				c = NULL;
			}
			break;

		case 1:
			cout << endl << endl << "                                         ------------- 성적 비율 기록 ------------- " << endl << endl << endl;
			sprintf(buffer, "SELECT 1 FROM Information_schema.tables where table_schema = 'forexam_db' and table_name = '%s'", *id_name);
			mysql_query(&mysql, buffer);
			myresult = mysql_store_result(&mysql);
			row = mysql_fetch_row(myresult);

			if (row == NULL) {
				mysql_free_result(myresult);
				cout << "                                           아직 평가 비율을 작성을 하지 않았습니다";
				sprintf(buffer, "CREATE TABLE %s(ID int primary key, Subject_name VARCHAR(30) not null, first int, last int, middle int, first_score int, last_score int, middle_score int, total int)", *id_name);
				xoxo++;
				if (mysql_query(&mysql, buffer) == 0) {
					cout << "ok";
				}
					

				c = _getch(); //입력값 input
				if (c != NULL) {
					Sleep(10);
					system("cls");
					Sleep(10);
					c = NULL;
				}

				do {
					do {
						cout << endl << endl << endl << "                                 ---------------------- 평가 비율 입력 ---------------------- " << endl << endl << endl;
						cout << "                                  과목을 입력해주세요(더이상 과목이 없다면 0을 입력해주세요)                                    " << endl;
						cout << "                                  과목 =>";
						cin >> Subject_name;
						if (*Subject_name == '0') {
							y = 0;
							break;
						}
						cout << "                                                                                                 " << endl;
						cout << "                                                                                                 " << endl;
						//ID[strlen(ID) - 1] = '\0';

						sprintf(buffer, "select Subject_name from %s where Subject_name= \'%s\'", *id_name, Subject_name);
						mysql_query(&mysql, buffer);
						myresult = mysql_store_result(&mysql);
						row = mysql_fetch_row(myresult);

						if (row != NULL) {
							cout << "                                                  이미 작성한 과목 입니다.\n";
							Sleep(1000);
							system("cls");
							Sleep(10);
						}
						mysql_free_result(myresult);
					} while (row != NULL);

					if (y == 0) {
						
						break;
					}


					do {
						cout << endl << endl << "                                  중간 고사 비율를 입력해주세요(중간고사가 없다면 0입력)                                    " << endl;
						cout << "                                  중간 고사 비율(백분율로 입력) =>";
						cin >> first;

						cout << "                                                                                                 " << endl;
						cout << "                                                                                                 " << endl;
						//Password[strlen(Password) - 1] = '\0';

						if (first == '\n') {
							cout << "                                                     다시 입력하세요\n";
							Sleep(1000);
							system("cls");
							Sleep(10);
						}
					} while (first == '\n');

					do {
						cout << endl << endl << "                                  기말 고사 비율를 입력해주세요(기말고사가 없다면 0입력)                                    " << endl;
						cout << "                                  기말 고사 비율(백분율로 입력) =>";
						cin >> last;

						cout << "                                                                                                 " << endl;
						cout << "                                                                                                 " << endl;
						//Password[strlen(Password) - 1] = '\0';

						if (last == '\n') {
							cout << "                                        다시 입력하세요\n";
							Sleep(2000);
							system("cls");
							Sleep(10);
						}
					} while (last == '\n');

					do {
						cout << endl << endl << "                                  수행 평가 비율를 입력해주세요(수행평가가 없다면 0입력)                                    " << endl;
						cout << "                                  수행 평가 비율(백분율로 입력) =>";
						cin >> middle;

						cout << "                                                                                                 " << endl;
						cout << "                                                                                                 " << endl;
						//Password[strlen(Password) - 1] = '\0';

						if (middle == '\n') {
							cout << "                                        다시 입력하세요\n";
							Sleep(2000);
							system("cls");
							Sleep(10);
						}
						
					} while (middle == '\n');
					sprintf(buffer, "insert into %s(ID, Subject_name, first, last, middle)values(%d, \'%s\', %d, %d, %d)", *id_name, xoxo, Subject_name, first, last, middle);
					xoxo++;

					if (mysql_query(&mysql, buffer) == 0) {
						cout << "                                 ----------------------" << Subject_name << " 기록완료 ----------------------\n";
						cout << endl << endl << "                                                                                                아무 키나 눌러주세요";
						c = _getch(); //입력값 input
						if (c != NULL) {
							Sleep(10);
							system("cls");
							Sleep(10);
							c = NULL;
						}
					}
					else {
						cout << setw(10) << "기록 실패\n"; break;
					}
					c = _getch(); //입력값 input
					if (c != NULL) {
						Sleep(10);
						system("cls");
						Sleep(10);
						c = NULL;
					}
				} while (y != 0);

				//mysql_free_result(myresult);

				//sprintf(buffer, "insert into %s(ID, Subject_name, first, last, middle)values(%d, '0', 0, 0, 0)", *id_name,xoxo);
				if (c != NULL) {
					Sleep(10);
					system("cls");
					Sleep(10);
					c = NULL;
				}
			}
			else {
			//mysql_free_result(myresult);
				int a = 0;

				cout << "                                           |                |                 |    " << endl;
				cout << "                                  과목     |    중간고사    |     기말고사    |    수행평가" << endl;
				cout << "                                           |                |                 |    " << endl;
				
				sprintf(buffer, "select Subject_name, first, last, middle from \%s\ ",*id_name);
							mysql_query(&mysql, buffer);
							myresult = mysql_store_result(&mysql);
							
							while (row = mysql_fetch_row(myresult)) {
								cout << "                             ---------------------------------------------------------------------   " << endl;
								printf("                                           |                |                 |          \n");
								printf("                                 %s      |       %s       |        %s       |        %s\n", row[0], row[1], row[2], row[3]);
								printf("                                           |                |                 |          \n");
							}
				/*while (xoxo!=2)
				{
					mysql_free_result(myresult);
					xoxo= xoxo-2;
					sprintf(buffer, "select Subject_name, first, last, middle from \%s\ where id = %d", *id_name,xoxo);
					mysql_query(&mysql, buffer);
					myresult = mysql_store_result(&mysql);
					row = mysql_fetch_row(myresult);

					if (row == NULL) {
						cout << "                                     -------------------- 잘못 입력하셨습니다------";
					}
					cout << "                             ---------------------------------------------------------------------   " << endl;
					cout << "                                           |                |                 |    " << endl;
					cout << "				  " << row[0] << "     |       " << row[1] << "       |       " << row[2] << "        |     " << row[3] << "		" << endl;
					cout << "                                           |                |                 |    " << endl;
					mysql_free_result(myresult);
				}*/
							cout << endl << endl << endl<<endl << endl <<endl<< endl << endl << endl<< endl << endl << endl << "                                                                                                아무 키나 눌러주세요";
							
							c = _getch(); //입력값 input
							if (c != NULL) {
								Sleep(10);
								system("cls");
								Sleep(10);
								c = NULL;
							}
			}
			break;
		case 2:
			while(1) {
				cout << endl << endl << endl << "                        점수를 입력할 과목을 입력하세요(더이상 없다면 0을 눌러주세요)" << endl;
				cout << "                        과목 : ";
				cin >> oo;
				if (strcmp(oo, "0") == 0) {
					Sleep(10);
					system("cls");
					Sleep(10);
					break;
				}	
				cout << endl << endl<< "                        "<< oo << "의 점수를 입력해주세요"<<endl ;
				cout << "                        점수 입력 : ";
				cin >> xoxo;

				sprintf(buffer, "UPDATE %s SET first_score = %d WHERE Subject_name = '%s'", *id_name, xoxo, oo);

				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl <<"                                                                                                아무 키나 눌러주세요";
				if (mysql_query(&mysql, buffer) == 0)
					cout << endl;
				else
					cout << ".";

				c = _getch(); //입력값 input
				if (c != NULL) {
					Sleep(10);
					system("cls");
					Sleep(10);
					c = NULL;
					}
				}
		

			break;
		case 4:
			while (1) {
				cout << endl << endl << endl << "                        수행평가 점수를 입력할 과목을 입력하세요(더이상 없다면 0을 눌러주세요)" << endl;
				cout << "                        과목 : ";
				cin >> oo;
				if (strcmp(oo, "0") == 0) {
					Sleep(10);
					system("cls");
					Sleep(10);
					break;
				}
				cout << endl << endl << "                        " << oo << "의 점수를 입력해주세요" << endl;
				cout << "                        점수 입력 : ";
				cin >> xoxo;

				sprintf(buffer, "UPDATE %s SET middle_score = %d WHERE Subject_name = '%s'", *id_name, xoxo, oo);

				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                                                                                아무 키나 눌러주세요";
				if (mysql_query(&mysql, buffer) == 0)
					cout << endl;
				else
					cout << ".";

				c = _getch(); //입력값 input
				if (c != NULL) {
					Sleep(10);
					system("cls");
					Sleep(10);
					c = NULL;
				}
			}

			break;
		case 3:
			while (1) {
				cout << endl << endl << endl << "                        기말 고사 점수를 입력할 과목을 입력하세요(더이상 없다면 0을 눌러주세요)" << endl;
				cout << "                        과목 : ";
				cin >> oo;
				if (strcmp(oo, "0") == 0) {
					Sleep(10);
					system("cls");
					Sleep(10);
					break;
				}
				cout << endl << endl << "                        " << oo << "의 점수를 입력해주세요" << endl;
				cout << "                        점수 입력 : ";
				cin >> xoxo;

				sprintf(buffer, "UPDATE %s SET last_score = %d WHERE Subject_name = '%s'", *id_name, xoxo, oo);

				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                                                                                아무 키나 눌러주세요";
				if (mysql_query(&mysql, buffer) == 0)
					cout << endl;
				else
					cout << ".";

				c = _getch(); //입력값 input
				if (c != NULL) {
					Sleep(10);
					system("cls");
					Sleep(10);
					c = NULL;
				}
			}

			break;
		case 5:
			repeat = choice;
			mysql_close(conn);
			exit(0);
			return(0);
			break;
		default:
			break;
		}

	}
}