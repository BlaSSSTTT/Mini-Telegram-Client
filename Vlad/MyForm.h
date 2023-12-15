#pragma once
#include<iostream>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <WinSock2.h>
#define BUF_SIZE 256 
#pragma comment(lib, "ws2_32.lib")

const int PORT = 12345;
const char* SERVER_IP = "192.168.0.102";
std::string name = "Vlad";
const char* id = "9\n";
//std::vector<System::Windows::Forms::TextBox^> textBoxArray = {};
/*TCHAR szName[] = TEXT("MyFileMappingObject");
std::string name = "e";
std::string namesAllProcess;
bool isInGroup = false;
int n = 0;
TCHAR szMsg[] = TEXT("Message from first process");
HANDLE hSemaphore;
std::string nameSemafore;
HANDLE hMutex;
std::string nameMutex;*/
/*struct Element {
	System::Windows::Forms::TextBox^ tb;
};*/


namespace Vlad {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::Collections::Generic;
	int startPane = 0;
	char* TCHARToChar(const TCHAR* tcharString)
	{

		int length = _tcslen(tcharString) + 1;
		int size = _tcslen(tcharString) * sizeof(char) + 1;

		char* charString = (char*)malloc(size);

#ifdef UNICODE
		wcstombs_s(nullptr, charString, size, tcharString, length);
#else
		strcpy_s(charString, size, tcharString);
#endif

		return charString;
	}
	
	/*value struct Item {
		TextBox^ textBox;
		PictureBox^ pictureBox;
	};*/

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:List<TextBox^>^ items;
	private:List<Label^>^ itemsL;
	private: System::Windows::Forms::Button^ button3;
	private:int sizeItems;
	public:
		MyForm(void)
		{
			InitializeComponent();
			items = gcnew List<TextBox^>();
			itemsL = gcnew List<Label^>();
			sizeItems = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel1;



	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(27, 52);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(495, 344);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(539, 412);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 412);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(506, 22);
			this->textBox2->TabIndex = 2;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::OnTimerTick);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(25, 449);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(506, 22);
			this->textBox3->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(539, 448);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Location = System::Drawing::Point(553, 52);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 344);
			this->panel1->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(665, 429);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"image";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1088, 500);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Vlad";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void sendMessage(const char* message) {
		// Ініціалізація Winsock
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			std::cerr << "Failed to initialize Winsock." << std::endl;
			return;
		}

		// Створення сокета для взаємодії з сервером
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET) {
			std::cerr << "Failed to create socket. Error code: " << WSAGetLastError() << std::endl;
			WSACleanup();
			return;
		}

		// Задання параметрів сервера для підключення
		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
		serverAddr.sin_port = htons(PORT);

		// Підключення до сервера
		if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
			std::cerr << "Failed to connect to server. Error code: " << WSAGetLastError() << std::endl;
			closesocket(clientSocket);
			WSACleanup();
			return;
		}

		// Відправлення повідомлення серверу
		send(clientSocket, message, strlen(message), 0);

		// Завершення роботи
		closesocket(clientSocket);
		WSACleanup();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string s = name + ": " + marshal_as<std::string>(textBox2->Text) + "\n";
		textBox2->Text = "";
		sendMessage(s.c_str());
		/*const DWORD mappingSize = 1024;

		// Створення файлового відображення у пам'яті
		HANDLE hMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, _T("SharedMemory"));

		if (!hMapping) {
			std::cout << "Помилка при створенні файлового відображення: " << GetLastError() << std::endl;
			return;
		}

		// Отримання вказівника на відображену область
		LPVOID pData = MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, mappingSize);

		if (!pData) {
			std::cout << "Помилка при отриманні вказівника на відображену область: " << GetLastError() << std::endl;
			CloseHandle(hMapping);
			return;
		}
		std::string s = name +": "+marshal_as<std::string>(textBox2->Text);
		textBox2->Text = "";
		size_t length = mbstowcs(nullptr, s.c_str(), 0) + 1;

		// Allocate memory for the wchar_t array
		wchar_t* myWcharArray = new wchar_t[length];

		// Convert std::string to wchar_t array
		mbstowcs(myWcharArray, s.c_str(), length);
		// Запис данних в відображену область
		length = s.length() + 1;  // +1 for null terminator
		TCHAR* myTcharArray = new TCHAR[length];


		_tcsncpy(myTcharArray, myWcharArray, length);


		_tcsncpy_s((TCHAR*)pData, mappingSize / sizeof(TCHAR), myWcharArray, _TRUNCATE);
		// Очікування введення користувача для продовження
		//std::cout << "Введіть щось та натисніть Enter, щоб завершити перший процес..." << std::endl;
		//std::cin.get();

		// Закриття відображення у пам'ять
		UnmapViewOfFile(pData);
		CloseHandle(hMapping);*/
	}
		   void splitString(const char* input, char*& firstPart, char*& secondPart) {
			   // Знаходимо позицію першого пробілу
			   const char* spacePosition = std::strchr(input, ' ');

			   if (spacePosition == nullptr) {
				   // Якщо пробіл не знайдено, просто копіюємо весь рядок в першу частину
				   firstPart = new char[std::strlen(input) + 1];
				   std::strcpy(firstPart, input);
				   secondPart = nullptr;
			   }
			   else {
				   // Копіюємо частину до пробілу в першу частину
				   size_t lengthFirst = spacePosition - input;
				   firstPart = new char[lengthFirst + 1];
				   std::strncpy(firstPart, input, lengthFirst);
				   firstPart[lengthFirst] = '\0';

				   // Копіюємо частину після пробілу в другу частину
				   size_t lengthSecond = std::strlen(spacePosition + 1);
				   secondPart = new char[lengthSecond + 1];
				   std::strcpy(secondPart, spacePosition + 1);
			   }
		   }
	private: System::Void OnTimerTick(System::Object^ sender, System::EventArgs^ e) {
		requestMessages();
		/*if (isInGroup) {
			button3->Visible = true;
		}
		const DWORD mappingSize = 1024;
		hSemaphore = CreateSemaphore(nullptr, 0, n, L"SEMAPHORE");
		//WaitForSingleObject(hSemaphore, INFINITE);
		//Sleep(50);
		HANDLE hMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, _T("SharedMemory"));
		if (!hMapping) {
			std::cout << "Помилка при відкритті файлового відображення: " << GetLastError() << std::endl;
			return;
		}

		// Отримання вказівника на відображену область
		LPVOID pData = MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);

		if (!pData) {
			std::cout << "Помилка при отриманні вказівника на відображену область: " << GetLastError() << std::endl;
			CloseHandle(hMapping);
			return;
		}

		// Виведення даних з відображеної області
		if (marshal_as<String^>(static_cast<wchar_t*>(pData))!=L"") {
			textBox1->Text = textBox1->Text + marshal_as<String^>(static_cast<wchar_t*>(pData)) + Environment::NewLine;
			barier();
			_tcsncpy_s((TCHAR*)pData, mappingSize / sizeof(TCHAR), _T(""), _TRUNCATE);
		}

		// Закриття відображення у пам'ять
		UnmapViewOfFile(pData);
		CloseHandle(hMapping);
		//CloseHandle(hSemaphore);*/
	}
	private:void removeFirstSevenChars(char* str) {
		for (int i = 0; i < strlen(str); i++) {
			str[i] = str[i + 7];
		}
	}
		   String^ RemoveEmptyLines(String^ text) {
			   // Split the text into lines
			   array<String^>^ lines = text->Split(gcnew array<wchar_t>{'\n'});

			   // Remove empty lines
			   array<String^>^ nonEmptyLines = gcnew array<String^>(0);
			   for each (String ^ line in lines) {
				   if (!String::IsNullOrWhiteSpace(line)) {
					   Array::Resize(nonEmptyLines, nonEmptyLines->Length + 1);
					   nonEmptyLines[nonEmptyLines->Length - 1] = line;
				   }
			   }

			   // Combine non-empty lines into a new text
			   return String::Join(Environment::NewLine, nonEmptyLines);
		   }
	private:void requestMessages() {
		// Ініціалізація Winsock
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			std::cerr << "Failed to initialize Winsock." << std::endl;
			return;
		}

		// Створення сокета для взаємодії з сервером
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET) {
			std::cerr << "Failed to create socket. Error code: " << WSAGetLastError() << std::endl;
			WSACleanup();
			return;
		}

		// Задання параметрів сервера для підключення
		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP); // Змініть це на IP-адресу сервера
		serverAddr.sin_port = htons(PORT);

		// Підключення до сервера
		if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
			std::cerr << "Failed to connect to server. Error code: " << WSAGetLastError() << std::endl;
			closesocket(clientSocket);
			WSACleanup();
			return;
		}

		// Відправлення запиту на отримання повідомлень
		const char* request1 = "get_messages ";
		char* request = new char[strlen(request1) + strlen(id) + 1];
		strcpy(request, request1);
		strcat(request, id);
		send(clientSocket, request, strlen(request), 0);

		// Отримання відповіді від сервера
		char buffer[100];
		int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (bytesReceived > 0) {
			
			if (strncmp(buffer, "del_el", 6) == 0) {
				
				removeFirstSevenChars(buffer);
				std::cout << buffer << std::endl;
				String^ s = msclr::interop::marshal_as<String^>(buffer);
				String^ currentText = textBox1->Text;

				String^ newText = RemoveEmptyLines(currentText->Replace(s, ""));
				
				/*std::string str = marshal_as<std::string>(newText);
				std::istringstream iss(str);
				newText = L"";
				while (std::getline(iss, str)) {
					std::cout << str << std::endl;
					if (str.compare("\n") != 0) {
						newText += marshal_as<String^>(str) + Environment::NewLine;
					}
				}*/
				textBox1->Text = newText + Environment::NewLine;
			}
			else {
				char* r;
				char* l;
				splitString(buffer, l, r);
				 TextBox^ textBox = gcnew TextBox();
				 Label^ label = gcnew Label();
				 label->Text = marshal_as<String^>(l);
				 if (300 > 5 + sizeItems * 25) {
					 textBox->Location = System::Drawing::Point(50, 5 + sizeItems * 25);
					 label->Location = System::Drawing::Point(5, 5 + sizeItems * 25);
					 
				 }
				 else {
					 textBox->Location = System::Drawing::Point(50, 285);
					 label->Location = System::Drawing::Point(5, 285);
					 
				 }
				 label->Size = System::Drawing::Size(40, 15);
				 textBox->Size = System::Drawing::Size(100, 50);
				 sizeItems++;
				 std::cout << sizeItems << std::endl;
				 panel1->Controls->Add(label);
				 panel1->Controls->Add(textBox);
			
				// Додаємо нове текстове поле до масиву

				items->Add(textBox);
				textBox->Text = marshal_as<String^>(r);
				itemsL->Add(label);
				textBox1->Text = textBox1->Text + marshal_as<String^>(buffer) + Environment::NewLine;
			}
			// Виведення отриманих повідомлень
			//std::cout << "Received messages from server: " << std::endl;
		   // std::cout.write(buffer, bytesReceived);
			
		}
		else {

			//std::cerr << "Error while receiving data from server. Error code: " << WSAGetLastError() << std::endl;
		}

		// Завершення роботи
		closesocket(clientSocket);
		WSACleanup();
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		// Ініціалізація Winsock
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			std::cerr << "Failed to initialize Winsock." << std::endl;
			return;
		}

		// Створення сокета для взаємодії з сервером
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET) {
			std::cerr << "Failed to create socket. Error code: " << WSAGetLastError() << std::endl;
			WSACleanup();
			return;
		}

		// Задання параметрів сервера для підключення
		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP); // Змініть це на IP-адресу сервера
		serverAddr.sin_port = htons(PORT);

		// Підключення до сервера
		if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
			std::cerr << "Failed to connect to server. Error code: " << WSAGetLastError() << std::endl;
			closesocket(clientSocket);
			WSACleanup();
			return;
		}

		// Відправлення запиту на отримання повідомлень
		std::string s = name + ": " + marshal_as<std::string>(textBox3->Text) + "\n";
		textBox3->Text = "";
		const char* request1 = "del_messages ";
		
		char* request = new char[strlen(request1)+ s.length() +1];
		strcpy(request, request1);
		strcat(request, s.c_str());
		send(clientSocket, request, strlen(request), 0);

		// Завершення роботи
		closesocket(clientSocket);
		WSACleanup();
	}
		  /* void Form_Paint(Object^ sender, PaintEventArgs^ e)
		   {
			   if (!isRotated) {
				   isRotated = true;
				   std::cout << "EEEEEEEEEEEEEEEEEEEE"<<std::endl;
				   // Rotate the Panel by 180 degrees
				   e->Graphics->TranslateTransform(panel1->Width, panel1->Height);
				   e->Graphics->RotateTransform(180.0f);
				   e->Graphics->TranslateTransform(-panel1->Width, -panel1->Height);

				   // Draw the Panel and its contents
				   button1->DrawToBitmap(gcnew Bitmap(button1->Width, button1->Height), button1->ClientRectangle);
				   panel1->DrawToBitmap(gcnew Bitmap(panel1->Width, panel1->Height), panel1->ClientRectangle);
			   }
		   }*/
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	/*std::ifstream imageFile("E:\\123.jpg", std::ios::binary);
	std::ostringstream imageStream;
	imageStream << imageFile.rdbuf();
	std::string imageData = imageStream.str();

	int serverSocket, clientSocket;
	struct sockaddr_in serverAddr, clientAddr;*/
}
};
}
