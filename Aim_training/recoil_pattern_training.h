#pragma once

#include <iostream>
#include <math.h>
#include "tinyxml2.h"

struct vector2 {
	int X;
	int Y;
};

namespace Aimtraining {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ recoil_pattern_training
	/// </summary>
	public ref class recoil_pattern_training : public System::Windows::Forms::Form {
	public:
		Graphics^ ground; //объ€вл€ем объект - графику, на которой будем рисовать
		Pen^ pen; //объ€вл€ем объект - карандаш, которым будем рисовать контур
		Random rand;
	private: System::Windows::Forms::Button^ restart_count;
	private: System::Windows::Forms::Label^ output_count;
	private: System::Windows::Forms::RadioButton^ choice_ak47;
	private: System::Windows::Forms::RadioButton^ choice_m4a4;
	private: System::Windows::Forms::RadioButton^ choice_m4a1_s;




	private: System::Windows::Forms::RadioButton^ choice_aug;
	private: System::Windows::Forms::RadioButton^ choice_galil;
	private: System::Windows::Forms::RadioButton^ choice_famas;




	private: SolidBrush^ Brush = gcnew SolidBrush(Color::BlueViolet);
	public:
		recoil_pattern_training(void) {
			InitializeComponent();
			pen = gcnew Pen(Color::WhiteSmoke);
			ground = pictureBox1->CreateGraphics();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~recoil_pattern_training() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:


	private: System::Windows::Forms::Button^ start_button;
	private: System::Windows::Forms::Button^ stop_button;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ radius;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(recoil_pattern_training::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radius = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->restart_count = (gcnew System::Windows::Forms::Button());
			this->output_count = (gcnew System::Windows::Forms::Label());
			this->choice_ak47 = (gcnew System::Windows::Forms::RadioButton());
			this->choice_m4a4 = (gcnew System::Windows::Forms::RadioButton());
			this->choice_m4a1_s = (gcnew System::Windows::Forms::RadioButton());
			this->choice_aug = (gcnew System::Windows::Forms::RadioButton());
			this->choice_galil = (gcnew System::Windows::Forms::RadioButton());
			this->choice_famas = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radius))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(750, 750);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &recoil_pattern_training::pictureBox1_Click);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &recoil_pattern_training::pictureBox1_MouseDown);
			// 
			// start_button
			// 
			this->start_button->BackColor = System::Drawing::Color::DimGray;
			this->start_button->Location = System::Drawing::Point(859, 13);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(75, 23);
			this->start_button->TabIndex = 3;
			this->start_button->Text = L"старт";
			this->start_button->UseVisualStyleBackColor = false;
			this->start_button->Click += gcnew System::EventHandler(this, &recoil_pattern_training::start_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->BackColor = System::Drawing::Color::DimGray;
			this->stop_button->Location = System::Drawing::Point(778, 13);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(75, 23);
			this->stop_button->TabIndex = 4;
			this->stop_button->Text = L"стоп";
			this->stop_button->UseVisualStyleBackColor = false;
			this->stop_button->Click += gcnew System::EventHandler(this, &recoil_pattern_training::stop_button_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(775, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"радиус кружков";
			// 
			// radius
			// 
			this->radius->BackColor = System::Drawing::Color::DimGray;
			this->radius->Location = System::Drawing::Point(778, 55);
			this->radius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70, 0, 0, 0 });
			this->radius->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->radius->Name = L"radius";
			this->radius->Size = System::Drawing::Size(156, 20);
			this->radius->TabIndex = 5;
			this->radius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->radius->ValueChanged += gcnew System::EventHandler(this, &recoil_pattern_training::radius_ValueChanged);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &recoil_pattern_training::timer1_Tick);
			// 
			// restart_count
			// 
			this->restart_count->BackColor = System::Drawing::Color::DimGray;
			this->restart_count->Location = System::Drawing::Point(778, 237);
			this->restart_count->Name = L"restart_count";
			this->restart_count->Size = System::Drawing::Size(104, 23);
			this->restart_count->TabIndex = 19;
			this->restart_count->Text = L"сбросить счет";
			this->restart_count->UseVisualStyleBackColor = false;
			this->restart_count->Click += gcnew System::EventHandler(this, &recoil_pattern_training::restart_count_Click);
			// 
			// output_count
			// 
			this->output_count->AutoSize = true;
			this->output_count->BackColor = System::Drawing::Color::DimGray;
			this->output_count->Location = System::Drawing::Point(775, 221);
			this->output_count->Name = L"output_count";
			this->output_count->Size = System::Drawing::Size(41, 13);
			this->output_count->TabIndex = 18;
			this->output_count->Text = L"счет: 0";
			// 
			// choice_ak47
			// 
			this->choice_ak47->AutoSize = true;
			this->choice_ak47->BackColor = System::Drawing::Color::DimGray;
			this->choice_ak47->Location = System::Drawing::Point(778, 82);
			this->choice_ak47->Name = L"choice_ak47";
			this->choice_ak47->Size = System::Drawing::Size(54, 17);
			this->choice_ak47->TabIndex = 20;
			this->choice_ak47->Text = L"AK-47";
			this->choice_ak47->UseVisualStyleBackColor = false;
			this->choice_ak47->CheckedChanged += gcnew System::EventHandler(this, &recoil_pattern_training::choice_ak47_CheckedChanged);
			// 
			// choice_m4a4
			// 
			this->choice_m4a4->AutoSize = true;
			this->choice_m4a4->BackColor = System::Drawing::Color::DimGray;
			this->choice_m4a4->Location = System::Drawing::Point(778, 106);
			this->choice_m4a4->Name = L"choice_m4a4";
			this->choice_m4a4->Size = System::Drawing::Size(53, 17);
			this->choice_m4a4->TabIndex = 21;
			this->choice_m4a4->Text = L"M4A4";
			this->choice_m4a4->UseVisualStyleBackColor = false;
			this->choice_m4a4->CheckedChanged += gcnew System::EventHandler(this, &recoil_pattern_training::choice_m4a4_CheckedChanged);
			// 
			// choice_m4a1_s
			// 
			this->choice_m4a1_s->AutoSize = true;
			this->choice_m4a1_s->BackColor = System::Drawing::Color::DimGray;
			this->choice_m4a1_s->Location = System::Drawing::Point(778, 130);
			this->choice_m4a1_s->Name = L"choice_m4a1_s";
			this->choice_m4a1_s->Size = System::Drawing::Size(63, 17);
			this->choice_m4a1_s->TabIndex = 22;
			this->choice_m4a1_s->Text = L"M4A1-S";
			this->choice_m4a1_s->UseVisualStyleBackColor = false;
			this->choice_m4a1_s->CheckedChanged += gcnew System::EventHandler(this, &recoil_pattern_training::choice_m4a1_s_CheckedChanged);
			// 
			// choice_aug
			// 
			this->choice_aug->AutoSize = true;
			this->choice_aug->BackColor = System::Drawing::Color::DimGray;
			this->choice_aug->Location = System::Drawing::Point(778, 201);
			this->choice_aug->Name = L"choice_aug";
			this->choice_aug->Size = System::Drawing::Size(48, 17);
			this->choice_aug->TabIndex = 26;
			this->choice_aug->Text = L"AUG";
			this->choice_aug->UseVisualStyleBackColor = false;
			this->choice_aug->CheckedChanged += gcnew System::EventHandler(this, &recoil_pattern_training::choice_aug_CheckedChanged);
			// 
			// choice_galil
			// 
			this->choice_galil->AutoSize = true;
			this->choice_galil->BackColor = System::Drawing::Color::DimGray;
			this->choice_galil->Location = System::Drawing::Point(778, 177);
			this->choice_galil->Name = L"choice_galil";
			this->choice_galil->Size = System::Drawing::Size(55, 17);
			this->choice_galil->TabIndex = 25;
			this->choice_galil->Text = L"GALIL";
			this->choice_galil->UseVisualStyleBackColor = false;
			this->choice_galil->CheckedChanged += gcnew System::EventHandler(this, &recoil_pattern_training::choice_galil_CheckedChanged);
			// 
			// choice_famas
			// 
			this->choice_famas->AutoSize = true;
			this->choice_famas->BackColor = System::Drawing::Color::DimGray;
			this->choice_famas->Location = System::Drawing::Point(778, 153);
			this->choice_famas->Name = L"choice_famas";
			this->choice_famas->Size = System::Drawing::Size(61, 17);
			this->choice_famas->TabIndex = 24;
			this->choice_famas->Text = L"FAMAS";
			this->choice_famas->UseVisualStyleBackColor = false;
			this->choice_famas->CheckedChanged += gcnew System::EventHandler(this, &recoil_pattern_training::choice_famas_CheckedChanged);
			// 
			// recoil_pattern_training
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(946, 783);
			this->Controls->Add(this->choice_aug);
			this->Controls->Add(this->choice_galil);
			this->Controls->Add(this->choice_famas);
			this->Controls->Add(this->choice_m4a1_s);
			this->Controls->Add(this->choice_m4a4);
			this->Controls->Add(this->choice_ak47);
			this->Controls->Add(this->restart_count);
			this->Controls->Add(this->output_count);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radius);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->start_button);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"recoil_pattern_training";
			this->Text = L"recoil_pattern_training";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radius))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		//количество пуль
		float amount_bullet = 0;
		//радиус кружков
		int circle_radius = 10;
		//массив пуль
		vector2* circles = new vector2[amount_bullet];
		//идет тренировка (false-нет)
		bool start_training = false;
		//количество попаданий по кружкам
		float count = 0;
		//текуща€ пул€
		int count_bullet = 0;
		//открытие файла дл€ записи результатов
		tinyxml2::XMLDocument* data_base = new tinyxml2::XMLDocument("data.xml");
	private:
		//отрисовка кружка
		void DrawCircle(int x, int y) {
			try {
				ground->FillEllipse(Brush, x, y, circle_radius, circle_radius);
				ground->DrawEllipse(pen, x, y, circle_radius, circle_radius);
			}
			catch (System::OverflowException^ ex) {
				return;
			}
		}
		//отрисовка кружка
		void DrawCircle(int x, int y, int r) {
			ground->FillEllipse(Brush, x, y, r, r);
			ground->DrawEllipse(pen, x, y, r, r);
		}
		//подсчет среднего времени
		int count_time(int* arr, int razm) {
			int sum = 0;
			for (int i = 1; i < razm; i++) {
				sum += arr[i];
			}
			try {
				return sum / (razm - 1);
			}
			catch (System::DivideByZeroException^ ex) {
				return sum;
			}
		}
	private:
		//запуск тренировки
		System::Void start_button_Click(System::Object^ sender, System::EventArgs^ e) {
			Point p(0, 0);
			ground->DrawImage(pictureBox1->Image, p);
			DrawCircle(375, 385, 5);
		}
	private:
		//отсановка тренировки
		System::Void stop_button_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
		}
	private:
		//изменение радиуса кружков
		System::Void radius_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_radius = Convert::ToInt32(radius->Value);
			output_count->Text = "счет: 0";
		}
	private:
		//расчеты и отрисовка кружков на холсте
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			int c_y = abs(this->Location.Y - Cursor->Position.Y) - 43;
			int c_x = abs(this->Location.X - Cursor->Position.X) - 20;
			int x = c_x - 375;
			int y = c_y - 385;
			std::cout << x << ", " << y << std::endl;
			//this->Cursor->Position = Point(this->Location.X + 20 + circles[count_bullet].X, this->Location.Y + 42 + circles[count_bullet].Y);
			count_bullet++;
			if (sqrt(pow(x, 2) + pow(y, 2)) <= circle_radius / 2) {
				count++;
				output_count->Text = "счет: " + Convert::ToString(count);
			}
			DrawCircle(circles[count_bullet].X, circles[count_bullet].Y);
			if (count_bullet == amount_bullet) {
				timer1->Enabled = false;
				start_training = false;
				MessageBox::Show("ваш результат: " + Convert::ToString(count / amount_bullet));
				if (data_base->LoadFile("data.xml") == tinyxml2::XML_SUCCESS) {
					if (choice_ak47->Checked) {
						tinyxml2::XMLElement* AK = data_base->FirstChildElement("AK47");
						AK->SetAttribute("value", count / amount_bullet);
					}
					else if(choice_m4a4->Checked) {
						tinyxml2::XMLElement* AK = data_base->FirstChildElement("M4A4");
						AK->SetAttribute("value", count / amount_bullet);
					}
					else if (choice_m4a1_s->Checked) {
						tinyxml2::XMLElement* AK = data_base->FirstChildElement("M4A1S");
						AK->SetAttribute("value", count / amount_bullet);
					}
					else if (choice_aug->Checked) {
						tinyxml2::XMLElement* AK = data_base->FirstChildElement("AUG");
						AK->SetAttribute("value", count / amount_bullet);
					}
					else if (choice_famas->Checked) {
						tinyxml2::XMLElement* AK = data_base->FirstChildElement("FAMAS");
						AK->SetAttribute("value", count / amount_bullet);
					}
					else if (choice_galil->Checked) {
						tinyxml2::XMLElement* AK = data_base->FirstChildElement("GALIL");
						AK->SetAttribute("value", count / amount_bullet);
					}
					data_base->SaveFile("data.xml");
				}
				count_bullet = 0;
			}
		}
	private:
		//обработка нажати€ на кнопку мыши
		System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			timer1->Enabled = true;
			Point p(0, 0);
			ground->DrawImage(pictureBox1->Image, p);
			DrawCircle(375, 385, 5);
			count = 0;
			count_bullet = 0;
		}
	private:
		//перезапуск тренировки
		System::Void restart_count_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			output_count->Text = "счет: 0";
		}
	private:
		//выбран рисунок отдачи ак47
		System::Void choice_ak47_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			vector2* AK47 = new vector2[30];
			AK47[0] = { 375 , 375 };
			AK47[1] = { 375 + 1, 375 - 3 };
			AK47[2] = { 375 , 375 - 17 };
			AK47[3] = { 375 + 1, 375 - 40 };
			AK47[4] = { 375 + 3, 375 - 64 };
			AK47[5] = { 375 - 6, 375 - 87 };
			AK47[6] = { 375 - 12, 375 - 108 };
			AK47[7] = { 375 - 23, 375 - 124 };
			AK47[8] = { 375 - 10, 375 - 136 };
			AK47[9] = { 375 + 23, 375 - 132 };
			AK47[10] = { 375 + 38, 375 - 136 };
			AK47[11] = { 375 + 59, 375 - 140 };
			AK47[12] = { 375 + 61, 375 - 144 };
			AK47[13] = { 375 + 41, 375 - 146 };
			AK47[14] = { 375 + 28, 375 - 144 };
			AK47[15] = { 375 + 33, 375 - 146 };
			AK47[16] = { 375 + 18, 375 - 153 };
			AK47[17] = { 375 + 6, 375 - 157 };
			AK47[18] = { 375 - 13, 375 - 157 };
			AK47[19] = { 375 - 24, 375 - 149 };
			AK47[20] = { 375 - 39, 375 - 149 };
			AK47[21] = { 375 - 28, 375 - 152 };
			AK47[22] = { 375 - 21, 375 - 157 };
			AK47[23] = { 375 - 16, 375 - 159 };
			AK47[24] = { 375 - 31, 375 - 157 };
			AK47[25] = { 375 - 33, 375 - 159 };
			AK47[26] = { 375 - 20, 375 - 161 };
			AK47[27] = { 375 + 6, 375 - 159 };
			AK47[28] = { 375 + 38, 375 - 145 };
			AK47[29] = { 375 + 50, 375 - 145 };
			circles = AK47;
			amount_bullet = 30;
		}
	private:
		//выбран рисунок отдачи м4а4
		System::Void choice_m4a4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			vector2* M4A4 = new vector2[30];
			M4A4[0] = { 375 , 375 };
			M4A4[1] = { 375 + 1, 375 - 3 };
			M4A4[2] = { 375 , 375 - 10 };
			M4A4[3] = { 375 + 4, 375 - 24 };
			M4A4[4] = { 375 , 375 - 42 };
			M4A4[5] = { 375 + 6, 375 - 58 };
			M4A4[6] = { 375 + 10, 375 - 77 };
			M4A4[7] = { 375 - 3, 375 - 88 };
			M4A4[8] = { 375 - 10, 375 - 99 };
			M4A4[9] = { 375 - 27, 375 - 103 };
			M4A4[10] = { 375 - 23, 375 - 108 };
			M4A4[11] = { 375 - 10, 375 - 115 };
			M4A4[12] = { 375 + 11, 375 - 111 };
			M4A4[13] = { 375 + 19, 375 - 110 };
			M4A4[14] = { 375 + 49, 375 - 106 };
			M4A4[15] = { 375 + 49, 375 - 110 };
			M4A4[16] = { 375 + 61, 375 - 110 };
			M4A4[17] = { 375 + 60, 375 - 114 };
			M4A4[18] = { 375 + 50, 375 - 115 };
			M4A4[19] = { 375 + 44, 375 - 115 };
			M4A4[20] = { 375 + 34, 375 - 115 };
			M4A4[21] = { 375 + 26, 375 - 118 };
			M4A4[22] = { 375 + 7, 375 - 119 };
			M4A4[23] = { 375 , 375 - 120 };
			M4A4[24] = { 375 - 1, 375 - 126 };
			M4A4[25] = { 375 - 9, 375 - 124 };
			M4A4[26] = { 375 - 5, 375 - 128 };
			M4A4[27] = { 375 - 7, 375 - 126 };
			M4A4[28] = { 375 - 9, 375 - 130 };
			M4A4[29] = { 375 - 14, 375 - 132 };
			circles = M4A4;
			amount_bullet = 30;
		}
	private:
		//выбран рисунок отдачи м4а1s
		System::Void choice_m4a1_s_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			vector2* M4A1S = new vector2[25];
			M4A1S[0] = { 375 , 375 };
			M4A1S[1] = { 375 + 1, 375 - 3 };
			M4A1S[2] = { 375 , 375 - 10 };
			M4A1S[3] = { 375 + 4, 375 - 24 };
			M4A1S[4] = { 375 , 375 - 42 };
			M4A1S[5] = { 375 + 6, 375 - 58 };
			M4A1S[6] = { 375 + 10, 375 - 77 };
			M4A1S[7] = { 375 - 3, 375 - 88 };
			M4A1S[8] = { 375 - 10, 375 - 99 };
			M4A1S[9] = { 375 - 27, 375 - 103 };
			M4A1S[10] = { 375 - 23, 375 - 108 };
			M4A1S[11] = { 375 - 10, 375 - 115 };
			M4A1S[12] = { 375 + 11, 375 - 111 };
			M4A1S[13] = { 375 + 19, 375 - 110 };
			M4A1S[14] = { 375 + 49, 375 - 106 };
			M4A1S[15] = { 375 + 49, 375 - 110 };
			M4A1S[16] = { 375 + 61, 375 - 110 };
			M4A1S[17] = { 375 + 60, 375 - 114 };
			M4A1S[18] = { 375 + 50, 375 - 115 };
			M4A1S[19] = { 375 + 44, 375 - 115 };
			M4A1S[20] = { 375 + 34, 375 - 115 };
			M4A1S[21] = { 375 + 26, 375 - 118 };
			M4A1S[22] = { 375 + 7, 375 - 119 };
			M4A1S[23] = { 375 , 375 - 120 };
			M4A1S[24] = { 375 - 1, 375 - 126 };
			circles = M4A1S;
			amount_bullet = 25;
		}
	private:
		//выбран рисунок отдачи famas
		System::Void choice_famas_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			vector2* FAMAS = new vector2[25];
			FAMAS[0] = { 375 , 375 };
			FAMAS[1] = { 375 + 2, 375 - 2 };
			FAMAS[2] = { 375 + 1, 375 - 3 };
			FAMAS[3] = { 375 + 7, 375 - 12 };
			FAMAS[4] = { 375 + 8, 375 - 27 };
			FAMAS[5] = { 375 + 8, 375 - 44 };
			FAMAS[6] = { 375 - 2, 375 - 55 };
			FAMAS[7] = { 375 - 15, 375 - 64 };
			FAMAS[8] = { 375 - 10, 375 - 75 };
			FAMAS[9] = { 375 + 4, 375 - 78 };
			FAMAS[10] = { 375 + 13, 375 - 82 };
			FAMAS[11] = { 375 + 26, 375 - 84 };
			FAMAS[12] = { 375 + 24, 375 - 90 };
			FAMAS[13] = { 375 + 5, 375 - 93 };
			FAMAS[14] = { 375 - 2, 375 - 94 };
			FAMAS[15] = { 375 - 17, 375 - 93 };
			FAMAS[16] = { 375 - 22, 375 - 95 };
			FAMAS[17] = { 375 - 33, 375 - 94 };
			FAMAS[18] = { 375 - 35, 375 - 97 };
			FAMAS[19] = { 375 - 33, 375 - 98 };
			FAMAS[20] = { 375 - 12, 375 - 101 };
			FAMAS[21] = { 375 - 18, 375 - 100 };
			FAMAS[22] = { 375 - 14, 375 - 100 };
			FAMAS[23] = { 375 - 30, 375 - 97 };
			FAMAS[24] = { 375 - 42, 375 - 89 };
			circles = FAMAS;
			amount_bullet = 25;
		}
	private:
		//выбран рисунок отдачи galil
		System::Void choice_galil_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			vector2* GALIL = new vector2[35];
			GALIL[0] = { 375 , 375 };
			GALIL[1] = { 375 - 2 , 375 - 1};
			GALIL[2] = { 375 , 375 - 4};
			GALIL[3] = { 375 - 5 , 375 - 13 };
			GALIL[4] = { 375 - 14 ,375 - 25 };
			GALIL[5] = { 375 - 16 , 375 - 42 };
			GALIL[6] = { 375 - 15 , 375 - 59 };
			GALIL[7] = { 375 - 19 , 375 - 70 };
			GALIL[8] = { 375 - 29 , 375 - 79 };
			GALIL[9] = { 375 - 24 , 375 - 90 };
			GALIL[10] = { 375 - 8 , 375 - 95 };
			GALIL[11] = { 375 + 14 , 375 - 93 };
			GALIL[12] = { 375 + 37 , 375 - 87 };
			GALIL[13] = { 375 + 43 , 375 - 90 };
			GALIL[14] = { 375 + 50 , 375 - 91 };
			GALIL[15] = { 375 + 54 , 375 - 93 };
			GALIL[16] = { 375 + 58 , 375 - 95 };
			GALIL[17] = { 375 + 53 , 375 - 99 };
			GALIL[18] = { 375 + 34 , 375 - 103 };
			GALIL[19] = { 375 + 24 , 375 - 105 };
			GALIL[20] = { 375 + 7 , 375 - 105 };
			GALIL[21] = { 375 - 13 , 375 - 72 };
			GALIL[22] = { 375 - 18 , 375 - 96 };
			GALIL[23] = { 375 - 21 , 375 - 98 };
			GALIL[24] = { 375 - 21 , 375 - 104 };
			GALIL[25] = { 375 - 30 , 375 - 102 };
			GALIL[26] = { 375 - 42 , 375 - 98 };
			GALIL[27] = { 375 - 35 , 375 - 100 };
			GALIL[28] = { 375 - 11 , 375 - 97 };
			GALIL[29] = { 375 + 7 , 375 - 96 };
			GALIL[30] = { 375 + 15 , 375 - 102 };
			GALIL[31] = { 375 + 19 , 375 - 99 };
			GALIL[32] = { 375 + 22 , 375 - 102};
			GALIL[33] = { 375 + 40 , 375 - 92 };
			GALIL[34] = { 375 + 51 , 375 - 91 };
			circles = GALIL;
			amount_bullet = 35;
		}
	private:
		//выбран рисунок отдачи aug
		System::Void choice_aug_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			vector2* AUG = new vector2[30];
			AUG[0] = { 375 , 375 };
			AUG[1] = { 375 - 1, 375 - 2 };
			AUG[2] = { 375 - 1, 375 - 7 };
			AUG[3] = { 375 + 2, 375 - 18 };
			AUG[4] = { 375 + 6, 375 - 34 };
			AUG[5] = { 375 + 2, 375 - 53 };
			AUG[6] = { 375 - 4, 375 - 69 };
			AUG[7] = { 375 - 13, 375 - 83 };
			AUG[8] = { 375 - 18, 375 - 95 };
			AUG[9] = { 375 - 27 , 375 - 100 };
			AUG[10] = { 375 - 15, 375 - 107 };
			AUG[11] = { 375 - 12, 375 - 109 };
			AUG[12] = { 375 - 21, 375 - 110 };
			AUG[13] = { 375 - 21, 375 - 112 };
			AUG[14] = { 375 - 5, 375 - 113 };
			AUG[15] = { 375 + 19, 375 - 107 };
			AUG[16] = { 375 + 40, 375 - 98 };
			AUG[17] = { 375 + 41, 375 - 101 };
			AUG[18] = { 375 + 44, 375 - 104 };
			AUG[19] = { 375 + 51, 375 - 105 };
			AUG[20] = { 375 + 34, 375 - 108 };
			AUG[21] = { 375 + 19, 375 - 107 };
			AUG[22] = { 375 + 11, 375 - 110 };
			AUG[23] = { 375 + 6, 375 - 113 };
			AUG[24] = { 375 + 2, 375 - 111 };
			AUG[25] = { 375 - 4, 375 - 113 };
			AUG[26] = { 375 - 11, 375 - 115 };
			AUG[27] = { 375 - 13, 375 - 110 };
			AUG[28] = { 375 - 24, 375 - 107 };
			AUG[29] = { 375 - 38, 375 - 104 };
			circles = AUG;
			amount_bullet = 30;
		}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
