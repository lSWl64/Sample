#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

void inputArr(char***, int, char);
void outputArr(char***, int);
void sleep(float);
void moveLeft(char***, int);
void moveRight(char***, int);
void moveUp(char***, int);
void moveDown(char***, int);


int main()
{	//변수 선언
	string inp;
	char dir;
	float spd;
	int inpLen, rNum;

	//랜덤함수 설정
	random_device rd;
	mt19937 gen(rd());

	//필요한 값 입력
	cout << "input: ";
	getline(cin, inp);
	cout << endl << "direction(L,R,U,D,A): ";
	cin >> dir;
	cout << endl << "Speed(sec): ";
	cin >> spd;
	inpLen = inp.length();

	//3차원 포인터 arr에 동적 할당
	char*** arr = new char** [inpLen];
	for (int i = 0; i < inpLen; i++)
	{
		arr[i] = new char* [5];
		for (int j = 0; j < 6; j++)
		{
			arr[i][j] = new char[6]{ 0, };
		}
	}

	//arr 입력
	for (int i = 0; i < inpLen; i++)
	{
		inputArr(arr, i, inp[i]);
	}

	//출력
	while (1)
	{
		system("cls");
		switch (dir)
		{
		case 'L':
			moveLeft(arr, inpLen);
			break;
		case 'R':
			moveRight(arr, inpLen);
			break;
		case 'U':
			moveUp(arr, inpLen);
			break;
		case 'D':
			moveDown(arr, inpLen);
			break;
		case 'A':
		{
			rNum = gen() % 4;
			switch (rNum)
			{
			case 0:
				moveLeft(arr, inpLen);
				break;
			case 1:
				moveRight(arr, inpLen);
				break;
			case 2:
				moveUp(arr, inpLen);
				break;
			case 3:
				moveDown(arr, inpLen);
				break;
			}
			break;
		}
		default:
			cout << "잘못된 입력입니다.(L,R,U,D,A)에서 골라주세요." << endl;
			return 0;
		}
		outputArr(arr, inpLen);
		sleep(spd*1000);
	}

	return 0;
}



void inputArr(char*** arr, int index, char inp)
{

	switch (inp) {
	case ' ':
	{
		char SP[5][6] = {
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (SP[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case '!':
	{
		char EM[5][6] = {
				{0,0,1,1,0,0},
				{0,0,1,1,0,0},
				{0,0,1,1,0,0},
				{0,0,0,0,0,0},
				{0,0,1,1,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (EM[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'a':
	case 'A':
	{
		char A[5][6] = {
				{0,0,1,0,0,0},
				{0,1,0,1,0,0},
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (A[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'b':
	case 'B':
	{
		char B[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (B[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'c':
	case 'C':
	{
		char C[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,0,0,0,0,0},
				{1,0,0,0,0,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (C[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
  }
	case 'd':
	case 'D':
	{
		char D[5][6] = {
				{1,1,1,1,0,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (D[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
  }
	case 'e':
	case 'E':
	{
		char E[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (E[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
  }
	case 'f':
	case 'F':
	{
		char F[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,0,0,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (F[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'g':
	case 'G':
	{
		char G[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,0,1,1,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (G[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'h':
	case 'H':
	{
		char H[5][6] = {
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (H[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'i':
	case 'I':
	{
		char I[5][6] = {
				{1,1,1,1,1,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (I[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'j':
	case 'J':
	{
		char J[5][6] = {
				{1,1,1,1,1,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{1,1,1,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (J[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'k':
	case 'K':
	{
		char K[5][6] = {
				{1,0,0,0,1,0},
				{1,0,0,1,0,0},
				{1,1,1,0,0,0},
				{1,0,0,1,0,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (K[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'l':
	case 'L':
	{
		char L[5][6] = {
				{1,0,0,0,0,0},
				{1,0,0,0,0,0},
				{1,0,0,0,0,0},
				{1,0,0,0,0,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (L[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'm':
	case 'M':
	{
		char M[5][6] = {
				{1,0,0,0,1,0},
				{1,1,0,1,1,0},
				{1,0,1,0,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (M[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'n':
	case 'N':
	{
		char N[5][6] = {
				{1,0,0,0,1,0},
				{1,1,0,0,1,0},
				{1,0,1,0,1,0},
				{1,0,0,1,1,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (N[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'o':
	case 'O':
	{
		char O[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (O[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'p':
	case 'P':
	{
		char P[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,0,0,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (P[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'q':
	case 'Q':
	{
		char Q[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,0,1,0,1,0},
				{1,1,1,1,1,0},
				{0,0,0,1,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Q[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'r':
	case 'R':
	{
		char R[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0},
				{1,0,0,1,0,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (R[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 's':
	case 'S':
	{
		char S[5][6] = {
				{1,1,1,1,1,0},
				{1,0,0,0,0,0},
				{1,1,1,1,1,0},
				{0,0,0,0,1,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (S[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 't':
	case 'T':
	{
		char T[5][6] = {
				{1,1,1,1,1,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (T[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'u':
	case 'U':
	{
		char U[5][6] = {
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (U[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'v':
	case 'V':
	{
		char V[5][6] = {
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{0,1,0,1,0,0},
				{0,1,0,1,0,0},
				{0,0,1,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (V[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'w':
	case 'W':
	{
		char W[5][6] = {
				{1,0,0,0,1,0},
				{1,0,0,0,1,0},
				{1,0,1,0,1,0},
				{1,1,0,1,1,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (W[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'x':
	case 'X':
	{
		char X[5][6] = {
				{1,0,0,0,1,0},
				{0,1,0,1,0,0},
				{0,0,1,0,0,0},
				{0,1,0,1,0,0},
				{1,0,0,0,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (X[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'y':
	case 'Y':
	{
		char Y[5][6] = {
				{1,0,0,0,1,0},
				{0,1,0,1,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Y[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	case 'z':
	case 'Z':
	{
		char Z[5][6] = {
				{1,1,1,1,1,0},
				{0,0,0,1,0,0},
				{0,0,1,0,0,0},
				{0,1,0,0,0,0},
				{1,1,1,1,1,0}
		};
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Z[i][j] == 1)
				arr[index][i][j] = inp;
				else
				arr[index][i][j] = 32;
			}
		}
		break;
	}
	default:
		cout << "영어알파벳, 공백 또는 느낌표만 입력가능합니다 !";
		exit(1);
	}

}

void outputArr(char*** arr, int len)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				cout << arr[j][i][k];
			}
		}
		cout << endl;
	}
}

void sleep(float spd)
{
	clock_t start = clock();
	while (1)
	{
		if ((clock() - start) >= spd)
			break;
	}
}

void moveLeft(char*** arr, int len)
{
	char tmp1,tmp2;
	for(int j=0; j<5; j++)
	{
		for(int i=len-1; i>=0; i--)
		{
			if(i==len-1)
				tmp1 = arr[i][j][5];

			for(int k=5; k>=0; k--)
			{
				if(i==0 && k==0)
				{
					arr[len-1][j][5]= tmp1;
					continue;
				}
				if(k==0)
				{
					tmp2 = arr[i-1][j][5];
					arr[i-1][j][5] = tmp1;
					tmp1 = tmp2;
					continue;
				}
				tmp2 = arr[i][j][k-1];
				arr[i][j][k-1] = tmp1;
				tmp1=tmp2;
			}
		}
	}
}

void moveRight(char*** arr, int len)
{
	char tmp1,tmp2;
	for(int j=0; j<5; j++)
	{
		for(int i=0; i<len; i++)
		{
			if(i==0)
				tmp1 = arr[i][j][0];

			for(int k=0; k<6; k++)
			{
				if(i==len-1 && k==5)
				{
					arr[0][j][0]= tmp1;
					continue;
				}
				if(k==5)
				{
					tmp2 = arr[i+1][j][0];
					arr[i+1][j][0] = tmp1;
					tmp1 = tmp2;
					continue;
				}
				tmp2 = arr[i][j][k+1];
				arr[i][j][k+1] = tmp1;
				tmp1=tmp2;
			}
		}
	}
}

void moveUp(char*** arr, int len)
{
	char tmp1,tmp2;
	for(int i=0; i<len; i++)
	{
		for(int k=0; k<6; k++)
		{
			for(int j=4; j>=0; j--)
			{
				if(j==4)
					tmp1 = arr[i][j][k];
				else if(j==0)
				{
					arr[i][4][k] = tmp1;
					continue;
				}
				tmp2 = arr[i][j-1][k];
				arr[i][j-1][k] = tmp1;
				tmp1=tmp2;
			}
		}
	}
}
void moveDown(char*** arr, int len)
{
	char tmp1,tmp2;
	for(int i=0; i<len; i++)
	{
		for(int k=0; k<6; k++)
		{
			for(int j=0; j<5; j++)
			{
				if(j==0)
					tmp1 = arr[i][j][k];
				else if(j==4)
				{
					arr[i][0][k] = tmp1;
					continue;
				}
				tmp2 = arr[i][j+1][k];
				arr[i][j+1][k] = tmp1;
				tmp1=tmp2;
			}
		}
	}
}
